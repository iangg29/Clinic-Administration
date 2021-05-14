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

/*
 * Doctor: Clase del doctor.
 * @file Doctor.h
 * @author Ian
 * */

class Doctor : public Person {
private:
    Specialty specialty;
public:
    Doctor();

    Doctor(string name, int age, Gender gender, string nationality, string celular, string email, Specialty specialty);

    Specialty getSpecialty();

    void setSpecialty(Specialty specialty);
};

/**
 * Constructor de la clase sin parámetros.
 * */
Doctor::Doctor() {
    this->specialty = Specialty("NONE");
}

/**
 * Constructor principal de la clase con parámetros.
 * @param name Nombre del doctor
 * @param age Edad del doctor
 * @param gender Género del doctor
 * @param nationality Nacionalidad del doctor
 * @param celular Celular del doctor
 * @param email Correo electrónico del doctor
 * @param specialty Especialidad del doctor
 * */
Doctor::Doctor(string name, int age, Gender gender, string nationality, string celular, string email,
               Specialty specialty) : Person(name, age, gender, nationality, celular, email) {
    this->specialty = specialty;
}

/**
 * Obtiene la especialidad del doctor.
 * @return Especialidad
 * */
Specialty Doctor::getSpecialty() {
    return this->specialty;
}

/**
 * Asigna la especialidad al doctor.
 * @param specialty Especialidad
 * */
void Doctor::setSpecialty(Specialty specialty) {
    this->specialty = specialty;
}


#endif //CLINICADMINISTRATION_DOCTOR_H
