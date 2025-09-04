#include "exit.hpp"
#include "Exitcode.hpp"

int Exit::run(const std::vector<std::string>& args) {
    if(args.size() > 1 && args[1] == "--help") {
        this->help();
        return static_cast<int>(Exitcode::Ok);
    }

    return static_cast<int>(Exitcode::Exit);
}

void Exit::help() const {
    std::cout << "Quits the console" << std::endl;
}