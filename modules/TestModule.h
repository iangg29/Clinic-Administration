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

    void start() override;

    void end() override;
};

TestModule::TestModule() : Module("Test Module") {}

void TestModule::start() {
    log("INSTANCE CREATED!");
}

void TestModule::end() {
    log("CLEARING CACHE! ENDING...");
}


#endif //CLINICADMINISTRATION_TESTMODULE_H
