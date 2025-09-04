#ifndef EXIT_H
#define EXIT_H

#include <iostream>
#include <vector>
#include <string>
#include "../ICommand.hpp"

class Exit : public ICommand {

    public:

    int run(const std::vector<std::string>& args) override;
    void help() const override;
};

#endif