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
	int size=g.analyse.size(); // le nombre de 'key' de Cible
		vector<pair<int,string> > vec(size);

	nbHit_Horaires nbStruct;
	map<string, nbHit_Horaires> ::const_iterator iterRef;
	map<string, map<string, nbHit_Horaires> >::const_iterator iter;
	for ( iter=g.analyse.begin() ; iter != g.analyse.end(); iter++ ) {
		int sum=0;
	    for( iterRef=iter->second.begin(); iterRef != iter->second.end(); iterRef++){
	    	nbStruct = iterRef->second ;
	    sum += nbStruct.totalHeures();
	    }
	    if(sum!=1) //sum!=0 yapmak lazim
	    vec.push_back(pair<int,string>(sum,iter->first));
	   // os << iter->first << "   " << "(dfdf "<<sum << " Hits)"<< endl; // (*iterCible).second.extension
	}

	//HATA VAR sort'da
	sort(vec.rbegin(),vec.rend());
	//vec.erase(vec.begin()+size,vec.end());
	vec.resize(size);

	for(vector<pair<int,string> >::const_iterator i = vec.begin(); i != vec.end(); ++i){
		os << i->second << "  " << "(" << i->first << " hits)" << endl;
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

vector<pair<int,string> > Graph::sansOption(bool flag){

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

		if(size > 10){
			sort(vec.rbegin(),vec.rend());// size yerine 15'de yazabilirdim ama belki cible key 15'ten azdir diye boyle yaptm
			vec.erase(vec.begin()+10,vec.end());
		}
		else{
			sort(vec.rbegin(),vec.rend());
			//vec.resize(size);
			vec.erase(vec.begin()+size,vec.end());
		}

		if(!flag){
		for(vector<pair<int,string> >::const_iterator i = vec.begin(); i != vec.end(); ++i){
				cout << i->second << "  " << "(" << i->first << " hits)" << endl;
			}
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

				for ( iter=analyse.begin() ; iter != analyse.end(); ){
					int sum=0;
				    for( iterRef=iter->second.begin(); iterRef != iter->second.end(); ){
								if(iterRef->second.heures[heure] == 0){
									iter->second.erase(iterRef++);
											    }
								else{
									for(int i=0;i<24;i++){ // gerekli olan saati bir tek sifirlamadik
											if(i!=heure)
											iterRef->second.heures[i]=0;
										}
								    sum += iterRef->second.heures[heure];
									++iterRef;
								}
				    }
				 if(sum == 0)
					 analyse.erase(iter++);
				 else
					 ++iter;
				}
}


void Graph::OptionX(set<string> & setExt){

	map<string, nbHit_Horaires> ::iterator iterRef;
	map<string, map<string, nbHit_Horaires> >::iterator iter;
	set <string>::iterator set_iter;

	for ( iter=analyse.begin() ; iter != analyse.end();){
		bool flag=true;
						    for( iterRef=iter->second.begin(); iterRef != iter->second.end() && flag;iterRef++){
						    	//set_iter=setExt.find(iterRef->second.extension);
						    	if(setExt.find(iterRef->second.extension) == setExt.end()){
						    		//cout << iter->first << " eklenmedi! " << endl;
						   flag=false;
						    		}
						    	}
						   if(flag==false)
						    analyse.erase(iter++);
						    else
						    	++iter;
						}

	/*for(set_iter = setExt.begin(); set_iter != setExt.end(); set_iter++){
		cout<<*set_iter << endl;
	}*/
}


void Graph::OptionG(string pathDot){
	map<string, string> NodeUrl;
	map<string, nbHit_Horaires> ::iterator iterRef;
		map<string, map<string, nbHit_Horaires> >::iterator iter;
		int sum,count=0;
	ofstream myfile(pathDot.c_str());
	if(myfile.is_open())
		cout << "Le fichier isim.dot généré: " << endl;
		streambuf *file_buffer=myfile.rdbuf();
	streambuf *old_cout_buffer=cout.rdbuf(file_buffer);
	//envoyer une chaine a cout qui maintenant redirige sur le fichier
	cout << "digraph{" << endl;
	for ( iter=analyse.begin() ; iter != analyse.end();iter++){
		sum=0;
		 for( iterRef=iter->second.begin(); iterRef != iter->second.end();iterRef++){
			 nbHit_Horaires nbStruct = iterRef->second; //  totalHeures() metodu icin gecerli, ondan tanimladim
			sum += nbStruct.totalHeures();
			ostringstream temp1,temp2;  //temp as in temporary
			string result1,result2;

			if(NodeUrl.find(iterRef->first) == NodeUrl.end()){
				temp1<<count++;
				result1="node" + temp1.str();
				NodeUrl[iterRef->first]=result1;
				cout << NodeUrl[iterRef->first] << " [label=\""<< iterRef->first << "\"" << "];" << endl ;
			}

			if(NodeUrl.find(iter->first) == NodeUrl.end()){
				temp2<<count++;
				result2="node" +temp2.str();
				NodeUrl[iter->first]=result2;
				cout << NodeUrl[iter->first] << " [label=\""<< iter->first << "\"" << "];" << endl ;
			}
			 cout << NodeUrl[iterRef->first] << " -> "<< NodeUrl[iter->first] << "[label=" << sum << "];" << endl ;
		 }
	}


	cout << "}" << endl;
	cout.rdbuf(old_cout_buffer);
		myfile.close();
}


void Graph::OptionGTop10(string pathDot,bool flag){
	map<string, string> NodeUrl;
	map<string, nbHit_Horaires> ::iterator iterRef;
	map<string, map<string, nbHit_Horaires> >::iterator iter;
	vector<pair<int,string> > ve;
		vector<pair<int,string> >::const_iterator it;
		ve=sansOption(flag); // use for sort output also

		for ( iter=analyse.begin() ; iter != analyse.end();){
				for(it=ve.begin();it!=ve.end();it++){
					if(iter->first != it->second){
						analyse.erase(iter++);
					}
					else
						++iter;
				}
		}
//buraya kadar vector'de bulunmayan cible'leri analyse'den eledik
		OptionG(pathDot);
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
