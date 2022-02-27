/*************************************************************************
                           LectureLog  -  Lecture des éléments d'une ligne de log

                             -------------------
    début                : 14/01/2021 au 06/02/2022
    copyright            : (C) 2022 par cflandre & cthomas1
    e-mail               : corentin.flandre@insa-lyon.fr 
                           & colin.thomas@insa-lyon.fr
*************************************************************************/

//---------- Interface du module <LectureLog> (fichier LectureLog.h) -------------------
#if ! defined ( LectureLog_H )
#define LectureLog_H
#include <string>
#include "StructureLog.h"
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
// 	string IP; 
// 	string Date ;
// 	string URLDepart ;
//   string URLArrivee ;
//   string UserLogname ;
//   string UserAuth ;
//   string statusCode ;
//   string dataQuantity ;
//   string navigateur ;
// 	}log;

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

log * LireLog(char * ligne);
// Mode d'emploi : 
// 
// Contrat :
// 
#endif // XXX_H

