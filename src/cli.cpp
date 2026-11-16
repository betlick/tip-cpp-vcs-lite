#include "vcslite/cli.hpp"

#include "vcslite/error.hpp"
#include "vcslite/repository.hpp"

#include <exception>
#include <filesystem>
#include <ostream>

namespace vcslite {
namespace {

void require(bool condition, const std::string& syntax) {
    if (!condition) {
        throw UsageError("Expected: " + syntax + ". See vcslite --help.");
    }
}

} // namespace

void CLI::printHelp(std::ostream& output) const {
    output << "VCS Lite - local file version manager\n\n"
           << "Usage (run from the working directory):\n"
           << "  vcslite init\n"
           << "  vcslite commit -m \"message\"\n"
           << "  vcslite log\n"
           << "  vcslite status\n"
           << "  vcslite checkout <id> [--force]\n"
           << "  vcslite --help\n\n"
           << "--force replaces unsaved files after making a preserved backup.\n"
           << "Project stage: buildable skeleton. Repository operations are not implemented.\n";
}

int CLI::run(const std::vector<std::string>& args,
             std::ostream& output, std::ostream& errors) const {
    try {
        if (args.empty()) {
            printHelp(output);
            return 0;
        }
        const auto& command = args.front();
        if (command == "--help") {
            require(args.size() == 1, "vcslite --help");
            printHelp(output);
            return 0;
        }

        if (command == "init" || command == "log" || command == "status") {
            require(args.size() == 1, "vcslite " + command);
        } else if (command == "commit") {
            require(args.size() == 3 && args[1] == "-m", "vcslite commit -m \"message\"");
            require(args[2].find_first_not_of(" \t\n\r\v\f") != std::string::npos,
                    "vcslite commit -m \"non-empty message\"");
        } else if (command == "checkout") {
            require(args.size() == 2 || (args.size() == 3 && args[2] == "--force"),
                    "vcslite checkout <id> [--force]");
            require(!args[1].empty() && args[1].front() != '-',
                    "vcslite checkout <id> [--force]");
        } else {
            throw UsageError("Unknown command: " + command + ". See vcslite --help.");
        }

        Repository repository(std::filesystem::current_path());
        if (command == "init") {
            output << (repository.init() ? "Repository initialized.\n" : "Repository already exists.\n");
        } else if (command == "commit") {
            const auto saved = repository.commit(args[2]);
            output << "Created commit " << saved.id << '\n';
        } else if (command == "log") {
            const auto history = repository.log();
            if (history.commits.empty()) {
                output << "No commits yet.\n";
            }
            for (const auto& saved : history.commits) {
                output << saved.id;
                if (history.head && *history.head == saved.id) {
                    output << " (HEAD)";
                }
                output << "  " << saved.createdAt << "  " << saved.message << '\n';
            }
        } else if (command == "status") {
            const auto changes = repository.status();
            if (changes.empty()) {
                output << "Working directory is clean.\n";
            }
            for (const auto& path : changes.added) {
                output << "added: " << path.generic_u8string() << '\n';
            }
            for (const auto& path : changes.modified) {
                output << "modified: " << path.generic_u8string() << '\n';
            }
            for (const auto& path : changes.deleted) {
                output << "deleted: " << path.generic_u8string() << '\n';
            }
        } else {
            const bool force = args.size() == 3;
            if (force) {
                errors << "Warning: --force will replace unsaved files after creating a backup.\n";
            }
            const auto restored = repository.checkout(args[1], force);
            output << "Restored commit " << args[1] << '\n';
            if (restored.preservedBackup) {
                output << "Backup: " << restored.preservedBackup->u8string() << '\n';
            }
        }
        return 0;
    } catch (const UsageError& error) {
        errors << "Error: " << error.what() << '\n';
        return 2;
    } catch (const std::exception& error) {
        errors << "Error: " << error.what() << '\n';
        return 1;
    }
}

} // namespace vcslite
