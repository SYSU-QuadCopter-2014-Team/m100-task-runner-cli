//
// Created by perqin on 5/16/17.
//

#ifndef M100_TASK_RUNNER_CLI_COMMANDSMANAGER_H
#define M100_TASK_RUNNER_CLI_COMMANDSMANAGER_H

#include <vector>
#include <string>
#include "dependenciesmanager.h"
#include "abstractcommand.h"
#include "sdk.h"

class CommandsManager {
public:
    CommandsManager();
    AbstractCommand * getCommandByName(const std::string & name);
    std::vector<AbstractCommand*> getAllCommands();
    void runTask(const char &shortCut, const std::string &name, const std::vector<std::string> &arguments, DependenciesManager & dependenciesManager, Sdk & sdk);

private:
    std::vector<AbstractCommand *> commands;
};

#endif //M100_TASK_RUNNER_CLI_COMMANDSMANAGER_H
