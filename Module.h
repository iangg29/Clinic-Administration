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
#include "iStart.h"

using namespace std;

class Application;

class Module : public iStart {
private:
    Application *app;
    string display;
    int startupTime;
    bool started;
protected:
    void log(string message);

    void logWarn(string message);

    void logFatal(string message);

public:
    explicit Module(string display);

    Module(Application *app, string display);

    virtual void start() override;

    virtual void end() override;

    string getDisplay();

    int getStartupTime();

    bool isStarted();

    void setStarted(bool started);

    Application *getApplication();
};

Module::Module(string display) {
    this->display = display;
    this->startupTime = TimeUtil().getMillis();
    this->started = false;
}

Module::Module(Application *app, string display) {
    this->app = app;
    this->display = display;
    this->startupTime = TimeUtil().getMillis();
    this->started = false;
    try {
        start();
    } catch (exception exception) {
        logWarn("Module couldn't load!");
    }
}

void Module::start() {
    if (!isStarted()) {
        setStarted(true);
        log(getDisplay().append(" module loaded successfully!"));
    }
}

void Module::end() {
    if (isStarted()) {
        setStarted(false);
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

Application *Module::getApplication() {
    return this->app;
}

#endif //CLINICADMINISTRATION_MODULE_H
