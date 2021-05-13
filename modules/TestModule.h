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

class TestModule : public Module {
public:

    TestModule();

    explicit TestModule(Application *app);

    void start() override;

    void end() override;
};

TestModule::TestModule() : Module("Test Module") {}

TestModule::TestModule(Application *app) : Module(app, "Test Module") {
    try {
        start();
    } catch (exception exception) {
        logWarn("Module couldn't load!");
    }
}

void TestModule::start() {
    log("INSTANCE CREATED!");
}

void TestModule::end() {
    log("CLEARING CACHE! ENDING...");
}


#endif //CLINICADMINISTRATION_TESTMODULE_H
