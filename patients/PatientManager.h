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

PatientManager::PatientManager() : Module(NAME_PATIENT) {}

PatientManager::PatientManager(Application *app) : Module(app, NAME_PATIENT) {
    try {
        start();
    } catch (exception exception) {
        logWarn("Module couldn't load!");
    }
}

void PatientManager::start() {
    Module::start();
}

void PatientManager::end() {
    Module::end();
    log("CLEARING CACHE!");
}

unordered_map<int, Patient> PatientManager::getPatients() {
    return this->patients;
}

void PatientManager::registerPatient(Patient &patient) {
    int newID = getCount() + 1;
    getPatients().insert(make_pair(newID, patient));
    patient.setId(newID);
    setCount(newID);
}

void PatientManager::unregisterPatient(Patient &patient) {
    unordered_map<int, Patient>::const_iterator searchResult = getPatients().find(patient.getId());
    if (searchResult != getPatients().end()) {
        getPatients().erase(searchResult);
        cout << "PACIENTE BORRADO!" << endl;
    }
}

int PatientManager::getCount() {
    return this->count;
}

void PatientManager::setCount(int count) {
    this->count = count;
}


#endif //CLINICADMINISTRATION_PATIENTMANAGER_H
