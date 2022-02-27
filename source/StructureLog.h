/*************************************************************************
                           StructureLog  -  Struct des infos d'une ligne de log

                             -------------------
    début                : 14/01/2021 au 06/02/2022
    copyright            : (C) 2022 par cflandre & cthomas1
    e-mail               : corentin.flandre@insa-lyon.fr 
                           & colin.thomas@insa-lyon.fr
*************************************************************************/

#if ! defined ( StructureLog_H )
#define StructureLog_H
#include <string>
using namespace std;

typedef struct {
	string IP ; 
	string Date ;
	string URLDepart ;
  string URLArrivee ;
  string UserLogname ;
  string UserAuth ;
  string statusCode ;
  string dataQuantity ;
  string navigateur ;
} log;

#endif