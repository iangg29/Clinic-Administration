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
 * PayloadCancelled: Excepción que generada cuando el usuario cancela la acción.
 * @file PayloadCancelled.h
 * @author Ian
 * */


using namespace std;

struct PayloadCancelled : public exception {
    /**
     * Obtiene el mensaje de la excepción.
     * @return Mensaje
     * */
    const char *getMessage() const noexcept {
        return "La acción solicitada fué cancelada con éxito.";
    }
};

#endif //CLINICADMINISTRATION_MODULEFAILEDLOADING_H
