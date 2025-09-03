#include "pwd.hpp"
#include "Exitcode.hpp"

auto pwd_cmd(const std::vector<std::string>& args) -> int {
    std::string current_path = std::filesystem::current_path().string();
    std::cout << current_path << std::endl;
    return static_cast<int>(Exitcode::Ok);
}