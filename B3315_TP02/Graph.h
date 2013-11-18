#ifndef GRAPH_H_
#define GRAPH_H_
#include <string>
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

class LectureEcriture;

struct nbHit_Horaires
{
	int heures[24];
	string extension;
	nbHit_Horaires(){
		extension="";
		for(int i=0;i<24;i++)
			heures[i]=0;
	}
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
