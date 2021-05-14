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

#ifndef CLINICADMINISTRATION_PATIENT_H
#define CLINICADMINISTRATION_PATIENT_H

#include <iostream>
#include <string>
#include "Person.h"

class Patient : public Person {
private:
    int ID;
    bool drink;
    bool smoke;
    bool chronic;
public:
    Patient();

    Patient(string name, int age, Gender gender, string nationality, string celular, string email, bool drink,
            bool smoke, bool chronic);

    int getId();

    void setId(int ID);

    bool patientDrink();

    void setDrink(bool drink);

    bool patientSmoke();

    void setSmoke(bool smoke);

    bool patientChronic();

    void setChronic(bool chronic);
};

Patient::Patient() : Person() {
    this->ID = 0;
    this->drink = false;
    this->smoke = false;
    this->chronic = false;
}

Patient::Patient(string name, int age, Gender gender, string nationality, string celular, string email, bool drink,
                 bool smoke, bool chronic) : Person(name, age, gender, nationality, celular, email) {
    this->ID = 0;
    this->drink = drink;
    this->smoke = smoke;
    this->chronic = chronic;
}

int Patient::getId() {
    return this->ID;
}

void Patient::setId(int ID) {
    this->ID = ID;
}

bool Patient::patientDrink() {
    return this->drink;
}

void Patient::setDrink(bool drink) {
    this->drink = drink;
}

bool Patient::patientSmoke() {
    return this->smoke;
}

void Patient::setSmoke(bool smoke) {
    this->smoke = smoke;
}

bool Patient::patientChronic() {
    return this->chronic;
}

void Patient::setChronic(bool chronic) {
    this->chronic = chronic;
}


#endif //CLINICADMINISTRATION_PATIENT_H
