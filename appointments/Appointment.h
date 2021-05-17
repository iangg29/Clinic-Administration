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

#ifndef CLINICADMINISTRATION_APPOINTMENT_H
#define CLINICADMINISTRATION_APPOINTMENT_H

#include <iostream>
#include <string>
#include "../patients/Specialty.h"
#include "../patients/Doctor.h"
#include "../patients/Patient.h"

/*
 * Appointment: Clase principal de cada consulta.
 * @file Appointment.h
 * @author Ian
 * */

class Appointment {
private:
    int ID;
    Specialty specialty;
    int day;
    int month;
    Doctor doctor;
    Patient *patient;
    int cost;
    bool active;
public:
    Appointment(int day, int month, int cost, Specialty specialty, Doctor doctor, Patient *patient);

    void reserve();

    void cancel();

    void pay();

    int getID();

    void setID(int ID);

    int getDay();

    void setDay(int day);

    int getMonth();

    void setMonth(int month);

    int getCost();

    void setCost(int cost);

    bool isActive();

    void setActive(bool active);

    Specialty getSpecialty();

    void setSpecialty(Specialty specialty);

    Doctor getDoctor();

    void setDoctor(Doctor doctor);

    Patient *getPatient();

    void setPatient(Patient *patient);

    void printShort();

    void printComplete();
};

/**
 * Constructor principal de la clase con parámetros.
 * @param day Día de la consulta.
 * @param month Mes de la consulta.
 * @param cost Costo de la consulta.
 * @param specialty Especialidad de la consulta.
 * @param doctor Doctor que realizará la consulta.
 * @param patient Paciente que asistirá.
 * */
Appointment::Appointment(int day, int month, int cost, Specialty specialty, Doctor doctor, Patient *patient) {
    this->ID = 0;
    this->day = day;
    this->month = month;
    this->cost = cost;
    this->active = false;
    this->specialty = specialty;
    this->doctor = doctor;
    this->patient = patient;
}

/**
 * Método para reservar la consulta.
 * */
void Appointment::reserve() {

}

/**
 * Método para cancelar la consulta.
 * */
void Appointment::cancel() {

}

/**
 * Método para pagar la consulta.
 * */
void Appointment::pay() {
    // TODO: Transaction
}

/**
 * Obtiene el ID de la consulta.
 * @return ID ID
 * */
int Appointment::getID() {
    return this->ID;
}

/**
 * Asigna el ID a la consulta.
 * @param ID
 * */
void Appointment::setID(int ID) {
    this->ID = ID;
}

/**
 * Obtiene el día de la consulta.
 * @return Día
 * */
int Appointment::getDay() {
    return this->day;
}

/**
 * Asigna el día a la consulta.
 * @param day Día
 * */
void Appointment::setDay(int day) {
    this->day = day;
}

/**
 * Obtiene el mes de la consulta.
 * @return Mes
 * */
int Appointment::getMonth() {
    return this->month;
}

/**
 * Asigna el mes a la consulta.
 * @param month Mes
 * */
void Appointment::setMonth(int month) {
    this->month = month;
}

/**
 * Obtiene el costo de la consulta.
 * @return Costo
 * */
int Appointment::getCost() {
    return this->cost;
}

/**
 * Asignar el costo de la consulta.
 * @param cost Costo
 * */
void Appointment::setCost(int cost) {
    this->cost = cost;
}

/**
 * Verifica si la consulta está activa.
 * @return Activa
 * */
bool Appointment::isActive() {
    return this->active;
}

/**
 * Asignar si la consulta es activa.
 * @param active Activas
 * */
void Appointment::setActive(bool active) {
    this->active = active;
}

/**
 * Obtiene la especialidad de la consulta.
 * @return Especialidad
 * */
Specialty Appointment::getSpecialty() {
    return this->specialty;
}

/**
 * Asigna la especialidad a la consulta.
 * @param specialty Especialidad
 * */
void Appointment::setSpecialty(Specialty specialty) {
    this->specialty = specialty;
}

/**
 * Obtiene el doctor de la consulta.
 * @return Doctor
 * */
Doctor Appointment::getDoctor() {
    return this->doctor;
}

/**
 * Asigna el doctor a la consulta.
 * @param doctor Doctor
 * */
void Appointment::setDoctor(Doctor doctor) {
    this->doctor = doctor;
}

/**
 * Obtiene el paciente de la consulta.
 * */
Patient *Appointment::getPatient() {
    return this->patient;
}

/**
 * Asigna el paciente de la consulta.
 * @param patient Paciente
 * */
void Appointment::setPatient(Patient *patient) {
    this->patient = patient;
}

void Appointment::printShort() {
    cout << "(ID:" << getID() << ") Fecha: " << getDay() << "/" << getMonth() << " :: Paciente: "
         << getPatient()->getName() << "." << endl;
}

void Appointment::printComplete() {
    cout << "---- ==== CONSULTA [" << getID() << "] ==== ----" << endl;
    cout << "Fecha: " << getDay() << "/" << getMonth() << endl;
    cout << "Costo: $" << getCost() << endl;
    cout << "Especialidad: " << getSpecialty().getName() << endl;
    cout << "Paciente: " << getPatient()->getName() << " [ID:" << getPatient()->getId() << "]" << endl;
    cout << "__________________________________" << endl;
}

#endif //CLINICADMINISTRATION_APPOINTMENT_H
