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

int nbHit_Horaires::totalHeures(){
	int sum=0;
	for(int i=0; i<24; i++){
	sum+=heures[i];
	}
	return sum;
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
		if(analyse.find(cible_url) == analyse.end()  || analyse.find(cible_url)->second.find(source_url) == analyse.find(cible_url)->second.end())
		{
				nbHit_Horaires a={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},""};
				a.extension=extension;
				a.heures[hour-1]++;
			analyse[cible_url][source_url]=a;
		}
		else{
				nbHit_Horaires a;
				a=analyse[cible_url][source_url];
				a.heures[hour-1]++;
				analyse[cible_url][source_url]=a;
			}

			nbHit_Horaires a;
			a=analyse[cible_url][source_url];
	//cout << "saat: " <<hour-1 << "    uzanti: " <<a.extension <<  "	" << " hit sayisi: " << a.heures[10] <<endl;

}

void Graph::sansOption(){
	int sum=0;
	int size=analyse.size(); 
	vector<pair<int,string> > vec(size);

	map<string, nbHit_Horaires> ::const_iterator iterRef;
		map<string, map<string, nbHit_Horaires> >::const_iterator iter;

		for ( iter=analyse.begin() ; iter != analyse.end(); iter++ ){
		    for( iterRef=iter->second.begin(); iterRef != iter->second.end(); iterRef++){
		    	nbHit_Horaires nbStruct = iterRef->second; //  totalHeures() metodu nbHit_Horaires struct'u icin gecerli, ondan tanimladim
		    	sum= nbStruct.totalHeures();
		    	vec.push_back(pair<int,string>(sum,iter->first));
		    }
		}

		if(size > 15){
			sort(vec.rbegin(),vec.rbegin()+15);// size() yerine 15'de yazabilirdim ama belki cible key 15'ten azdir diye boyle yaptm
			vec.erase(vec.begin()+15,vec.end());
		}
		else{
			sort(vec.rbegin(),vec.rend());
		vec.erase(vec.begin()+size,vec.end());
		     }
		for(vector<pair<int,string> >::const_iterator i = vec.begin(); i != vec.end(); ++i){
				cout << i->second << "  " << "(" << i->first << " hits)" << endl;
			}

}

Graph::Graph() {
	// TODO Auto-generated destructor stub
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}
