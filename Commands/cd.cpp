#include "cd.hpp"
#include "Exitcode.hpp"

int Cd::run(const std::vector<std::string>& args) {
    if(args.size() < 2) {
        std::cerr << "Missing argument" << std::endl;
        return static_cast<int>(Exitcode::InvalidCommand);
    }

    if(args[1] == "--help") {
        this->help();
        return static_cast<int>(Exitcode::Ok);
    }

    try {
        std::filesystem::current_path(args[1]);
    } catch(std::filesystem::filesystem_error &e) {
        std::cerr << "cd: " << e.what() << std::endl;
        return static_cast<int>(Exitcode::FilesystemError);
    }

    return static_cast<int>(Exitcode::Ok);
}

void Cd::help() const {
    std::cout << "Changes the directory" << std::endl;
}