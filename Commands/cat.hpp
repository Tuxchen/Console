#ifndef CAT_H
#define CAT_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <ios>
#include <iomanip>
#include "../ICommand.hpp"

class Cat : public ICommand {
    public:

    int run(const std::vector<std::string>& args) override;
    void help() const override;
};

#endif