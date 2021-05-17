//
// ClinicAdministration
//
// Ian García González
// A01706892
//
// File created on 13/05/21.
//
// Copyright © 2021. All rights reserved.
//
//

#ifndef CLINICADMINISTRATION_ISTART_H
#define CLINICADMINISTRATION_ISTART_H

/*
 * iStart: Interfaz para heredar método de inicio y fin.
 * @file iStart.h
 * @author Ian
 * */

class iStart {
public:
    /*
     * Método de inicio.
     */
    virtual void start() = 0;

    /*
     * Método de finalizar.
     */
    virtual void end() = 0;
};


#endif //CLINICADMINISTRATION_ISTART_H
