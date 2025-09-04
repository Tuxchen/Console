#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <memory>
#include "ICommand.hpp"

class Console {
    std::regex prompt_pattern;
    std::regex input_pattern;
    std::string prompt;
    std::string input;

    using CommandMap = std::map<std::string, std::unique_ptr<ICommand>>;
    CommandMap commands;

    public:

    Console();

    void read();

    int eval();

    void run();
};

#endif