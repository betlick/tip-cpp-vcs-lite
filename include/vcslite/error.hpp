#pragma once

#include <stdexcept>

namespace vcslite {

class Error : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class UsageError : public Error {
public:
    using Error::Error;
};

} // namespace vcslite
