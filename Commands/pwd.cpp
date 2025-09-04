#include "pwd.hpp"
#include "Exitcode.hpp"

int Pwd::run(const std::vector<std::string>& args) {
    if(args.size() > 1 && args[1] == "--help") {
        this->help();
        return static_cast<int>(Exitcode::Ok);
    }

    std::string current_path = std::filesystem::current_path().string();
    std::cout << current_path << std::endl;
    return static_cast<int>(Exitcode::Ok);
}

void Pwd::help() const {
    std::cout << "Shows the current directory" << std::endl;
}