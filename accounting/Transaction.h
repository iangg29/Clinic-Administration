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

using namespace std;

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
    Transaction(int value, string reason, TransactionType type);

    float getValue();

    void setValue(float value);

    string getReason();

    void setReason(string reason);

    TransactionType getType();

    void setType(TransactionType type);
};

Transaction::Transaction(float value, string reason, TransactionType type) {
    this->value = value;
    this->reason = reason;
    this->type = type;
}

float Transaction::getValue() {
    return this->value;
}

void Transaction::setValue(float value) {
    this->value = value;
}

string Transaction::getReason() {
    return this->reason;
}

void Transaction::setReason(string reason) {
    this->reason = reason;
}

TransactionType Transaction::getType() {
    return this->type;
}

void Transaction::setType(TransactionType type) {
    this->type = type;
}

#endif //CLINICADMINISTRATION_TRANSACTION_H
