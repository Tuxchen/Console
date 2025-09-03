#include "Console.hpp"

int main() {
    Console console;
    int type{0};

    while(true) {
        console.read();
        type = console.eval();

        if(type == -1) { // Konsole beenden
            break;
        }
    }

    return 0;
}