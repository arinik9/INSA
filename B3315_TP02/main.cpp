#include "LectureEcriture.h"
#include "Graph.h"

using namespace std;

int main(int argc,char **lstarg)
{
	Graph g;
	LectureEcriture l("anonyme.log");
	while(!l.EstFini())
	{
		UnLog ul;
		ul.aQuelHeure
		ul=l.ProchainLog();
		g.Ajouter(ul.aQuelHeure,ul.cible_url,ul.extension,ul.source_url);
	}

 //Ben nejat yilan


	return 0;
}

