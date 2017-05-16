//
// Created by perqin on 5/16/17.
//

#include "hellocommand.h"

#include <iostream>

char HelloCommand::getShortCut() {
    return 'x';
}

std::string HelloCommand::getName() {
    return "hello";
}

std::string HelloCommand::getDescription() {
    return "A sample command that says hello";
}

std::string HelloCommand::getHelp() {
    return "hello [name]...\nIt will say hello to all names if provided.";
}

bool HelloCommand::isDependenciesMet(DependenciesManager &) {
    return true;
}

bool HelloCommand::runTask(const std::vector<std::string> &arguments, DependenciesManager & dependenciesManager, Sdk & sdk) {
    if (arguments.size() == 0) {
        std::cout << "Hello!" << std::endl;
    } else {
        for (auto argument : arguments) {
            std::cout << "Hello, " << argument << "!" << std::endl;
        }
    }
    return true;
}
