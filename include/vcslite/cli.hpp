#pragma once

#include <iosfwd>
#include <string>
#include <vector>

namespace vcslite {

class CLI {
public:
    // args does not contain the executable name. Returns a process exit code.
    int run(const std::vector<std::string>& args,
            std::ostream& output, std::ostream& errors) const;
    void printHelp(std::ostream& output) const;
};

} // namespace vcslite
