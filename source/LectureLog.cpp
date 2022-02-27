/*************************************************************************
                           LectureLog  -  Traitement des lignes de log

                             -------------------
    début                : 14/01/2021 au 06/02/2022
    copyright            : (C) 2022 par cflandre & cthomas1
    e-mail               : corentin.flandre@insa-lyon.fr 
                           & colin.thomas@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <LectureLog> (fichier LectureLog.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "LectureLog.h"
#include <string>
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
// static void AffichageUnLog ( log monLog )
// // Mode d'emploi :
// //
// // Contrat :
// //
// // Algorithme :
// //
// {
//   cout << "Mon log est composé de:"<< endl;
//   cout << "IP: "<< "|"<< monLog.IP<< "|"<<endl;
//   cout << "Date: "<< "|"<< monLog.Date<< "|"<<endl;
//   cout << "URLDepart: "<< "|"<< monLog.URLDepart<< "|"<<endl;
//   cout << "URLArrivee: "<< "|"<< monLog.URLArrivee<< "|"<<endl;
//   cout << "UserLogname: "<< "|"<< monLog.UserLogname<< "|"<<endl;
//   cout << "UserAuth: "<< "|"<< monLog.UserAuth<< "|"<<endl;
//   cout << "statusCode: "<< "|"<< monLog.statusCode<< "|"<<endl;
//   cout << "dataQuantity: "<< "|"<< monLog.dataQuantity<< "|"<<endl;
//   cout << "navigateur: "<< "|"<< monLog.navigateur<< "|"<<endl;
// } //----- fin AffichageUnLog

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
log * LireLog(char * ligne)
// Algorithme :
//
{
    string s=ligne;
    log monLog; 

    log * ptLog=new(log);

    int arrivee;

    arrivee = s.find(" ");
    // cout <<"|" << s<< "|" << endl << "arrivee "<< arrivee << endl;
    monLog.IP = s.substr(0, arrivee);
    arrivee = arrivee + 1;
    s = s.substr(arrivee, s.length() - arrivee);

    arrivee = s.find(" ");
    // cout << "arrivee "<< arrivee << endl;
    monLog.UserLogname = s.substr(0, arrivee);
    arrivee = arrivee + 1;
    s = s.substr(arrivee, s.length() - arrivee);

    arrivee = s.find(" ");
    // cout << "arrivee "<< arrivee << endl;
    monLog.UserAuth = s.substr(0, arrivee);
    arrivee = arrivee + 1;
    s = s.substr(arrivee, s.length() - arrivee);

    arrivee = s.find("]");
    // cout << "arrivee "<< arrivee << endl;
    monLog.Date = s.substr(1, arrivee - 1);
    arrivee = arrivee + 1;
    s = s.substr(arrivee, s.length() - arrivee);

    arrivee = s.find(" ");
    arrivee = arrivee + 1;
    s = s.substr(arrivee, s.length() - arrivee);
    arrivee = s.find(" ");
    arrivee = arrivee + 1;
    s = s.substr(arrivee, s.length() - arrivee);

    arrivee = s.find(" ");
    monLog.URLArrivee = s.substr(0, arrivee);
    arrivee = arrivee + 1;
    s = s.substr(arrivee, s.length() - arrivee);

    arrivee = s.find(" ");
    arrivee = arrivee + 1;
    s = s.substr(arrivee, s.length() - arrivee);

    arrivee = s.find(" ");
    monLog.statusCode = s.substr(0, arrivee);
    arrivee = arrivee + 1;
    s = s.substr(arrivee, s.length() - arrivee);

    arrivee = s.find(" ");
    monLog.dataQuantity = s.substr(0, arrivee);
    arrivee = arrivee + 1;
    s = s.substr(arrivee, s.length() - arrivee);

    arrivee = s.find(" ");
    monLog.URLDepart = s.substr(1, arrivee - 2);
    arrivee = arrivee + 1;
    s = s.substr(arrivee, s.length() - arrivee);

    arrivee = s.length() - 1;
    monLog.navigateur = s.substr(1, arrivee - 2);
    arrivee = arrivee + 1;
    s = s.substr(arrivee, s.length() - arrivee);

    *ptLog=monLog;
    // AffichageUnLog(monLog);
    return ptLog;
} //----- fin de LireLog

