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

#ifndef CLINICADMINISTRATION_TESTMODULE_H
#define CLINICADMINISTRATION_TESTMODULE_H

#include <iostream>
#include <string>
#include "../Module.h"

class Application;

class TestModule : public Module {
private:
    Application *app;
public:

    TestModule();

    explicit TestModule(Application *app);

    void start() override;

    void end() override;

    Application *getApplication();
};

TestModule::TestModule() : Module("Test Module") {}

TestModule::TestModule(Application *app) : Module("Test Module") {
    this->app = app;
}

void TestModule::start() {
    log("INSTANCE CREATED!");
}

void TestModule::end() {
    log("CLEARING CACHE! ENDING...");
}

Application *TestModule::getApplication() {
    return this->app;
}


#endif //CLINICADMINISTRATION_TESTMODULE_H