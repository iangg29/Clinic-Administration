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

#ifndef CLINICADMINISTRATION_MODULE_H
#define CLINICADMINISTRATION_MODULE_H

#include <iostream>
#include <string>
#include "./utils/TimeUtil.h"

using namespace std;

class Module {
private:
    string display;
    int startupTime;
    bool started;
protected:
    void log(string message);

    void logWarn(string message);

    void logFatal(string message);

public:
    explicit Module(string display);

    virtual void start();

    virtual void end();

    string getDisplay();

    int getStartupTime();

    bool isStarted();

    void setStarted(bool started);
};

Module::Module(string display) {
    this->display = display;
    this->startupTime = TimeUtil().getMillis();
    this->started = false;
    // TODO: Register module!
    try {
        start();
    } catch (exception exception) {
        logWarn("Module couldn't load!");
    }
}

void Module::start() {
    if (!isStarted()) {
        setStarted(true);
        log("MODULO INICIADO...");
    }
}

void Module::end() {
    if (isStarted()) {
        setStarted(false);
        log("MODULO CERRADO...");
    }
}

string Module::getDisplay() {
    return this->display;
}

int Module::getStartupTime() {
    return this->startupTime;
}

bool Module::isStarted() {
    return this->started;
}

void Module::setStarted(bool started) {
    this->started = started;
}

void Module::log(string message) {
    cout << "[*] " << message << endl;
}

void Module::logWarn(string message) {
    cout << "[WARN] " << message << endl;
}

void Module::logFatal(string message) {
    cout << "[ERROR] " << message << endl;
}

#endif //CLINICADMINISTRATION_MODULE_H
