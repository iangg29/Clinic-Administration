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
#include "../patients/PatientManager.h"

/*
 * AppointmentManager: Módulo que administra las consultas de la aplicación.
 * @file AppointmentManager.h
 * @author Ian
 * */

const string NAME_APPOINTMENT = "Appointment Manager";

class AppointmentManager : public Module {
private:
    int count = 0;
    vector<Appointment *> appointments;
public:
    AppointmentManager();

    ~AppointmentManager();

    void start() override;

    void end() override;

    void menu() override;

    int getCount();

    void setCount(int count);

    void bookAppointment(Appointment *appointment, bool silent);

    Appointment *createBaseAppointment(PatientManager *pManager);

    Appointment *searchAppointment();

    void printLog();

    int askID();
};

/**
 * Constructor principal de la clase.
 * */
AppointmentManager::AppointmentManager() : Module(NAME_APPOINTMENT) {
    try {
        start();
    } catch (exception exception) {
        logWarn("Module couldn't load!");
    }
}

/**
 * Destructor de la clase.
 * */
AppointmentManager::~AppointmentManager() {
    for (Appointment *appointment : appointments) {
        delete appointment;
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
void AppointmentManager::bookAppointment(Appointment *appointment, bool silent = false) {
    if (appointment) {
        if (appointment->getPatient()) {
            int newID = getCount() + 1;
            appointment->setID(newID);
            setCount(newID);
            appointments.push_back(appointment);
            if (!silent) {
                log("AppointmentManager :: BookAppointment :: COMPLETE");
                cout << "La consulta ha sido agendada para el " << appointment->getDay() << "/"
                     << appointment->getMonth()
                     << ". (ID:" << appointment->getID() << ")." << endl;
            }
        } else {
            logWarn("No se ha encontrado el usuario con ese ID.");
        }
    }
}

/**
 * Imprime el menú del módulo.
 * */
void AppointmentManager::menu() {
    cout << "---- ==== CONSULTAS ==== ----" << endl;
    cout << "Selecciona una opción:" << endl;
    cout << "1. Ver agenda" << endl;
    cout << "2. Agendar consulta" << endl;
    cout << "3. Buscar consulta" << endl;
    cout << "4. Pagar consulta" << endl;
    cout << "5. Regresar" << endl;
    cout << "-----------------------------" << endl;
}

/**
 * Imprime la agenda de la clínica.
 * */
void AppointmentManager::printLog() {
    if (appointments.empty()) {
        log("La agenda de consultas está vacía.");
    } else {
        cout << "---- ==== AGENDA ==== ----" << endl;
        for (Appointment *appointment : appointments) {
            appointment->printShort();
        }
    }
}

/**
 * Pregunta al usuario el ID.
 * @return ID
 * */
int AppointmentManager::askID() {
    int ID;
    cout << "Ingresa el ID de la consulta: ";
    cin >> ID;
    return ID;
}

/**
 * Crea una consulta base con preguntas al usuario. (CLI)
 * @return Consulta
 * */
Appointment *AppointmentManager::createBaseAppointment(PatientManager *patientManager) {
    int day, month, cost;
    string specialty, doctor;
    cout << "Ingresa el número de día: ";
    cin >> day;
    cout << "Ingresa el número de mes: ";
    cin >> month;
    cout << "Ingresa el costo de la consulta: ";
    cin >> cost;
    cout << "Ingresa la especialidad: ";
    cin >> specialty;
    cout << "Ingresa el nombre del doctor: ";
    cin >> doctor;
    return new Appointment(day, month, cost, Specialty(specialty), Doctor(), patientManager->searchPatient());
}

/**
 * Busca una consulta por medio de su ID.
 * @return Consulta
 * */
Appointment *AppointmentManager::searchAppointment() {
    int ID = askID();
    if (!appointments.empty() && ID > 0) {
        for (Appointment *appointment : appointments) {
            if (appointment->getID() == ID) {
                return appointment;
            }
        }
    }
    return nullptr;
}


#endif //CLINICADMINISTRATION_APPOINTMENTMANAGER_H
