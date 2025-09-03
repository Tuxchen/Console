#include "ls.hpp"
#include "Exitcode.hpp"

auto ls_cmd(const std::vector<std::string>& args) -> int {
    std::string path = (args.size() < 2) ? "." : args[1];

    for(auto& elem : std::filesystem::directory_iterator(path)) {
        std::cout << elem.path().filename().string() << " ";
    }
    std::cout << std::endl;

    return static_cast<int>(Exitcode::Ok);
}