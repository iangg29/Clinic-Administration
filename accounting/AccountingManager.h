//
// ClinicAdministration
//
// Ian García González
// A01706892
//
// File created on 13/05/21.
//
// Copyright © 2021. All rights reserved.
//
//

#ifndef CLINICADMINISTRATION_ACCOUNTINGMANAGER_H
#define CLINICADMINISTRATION_ACCOUNTINGMANAGER_H

#include <iostream>
#include <string>
#include "../Module.h"

const string NAME_ACCOUNTING = "Accounting Manager";

class AccountingManager : public Module {
public:
    AccountingManager();

    explicit AccountingManager(Application *app);

    void start() override;

    void end() override;
};

AccountingManager::AccountingManager() : Module(NAME_ACCOUNTING) {}

AccountingManager::AccountingManager(Application *app) : Module(app, NAME_ACCOUNTING) {
    try {
        start();
    } catch (exception exception) {
        logWarn("Module couldn't load!");
    }
}

void AccountingManager::start() {
    Module::start();
}

void AccountingManager::end() {
    Module::end();
    log("CLEARING CACHE!");
}


#endif //CLINICADMINISTRATION_ACCOUNTINGMANAGER_H
