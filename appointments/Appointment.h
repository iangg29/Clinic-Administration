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

#ifndef CLINICADMINISTRATION_APPOINTMENT_H
#define CLINICADMINISTRATION_APPOINTMENT_H

#include <iostream>
#include <string>

class Appointment {
private:
    int ID;
    // TODO: Specialty
    int day;
    string month;
    // TODO: Doctor
    // TODO: Patient
    int cost;
    bool active;
public:
    Appointment(int day, string month, int cost);

    void reserve();

    void cancel();

    void pay();

    int getID();

    void setID(int ID);

    int getDay();

    void setDay(int day);

    string getMonth();

    void setMonth(string month);

    int getCost();

    void setCost(int cost);

    bool isActive();

    void setActive(bool active);
};

Appointment::Appointment(int day, string month, int cost) {
    this->ID = 0;
    this->day = day;
    this->month = month;
    this->cost = cost;
    this->active = true;
}

void Appointment::reserve() {

}

void Appointment::cancel() {

}

void Appointment::pay() {
    // TODO: Transaction
}

int Appointment::getID() {
    return this->ID;
}

void Appointment::setID(int ID) {
    this->ID = ID;
}

int Appointment::getDay() {
    return this->day;
}

void Appointment::setDay(int day) {
    this->day = day;
}

string Appointment::getMonth() {
    return this->month;
}

void Appointment::setMonth(string month) {
    this->month = month;
}

int Appointment::getCost() {
    return this->cost;
}

void Appointment::setCost(int cost) {
    this->cost = cost;
}

bool Appointment::isActive() {
    return this->active;
}

void Appointment::setActive(bool active) {
    this->active = active;
}


#endif //CLINICADMINISTRATION_APPOINTMENT_H
