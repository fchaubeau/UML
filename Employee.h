/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#if ! defined ( EMPLOYEE_H )
#define EMPLOYEE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <ctime>
#include <list>
#include "User.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Ensemble>
//
//
//------------------------------------------------------------------------

class Employee : User
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
        // type Méthode ( liste des paramètres );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Employee(const Employee& anEmployee);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Employee(string mail, string name, string password, string tel, int point);

    Employee();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Employee();
    // Mode d'emploi :
    //
    // Contrat :
    //

    double getMeanAirQuality(pair<double, double> center, double radius, time_t t);

    double getMeanAirQUalityTimeSpawn(pair<double, double> center, double radius, time_t tdebut, time_t tFin);

    list<Sensor> getSimilarSensor(Sensor s);



//------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    int point;
};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // EMPLOYEE_H
