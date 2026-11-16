#include "vcslite/repository.hpp"

#include "vcslite/error.hpp"

#include <utility>

namespace vcslite {

Repository::Repository(std::filesystem::path root)
    : root_(std::move(root)), metadata_(root_), files_(root_) {}

bool Repository::init() {
    throw Error("init is not implemented yet. This is the structure/CMake stage.");
}

Commit Repository::commit(const std::string& /*message*/) {
    throw Error("commit is not implemented yet. This is the structure/CMake stage.");
}

HistoryResult Repository::log() const {
    throw Error("log is not implemented yet. This is the structure/CMake stage.");
}

StatusResult Repository::status() const {
    throw Error("status is not implemented yet. This is the structure/CMake stage.");
}

CheckoutResult Repository::checkout(const std::string& /*id*/, bool /*force*/) {
    throw Error("checkout is not implemented yet. This is the structure/CMake stage.");
}

} // namespace vcslite
