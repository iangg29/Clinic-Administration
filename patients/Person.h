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

#ifndef CLINICADMINISTRATION_PERSON_H
#define CLINICADMINISTRATION_PERSON_H

#include <iostream>
#include <string>

using namespace std;

enum class Gender {
    MALE,
    FEMALE,
    UNDEFINED
};

class Person {
private:
    string name;
    int age;
    Gender gender;
    string nationality;
    string celular;
    string email;
public:
    Person();

    Person(string name, int age, Gender gender, string nationality, string celular, string email);

    bool isUnderAge();

    string getName();

    void setName(string name);

    int getAge();

    void setAge(int age);

    Gender getGender();

    void setGender(Gender gender);

    string getNationality();

    void setNationality(string nationality);

    string getCelular();

    void setCelular(string celular);

    string getEmail();

    void setEmail(string email);
};

Person::Person() {
    this->name = "";
    this->age = 0;
    this->gender = Gender::UNDEFINED;
    this->nationality = "";
    this->celular = "";
    this->email = "";
}

Person::Person(string name, int age, Gender gender, string nationality, string celular, string email) {
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->nationality = nationality;
    this->celular = celular;
    this->email = email;
}

bool Person::isUnderAge() {
    return this->age < 18;
}

string Person::getName() {
    return this->name;
}

void Person::setName(string name) {
    this->name = name;
}

int Person::getAge() {
    return this->age;
}

void Person::setAge(int age) {
    this->age = age;
}

Gender Person::getGender() {
    return this->gender;
}

void Person::setGender(Gender gender) {
    this->gender = gender;
}

string Person::getNationality() {
    return this->nationality;
}

void Person::setNationality(string nationality) {
    this->nationality = nationality;
}

string Person::getCelular() {
    return this->celular;
}

void Person::setCelular(string celular) {
    this->celular = celular;
}

string Person::getEmail() {
    return this->email;
}

void Person::setEmail(string email) {
    this->email = email;
}


#endif //CLINICADMINISTRATION_PERSON_H
