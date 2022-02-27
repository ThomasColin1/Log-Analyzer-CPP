/*************************************************************************
                           AnalyseLog  -  Traitement des logs pour 
                            l'application analog

                             -------------------
    début                : 14/01/2021 au 06/02/2022
    copyright            : (C) 2022 par cflandre & cthomas1
    e-mail               : corentin.flandre@insa-lyon.fr 
                           & colin.thomas@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <AnalyseLog> (fichier AnalyseLog.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <istream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "StructureLog.h"
#include "AnalyseLog.h"
#include "LectureLog.h"
#include "Statistiques.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

static bool verificationOptionE(string URLArrivee){
    int debutAEnlever = URLArrivee.find(".png");

    if(debutAEnlever !=-1){
        // cout << " PNG" << endl;
        return false;
    }
    debutAEnlever = URLArrivee.find(".js");
    if(debutAEnlever !=-1){
        return false;
    }
    debutAEnlever = URLArrivee.find(".jpg");
    if(debutAEnlever !=-1){
        return false;
    }
    debutAEnlever = URLArrivee.find(".css");
    if(debutAEnlever !=-1){
        return false;
    }
    debutAEnlever = URLArrivee.find(".gif");
    if(debutAEnlever !=-1){
        return false;
    }
  return true ;
}




//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres )
// Algorithme :
//
// {
// } //----- fin de Nom

int AnalyseLog(string fichierLog, string urlSite, string fichierDot, bool stateT, bool stateE, bool stateG, int heure)
// Algorithme : for each-row
{
  string sHeure=to_string(heure);
  if(sHeure.size()==1){
    sHeure="0"+sHeure;
  }
  //Ouverture du fichier
  ifstream leFichierLog;
  // leFichierLog.open("../tmp/"+fichierLog);
  leFichierLog.open(fichierLog);
  // Erreur d'ouverture du fichier
  if(!leFichierLog){
      cout << " Erreur -> Le fichier "<< fichierLog << " est introuvable" << endl;
    leFichierLog.close();
  }
  // Succes de l'ouverture du fichier
  else{

    char * buffer = new char[1000];
    int index;
    Statistiques * stats = new Statistiques();
    int i=0;
    while(!leFichierLog.eof()){
      if (i%1000==0){
      // cout << "Lecture initiale : "<<i << endl;
      }
      i++;
      leFichierLog.getline(buffer,1000,'\n');
      log * ptLog = LireLog(buffer);
      //On enlève le nom du site originel de l'url de depart
      

      //selection
      if(!stateE && !stateT){
        stats->ajouterSite(ptLog->URLArrivee);
        stats->ajouterSite(ptLog->URLDepart, urlSite);
      }else if(stateE && !stateT && verificationOptionE(ptLog->URLArrivee)){
        // cout << "cas 2 " << ptLog->URLArrivee<<endl;
        stats->ajouterSite(ptLog->URLArrivee);
        stats->ajouterSite(ptLog->URLDepart, urlSite);
      }else if(stateT && !stateE && ptLog->Date.substr(12, 2)==(to_string(heure)) ){
        // cout << "cas 3 " << ptLog->URLArrivee<<endl;
        stats->ajouterSite(ptLog->URLArrivee);
        stats->ajouterSite(ptLog->URLDepart, urlSite);
      }else if(verificationOptionE(ptLog->URLArrivee) && ptLog->Date.substr(12, 2)==(to_string(heure))){
        // cout << "cas 4 " << ptLog->URLArrivee<<endl;
        stats->ajouterSite(ptLog->URLArrivee);
        stats->ajouterSite(ptLog->URLDepart, urlSite);
      }
    }

    leFichierLog.clear();
    leFichierLog.seekg(0);
    i=0;
    
    while(!leFichierLog.eof()){
      // if (i%1000==0){
      // cout << "Ajout dans le top 10 : "<<i << endl;
      i++;
      // }
      leFichierLog.getline(buffer,1000,'\n');
      log * ptLog = LireLog(buffer);
      
      if(!stateE && !stateT){
        // cout << "cas 1 TOP 10 " << ptLog->URLArrivee<<endl;
        index=stats->ajouterSite(ptLog->URLArrivee);
        stats->ajouterTop10(index);
      }else if(stateE && !stateT && verificationOptionE(ptLog->URLArrivee)){
        // cout << "cas 2 TOP 10 " << ptLog->URLArrivee<<endl;
        index=stats->ajouterSite(ptLog->URLArrivee);
        stats->ajouterTop10(index);
      }else if(stateT && !stateE && ptLog->Date.substr(12, 2)==(sHeure)){
        // cout << "cas 3 TOP 10 " << ptLog->URLArrivee<<endl;
        index=stats->ajouterSite(ptLog->URLArrivee);
        stats->ajouterTop10(index);
      }else if(verificationOptionE(ptLog->URLArrivee) && ptLog->Date.substr(12, 2)==(sHeure)){
        // cout << "cas 4 TOP 10  " << ptLog->URLArrivee<<endl;
        index=stats->ajouterSite(ptLog->URLArrivee);
        stats->ajouterTop10(index);
      }
    }
    stats->afficherTop10();

    
    
    leFichierLog.clear();
    leFichierLog.seekg(0);
    if(stateG==true){
      // cout << "OPTIONG" << endl;
      i=1;
      while(!leFichierLog.eof()){
        // if (i%1000==0){
          // cout << "Réalisation de l'option G : "<<i << endl;
        // }
        i++;
        leFichierLog.getline(buffer,1000,'\n');
        log * ptLog = LireLog(buffer);
        int indexDepart;
        int indexArrivee;
        
        if(!stateE && !stateT){
          // cout << "cas 1 TOP 10 " << ptLog->URLArrivee<<endl;
          indexDepart=stats->ajouterSite(ptLog->URLDepart, urlSite);
          indexArrivee=stats->ajouterSite(ptLog->URLArrivee);
          stats->ajouterOptionG(indexDepart, indexArrivee);
        }else if(stateE && !stateT && verificationOptionE(ptLog->URLArrivee)){
          // cout << "cas 2 TOP 10 " << ptLog->URLArrivee<<endl;
          indexDepart=stats->ajouterSite(ptLog->URLDepart, urlSite);
          indexArrivee=stats->ajouterSite(ptLog->URLArrivee);
          stats->ajouterOptionG(indexDepart, indexArrivee);
        }else if(stateT && !stateE && ptLog->Date.substr(12, 2)==(sHeure)){
          // cout << "cas 3 TOP 10 " << ptLog->URLArrivee<<endl;
          indexDepart=stats->ajouterSite(ptLog->URLDepart, urlSite);
          indexArrivee=stats->ajouterSite(ptLog->URLArrivee);
          stats->ajouterOptionG(indexDepart, indexArrivee);
        }else if(verificationOptionE(ptLog->URLArrivee) && ptLog->Date.substr(12, 2)==(sHeure)){
          // cout << "cas 4 TOP 10  " << ptLog->URLArrivee<<endl;
          indexDepart=stats->ajouterSite(ptLog->URLDepart, urlSite);
          indexArrivee=stats->ajouterSite(ptLog->URLArrivee);
          stats->ajouterOptionG(indexDepart, indexArrivee);
        }
      }
      // cout << stats->creerFichierDot() << endl; // C'est 
      string sDot = stats->creerFichierDot();
      ofstream fic ( fichierDot );
      streambuf *oldCoutBuffer = cout.rdbuf ( fic.rdbuf ( ) ); // On envoie cout sur le fichier ouvert
      cout << sDot;
      cout.rdbuf ( oldCoutBuffer ); // remise en place de cout sur la sortie standard
      fic.close ( );
    }
    
    



    delete[] buffer;
    delete stats;
    leFichierLog.close();
  }
  
  return 0;
} //---- fin de URL

