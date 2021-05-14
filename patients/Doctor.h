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

#ifndef CLINICADMINISTRATION_DOCTOR_H
#define CLINICADMINISTRATION_DOCTOR_H

#include <iostream>
#include <string>
#include "Person.h"
#include "Specialty.h"

class Doctor : public Person {
private:
    Specialty specialty;
public:
    Doctor();

    Doctor(string name, int age, Gender gender, string nationality, string celular, string email, Specialty specialty);

    Specialty getSpecialty();

    void setSpecialty(Specialty specialty);
};

Doctor::Doctor() {
    this->specialty = Specialty("NONE");
}

Doctor::Doctor(string name, int age, Gender gender, string nationality, string celular, string email,
               Specialty specialty) : Person(name, age, gender, nationality, celular, email) {
    this->specialty = specialty;
}

Specialty Doctor::getSpecialty() {
    return this->specialty;
}

void Doctor::setSpecialty(Specialty specialty) {
    this->specialty = specialty;
}


#endif //CLINICADMINISTRATION_DOCTOR_H
