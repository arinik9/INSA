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
	bool booleanT=false,booleanL=false,booleanG=false,booleanX=false,error=false;
	bool boolFichierVide=false;
	int CombienFoisOptionL=0,CombienFoisOptionX=0,CombienFoisOptionG=0,CombienFoisOptionT=0;
	int CombienFoisFichierLog=0,CombienFoisFichierDot=0;
	//cout<<"ARG-C "<<argc<<endl;
	//copy(argv,argv+argc-1,ostream_iterator<char *>(cout,";"));

bool boolfichierExiste=false;
 int k=1;
 int hour=0,hitSup=0;
 string pathDot;
 string nomFichier;


while (k<argc ) 
{
	stringstream ss;
	string s;
	ss << argv[k] ;
	ss >> s;
	int sizeS=s.size();
			if(s.compare("-x") == 0)
			{
				CombienFoisOptionX++;
				//cout << "-x gordum"<< endl;
				booleanX = true;
				//işlemler ....
			}
			else if(k != argc-1 && s.compare("-t") == 0)
			{

				CombienFoisOptionT++;
				string b;
				b += argv[k+1];

				int c=atoi(b.c_str());

				stringstream hh;
								string h;
								   hh << c;
								   hh >> h;

				if(b.length()==h.length() && (b == "0" || (c>0 && c<=23)))
				{
					booleanT = true;
					hour=c;
					//cout  <<"-t gordum sonrasında 0-23 arası sayı ile ! " << endl;
					//işlemler ....
				}
				else
				{
					error=true;
				}
			}
			else if(k != argc-1 && s.compare("-l") == 0)
			{
				CombienFoisOptionL++;
				string b;
				b += argv[k+1];
				int c=atoi(b.c_str());

				stringstream hh;//create a stringstream
						string h;
						   hh << c;
						   hh >> h;

				//cout << "c'nin deger: " << c+1 << endl;
				if(b.length()==h.length() && c>0)
				{
					booleanL = true;
					hitSup=c;
					//cout << "-l gordum sonrasında 0'dan büyük sayı ile ! " << endl;
					//işlemler ....
				}
				else
				{
					error=true;
					//-l den sonra gelen kısım sayı degil ya da 0dan kucuk. ona gore kontrol flagleri koyarız.
				}
			}
			else if(s.compare("-g") == 0)
			{
				CombienFoisOptionG++;
				stringstream sss;
				string ss;
				sss << argv[k+1] ;
				sss >> ss;
				int sizeSS=ss.size();
				if(sizeSS >= 5 && ss.substr(sizeSS-4,4)==".dot")
				{
					CombienFoisFichierDot++;
						pathDot=ss;
						booleanG = true;
						//cout << "-g gordum .dot uzantisiyla" << endl;
						//işlemler ....
				}
				else{

					error=true;
						//bunun if i de else'i de zor.
				}
			}
			else if(sizeS >= 5 && s.substr(sizeS-4,4) == ".log")
				{ //2 tane ananoyme.log yazarsa nolur?
				CombienFoisFichierLog++;

				ifstream my_file(s.c_str());
				 if (my_file.good()) // if le fichier .log est lisible et exist
				 {
					 my_file.seekg(0,ios::end);
					size_t size = my_file.tellg();
					if( size == 0)
					{
					boolFichierVide=true;
					boolfichierExiste=true;
					}
					else if(size != 0){
					 nomFichier=s;
					 boolfichierExiste=true;
					// argc=-1;  // while'den ciksin diye
					}
				 }
				 else{
					 error=true;
					 argc=-1;   // while'den ciksin diye
				 }
				}
			else{  // mesela -glt gibi bir commande yazarsa, ya da -g option'suz "abc.dot" file yazarsa

				stringstream dd;
				string d;
				dd << argv[k-1];
				dd >> d;
				if(d.compare("-g") == 0 || d.compare("-t") == 0 || d.compare("-l") == 0){
					if(error==true) // daha onceden true ise true olarak kalsin, zaten error varmis
					error=true;		//daha onceden error yoksa false olarak kalsin, yani hic biseyi degistirmesin bu if else
				}
				else{
					//cout << "cas d'error" << endl;
					error=true;
				}


			//Mahmut'un yorumu:
				//yukarı da k ları güzel artırırsak burası işe yarar.
				// yani -t den sonra 12e bakmadan sonraki optiona bakar.
			}
			//printf("argv = %s\n" ,argv[k]);
			k++;
 }

 if(CombienFoisOptionG>1 || CombienFoisOptionT>1 || CombienFoisOptionL>1 || CombienFoisOptionX>1 || CombienFoisFichierDot>1 || CombienFoisFichierLog>1){
				cout << "plusieurs fois meme option" << endl;
				error=true;
			}

	//cout << "--------------------- "  << endl;
	//cout << "--------------------- "  << endl;


if(!boolfichierExiste){
 	cout << "pas de fichier ajouté!! " << endl;
 	return 1;
}

else if(boolfichierExiste && boolFichierVide && !error){
	 cout << "Fichier est vide \n" << endl;
  	return 2;
 }

else if(boolfichierExiste && error){
 	 cout << "Error! \n" << endl;
   	return 3;
}

else if(boolfichierExiste && !error && !boolFichierVide){
	Graph g;
	LectureEcriture l(nomFichier);

	set <string> setExtension;
		while(!l.EstFini())
	{
		UnLog ul;
		ul=l.ProchainLog();
		if(ul.aQuelHeure != "" && ul.cible_url != "" && ul.extension != "" && ul.source_url!= ""){
			g.Ajouter(ul.aQuelHeure,ul.cible_url,ul.extension,ul.source_url);
			if(ul.extension!="jpg" && ul.extension!="ico" && ul.extension!="ics" && ul.extension!="png" && ul.extension!="gif") //css
			setExtension.insert(ul.extension);
		}
	}

		if( booleanT == true){
			g.OptionT(hour);
		}
		if( booleanX == true){
			g.OptionX(setExtension);
		}
		if( booleanL == true){
			g.OptionL(hitSup);
		}
		if( booleanG == true){
			g.OptionG(pathDot,booleanG);
			booleanG=false;
		}
		g.sansOption(booleanG);

   return 0;
	}

}
