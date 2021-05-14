//
// ClinicAdministration
//
// Ian García González
// A01706892
//
// File created on 11/05/21.
//
// Copyright © 2021. All rights reserved.
//
//

#ifndef CLINICADMINISTRATION_APPLICATION_H
#define CLINICADMINISTRATION_APPLICATION_H

#include <iostream>
#include <string>
#include <vector>
#include "Module.h"
#include "accounting/AccountingManager.h"
#include "appointments/AppointmentManager.h"
#include "patients/PatientManager.h"
#include "exceptions/ModuleFailedLoading.h"
#include "cli/CommandManager.h"

using namespace std;

class Application {
private:
    string name;
    string author;
    double version;
    bool debug;
    bool started;
    unsigned int startTime;
    unsigned int finishTime;
    vector<Module> modules;

    AccountingManager accountingManager;
    AppointmentManager appointmentManager;
    PatientManager patientManager;
    CommandManager commandManager;

    void log(string message);

public:
    Application(string name, bool debug);

    void init();

    void end();

    bool isDebug();

    bool isStarted();

    void setStarted(bool started);

    void addModule(Module &module);

    void appInfo();

    string getName();

    string getAuthor();

    double getVersion();

    int getStartTime();

    int getFinishTime();

    vector<Module> getModules();

    AccountingManager getAccountingManager();

    AppointmentManager getAppointmentManager();

    PatientManager getPatientManager();

    CommandManager getCommandManager();
};

Application::Application(string name, bool debug) {
    this->name = name;
    this->author = "Ian García";
    this->version = 0.1;
    this->debug = debug;
}

void Application::init() {
    if (!isStarted()) {
        this->startTime = TimeUtil().getMillis();
        appInfo();
        setStarted(true);
        try {
            log("Cargando módulos...");
            this->accountingManager = AccountingManager(this);
            this->appointmentManager = AppointmentManager(this);
            this->patientManager = PatientManager(this);
            this->commandManager = CommandManager(this);
            addModule(accountingManager);
            addModule(appointmentManager);
            addModule(patientManager);
            addModule(commandManager);
        } catch (ModuleFailedLoading &e) {
            log(e.getMessage());
        }
        this->finishTime = TimeUtil().getMillis();
        string startTimeMsg;
        startTimeMsg = "Application started in [" + to_string((finishTime - startTime)) + "] ms.";
        if (isDebug()) log(startTimeMsg);
        commandManager.menu();
    }
}

void Application::end() {
    if (isStarted()) {
        setStarted(false);
        log("ENDED!");
        for (Module &module : getModules()) {
            module.end();
        }
    }
}

void Application::appInfo() {
    string message, authorMsg;
    message = getName() + " iniciando...";
    authorMsg = "Creado por " + getAuthor() + ".";
    log(message);
    log(authorMsg);
}

string Application::getName() {
    return this->name;
}

string Application::getAuthor() {
    return this->author;
}

double Application::getVersion() {
    return this->version;
}

bool Application::isDebug() {
    return this->debug;
}

bool Application::isStarted() {
    return this->started;
}

int Application::getStartTime() {
    return this->startTime;
}

int Application::getFinishTime() {
    return this->finishTime;
}

void Application::log(string message) {
    cout << "[*] " << message << endl;
}

void Application::setStarted(bool started) {
    this->started = started;
}

vector<Module> Application::getModules() {
    return this->modules;
}

void Application::addModule(Module &module) {
    try {
        getModules().push_back(module);
    } catch (exception exception) {
        throw ModuleFailedLoading();
    }
}

AccountingManager Application::getAccountingManager() {
    return this->accountingManager;
}

AppointmentManager Application::getAppointmentManager() {
    return this->appointmentManager;
}

PatientManager Application::getPatientManager() {
    return this->patientManager;
}

CommandManager Application::getCommandManager() {
    return this->commandManager
}


#endif //CLINICADMINISTRATION_APPLICATION_H
