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
    vector<Transaction *> transactions;
public:
    AccountingManager();

    void start() override;

    void end() override;

    void menu() override;

    float getBalance();

    float setBalance(float balance);

    void addTransaction(Transaction *transaction);

    void printBalance();

    void printHistorical();
};

/**
 * Constructor principal de la clase.
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
    cout << "---- ==== CONTABILIDAD ==== ----" << endl;
    cout << "Selecciona una opción:" << endl;
    cout << "1. Mostrar balance" << endl;
    cout << "2. Ver historial" << endl;
    cout << "3. Regresar" << endl;
    cout << "-----------------------------" << endl;
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
void AccountingManager::addTransaction(Transaction *transaction) {
    if (transaction) {
        float newBalance;
        if (transaction->getType() == TransactionType::INCOME) {
            newBalance = getBalance() + transaction->getValue();
            setBalance(newBalance);
        } else {
            newBalance = getBalance() - transaction->getValue();
            setBalance(newBalance);
        }
        log("Se ha actualizado el balance financiero.");
        transactions.push_back(transaction);
    }
}

/**
 * Imprime el balance total hasta la fecha.
 * */
void AccountingManager::printBalance() {
    cout << "El balance de la clínica es de $" << getBalance() << "MXN." << endl;
}

/**
 * Imprime el historial de transacciones hasta la fecha.
 * */
void AccountingManager::printHistorical() {
    if (transactions.empty()) {
        logWarn("No se encontraron transacciones.");
    } else {
        cout << "---- ==== TRANSACCIONES ==== ----" << endl;
        for (Transaction *transaction : transactions) {
            transaction->print();
        }
    }
}


#endif //CLINICADMINISTRATION_ACCOUNTINGMANAGER_H
