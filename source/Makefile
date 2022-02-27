analog: main.o AnalyseLog.o Statistiques.o LectureLog.o
	g++ -o ../bin/analog main.o AnalyseLog.o Statistiques.o LectureLog.o -g
AnalyseLog.o: AnalyseLog.cpp
	g++ -c AnalyseLog.cpp -g -ansi -pedantic -Wall -std=c++11
main.o: main.cpp
	g++ -c main.cpp -g -ansi -pedantic -Wall -std=c++11
Statistiques.o: Statistiques.cpp
	g++ -c Statistiques.cpp -g -ansi -pedantic -Wall -std=c++11
LectureLog.o: LectureLog.cpp
	g++ -c LectureLog.cpp -g -ansi -pedantic -Wall -std=c++11