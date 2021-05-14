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

#ifndef CLINICADMINISTRATION_TRANSACTION_H
#define CLINICADMINISTRATION_TRANSACTION_H

#include <iostream>
#include <string>

/*
 * Transaction: Clase principal de la transacción de la clínica.
 * TransactionType: Tipo de transacción.
 * @file Transaction.h
 * @author Ian
 * */

using namespace std;

/**
 * Tipos de transacción disponible.
 * INCOME: Ingreso
 * OUTCOME: Gasto
 * */
enum class TransactionType {
    INCOME,
    OUTCOME
};

class Transaction {
private:
    float value;
    string reason;
    TransactionType type;
public:
    Transaction(float value, string reason, TransactionType type);

    float getValue();

    void setValue(float value);

    string getReason();

    void setReason(string reason);

    TransactionType getType();

    void setType(TransactionType type);
};

/**
 * Constructor principal de la clase con parámetros.
 * @param value Valor de la transacción
 * @param reason Razón de la transacción
 * @param type Tipo de la transacción
 * */
Transaction::Transaction(float value, string reason, TransactionType type) {
    this->value = value;
    this->reason = reason;
    this->type = type;
}

/**
 * Obtiene el valor de la transacción.
 * */
float Transaction::getValue() {
    return this->value;
}

/**
 * Asigna el valor a la transacción.
 * @param value Valor
 * */
void Transaction::setValue(float value) {
    this->value = value;
}

/**
 * Obtiene la razón de la transacción.
 * @return reason
 * */
string Transaction::getReason() {
    return this->reason;
}

/**
 * Asigna la razón a la transacción.
 * @param reason Razón
 * */
void Transaction::setReason(string reason) {
    this->reason = reason;
}

/**
 * Obtiene el tipo de la transacción.
 * @return tipo
 * */
TransactionType Transaction::getType() {
    return this->type;
}

/**
 * Asigna el tipo de transacción a la transacción.
 * @param type Tipo de transacción
 * */
void Transaction::setType(TransactionType type) {
    this->type = type;
}

#endif //CLINICADMINISTRATION_TRANSACTION_H
