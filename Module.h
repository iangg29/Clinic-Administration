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

#ifndef CLINICADMINISTRATION_MODULE_H
#define CLINICADMINISTRATION_MODULE_H

#include <iostream>
#include <string>
#include "./utils/TimeUtil.h"
#include "iStart.h"

/*
 * Module: Estructura de módulo para la aplicación.
 * @file Module.h
 * @author Ian
 * */

using namespace std;

class Module : public iStart {
private:
    string display;
    int startupTime;
    bool started;
protected:
    void log(string message);

    void logWarn(string message);

    void logFatal(string message);

public:
    Module(string display);

    virtual void start() override;

    virtual void end() override;

    virtual void menu();

    string getDisplay();

    int getStartupTime();

    bool isStarted();

    void setStarted(bool started);
};

/**
 * Constructor principal de la clase.
 * @param display Nombre
 * */
Module::Module(string display) {
    this->display = display;
    this->startupTime = TimeUtil().getMillis();
    this->started = false;
    try {
        start();
    } catch (exception exception) {
        logWarn("Module couldn't load!");
    }
}

/**
 * Método de inicio.
 * */
void Module::start() {
    if (!isStarted()) {
        setStarted(true);
        log(getDisplay().append(" module loaded successfully!"));
    }
}

/**
 * Método de finalización.
 * */
void Module::end() {
    if (isStarted()) {
        setStarted(false);
    }
}

/**
 * Obtiene el nombre del módulo.
 * @return Name
 * */
string Module::getDisplay() {
    return this->display;
}

/**
 * Obtiene el tiempo de inicio del módulo.
 * @return Time
 * */
int Module::getStartupTime() {
    return this->startupTime;
}

/**
 * Obtiene el status del módulo.
 * @return Started
 * */
bool Module::isStarted() {
    return this->started;
}

/**
 * Asigna el status del módulo.
 * @param started Started
 * */
void Module::setStarted(bool started) {
    this->started = started;
}

/**
 * Imprime un mensaje informativo al usuario.
 * @param message Mensaje
 * */
void Module::log(string message) {
    cout << "[*] " << message << endl;
}

/**
 * Imprime un mensaje de alerta al usuario.
 * @param message Mensaje
 * */
void Module::logWarn(string message) {
    cout << "[WARN] " << message << endl;
}

/**
 * Imprime un mensaje de error al usuario.
 * @param message Mensaje
 * */
void Module::logFatal(string message) {
    cout << "[ERROR] " << message << endl;
}

/**
 * Método para imprimir el menú.
 * */
void Module::menu() {}

#endif //CLINICADMINISTRATION_MODULE_H
