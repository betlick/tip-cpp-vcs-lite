#pragma once

#include "vcslite/types.hpp"

namespace vcslite {

class MetadataStore {
public:
    explicit MetadataStore(std::filesystem::path workingRoot);

    [[nodiscard]] RepositoryState readState() const;
    // Write to a temporary file, then replace state.json as one operation.
    void writeState(const RepositoryState& state) const;
    [[nodiscard]] Commit readCommit(const std::string& id) const;
    void writeCommit(const Commit& commit,
                     const std::filesystem::path& temporaryCommitDirectory) const;
    [[nodiscard]] std::vector<Commit> readHistory() const;

private:
    std::filesystem::path workingRoot_;
};

} // namespace vcslite
