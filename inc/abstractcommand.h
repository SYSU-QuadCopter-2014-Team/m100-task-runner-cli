#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include "dependenciesmanager.h"
#include "sdk.h"

class AbstractCommand {
public:
    AbstractCommand() {}

    static bool parseLine(const std::string & line, char & shortCut, std::string & name, std::vector<std::string> & arguments);

    virtual char getShortCut() = 0;

    virtual std::string getName() = 0;

    virtual std::string getDescription() = 0;

    virtual std::string getHelp() = 0;

    virtual bool isDependenciesMet(DependenciesManager &);

    virtual bool runTask(const std::vector<std::string> &arguments, DependenciesManager &, Sdk &) = 0;
};

#endif // COMMAND_H
