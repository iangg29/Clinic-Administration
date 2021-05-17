//
// ClinicAdministration
//
// Ian García González
// A01706892
//
// File created on 14/05/21.
//
// Copyright © 2021. All rights reserved.
//
//

#ifndef CLINICADMINISTRATION_COMMANDMANAGER_H
#define CLINICADMINISTRATION_COMMANDMANAGER_H

#include <iostream>
#include <string>
#include <algorithm>
#include "../Module.h"

/*
 * CommandManager: Módulo que administra las interacciones del usuario con la aplicación.
 * @file CommandManager.h
 * @author Ian
 * */

const string NAME_CLI = "CLI Manager";

class CommandManager : public Module {
public:
    CommandManager();

    void start() override;

    void end() override;

    void menu() override;

    bool confirm();
};

/**
 * Constructor principal de la aplicación.
 * */
CommandManager::CommandManager() : Module(NAME_CLI) {
    try {
        start();
    } catch (exception exception) {
        logWarn("Module couldn't be loaded!");
    }
}

/**
 * Método inicial del módulo.
 * */
void CommandManager::start() {
    Module::start();
}


/**
 * Método para finalización de módulo.
 * */
void CommandManager::end() {
    Module::end();
}

/**
 * Imprime el menú del módulo.
 * */
void CommandManager::menu() {
    cout << "---- ==== MENU ==== ----" << endl;
    cout << "Selecciona una opción:" << endl;
    cout << "1. Pacientes" << endl;
    cout << "2. Consultas" << endl;
    cout << "3. Contabilidad" << endl;
    cout << "4. Salir" << endl;
    cout << "------------------------" << endl;
}


/**
 * Método de ayuda para confirmar.
 * @return Respuesta del usuario
 * */
bool CommandManager::confirm() {
    string answer;
    log("¿Estás seguro de realizar esta acción? (y/n)");
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
    if (answer.find('Y', 0) == 0) {
        return true;
    }
    return false;
}


#endif //CLINICADMINISTRATION_COMMANDMANAGER_H
