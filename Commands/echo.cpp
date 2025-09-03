#include "echo.hpp"
#include "Exitcode.hpp"

auto echo_cmd(const std::vector<std::string>& args) -> int {
    for(int i = 1; i < args.size(); ++i) {
        std::cout << args[i] << " ";
    }
    std::cout << std::endl;
    return static_cast<int>(Exitcode::Ok);
}