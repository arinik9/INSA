#ifndef GRAPH_H_
#define GRAPH_H_
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <set>

using namespace std;

class LectureEcriture;

struct nbHit_Horaires
{
	int heures[24];
	string extension;
	//vector<int> heures;
	//nbHit_Horaires():heures(24,0),extenstion(){}
	nbHit_Horaires & operator = (const nbHit_Horaires &);
	int totalHeures();
};


//nbHit_Horaires InitialisationNbHit_Horaires();

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
	vector<pair<int,string> > sansOption(bool flag);
	int GetSize();
	void OptionL(int nbHitSup);
	void OptionT(int heure);
	void CombienDifferentExtension();
	void OptionX(set<string> & setExt);
	void OptionG(string pathDot);
	void OptionGTop10(string pathDot,bool flag);
	//vector<int,string> PutInVect();
};

	#endif /* GRAPH_H_ */
