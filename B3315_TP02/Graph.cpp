#include "Graph.h"


void Graph::Ajouter(string aQuelHeure,string cible_url,string extension,string source_url)
{
	string s = aQuelHeure;
	int hour = atoi(s.c_str());
				if(analyse.find(source_url) == analyse.end())
				{
					nbHit_Horaires a={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},""};
					a.extension=extension;
					a.heures[hour-1]++;
					analyse[source_url][cible_url]=a;
				}
			else{
					if (analyse.find(source_url)->second.find(cible_url) == analyse.find(source_url)->second.end())
					{
						nbHit_Horaires a;
						a.extension=extension;
						a.heures[hour-1]++;
						analyse[source_url][cible_url]=a;
					}
					else;
				}
}


Graph::~Graph() {
	// TODO Auto-generated destructor stub
}
