/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Employee.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ensemble::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Employee::Employee(const Employee& anEmployee)
// Algorithme :
//
{
    mail = anEmployee.mail;
    name = anEmployee.name;
    password = anEmployee.password;
    tel = anEmployee.tel;
    point = anEmployee.point;

} //----- Fin de Employee (constructeur de copie)

Employee::Employee(string mail, string name, string password, string tel, int point)
{
    this->mail = mail;
    this->name = name;
    this->password = password;
    this->tel = tel;
    this->point = point;
}


Employee::Employee()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Ensemble>" << endl;
#endif
} //----- Fin de Employee


Employee::~Employee()
// Algorithme :
//
{
} //----- Fin de ~Employee

double Employee::getMeanAirQUalityTimeSpawn(pair<double, double> center, double radius, time_t tdebut, time_t tFin)
{
    return 0.0;
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
