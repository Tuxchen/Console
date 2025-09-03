#include "cd.hpp"
#include "Exitcode.hpp"

auto cd_cmd(const std::vector<std::string>& args) -> int {
    if(args.size() < 2) {
        std::cerr << "Missing argument" << std::endl;
        return static_cast<int>(Exitcode::InvalidCommand);
    }

    try {
        std::filesystem::current_path(args[1]);
    } catch(std::filesystem::filesystem_error &e) {
        std::cerr << "cd: " << e.what() << std::endl;
        return static_cast<int>(Exitcode::FilesystemError);
    }

    return static_cast<int>(Exitcode::Ok);
}