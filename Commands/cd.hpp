#ifndef CD_H
#define CD_H

#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include "../ICommand.hpp"

class Cd : public ICommand {

    public:

    int run(const std::vector<std::string>& args) override;
    void help() const override;
};

#endif