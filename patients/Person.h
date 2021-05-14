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

/*
 * Person: Clase base para tipos de personas dentro de la clínica.
 * Gender: Género de la persona.
 * @file Person.h
 * @author Ian
 * */

using namespace std;

/**
 * Tipos disponibles de género.
 * MALE: Hombre
 * FEMALE: Mujer
 * UNDEFINED: Sin definir
 */
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

/**
 * Constructor de la clase sin parámetros.
 * */
Person::Person() {
    this->name = "";
    this->age = 0;
    this->gender = Gender::UNDEFINED;
    this->nationality = "";
    this->celular = "";
    this->email = "";
}

/**
 * Constructor principal de la clase con parámetros.
 * @param name Nombre de la persona.
 * @param age Edad de la persona.
 * @param gender Género de la persona.
 * @param nationality Nacionalidad de la persona.
 * @param celular Celular de contacto.
 * @param email Correo electrónico de contacto.
 * */
Person::Person(string name, int age, Gender gender, string nationality, string celular, string email) {
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->nationality = nationality;
    this->celular = celular;
    this->email = email;
}

/**
 * Menciona si la persona es menor de edad.
 * @return Verdadero si es menor de edad.
 * */
bool Person::isUnderAge() {
    return this->age < 18;
}

/**
 * Obtiene el nombre de la persona.
 * @return Nombre
 * */
string Person::getName() {
    return this->name;
}

/**
 * Asigna el nombre a la persona.
 * @param name Nombre
 * */
void Person::setName(string name) {
    this->name = name;
}

/**
 * Obtiene la edad de la persona.
 * @return Edad
 * */
int Person::getAge() {
    return this->age;
}

/**
 * Asigna la edad a la persona.
 * @param age Edad
 * */
void Person::setAge(int age) {
    this->age = age;
}

/**
 * Obtiene el género de la persona.
 * @return Género
 * */
Gender Person::getGender() {
    return this->gender;
}

/**
 * Asigna el género a la persona.
 * @param gender Género
 * */
void Person::setGender(Gender gender) {
    this->gender = gender;
}

/**
 * Obtiene la nacionalidad de la persona.
 * @return Nacionalidad
 * */
string Person::getNationality() {
    return this->nationality;
}

/**
 * Asigna la nacionalidad a la persona.
 * @param nationality Nacionalidad
 * */
void Person::setNationality(string nationality) {
    this->nationality = nationality;
}

/**
 * Obtiene el celular de la persona.
 * @return Celular
 * */
string Person::getCelular() {
    return this->celular;
}

/**
 * Asigna el celular a la persona.
 * @param celular Celular
 * */
void Person::setCelular(string celular) {
    this->celular = celular;
}

/**
 * Obtiene el email de la persona.
 * @return Correo electrónico
 * */
string Person::getEmail() {
    return this->email;
}

/**
 * Asigna el email a la persona.
 * @param email Correo electrónico
 * */
void Person::setEmail(string email) {
    this->email = email;
}


#endif //CLINICADMINISTRATION_PERSON_H
