#ifndef GRAPH_H_
#define GRAPH_H_
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class LectureEcriture;

struct nbHit_Horaires
{
	int heures[24];
	string extension;
	//vector<int> heures;  // hoca denemisti
	//nbHit_Horaires():heures(24,0),extenstion(){}
	nbHit_Horaires & operator = (const nbHit_Horaires &);
	int totalHeures();

};


class Graph {
private:
		typedef map<string, nbHit_Horaires> Referer;
		typedef map<string, Referer> Cible;
		Cible analyse;

public:
	Graph();
	virtual ~Graph();
	friend ostream & operator << (ostream & os,const Graph & g);
	void Ajouter(string aQuelHeure,string cible_url,string extension,string source_url);
	void sansOption();
};

	#endif /* GRAPH_H_ */
