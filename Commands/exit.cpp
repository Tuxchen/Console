#include "exit.hpp"
#include "Exitcode.hpp"

auto exit_cmd(const std::vector<std::string>& args) -> int {
    return static_cast<int>(Exitcode::Exit);
}