#pragma once

#include <cstdint>
#include <filesystem>
#include <optional>
#include <string>
#include <vector>

namespace vcslite {

// All paths are relative to a working directory or a snapshot's files directory.
struct FileEntry {
    std::filesystem::path relativePath;
    std::uintmax_t size = 0;
};

struct Commit {
    std::string id;
    std::optional<std::string> parentId;
    std::string createdAt; // UTC, e.g. 2026-11-16T16:00:00Z.
    std::string message;
    std::vector<FileEntry> files;
};

struct RepositoryState {
    std::optional<std::string> head;
    std::optional<std::string> latest;
};

struct StatusResult {
    std::vector<std::filesystem::path> added;
    std::vector<std::filesystem::path> modified;
    std::vector<std::filesystem::path> deleted;

    [[nodiscard]] bool empty() const noexcept {
        return added.empty() && modified.empty() && deleted.empty();
    }
};

struct HistoryResult {
    std::vector<Commit> commits; // Newest first; includes commits after HEAD.
    std::optional<std::string> head;
};

struct CheckoutResult {
    std::optional<std::filesystem::path> preservedBackup;
};

inline constexpr std::uintmax_t maxFileCount = 1000;
inline constexpr std::uintmax_t maxTotalBytes = 100'000'000;

} // namespace vcslite
