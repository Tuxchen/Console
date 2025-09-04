#ifndef PWD_H
#define PWD_H

#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include "../ICommand.hpp"

class Pwd : public ICommand {

    public:

    int run(const std::vector<std::string>& args) override;
    void help() const override;
};

#endif