#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <chrono>
#include <map>
#include <functional>
#include <fstream>
#include <ios>
#include <filesystem>

using Command = std::function<int(const std::vector<std::string>& args)>;

class Console {
    std::regex prompt_pattern;
    std::regex input_pattern;
    std::string prompt;
    std::string input;
    std::map<std::string, Command> commands;

    public:

    Console();

    void read();

    int eval();
};

#endif