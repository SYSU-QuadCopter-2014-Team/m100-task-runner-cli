//
// Created by perqin on 5/16/17.
//

#ifndef M100_TASK_RUNNER_CLI_DEPENDENCIESMANAGER_H
#define M100_TASK_RUNNER_CLI_DEPENDENCIESMANAGER_H

#include <map>

class DependenciesManager {
public:
    DependenciesManager();
    bool isDependencyMet(int);
    void addDependency(int);
    void removeDependency(int);

private:
    std::map<int, bool> dependencies;
};

#endif //M100_TASK_RUNNER_CLI_DEPENDENCIESMANAGER_H
