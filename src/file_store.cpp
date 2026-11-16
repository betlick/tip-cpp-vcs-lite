#include "vcslite/file_store.hpp"

#include "vcslite/error.hpp"

#include <utility>

namespace vcslite {

FileStore::FileStore(std::filesystem::path workingRoot)
    : workingRoot_(std::move(workingRoot)) {}

std::vector<FileEntry> FileStore::scan() const {
    throw Error("FileStore::scan is not implemented yet.");
}

StatusResult FileStore::compare(
    const std::optional<std::filesystem::path>& /*snapshotFilesDirectory*/) const {
    throw Error("FileStore::compare is not implemented yet.");
}

void FileStore::saveSnapshot(const std::filesystem::path& /*destinationFilesDirectory*/,
                              const std::vector<FileEntry>& /*files*/) const {
    throw Error("FileStore::saveSnapshot is not implemented yet.");
}

void FileStore::validateSnapshot(const std::filesystem::path& /*snapshotFilesDirectory*/,
                                  const std::vector<FileEntry>& /*manifest*/) const {
    throw Error("FileStore::validateSnapshot is not implemented yet.");
}

std::filesystem::path FileStore::backup() const {
    throw Error("FileStore::backup is not implemented yet.");
}

void FileStore::restore(const std::filesystem::path& /*snapshotFilesDirectory*/) const {
    throw Error("FileStore::restore is not implemented yet.");
}

void FileStore::rollback(const std::filesystem::path& /*backupDirectory*/) const {
    throw Error("FileStore::rollback is not implemented yet.");
}

} // namespace vcslite
