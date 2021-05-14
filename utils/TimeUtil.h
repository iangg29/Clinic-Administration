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

/*
 * TimeUtil: Clase de utilidad para obtener el tiempo actual en milisegundos.
 * @file TimeUtil.h
 * @author Ian
 * */


class TimeUtil {
public:
    int getMillis();
};

/**
 * Obtiene tiempo actual en milisegundos.
 * @return Tiempo
 * */
int TimeUtil::getMillis() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
}


#endif //CLINICADMINISTRATION_TIMEUTIL_H
