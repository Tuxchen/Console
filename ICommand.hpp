#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <vector>
#include <string>

struct ICommand {
    virtual ~ICommand() = default;
    virtual int run(const std::vector<std::string>& args) = 0;
    virtual void help() const = 0;
};

#endif