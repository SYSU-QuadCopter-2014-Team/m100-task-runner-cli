//
// Created by perqin on 5/16/17.
//

#ifndef M100_TASK_RUNNER_CLI_COMMANDS_H
#define M100_TASK_RUNNER_CLI_COMMANDS_H

#include <vector>
#include "abstractcommand.h"

class Commands {
public:
    static void registerCommands(std::vector<AbstractCommand*> &);
};

#endif //M100_TASK_RUNNER_CLI_COMMANDS_H
