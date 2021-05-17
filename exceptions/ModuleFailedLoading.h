//
// ClinicAdministration
//
// Ian García González
// A01706892
//
// File created on 12/05/21.
//
// Copyright © 2021. All rights reserved.
//
//

#ifndef CLINICADMINISTRATION_MODULEFAILEDLOADING_H
#define CLINICADMINISTRATION_MODULEFAILEDLOADING_H

#include <iostream>
#include <string>

/*
 * ModuleFailedLoading: Excepción que generada cuando algún módulo no puede iniciar.
 * @file ModuleFailedLoading.h
 * @author Ian
 * */


using namespace std;

struct ModuleFailedLoading : public exception {
    /**
     * Obtiene el mensaje de la excepción.
     * @return Mensaje
     * */
    const char *getMessage() const noexcept {
        return "Module couldn't load successfully, terminating app.";
    }
};

#endif //CLINICADMINISTRATION_MODULEFAILEDLOADING_H
