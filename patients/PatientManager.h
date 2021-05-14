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
#include "../Module.h"

const string NAME_PATIENT = "Patient Manager";

class PatientManager : public Module {
public:
    PatientManager();

    explicit PatientManager(Application *app);

    void start() override;

    void end() override;
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


#endif //CLINICADMINISTRATION_PATIENTMANAGER_H
