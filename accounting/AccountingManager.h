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

/*
 * AccountingManager: Clase de módulo que administra el balance de la clínica.
 * @file AccountingManager.h
 * @author Ian
 * */

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

/**
 * Constructor de la clase sin parámetros.
 * */
AccountingManager::AccountingManager() : Module(NAME_ACCOUNTING) {}

/**
 * Constructor principal de la clase con parámetros.
 * @param app Instancia de la aplicación principal.
 * */
AccountingManager::AccountingManager(Application *app) : Module(app, NAME_ACCOUNTING) {
    try {
        start();
    } catch (exception exception) {
        logWarn("Module couldn't load!");
    }
}

/**
 * Método de inicio del módulo.
 * */
void AccountingManager::start() {
    Module::start();
}

/**
 * Método de finalización de módulo.
 * */
void AccountingManager::end() {
    Module::end();
    log("CLEARING CACHE!");
}

/**
 * Obtiene el balance general de la clínica.
 * @return Balance
 * */
float AccountingManager::getBalance() {
    return this->balance;
}

/**
 * Asigna el balance general.
 * @param balance Nuevo balance
 * */
float AccountingManager::setBalance(float balance) {
    this->balance = balance;
}

/**
 * Agrega una transacción al historial.
 * @param transaction Transacción
 * */
void AccountingManager::addTransaction(Transaction transaction) {
    // TODO: Transaction logic.
}


#endif //CLINICADMINISTRATION_ACCOUNTINGMANAGER_H
