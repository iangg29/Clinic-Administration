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

unordered_map<int, Appointment> AppointmentManager::getAppointments() {
    return this->appointments;
}

int AppointmentManager::getCount() {
    return this->count;
}

void AppointmentManager::setCount(int count) {
    this->count = count;
}

void AppointmentManager::logAppointment(Appointment &appointment) {
    int newID = getCount() + 1;
    appointment.setID(newID);
    getAppointments().insert(make_pair(newID, appointment));
    setCount(newID)
}


#endif //CLINICADMINISTRATION_APPOINTMENTMANAGER_H
