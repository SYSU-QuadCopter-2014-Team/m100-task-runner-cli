#include <iostream>
#include "command.h"

int main(/*int argc, char *argv[]*/) {
    bool shouldQuit = false;
    std::string cmd;
    while (!shouldQuit) {
        std::cout << "(runner) ";
        std::getline(std::cin, cmd);
        Command command(cmd);
        switch (command.getCode()) {
        case Command::CODE_QUIT:
            shouldQuit = true;
            break;
        default:
            std::cout << "Unknown command" << std::endl;
            break;
        }
    }
    return 0;
}
