#include "abstractcommand.h"

bool AbstractCommand::parseLine(const std::string & line, char &shortCut, std::string &name, std::vector<std::string> &arguments) {
    std::string first;
    unsigned start = 0;
    bool buffered = false;
    bool getFirst = false;

    arguments.clear();

    for (unsigned i = 0; i <= line.size(); ++i) {
        if ((i == line.size() || line.at(i) == ' ') && buffered) {
            buffered = false;
            if (!getFirst) {
                getFirst = true;
                first = line.substr(start, i - start);
            } else {
                arguments.push_back(line.substr(start, i - start));
            }
        } else if (!buffered) {
            buffered = true;
            start = i;
        }
    }

    if (!getFirst) {
        // Empty string!
        return false;
    }

    if (first.size() == 1) {
        shortCut = first.at(0);
        name = "";
    } else {
        shortCut = '\0';
        name = first;
    }
}
