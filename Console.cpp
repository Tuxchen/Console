#include "Console.hpp"
#include "Commands/echo.hpp"
#include "Commands/exit.hpp"
#include "Commands/ls.hpp"
#include "Commands/cat.hpp"
#include "Commands/pwd.hpp"
#include "Commands/cd.hpp"

Console::Console() : prompt(">") {
    input_pattern = std::regex(R"((\S+))");

    commands["cat"] = std::make_unique<Cat>();
    commands["echo"] = std::make_unique<Echo>();
    commands["exit"] = std::make_unique<Exit>();
    commands["ls"] = std::make_unique<Ls>();
    commands["pwd"] = std::make_unique<Pwd>();
    commands["cd"] = std::make_unique<Cd>();
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
        return commands.at(command)->run(args);
    } catch(std::out_of_range &e) {
        std::cerr << "Invalid command: " << command << std::endl;
        std::cerr << "Interrupt with Code 10\n";
        return 10;
    }
}

void Console::run() {
    int type;

    do {
        this->read();
        type = this->eval();
    } while(type != -1);
}