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
    vector<Patient *> patients;
public:
    PatientManager();

    void start() override;

    void end() override;

    void menu() override;

    int getCount();

    void setCount(int count);

    void registerPatient(Patient *patient, bool silent);

    void unregisterPatient();

    Patient *searchPatient();

    void printRecord();

    Patient *createPatient();

    int askID();
};

/**
 * Constructor de la clase sin parámetros.
 * */
PatientManager::PatientManager() : Module(NAME_PATIENT) {
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
 * Registra un nuevo paciente en el mapa.
 * @param patient Paciente a registrar
 * */
void PatientManager::registerPatient(Patient *patient, bool silent = false) {
    if (patient) {
        int newID = getCount() + 1;
        patient->setId(newID);
        setCount(newID);
        patients.push_back(patient);
        if (!silent) {
            log("PatientManager :: RegisterPatient :: COMPLETE");
            cout << "(ID:" << patient->getId() << ") Nombre: " << patient->getName() << "." << endl;
        }
    }
}

/**
 * Remueve al paciente del mapa.
 * @param ID ID del paciente a quitar
 * */
void PatientManager::unregisterPatient() {
    int ID = askID();
    if (patients.empty()) return;
    if (ID <= 0) return;
    for (vector<Patient *>::iterator iterator = patients.begin(); iterator != patients.end(); iterator++) {
        if ((*iterator)->getId() == ID) {
            patients.erase(iterator);
            cout << "PatientManager :: UnregisterPatient :: COMPLETE" << endl;
            break;
        }
    }
}

Patient *PatientManager::searchPatient() {
    int ID = askID();
    if (!patients.empty() && ID > 0) {
        for (Patient *patient : patients) {
            if (patient->getId() == ID) {
                return patient;
            }
        }
    }
    return nullptr;
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

void PatientManager::menu() {
    cout << "---- ==== PACIENTES ==== ----" << endl;
    cout << "Selecciona una opción:" << endl;
    cout << "1. Registrar paciente" << endl;
    cout << "2. Borrar paciente" << endl;
    cout << "3. Buscar paciente" << endl;
    cout << "4. Registro completo" << endl;
    cout << "5. Regresar" << endl;
    cout << "-----------------------------" << endl;
}

void PatientManager::printRecord() {
    if (patients.empty()) {
        log("El registro de pacientes está vacío.");
    } else {
        cout << "---- ==== REGISTRO ==== ----" << endl;
        for (Patient *patient : patients) {
            patient->printShort();
        }
    }
}

Patient *PatientManager::createPatient() {
    Gender gen;
    string name, nationality, celular, email, gender;
    int age;
    bool drink, smoke, chronic = false;
    cout << "Ingresa el nombre: ";
    cin >> name;
    cout << "Ingresa la edad: ";
    cin >> age;
    cout << "Ingresa el género: (H/M/U)";
    cin >> gender;
    cout << "Ingresa la nacionalidad: ";
    cin >> nationality;
    cout << "Ingresa el celular: ";
    cin >> celular;
    cout << "Ingresa el email: ";
    cin >> email;
    if (gender == "H") {
        gen = Gender::MALE;
    } else if (gender == "M") {
        gen = Gender::FEMALE;
    } else {
        gen = Gender::UNDEFINED;
    }
    return new Patient(name, age, gen, nationality, celular, email, drink, smoke,
                       chronic);
}

int PatientManager::askID() {
    int ID;
    cout << "Ingresa el ID del paciente: ";
    cin >> ID;
    return ID;
}


#endif //CLINICADMINISTRATION_PATIENTMANAGER_H
