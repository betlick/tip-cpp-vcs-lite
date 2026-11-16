#include "vcslite/metadata_store.hpp"

#include "vcslite/error.hpp"

#include <utility>

namespace vcslite {

MetadataStore::MetadataStore(std::filesystem::path workingRoot)
    : workingRoot_(std::move(workingRoot)) {}

RepositoryState MetadataStore::readState() const {
    throw Error("MetadataStore::readState is not implemented yet.");
}

void MetadataStore::writeState(const RepositoryState& /*state*/) const {
    throw Error("MetadataStore::writeState is not implemented yet.");
}

Commit MetadataStore::readCommit(const std::string& /*id*/) const {
    throw Error("MetadataStore::readCommit is not implemented yet.");
}

void MetadataStore::writeCommit(const Commit& /*commit*/,
                                const std::filesystem::path& /*temporaryCommitDirectory*/) const {
    throw Error("MetadataStore::writeCommit is not implemented yet.");
}

std::vector<Commit> MetadataStore::readHistory() const {
    throw Error("MetadataStore::readHistory is not implemented yet.");
}

} // namespace vcslite
