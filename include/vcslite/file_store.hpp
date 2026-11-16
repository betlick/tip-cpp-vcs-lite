#pragma once

#include "vcslite/types.hpp"

namespace vcslite {

class FileStore {
public:
    explicit FileStore(std::filesystem::path workingRoot);

    [[nodiscard]] std::vector<FileEntry> scan() const;
    // nullopt means there is no initial commit: every working file is added.
    [[nodiscard]] StatusResult compare(
        const std::optional<std::filesystem::path>& snapshotFilesDirectory) const;
    void saveSnapshot(const std::filesystem::path& destinationFilesDirectory,
                      const std::vector<FileEntry>& files) const;
    void validateSnapshot(const std::filesystem::path& snapshotFilesDirectory,
                          const std::vector<FileEntry>& manifest) const;
    [[nodiscard]] std::filesystem::path backup() const;
    void restore(const std::filesystem::path& snapshotFilesDirectory) const;
    void rollback(const std::filesystem::path& backupDirectory) const;

private:
    std::filesystem::path workingRoot_;
};

} // namespace vcslite
