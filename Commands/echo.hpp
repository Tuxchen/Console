#ifndef ECHO_H
#define ECHO_H

#include <vector>
#include <string>
#include <iostream>
#include "../ICommand.hpp"

class Echo : public ICommand {

    public:

    int run(const std::vector<std::string>& args) override;
    void help() const override;
};

#endif