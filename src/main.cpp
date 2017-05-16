#include <iostream>
#include "abstractcommand.h"
#include "commandsmanager.h"

void printHelp(CommandsManager & commandsManager, DependenciesManager & dependenciesManager);

void printHelpOfCommand(AbstractCommand*);

int main(/*int argc, char *argv[]*/) {
    bool shouldQuit = false;
    char shortCut;

    std::string cmd;
    std::string name;
    std::vector<std::string> arguments;

    DependenciesManager dependenciesManager;
    CommandsManager commandsManager;
    Sdk sdk;

    while (!shouldQuit) {
        std::cout << "(runner) ";
        std::getline(std::cin, cmd);
        if (AbstractCommand::parseLine(cmd, shortCut, name, arguments)) {
            // Built-in commands
            if ('q' == shortCut || "quit" == name) {
                shouldQuit = true;
            }
            if ('h' == shortCut || "help" == name) {
                if (arguments.size() >= 1) {
                    printHelpOfCommand(commandsManager.getCommandByName(arguments.at(0)));
                } else {
                    printHelp(commandsManager, dependenciesManager);
                }
            }

            // Commands with task
            commandsManager.runTask(shortCut, name, arguments, dependenciesManager, sdk);
        } else {
            std::cout << "Invalid input!" << std::endl;
        }
    }
    return 0;
}

void printHelp(CommandsManager & commandsManager, DependenciesManager & dependenciesManager) {
    std::cout << "M100 Task Runner CLI build 20170516" << std::endl;
    std::cout << std::endl;
    std::cout << "Available commands: " << std::endl;
    for (auto command : commandsManager.getAllCommands()) {
        if (command->isDependenciesMet(dependenciesManager)) {
            std::cout << command->getName() << "[" << command->getShortCut() << "]" << std::endl;
            std::cout << "    " << command->getDescription() << std::endl;
        }
    }
}

void printHelpOfCommand(AbstractCommand * command) {
    std::cout << "Command: " << command->getName() << std::endl;
    std::cout << "Description: " << command->getDescription() << std::endl;
    std::cout << "Help: " << command->getHelp() << std::endl;
}
