#include "echo.hpp"
#include "Exitcode.hpp"

int Echo::run(const std::vector<std::string>& args) {
    if(args.size() > 1 && args[1] == "--help") {
        this->help();
        return static_cast<int>(Exitcode::Ok);
    }

    for(int i = 1; i < args.size(); ++i) {
        std::cout << args[i] << " ";
    }
    std::cout << std::endl;
    return static_cast<int>(Exitcode::Ok);
}

void Echo::help() const {
    std::cout << "Prints text to the console" << std::endl;
}