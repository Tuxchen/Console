#include "Console.hpp"
#include "Commands/echo.hpp"
#include "Commands/exit.hpp"
#include "Commands/ls.hpp"
#include "Commands/cat.hpp"
#include "Commands/pwd.hpp"
#include "Commands/cd.hpp"

Console::Console() : prompt(">") {
    input_pattern = std::regex(R"((\S+))");

    commands["echo"] = echo_cmd;
    commands["exit"] = exit_cmd;
    commands["ls"] = ls_cmd;
    commands["cat"] = cat_cmd;
    commands["pwd"] = pwd_cmd;
    commands["cd"] = cd_cmd;
}

void Console::read() {
    std::cout << prompt << " ";
    std::getline(std::cin, input);
}

int Console::eval() {
    std::sregex_iterator iter(input.begin(), input.end(), input_pattern);
    std::sregex_iterator end;
        
    std::vector<std::string> args;

    for(; iter != end; ++iter) {
        args.push_back(iter->str());
    }

    if(args.empty()) {
        return 0;
    }

    std::string command = args[0];

    try {
        return commands.at(command)(args);
    } catch(std::out_of_range &e) {
        std::cerr << "Invalid command: " << e.what() << std::endl;
        std::cerr << "Interrupt with Code 10\n";
        return 10;
    }   
}