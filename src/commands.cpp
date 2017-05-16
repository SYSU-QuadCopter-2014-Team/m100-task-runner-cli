//
// Created by perqin on 5/16/17.
//

#include "commands.h"
#include "hellocommand.h"

void Commands::registerCommands(std::vector <AbstractCommand*> & commands) {
    commands.push_back(new HelloCommand);
}
