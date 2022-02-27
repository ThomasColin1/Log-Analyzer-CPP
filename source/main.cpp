#include <iostream>
using namespace std;
#include <string>
#include "AnalyseLog.h"

int main(int argc, char * argv[]){
  
  string buffer;
  bool stateT=false;
  bool stateE=false;
  bool stateG=true;
  string fichierDot;
  // cout << "fichierDot:"<< fichierDot << endl;//voir la valeur par défaut
  string fichierLog;
  string urlSite; 
  int heure;

  // Si au moins les bons arguments
  if(argc>=3){
    for (int i =1; i<argc-2; i++){
      string buffer = argv[i];
      if(buffer=="-t"){
        if(0<=stoi(argv[i+1])&&stoi(argv[i+1])<24){
          stateT=true;
          heure=stoi(argv[i+1]);
          i++;
          // cout << "Paramètre T reconnu pour l'heure"<<heure <<endl;
        }
        
      }else if (buffer=="-e"){
        stateE=true;
        // cout << "Paramètre E reconnu" << endl;
      }else if (buffer=="-g"){
        stateG=true;
        fichierDot =  argv[i+1];
        i++;
        // cout << "Paramètre G reconnu pour le fichier"<<fichierDot <<endl;
      }else{
        cout << "erreur parametre "<< buffer<< " non reconnu" << endl; // Améliorer l'erreur
        return 1;
      }
    }
    fichierLog = argv[argc-2];
    urlSite= argv[argc-1];
    // cout << "Nom du fichier de log : "<< fichierLog << "\nNom de l'URL de départ : "<<urlSite << endl;
    AnalyseLog(fichierLog, urlSite, fichierDot, stateT, stateE, stateG, heure);
  }
  
  //Si pas assez d'arguments -> afficher mode d'emploi
  else{
    cout << "\n    Mode d'emploi de l'application Analyse de logs Apache" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "|commande pour lancer l'application depuis le dossier source:   |"<< endl;
    cout << "|                                                               |" << endl;
    cout << "|../bin/analog [options] cheminfichier.log adresseintranet      |" << endl; 
    cout << "|                                                               |" << endl;
    cout << "|[-e]  pour exclure les extensions .png, .gif, .jpg, .css et .js|" << endl;
    cout << "|[-t heure] pour ne prendre en compte que les logs dans         |"<< endl;
    cout << "|l'intervalle [heure, heure+1]                                  |"<< endl;
    cout << "|[-g nomfichier.dot] pour produire le fichier au format GraphViz|" << endl;
    cout << "|                                                               |" << endl;
    cout << "|Pour ensuite transformer le .dot en format .png il faut faire  |"<< endl; 
    cout << "|la commande:       dot -Tpng -o nomimage.png nomfichier.dot    |" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "      Mode d'emploi de l'application Analyse de logs Apache\n" << endl;

  }
  return 0;
}