//
// TC1030
//
// Ian García González
// A01706892
//
// File created on 08/05/2021.
//
// Copyright © 2021. All rights reserved.
//
//
#include "Application.h"

/*
 * @file main.cpp
 * @author Ian
 * */

Application *application = nullptr;

/*
 * Método inicial de la aplicación
 * Crea la instancia principal y la inicia.
 * */
int main() {
    application = new Application("Clinic Administration", true);
    application->init();
    return 0;
}
