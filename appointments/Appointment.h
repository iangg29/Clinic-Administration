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

/*
 * Appointment: Clase principal de cada consulta.
 * @file Appointment.h
 * @author Ian
 * */

class Appointment {
private:
    int ID;
    // TODO: Specialty
    int day;
    string month;
    // TODO: Doctor
    // TODO: Patient
    int cost;
    bool active;
public:
    Appointment(int day, string month, int cost);

    void reserve();

    void cancel();

    void pay();

    int getID();

    void setID(int ID);

    int getDay();

    void setDay(int day);

    string getMonth();

    void setMonth(string month);

    int getCost();

    void setCost(int cost);

    bool isActive();

    void setActive(bool active);
};

/**
 * Constructor principal de la clase con parámetros.
 * @param day Día de la consulta.
 * @param month Mes de la consulta.
 * @param cost Costo de la consulta.
 * */
Appointment::Appointment(int day, string month, int cost) {
    this->ID = 0;
    this->day = day;
    this->month = month;
    this->cost = cost;
    this->active = false;
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
string Appointment::getMonth() {
    return this->month;
}

/**
 * Asigna el mes a la consulta.
 * @param month Mes
 * */
void Appointment::setMonth(string month) {
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


#endif //CLINICADMINISTRATION_APPOINTMENT_H
