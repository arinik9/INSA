#include "Graph.h"


void Graph::Ajouter(string aQuelHeure,string cible_url,string extension,string source_url)
{
	string s = aQuelHeure;
	int hour = atoi(s.c_str());
				if(analyse.find(source_url) == analyse.end())
				{
					nbHit_Horaires a;
					a.extension=extension;
					a.heures[hour-1]++;
					analyse.insert(make_pair(source_url,make_pair(cible_url,a)));
				}
			else{
					if (analyse.find(source_url)->second.find(cible_url) == analyse.find(source_url)->second.end())
					{
						nbHit_Horaires a;
						a.extension=extension;
						a.heures[hour-1]++;
						analyse.find(source_url)->second.insert(make_pair(cible_url,a));
					}
					else;
				}
}


Graph::~Graph() {
	// TODO Auto-generated destructor stub
}
