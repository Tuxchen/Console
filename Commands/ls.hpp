#ifndef LS_H
#define LS_H

#include <vector>
#include <string>
#include <iostream>
#include <filesystem>
#include "../ICommand.hpp"

class Ls : public ICommand {

    public:

    int run(const std::vector<std::string>& args) override;
    void help() const override;
};

#endif