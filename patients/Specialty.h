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

#ifndef CLINICADMINISTRATION_SPECIALTY_H
#define CLINICADMINISTRATION_SPECIALTY_H

#include <string>

using namespace std;

class Specialty {
private:
    string name;
public:
    Specialty(string name);

    string getName();

    void setName(string name);
};

Specialty::Specialty(string name) {
    this->name = name;
}

string Specialty::getName() {
    return this->name;
}

void Specialty::setName(string name) {
    this->name = name;
}


#endif //CLINICADMINISTRATION_SPECIALTY_H
