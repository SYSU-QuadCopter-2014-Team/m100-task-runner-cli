#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command {
public:
    Command();
    Command(const std::string line);
    int getCode() const;
    bool dependenciesMet() const;
    bool runTask() const;
    static const int CODE_QUIT = 1;
private:
    int code;
};

#endif // COMMAND_H
