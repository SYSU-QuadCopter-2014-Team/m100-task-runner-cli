//
// Created by perqin on 5/16/17.
//

#include <set>
#include <iostream>
#include "commandsmanager.h"
#include "commands.h"

CommandsManager::CommandsManager() {
    std::set<char> shortCuts;
    std::set<std::string> names;
    Commands::registerCommands(commands);
    // Validate commands
    for (auto command : commands) {
        char shortCut = command->getShortCut();
        if (!(shortCut == '\0' || (shortCut >= 'A' && shortCut <= 'Z') || (shortCut >= 'a' && shortCut <= 'z') || (shortCut >= '0' && shortCut <= '9'))) {
            throw std::runtime_error(command->getName() + ": ShortCut must be a single char ranged from a-z, A-Z or 0-9");
        }
        if (shortCut != '\0' && shortCuts.find(shortCut) != shortCuts.end()) {
            throw std::runtime_error(command->getName() + ": ShortCut should be unique or none");
        }
        if (shortCut != '\0') {
            shortCuts.insert(shortCut);
        }

        if (command->getName().find(' ') != std::string::npos) {
            throw std::runtime_error(command->getName() + ": Command name must not contain space");
        }
        if (names.find(command->getName()) != names.end()) {
            throw std::runtime_error(command->getName() + ": Command name should be unique");
        }
        names.insert(command->getName());
    }
}

AbstractCommand *CommandsManager::getCommandByName(const std::string &name) {
    for (auto command : commands) {
        if (command->getName() == name) {
            return command;
        }
    }
    return nullptr;
}

void CommandsManager::runTask(const char &shortCut, const std::string &name, const std::vector<std::string> &arguments,
                              DependenciesManager &dependenciesManager, Sdk & sdk) {
    AbstractCommand * command = nullptr;
    for (auto c : commands) {
        if (c->getShortCut() == shortCut || c->getName() == name) {
            command = c;
        }
    }
    if (command != nullptr && command->isDependenciesMet(dependenciesManager)) {
        command->runTask(arguments, dependenciesManager, sdk);
    }
}

std::vector<AbstractCommand *> CommandsManager::getAllCommands() {
    return commands;
}
