#include "command.h"

Command::Command() : code(0) {
}

Command::Command(const std::string line) {
    code = CODE_QUIT;
}

int Command::getCode() const {
    return code;
}
