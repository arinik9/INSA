#include "Graph.h"
#include <set>

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
	nbHit_Horaires nbStruct;
	map<string, nbHit_Horaires> ::const_iterator iterRef;
	map<string, map<string, nbHit_Horaires> >::const_iterator iter;
	//int size=g.analyse.size();
	for ( iter=g.analyse.begin() ; iter != g.analyse.end(); iter++ ) {
		int sum=0;
	    for( iterRef=iter->second.begin(); iterRef != iter->second.end(); iterRef++){
	    	nbStruct = iterRef->second ; //  totalHeures() metodu icin gecerli, ondan tanimladim
	    sum += nbStruct.totalHeures();
	    }
	    if(sum != 0)
	    os << iter->first << "   " << "("<<sum << " Hits)"<< endl; // (*iterCible).second.extension
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
		//	cout << "if'in yaptigi" << endl;
				nbHit_Horaires a={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},""};
				a.extension=extension;
				a.heures[hour]++;

			analyse[cible_url][source_url]=a;
		//	cout << "cible: " << cible_url << "referer: " << source_url << " hour:" <<  hour << endl;
		}

		else if(analyse.find(cible_url)->second.find(source_url) == analyse.find(cible_url)->second.end()){
			//cout << "else if'in yaptigi" << endl;
			nbHit_Horaires a={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},""};
							a.extension=extension;
							a.heures[hour]++;
						analyse[cible_url][source_url]=a;
				//		cout << "cible: " << cible_url << "referer: " << source_url << " hour:" <<  hour << endl;
		}

		else{
			//cout << "else'in yaptigi" << endl;
				nbHit_Horaires a;
				a=analyse[cible_url][source_url];
				a.heures[hour]++;
				analyse[cible_url][source_url]=a;
				//cout << "cible: " << cible_url << "referer: " << source_url << " hour:" <<  hour << endl;
			}
}

vector<pair<int,string> > Graph::sansOption(){

	int size=analyse.size(); // le nombre de 'key' de Cible
	vector<pair<int,string> > vec(size);

	map<string, nbHit_Horaires> ::const_iterator iterRef;
		map<string, map<string, nbHit_Horaires> >::const_iterator iter;

		for ( iter=analyse.begin() ; iter != analyse.end(); iter++ ){
			int sum=0;
		    for( iterRef=iter->second.begin(); iterRef != iter->second.end(); iterRef++){
		    	nbHit_Horaires nbStruct = iterRef->second; //  totalHeures() metodu icin gecerli, ondan tanimladim
		    	sum += nbStruct.totalHeures();
		    }
		    vec.push_back(pair<int,string>(sum,iter->first));
		}

		cout << "message" << endl;

		if(size > 10){
			sort(vec.rbegin(),vec.rend());// size yerine 10'de yazabilirdim ama belki cible key 10'ten azdir diye boyle yaptm
			vec.erase(vec.begin()+10,vec.end());
		}
		else{
			sort(vec.rbegin(),vec.rend());
			vec.erase(vec.begin()+size,vec.end());
		}

		for(vector<pair<int,string> >::const_iterator i = vec.begin(); i != vec.end(); ++i){
				cout << i->second << "  " << "(" << i->first << " hits)" << endl;
			}

		return vec;
}

void Graph::OptionL(int nbHitSup){

		map<string, nbHit_Horaires> ::iterator iterRef;
			map<string, map<string, nbHit_Horaires> >::iterator iter;

			for ( iter=analyse.begin() ; iter != analyse.end();){
				int sum=0;
			    for( iterRef=iter->second.begin(); iterRef != iter->second.end(); iterRef++){
					for(int i=0; i<24; i++){
							sum+=iterRef->second.heures[i];
							}
			    }
			    if(sum <= nbHitSup){
			    analyse.erase(iter++);
			    }
			    else
			    	++iter;
			}
}


void Graph::OptionT(int heure){
	map<string, nbHit_Horaires> ::iterator iterRef;
				map<string, map<string, nbHit_Horaires> >::iterator iter;

				for ( iter=analyse.begin() ; iter != analyse.end();iter++){
				    for( iterRef=iter->second.begin(); iterRef != iter->second.end(); iterRef++){
							for(int i=0;i<24;i++){ // gerekli olan saati bir tek sifirlamadik
								if(i!=heure)
								iterRef->second.heures[i]=0;
							}
				    }
				}
}


void Graph::CombienDifferentExtension(){
	int count=0;
	map<string, nbHit_Horaires> ::iterator iterRef;
					map<string, map<string, nbHit_Horaires> >::iterator iter;
			set <string,less<string> > st1;
			set <string>::iterator st1_Iter;
					for ( iter=analyse.begin() ; iter != analyse.end(); iter++ ){
					    for( iterRef=iter->second.begin(); iterRef != iter->second.end(); iterRef++){
					    	//if ! iterRef->second.extension=="jpeg ou png ou .."
					        	st1.insert(iterRef->second.extension);
					    }
					}
					for(st1_Iter = st1.begin(); st1_Iter != st1.end(); st1_Iter++){
						count++;
					cout<<*st1_Iter << endl;
					}
					cout << count<<endl;
}


int Graph::GetSize(){
	return analyse.size();
}

Graph::Graph() {
	// TODO Auto-generated destructor stub
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}
