//
// Created by perqin on 5/16/17.
//

#include <set>
#include <vector>
#include <dependencies.h>
#include "dependenciesmanager.h"

DependenciesManager::DependenciesManager() {
    std::vector<int> dependenciesVector;
    Dependencies::registerDependencies(dependenciesVector);
    for (int d : dependenciesVector) {
        if (dependencies.find(d) != dependencies.end()) {
            throw std::runtime_error(std::to_string(d) + ": Dependency must be unique");
        }
        dependencies.insert(std::make_pair(d, false));
    }
}

bool DependenciesManager::isDependencyMet(int dependency) {
    std::map<int, bool>::const_iterator cit = dependencies.find(dependency);
    if (cit != dependencies.end()) {
        return cit->second;
    } else {
        // Maybe throwing an exception is better?
        return false;
    }
}

void DependenciesManager::addDependency(int dependency) {
    std::map<int, bool>::iterator it = dependencies.find(dependency);
    if (it != dependencies.end() && !it->second) {
        it->second = true;
    }
}

void DependenciesManager::removeDependency(int dependency) {
    std::map<int, bool>::iterator it = dependencies.find(dependency);
    if (it != dependencies.end() && it->second) {
        it->second = false;
    }
}
