//
// ClinicAdministration
//
// Ian García González
// A01706892
//
// File created on 10/05/21.
//
// Copyright © 2021. All rights reserved.
//
//

#ifndef CLINICADMINISTRATION_TIMEUTIL_H
#define CLINICADMINISTRATION_TIMEUTIL_H

#include <iostream>

class TimeUtil {
public:
    int getMillis();
};

int TimeUtil::getMillis() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
}


#endif //CLINICADMINISTRATION_TIMEUTIL_H
