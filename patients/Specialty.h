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

/*
 * Specialty: Clase de ayuda para especialidades.
 * @file Specialty.h
 * @author Ian
 * */

using namespace std;

class Specialty {
private:
    string name;
public:
    Specialty(string name);

    string getName();

    void setName(string name);
};

/**
 * Constructor de la clase.
 * @param name Nombre de la especialidad
 * */
Specialty::Specialty(string name) {
    this->name = name;
}

/**
 * Obtiene el nombre de la especialidad.
 * @return Nombre
 * */
string Specialty::getName() {
    return this->name;
}

/**
 * Asigna el nombre de la especialidad.
 * @param name Nombre
 * */
void Specialty::setName(string name) {
    this->name = name;
}


#endif //CLINICADMINISTRATION_SPECIALTY_H
