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

/*
 * Patient: Clase del paciente.
 * @file Patient.h
 * @author Ian
 * */

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

/**
 * Constructor de la clase sin parámetros.
 * */
Patient::Patient() : Person() {
    this->ID = 0;
    this->drink = false;
    this->smoke = false;
    this->chronic = false;
}

/**
 * Constructor principal de la clase con parámetros.
 * @param name Nombre del paciente
 * @param age Edad del paciente
 * @param gender Género del paciente
 * @param nationality Nacionalidad del paciente
 * @param celular Celular del paciente
 * @param email Correo electrónico del paciente
 * @param drink El paciente bebe alcohol
 * @param smoke El paciente fuma
 * @param chronic El paciente tiene alguna enfermedad crónica
 * */
Patient::Patient(string name, int age, Gender gender, string nationality, string celular, string email, bool drink,
                 bool smoke, bool chronic) : Person(name, age, gender, nationality, celular, email) {
    this->ID = 0;
    this->drink = drink;
    this->smoke = smoke;
    this->chronic = chronic;
}

/**
 * Obtiene el ID del paciente.
 * @return ID
 * */
int Patient::getId() {
    return this->ID;
}

/**
 * Asigna el ID al paciente.
 * @param ID ID
 * */
void Patient::setId(int ID) {
    this->ID = ID;
}

/**
 * Obtiene si el paciente bebe alcohol.
 * @return Bebe
 * */
bool Patient::patientDrink() {
    return this->drink;
}

/**
 * Asigna si el paciente bebe alcohol.
 * @param drink Bebe
 * */
void Patient::setDrink(bool drink) {
    this->drink = drink;
}

/**
 * Obtiene si el paciente fuma.
 * @return Fuma
 * */
bool Patient::patientSmoke() {
    return this->smoke;
}

/**
 * Asigna si el paciente fuma.
 * @param smoke Fumal
 * */
void Patient::setSmoke(bool smoke) {
    this->smoke = smoke;
}

/**
 * Obtiene si el paciente tiene alguna enfermedad crónica.
 * @return Chronic
 * */
bool Patient::patientChronic() {
    return this->chronic;
}

/**
 * Asigna si el paciente tiene alguna enfermedad crónica.
 * @param chronic Crónica
 * */
void Patient::setChronic(bool chronic) {
    this->chronic = chronic;
}


#endif //CLINICADMINISTRATION_PATIENT_H
