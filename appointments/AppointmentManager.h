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

#ifndef CLINICADMINISTRATION_APPOINTMENTMANAGER_H
#define CLINICADMINISTRATION_APPOINTMENTMANAGER_H

#include <iostream>
#include <string>
#include <unordered_map>
#include "../Module.h"
#include "Appointment.h"

/*
 * AppointmentManager: Módulo que administra las consultas de la aplicación.
 * @file AppointmentManager.h
 * @author Ian
 * */

const string NAME_APPOINTMENT = "Appointment Manager";

class AppointmentManager : public Module {
private:
    int count = 0;
    unordered_map<int, Appointment> appointments;
public:
    AppointmentManager();

    explicit AppointmentManager(Application *app);

    void start() override;

    void end() override;

    unordered_map<int, Appointment> getAppointments();

    int getCount();

    void setCount(int count);

    void logAppointment(Appointment &appointment);
};

/**
 * Constructor de la clase sin parámetros.
 * */
AppointmentManager::AppointmentManager() : Module(NAME_APPOINTMENT) {}

/**
 * Consturctor princiapal de la clase con parámetros.
 * @param app Instancia de la aplicación principal
 * */
AppointmentManager::AppointmentManager(Application *app) : Module(app, NAME_APPOINTMENT) {
    try {
        start();
    } catch (exception exception) {
        logWarn("Module couldn't load!");
    }
}

/**
 * Método inicial del módulo.
 * */
void AppointmentManager::start() {
    Module::start();
}

/**
 * Método para finalización de módulo.
 * */
void AppointmentManager::end() {
    Module::end();
    log("CLEARING CACHE!");
}

/**
 * Obtiene el mapa de consultas registradas en la aplicación.
 * @return Consultas
 * */
unordered_map<int, Appointment> AppointmentManager::getAppointments() {
    return this->appointments;
}

/**
 * Obtiene la cuenta de consultas registradas (aka ID).
 * @return Cuenta
 * */
int AppointmentManager::getCount() {
    return this->count;
}

/**
 * Asigna la cuenta al registro de consultas.
 * @param count Nueva cuenta
 * */
void AppointmentManager::setCount(int count) {
    this->count = count;
}

/**
 * Registro de una nueva consulta.
 * @param appointment Objeto de la consulta
 * */
void AppointmentManager::logAppointment(Appointment &appointment) {
    int newID = getCount() + 1;
    appointment.setID(newID);
    getAppointments().insert(make_pair(newID, appointment));
    setCount(newID)
}


#endif //CLINICADMINISTRATION_APPOINTMENTMANAGER_H
