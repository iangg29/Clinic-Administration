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
    vector<Module *> modules;

    AccountingManager *accountingManager;
    AppointmentManager *appointmentManager;
    PatientManager *patientManager;
    CommandManager *commandManager;

    void log(string message);

public:
    Application(string name, bool debug);

    ~Application();

    void init();

    void end();

    bool isDebug();

    bool isStarted();

    void setStarted(bool started);

    void addModule(Module *module);

    void appInfo();

    string getName();

    string getAuthor();

    double getVersion();

    int getStartTime();

    int getFinishTime();

    AccountingManager *getAccountingManager();

    AppointmentManager *getAppointmentManager();

    PatientManager *getPatientManager();

    CommandManager *getCommandManager();

    void loadSampleData();
};

Application::Application(string name, bool debug) {
    this->name = name;
    this->author = "Ian García";
    this->version = 0.1;
    this->debug = debug;
}

Application::~Application() {
    for (Module *module : modules) {
        delete module;
    }
}

void Application::init() {
    if (!isStarted()) {
        this->startTime = TimeUtil().getMillis();
        appInfo();
        setStarted(true);
        try {
            log("Cargando módulos...");
            this->accountingManager = new AccountingManager();
            this->appointmentManager = new AppointmentManager();
            this->patientManager = new PatientManager();
            this->commandManager = new CommandManager();
            addModule(accountingManager);
            addModule(appointmentManager);
            addModule(patientManager);
            addModule(commandManager);
        } catch (ModuleFailedLoading &e) {
            log(e.getMessage());
        }
        if (isDebug()) loadSampleData();
        this->finishTime = TimeUtil().getMillis();
        string startTimeMsg;
        startTimeMsg = "Application started in [" + to_string((finishTime - startTime)) + "] ms.";
        if (isDebug()) log(startTimeMsg);
        while (isStarted()) {
            int option, internal = 0;
            getCommandManager()->menu();
            while (!(cin >> option)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                log("Opción inválida, por favor ingresa un número!");
            }
            switch (option) {
                case 1:
                    getPatientManager()->menu();
                    while (!(cin >> internal)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        log("Opción inválida, por favor ingresa un número!");
                    }
                    switch (internal) {
                        case 1:
                            getPatientManager()->registerPatient(getPatientManager()->createPatient());
                            break;
                        case 2:
                            getPatientManager()->unregisterPatient();
                            break;
                        case 3:
                            getPatientManager()->searchPatient()->printComplete();
                            break;
                        case 4:
                            getPatientManager()->printRecord();
                            break;
                        case 5:
                            continue;
                        default:
                            continue;
                    }
                    break;
                case 2:
                    getAppointmentManager()->menu();
                    while (!(cin >> internal)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        log("Opción inválida, por favor ingresa un número!");
                    }
                    switch (internal) {
                        case 1:
                            getAppointmentManager()->printLog();
                            break;
                        case 2:
                            getAppointmentManager()->bookAppointment(getAppointmentManager()->createBaseAppointment(
                                    getPatientManager()));
                            break;
                        case 3:
                            getAppointmentManager()->searchAppointment()->printComplete();
                            break;
                        case 4:
                            // TODO: PAY
                            break;
                        case 5:
                            continue;
                        default:
                            continue;
                    }
                    break;
                case 3:
                    getAccountingManager()->menu();
                    while (!(cin >> internal)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        log("Opción inválida, por favor ingresa un número!");
                    }
                    switch (internal) {

                    }
                    break;
                case 4:
                    end();
                    break;
                default:
                    log("Por favor ingresa una opción correcta!");
                    break;
            }
        }
    }
}

void Application::end() {
    if (isStarted()) {
        setStarted(false);
        if (isDebug()) log("Cerrando módulos...");
        for (Module *module : modules) {
            module->end();
        }
        log("Aplicación finalizada con éxito.");
    }
}

void Application::appInfo() {
    string message, authorMsg;
    message = getName() + " iniciando...";
    authorMsg = "Creado por " + getAuthor() + ".";
    log(message);
    log(authorMsg);
    if (isDebug()) log("Iniciado en modo DEBUG! (Expect Sample DATA to load).");
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


void Application::addModule(Module *module) {
    if (module) {
        modules.push_back(module);
    }
}

AccountingManager *Application::getAccountingManager() {
    return this->accountingManager;
}

AppointmentManager *Application::getAppointmentManager() {
    return this->appointmentManager;
}

PatientManager *Application::getPatientManager() {
    return this->patientManager;
}

CommandManager *Application::getCommandManager() {
    return this->commandManager;
}

void Application::loadSampleData() {
    getPatientManager()->registerPatient(
            new Patient("Ian", 18, Gender::MALE, "Mexicana", "4315531315", "ian@gmail.com", false, false,
                        false), true);
    getPatientManager()->registerPatient(
            new Patient("Erick", 19, Gender::MALE, "Mexicana", "35236246", "erick@gmail.com", true, false,
                        false), true);
    getPatientManager()->registerPatient(
            new Patient("Said", 21, Gender::MALE, "Mexicana", "6457364234", "said@gmail.com", false, false,
                        false), true);
    getPatientManager()->registerPatient(
            new Patient("José", 19, Gender::MALE, "Mexicana", "5735574335", "jose@gmail.com", false, true,
                        false), true);
    getPatientManager()->registerPatient(
            new Patient("Ramón", 18, Gender::MALE, "Mexicana", "26264462", "ramon@gmail.com", true, false,
                        false), true);
    log("Sample DATA loaded successfully!");
}


#endif //CLINICADMINISTRATION_APPLICATION_H
