#include "ls.hpp"
#include "Exitcode.hpp"

int Ls::run(const std::vector<std::string>& args) {
    if(args.size() > 1 && args[1] == "--help") {
        this->help();
        return static_cast<int>(Exitcode::Ok);
    }
    
    std::string path = (args.size() < 2) ? "." : args[1];

    for(auto& elem : std::filesystem::directory_iterator(path)) {
        std::cout << elem.path().filename().string() << " ";
    }
    std::cout << std::endl;

    return static_cast<int>(Exitcode::Ok);
}

void Ls::help() const {
    std::cout << "Lists all files in a directory" << std::endl;
}