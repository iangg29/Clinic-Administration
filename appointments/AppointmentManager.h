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
#include "../Module.h"

const string NAME_APPOINTMENT = "Appointment Manager";

class AppointmentManager : public Module {
public:
    AppointmentManager();

    explicit AppointmentManager(Application *app);

    void start() override;

    void end() override;
};

AppointmentManager::AppointmentManager() : Module(NAME_APPOINTMENT) {}

AppointmentManager::AppointmentManager(Application *app) : Module(app, NAME_APPOINTMENT) {
    try {
        start();
    } catch (exception exception) {
        logWarn("Module couldn't load!");
    }
}

void AppointmentManager::start() {
    Module::start();
}

void AppointmentManager::end() {
    Module::end();
    log("CLEARING CACHE!");
}


#endif //CLINICADMINISTRATION_APPOINTMENTMANAGER_H
