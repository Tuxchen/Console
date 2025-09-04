#include "cat.hpp"
#include "Exitcode.hpp"

int Cat::run(const std::vector<std::string>& args) {
    if(args.size() < 2) {
        std::cerr << "No filename entered" << std::endl;
        std::cerr << "Interrupt with error code "
                    << static_cast<int>(Exitcode::MissingFile)
                    << std::endl;
        return static_cast<int>(Exitcode::MissingFile);
    }

    if(args[1] == "--help") {
        this->help();
        return static_cast<int>(Exitcode::Ok);
    }

    std::ifstream ifile(args[1], std::ios::binary);

    if(!ifile) {
        std::cerr << "Could " << args[1] << " not open." << std::endl;
        std::cerr << "Interrupt with error code "
                    << static_cast<int>(Exitcode::FileNotFound)
                    << std::endl;
        return static_cast<int>(Exitcode::FileNotFound);
    }

    std::vector<unsigned char> content((std::istreambuf_iterator<char>(ifile)), std::istreambuf_iterator<char>());

    bool is_binary = false;
    for(auto c : content) {
        if(c == 0) {
            is_binary = true;
            break;
        }
    }

    if(is_binary) {
        for(int i = 0; i < content.size(); ++i) {
            std::cout << std::hex << std::setw(2) << std::setfill('0')
                        << static_cast<int>(content[i]) << " ";
            if((i+1) % 16 == 0) std::cout << "\n";
        }
        std::cout << std::dec << std::endl;
    }
    else {
        std::cout.write(reinterpret_cast<char*>(content.data()), content.size());
        std::cout << std::endl;
    }

    return static_cast<int>(Exitcode::Ok);
}

void Cat::help() const {
    std::cout << "Shows the content of the given file." << std::endl;
}