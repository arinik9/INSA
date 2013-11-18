#ifndef GRAPH_H_
#define GRAPH_H_
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <stdlib.h>
using namespace std;

class LectureEcriture;

struct nbHit_Horaires
{
	int heures[24];
	string extension;
};



class Graph {
private:
		typedef map<string, nbHit_Horaires> Cible;
		typedef map<string, Cible> Referer;
		Referer analyse;
public:
	virtual ~Graph();
	//friend ostream & operator << (ostream & os,const Graph & g);
	void Ajouter(string aQuelHeure,string cible_url,string extension,string source_url);
};

	#endif /* GRAPH_H_ */
