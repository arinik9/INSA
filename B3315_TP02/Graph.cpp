#include "Graph.h"

nbHit_Horaires & nbHit_Horaires::operator = (const nbHit_Horaires & nbh)
{
	if (this != &nbh)
	{
		for(int i=0;i<24;i++)
		{
			this->heures[i]=nbh.heures[i];
		}
		extension=nbh.extension;
	}
	return (*this);
}


ostream & operator << (ostream & os, const Graph & g) {
	map<string, nbHit_Horaires> ::const_iterator iterRef;
	map<string, map<string, nbHit_Horaires> >::const_iterator iter;


	for ( iter=g.analyse.begin() ; iter != g.analyse.end(); iter++ ) {
	    os << "\n\nNew element\n" << iter->first << endl;
	    for( iterRef=iter->second.begin(); iterRef != iter->second.end(); iterRef++)
	      os << iterRef->first << endl; // (*iterCible).second.extension
	}

	  return os;
}

void Graph::Ajouter(string aQuelHeure,string cible_url,string extension,string source_url)
{
        string s = aQuelHeure;
       // cout << source_url << " kaynak " << extension <<  " " <<  cible_url<< " hedef " << endl;
        int hour = atoi(s.c_str());
	if(analyse.find(cible_url) == analyse.end())
	{
			nbHit_Horaires a={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},""};
			a.extension=extension;
			a.heures[hour-1]++;
		analyse[cible_url][source_url]=a;
	}
	else{
		if (analyse.find(cible_url)->second.find(source_url) == analyse.find(cible_url)->second.end())
		{
							nbHit_Horaires a;
							a=analyse[cible_url][source_url];
							a.heures[hour-1]++;
							analyse[cible_url][source_url]=a;
		}
		else{
								nbHit_Horaires a;
								a=analyse[cible_url][source_url];
								a.heures[hour-1]++;
								analyse[cible_url][source_url]=a;
		     }


	     }

		nbHit_Horaires a;
		a=analyse[cible_url][source_url];
		cout << " - " <<a.extension << " saat " << a.heures[1] <<endl; // output deneme 

}

Graph::Graph() {
	// TODO Auto-generated destructor stub
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}
