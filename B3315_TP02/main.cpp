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
	string nomFichier="anonyme.log"; // sans option için kullandim, if'in kosullarindan biri olcak
	Graph g;
	LectureEcriture l(nomFichier);
// -l option'u her zaman -t den sonra gelcek !!
		while(!l.EstFini())
	{
		UnLog ul;
		ul=l.ProchainLog();
		if(ul.aQuelHeure != "" && ul.cible_url != "" && ul.extension != "" && ul.source_url!= ""){
			g.Ajouter(ul.aQuelHeure,ul.cible_url,ul.extension,ul.source_url);
		}
	}
		//g.OptionT(18);
		//cout << g;
		g.sansOption();
		cout << "--------------------- "  << endl;

		//cout << g;
		cout << "--------------------- "  << endl;
		///g.OptionL(200);
		//g.OptionT(18);
		//cout << g;

	cout<<"ARG-C "<<argc<<endl;
	copy(argv,argv+argc-1,ostream_iterator<char *>(cout,";"));

	int k=0;
	while (k<argc)
			    {
				  printf("argv = %s\n" ,argv[k]);
				  k++;
			    }
		  return 0;
}
