#pragma once

#include "vcslite/file_store.hpp"
#include "vcslite/metadata_store.hpp"

namespace vcslite {

class Repository {
public:
    explicit Repository(std::filesystem::path root);

    // true if a new repository was created, false if it already existed.
    bool init();
    [[nodiscard]] Commit commit(const std::string& message);
    [[nodiscard]] HistoryResult log() const;
    [[nodiscard]] StatusResult status() const;
    [[nodiscard]] CheckoutResult checkout(const std::string& id, bool force = false);

private:
    std::filesystem::path root_;
    MetadataStore metadata_;
    FileStore files_;
};

} // namespace vcslite
