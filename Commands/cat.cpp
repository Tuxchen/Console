#include "cat.hpp"
#include "Exitcode.hpp"

auto cat_cmd(const std::vector<std::string>& args) -> int {
    if(args.size() < 2) {
        std::cerr << "No filename entered" << std::endl;
        std::cerr << "Interrupt with error code 1" << std::endl;
        return static_cast<int>(Exitcode::MissingFile);
    }

    std::ifstream ifile(args[1], std::ios::binary);

    if(!ifile) {
        std::cerr << args[1] << " not found." << std::endl;
        std::cerr << "Interrupt with error code 7" << std::endl;
        return static_cast<int>(Exitcode::FileNotFound);
    }

    ifile.seekg(0, std::ios::end);
    std::streamsize size = ifile.tellg();
    ifile.seekg(0, std::ios::beg);

    std::vector<char> content(size);

    ifile.read(content.data(), size);
    std::cout.write(content.data(), size);
    std::cout << std::endl;

    if(ifile.is_open()) {
        ifile.close();
    }

    return static_cast<int>(Exitcode::Ok);
}