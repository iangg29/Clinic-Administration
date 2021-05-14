//
// ClinicAdministration
//
// Ian García González
// A01706892
//
// File created on 14/05/21.
//
// Copyright © 2021. All rights reserved.
//
//

#ifndef CLINICADMINISTRATION_COMMANDMANAGER_H
#define CLINICADMINISTRATION_COMMANDMANAGER_H

#include <iostream>
#include <string>
#include "../Module.h"

const NAME_CLI = "CLI Manager";

class CommandManager : public Module {
public:
    CommandManager();

    explicit CommandManager(Application *app);

    void start() override;

    void end() override;

    static void menu();
};

CommandManager::CommandManager() : Module(NAME_CLI) {}

CommandManager::CommandManager(Application *app) : Module(app, NAME_CLI) {
    try {
        start();
    } catch (exception exception) {
        logWarn("Module couldn't be loaded!")
    }
}

void CommandManager::start() {
    Module::start();
}

void CommandManager::end() {
    Module::end();
}

void CommandManager::menu() {
    cout << "MENU??" << endl;
}


#endif //CLINICADMINISTRATION_COMMANDMANAGER_H
