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
#include "Transaction.h"

const string NAME_ACCOUNTING = "Accounting Manager";

class AccountingManager : public Module {
private:
    float balance;
public:
    AccountingManager();

    explicit AccountingManager(Application *app);

    void start() override;

    void end() override;

    float getBalance();

    float setBalance(float balance);

    void addTransaction(Transaction transaction);
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

float AccountingManager::getBalance() {
    return this->balance;
}

float AccountingManager::setBalance(float balance) {
    this->balance = balance;
}

void AccountingManager::addTransaction(Transaction transaction) {
    // TODO: Transaction logic.
}


#endif //CLINICADMINISTRATION_ACCOUNTINGMANAGER_H
