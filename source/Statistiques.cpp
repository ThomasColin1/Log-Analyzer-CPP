/*************************************************************************
                           Statistiques  -  Réalise les statistiques sur 
                                            nos logs

                             -------------------
    début                : 14/01/2021 au 06/02/2022
    copyright            : (C) 2022 par cflandre & cthomas1
    e-mail               : corentin.flandre@insa-lyon.fr 
                           & colin.thomas@insa-lyon.fr
*************************************************************************/

// -- Réalisation de la classe <Statistiques> (fichier Statistiques.cpp) -- 

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include<algorithm>

//------------------------------------------------------ Include personnel
#include "Statistiques.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

int Statistiques::ajouterSite(string url)
// Algorithme : On vérifie si l'url est déjà dans le set
//    Si il y est, on renvoie sa position
//    Si il n'y est pas, on l'ajoute et on renvoie sa position
{
  int position;
  if(sites.find(url) != sites.end()){
    position=distance(sites.begin(),sites.find(url));
  }else{
    sites.insert(url);
    position=distance(sites.begin(),sites.find(url));
  }
  return position;
}

int Statistiques::ajouterSite(string url, string urlSite)
// Algorithme : On vérifie si l'url est déjà dans le set
//    Si il y est, on renvoie sa position
//    Si il n'y est pas, on l'ajoute et on renvoie sa position
{
  if(url.find(urlSite)!=string::npos){
      url.erase (url.find(urlSite), urlSite.length());
  }else{
    url="Site exterieur";
  }
  int position;
  if(sites.find(url) != sites.end()){
    position=distance(sites.begin(),sites.find(url));
  }else{
    sites.insert(url);
    position=distance(sites.begin(),sites.find(url));
  }
  return position;
}

void Statistiques::ajouterTop10(int index){
  if(top10.find(index) != top10.end()){
    map<int,int>::iterator iterateur = top10.find(index);
    iterateur->second=iterateur->second+1;
  }else{
    top10.insert(std::pair<int,int>(index,1));
  }
  
#ifdef MAP
    cout << "Appel à l'ajout dans le top10 de <Statistiques>" << endl << "Position : " << index << " et nombre : " << iterateur->second << endl;
#endif
}

void Statistiques::ajouterOptionG(int indexDepart, int indexArrivee){
  if(optionG.find(make_pair(indexDepart,indexArrivee)) != optionG.end()){
    map<paire,int>::iterator iterateur = optionG.find(make_pair(indexDepart,indexArrivee));
    iterateur->second=iterateur->second+1;
  }else{
    optionG.insert(std::pair<paire,int>(make_pair(indexDepart,indexArrivee),1));
  }
  
#ifdef MAP
    cout << "Appel à l'ajout dans l'option G de <Statistiques>" << endl << "Position : " << indexDepart << "-" << indexArrivee << " et nombre : " << iterateur->second << endl;
#endif
}



string Statistiques::creerFichierDot(){
  string s="digraph {\n";
  set<string>::iterator itSet = sites.begin();
  for (itSet=sites.begin();itSet!=sites.end();itSet++){
    s+="\"";
    s+=*itSet;
    s+="\";\n";
  }
  map<paire,int>::iterator itG = optionG.begin();
  for (itG=optionG.begin();itG!=optionG.end();itG++){
    s+="\"";
    s+=getSite(itG->first.first);
    s+="\"";
    s+=" -> ";
    s+="\"";
    s+=getSite(itG->first.second);
    s+="\"";
    s+=" [label=\"";
    s+=to_string(itG->second);
    s+="\"];\n";
  }
  s+="}";
  return s;
}


void Statistiques::afficherTop10(){
  // cout << "DEBUT AFFICHER TOP 10" << endl;
  int classement[10][2];
  map<int,int>::iterator it=top10.begin();
  int max=0;
  bool presence=false;
  int maxTop=10;
  if(top10.size()<10){
    maxTop=top10.size();
  }
  // cout << " MAXTOP" << maxTop << endl;
  
  for (int i=0;i<maxTop;i++){
    // cout << "BOUCLE FOR" << endl;
    for (it=top10.begin();it!=top10.end();it++){
      // cout << "Calcul du numero "<<i << " du top 10" << endl;
      for(int j=0;j<i;j++){
        if(classement[j][0]==it->first){
          presence=true;
        }
      }
      if(presence==false && getSite(it->first)!="-" && getSite(it->first)!="" && max<=it->second){
        max=it->second;
        classement[i][0]=it->first;
        classement[i][1]=it->second;
      }
      presence=false;
    }
    max=0;
  }

  for(int i=0;i<maxTop;i++){
    cout << getSite(classement[i][0])<< ": " << classement[i][1] << " hits" << endl;
  }
}


string Statistiques::getSite(int position)
// Algorithme : 
//
{
  set<string>::iterator iterateur = sites.begin();
  for(int i = 0; i < position; i++){
    iterateur++;
  }
  return *iterateur;
}


//------------------------------------------------- Surcharge d'opérateurs
//Statistiques & Statistiques::operator = ( const Statistiques & maStat )
// Algorithme :
//
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Statistiques::Statistiques ( const Statistiques & maStat)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Statistiques>" << endl;
#endif
} //----- Fin de Statistiques (constructeur de copie)


Statistiques::Statistiques ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Statistiques>" << endl;
#endif
} //----- Fin de Statistiques


Statistiques::~Statistiques ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Statistiques>" << endl;
#endif
} //----- Fin de ~Statistiques


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

