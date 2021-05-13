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
#include "modules/TestModule.h"
#include "exceptions/ModuleFailedLoading.h"

using namespace std;

class Application {
private:
    string name;
    string author;
    float version;
    bool debug;
    bool started;
    unsigned int startTime;
    unsigned int finishTime;
    vector<Module> modules;

    void log(string message);

    TestModule testModule;

public:
    Application(string name, bool debug);

    void init();

    void end();

    string getName();

    string getAuthor();

    float getVersion();

    bool isDebug();

    bool isStarted();

    void setStarted(bool started);

    int getStartTime();

    int getFinishTime();

    vector<Module> getModules();

    void addModule(Module &module);

    TestModule getTestModule();
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
        setStarted(true);
        try {
            this->testModule = TestModule(this);
            addModule(testModule);
        } catch (ModuleFailedLoading &e) {
            log(e.getMessage());
        }
        log("INIT!");
        this->finishTime = TimeUtil().getMillis();
        if (isDebug()) cout << "Application started in [" << (finishTime - startTime) << "]ms." << endl;
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

string Application::getName() {
    return this->name;
}

string Application::getAuthor() {
    return this->author;
}

float Application::getVersion() {
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

TestModule Application::getTestModule() {
    return this->testModule;
}


#endif //CLINICADMINISTRATION_APPLICATION_H
