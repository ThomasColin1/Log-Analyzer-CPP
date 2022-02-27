# Log-Analyzer-CPP
 An apache log analyser who creates a graph to visualize the traffic on your website
 
 
 
Pour compiler/faire l'édition des liens il faut executer la commande $make
situé dans le dossier source. Pour executer l'application il est conseillé 
de rester dans le dossier source et d'effectuer la commande:

$../bin/analog [options] cheminfichier.log adresseintranet

-cheminfichier.log étant le chemin du fichier log à analyser. On a place certains fichiers logs 
dans le fichier tmp mais rentre le chemin du fichier log permet plus de liberté à l'utilisateur
-adresseintranet est le debut de l'url de l'intranet pour lequel nous analysons 
les logs.
-les options sont diverses: 
   [-e]  pour exclure les extensions .png, .gif, .jpg, .css et .js
   [-t heure] pour ne prendre en compte que les logs dans l'intervalle [heure, heure+1] 
   [-g nomfichier.dot] pour produire le fichier au format GraphViz

Exemple de commande conforme:

$../bin/analog -t 3 -e -g MonFichierDot.dot ../tmp/cflandre.log http://intranet-if.insa-lyon.fr



II. Choix sur l'application

De par la liberté sur l'énoncé du TP, nous avons fait différents choix 
qui doivent etre expliques: 
  - l'utilisateur doit rentre la totalité du chemin du fichier log dans la commande plutot que juste
le nom du fichier
  - les url de depart ne provenant pas de l'intranet seront classes comme provenant de Sites exterieurs 
pour dresser le fichier.dot
  - Les url de depart "non renseignes" provenant de l'adresse "-" inconnue seront regroupes
dans les url de Sites Exterieurs
  -


III. Fonctionnement des Tests

Pour executer un test il faut effectuer la commande dans le dossier Tests:

bash ./test.sh Testi

- i etant le numero du test

Pour faire tout les tests il faut effectuer la commande dans le dossier Tests: 

bash ./mktest.sh
