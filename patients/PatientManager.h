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

#ifndef CLINICADMINISTRATION_PATIENTMANAGER_H
#define CLINICADMINISTRATION_PATIENTMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "../Module.h"
#include "Patient.h"

/*
 * PatientManager: Clase que administra los pacientes.
 * @file PatientManager.h
 * @author Ian
 * */

const string NAME_PATIENT = "Patient Manager";

class PatientManager : public Module {
private:
    int count = 0;
    unordered_map<int, Patient> patients;
public:
    PatientManager();

    explicit PatientManager(Application *app);

    void start() override;

    void end() override;

    unordered_map<int, Patient> getPatients();

    int getCount();

    void setCount(int count);

    void registerPatient(Patient &patient);

    void unregisterPatient(Patient &patient);
};

/**
 * Constructor de la clase sin parámetros.
 * */
PatientManager::PatientManager() : Module(NAME_PATIENT) {}

/**
 * Constructor principal de la clase con parámetros.
 * @param app Instancia de la aplicación principal.
 * */
PatientManager::PatientManager(Application *app) : Module(app, NAME_PATIENT) {
    try {
        start();
    } catch (exception exception) {
        logWarn("Module couldn't load!");
    }
}

/**
 * Método de inicio del módulo.
 * */
void PatientManager::start() {
    Module::start();
}

/**
 * Método de finalización del módulo.
 * */
void PatientManager::end() {
    Module::end();
}

/**
 * Obtiene el mapa de los pacientes registrados.
 * @return Mapa pacientes
 * */
unordered_map<int, Patient> PatientManager::getPatients() {
    return this->patients;
}

/**
 * Registra un nuevo paciente en el mapa.
 * @param patient Paciente a registrar
 * */
void PatientManager::registerPatient(Patient &patient) {
    int newID = getCount() + 1;
    getPatients().insert(make_pair(newID, patient));
    patient.setId(newID);
    setCount(newID);
}

/**
 * Remueve al paciente del mapa.
 * @param patient Paciente a quitar
 * */
void PatientManager::unregisterPatient(Patient &patient) {
    unordered_map<int, Patient>::const_iterator searchResult = getPatients().find(patient.getId());
    if (searchResult != getPatients().end()) {
        getPatients().erase(searchResult);
        cout << "PACIENTE BORRADO!" << endl;
    }
}

/**
 * Obtiene la cuenta de pacientes (aka ID)
 * @return Cuenta de pacientes
 * */
int PatientManager::getCount() {
    return this->count;
}

/**
 * Asigna la cuenta de pacientes.
 * @param count Nueva cuenta
 * */
void PatientManager::setCount(int count) {
    this->count = count;
}


#endif //CLINICADMINISTRATION_PATIENTMANAGER_H
