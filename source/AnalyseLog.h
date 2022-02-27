/*************************************************************************
                           AnalyseLog  -  Traitement des logs pour 
                           l'application analog

                             -------------------
    début                : 14/01/2021 au 06/02/2022
    copyright            : (C) 2022 par cflandre & cthomas1
    e-mail               : corentin.flandre@insa-lyon.fr 
                           & colin.thomas@insa-lyon.fr
*************************************************************************/

//---------- Interface du module <AnalyseLog> (fichier AnalyseLog.h) -------------------
#if ! defined ( AnalyseLog_H )
#define AnalyseLog_H
#include <string>
using namespace std;
//------------------------------------------------------------------------
// Rôle du module <URL>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
// typedef struct   {
// 	string IP ; 
// 	string Date ;
// 	string URLDepart ;
//   string URLArrivee ;
//   string UserLogname ;
//   string UserAuth ;
//   string statusCode ;
//   string dataQuantity ;
//   string navigateur ;
// }log;

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

int AnalyseLog(string fichierLog, string urlSite, string fichierDot, bool stateT, bool stateE, bool stateG, int heure);
// Mode d'emploi : 
// 
// Contrat : 
// 


//////////////////////////////////////////////////////////////// PROTECTED
// ---------------------------------------------------- Methodes protégées
// static bool verificationOptionE(string URLArrivee);



#endif // XXX_H

