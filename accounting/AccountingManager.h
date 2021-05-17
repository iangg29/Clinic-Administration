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

    void start() override;

    void end() override;

    void menu() override;

    float getBalance();

    float setBalance(float balance);

    void addTransaction(Transaction transaction);
};

/**
 * Constructor de la clase sin parámetros.
 * */
AccountingManager::AccountingManager() : Module(NAME_ACCOUNTING) {
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
}

/**
 * Despliega el menú del módulo.
 * */
void AccountingManager::menu() {

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
 * Agrega una transacción modificando el balance general.
 * @param transaction Transacción
 * */
void AccountingManager::addTransaction(Transaction transaction) {
    // TODO: Transaction logic.
}


#endif //CLINICADMINISTRATION_ACCOUNTINGMANAGER_H
