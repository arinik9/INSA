#include "LectureEcriture.h"
#include "Graph.h"
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
	Graph g;
	LectureEcriture l("anonyme.log");
	int i=0;
		while(!l.EstFini())
	{
		UnLog ul;
		ul=l.ProchainLog();
		if(ul.aQuelHeure != "" && ul.cible_url != "" && ul.extension != "" && ul.source_url!= "")
		g.Ajouter(ul.aQuelHeure,ul.cible_url,ul.extension,ul.source_url);
	}
	
	/*	g.sansOption();
		cout << "--------------------- "  << endl;
		g.OptionT(11); //saat 11-12 arasi sadece
		cout << g;
		cout << "--------------------- "  << endl;
		g.OptionL(2); // Hit sayisi top. 2 ve 2'den buyukse
		cout << g;*/
		
	cout<<"ARG-C "<<argc<<endl;
	copy(argv,argv+argc-1,ostream_iterator<char *>(cout,";"));

}
