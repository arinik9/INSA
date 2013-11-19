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
	while(!l.EstFini())
	{
		UnLog ul;
		ul=l.ProchainLog();
		cout<<"AJOUT"<<endl;
		g.Ajouter(ul.aQuelHeure,ul.cible_url,ul.extension,ul.source_url);
	}
	
	cout<<"ARG-C "<<argc<<endl;
	copy(argv,argv+argc-1,ostream_iterator<char *>(cout,";"));
	if (argc == 1)
			    {
				  printf("argv = %s\n" ,argv[0]);
			    }
		  return 0;

}
