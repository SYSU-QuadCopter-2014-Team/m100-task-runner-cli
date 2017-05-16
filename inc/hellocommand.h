//
// Created by perqin on 5/16/17.
//

#ifndef M100_TASK_RUNNER_CLI_HELLOCOMMAND_H
#define M100_TASK_RUNNER_CLI_HELLOCOMMAND_H

#include "abstractcommand.h"

class HelloCommand : public AbstractCommand {
public:
    virtual char getShortCut();

    virtual std::string getName();

    virtual std::string getDescription();

    virtual std::string getHelp();

    virtual bool isDependenciesMet(DependenciesManager &);

    virtual bool runTask(const std::vector<std::string> &arguments, DependenciesManager &, Sdk &);
};

#endif //M100_TASK_RUNNER_CLI_HELLOCOMMAND_H
