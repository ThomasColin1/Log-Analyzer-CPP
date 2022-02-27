/*************************************************************************
                           Statistiques  -  Réalise les statistiques sur 
                                            nos logs

                             -------------------
    début                : 14/01/2021 au 06/02/2022
    copyright            : (C) 2022 par cflandre & cthomas1
    e-mail               : corentin.flandre@insa-lyon.fr 
                           & colin.thomas@insa-lyon.fr
************************************************************************/

// -- Interface de la classe <Statistiques> (fichier Statistiques.h) --
#if ! defined ( Statistiques_H )
#define Statistiques_H

//--------------------------------------------------- Interfaces utilisées
#include<map>
#include<set>
#include<vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef std::pair<int, int> paire;
//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class Statistiques
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    int ajouterSite(string url);
    // Mode d'emploi : Ajoute l'url dans le set si elle n'y est pas
    //    Dans tous les cas, renvoie la position de l'url
    // Contrat : 
    //

    int ajouterSite(string url, string urlSite);
    // Mode d'emploi : Ajoute l'url dans le set si elle n'y est pas, en y retirant urlSite si il se trouve dans la string
    //    Dans tous les cas, renvoie la position de l'url
    // Contrat : 
    //
    
    void ajouterTop10(int index);
    // Mode d'emploi : ajoute l'index de l'url avec 1 si il n'y est pas encore
    //    incrémente si l'index y est déjà

    void ajouterOptionG(int indexDepart, int indexArrivee);
    // Mode d'emploi : ajoute l'index de la paire indexDepart-indexArrivee 
    // avec 1 si il n'y est pas encore
    //    incrémente si la paire y est déjà

    string creerFichierDot();
    // Mode d'emploi : renvoie une string qui sera le contenu du fichier dot

    void afficherTop10();
    // Mode d'emploi : affiche les 10 sites les plus visités et leur nombre de visites

    string getSite(int position);
    // Mode d'emploi : 
    //
    // Contrat : 
    //

    


//------------------------------------------------- Surcharge d'opérateurs
    Statistiques & operator = ( const Statistiques & maStat );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Statistiques ( const Statistiques & maStat );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Statistiques ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    ~Statistiques ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  map<paire, int> optionG;
  map<int,int> top10;
  set<string> sites;
};

//-------------------------------- Autres définitions dépendantes de <Statistiques>

#endif // Statistiques_H