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

int main(int argc, char *argv[])// hocaninki:  int argc,char **lstarg
{
	bool booleanT=false,booleanL=false,booleanG=false,booleanX=false;
///	cout<<"ARG-C "<<argc<<endl;
	//copy(argv,argv+argc-1,ostream_iterator<char *>(cout,";"));

bool boolfichier=false;
 int k=1;
 int hour,hitSup;
 string pathDot;
 string nomFichier;
while (k<argc)
{
	stringstream ss;
	string s;
	ss <<argv[k] ;
	ss >> s; // string'e donusturmus olduk
	int sizeS=s.size();
	//cout << "size: "<<sizeS << endl;
			if(s.compare("-x") == 0)
			{
				cout << "-x gordum";
				booleanX = true;
				//işlemler ....
			}
			if(s.compare("-t") == 0)
			{
				string b;
				b += argv[k+1];
				int c=atoi(b.c_str());
				if(b == "0" || (c>0 && c<=23))
				{
					booleanT = true;
					hour=c;
					cout  <<"-t gordum sonrasında 0-23 arası sayı ile ! " << endl;
					//işlemler ....
				}
				else
				{
					//-t den sonra gelen kısım sayı degil. ona gore kontrol flagleri koyarız.
				}
			}
			if(s.compare("-l") == 0)
			{
				string b;
				b += argv[k+1];
				int c=atoi(b.c_str());
				//cout << "c'nin deger: " << c+1 << endl;
				if(c>0)
				{
					booleanL = true;
					hitSup=c;
					cout << "-l gordum sonrasında 0'dan büyük sayı ile ! " << endl;
					//işlemler ....
				}
				else
				{
					//-l den sonra gelen kısım sayı degil ya da 0dan kucuk. ona gore kontrol flagleri koyarız.
				}
			}
			if(s.compare("-g") == 0)
			{
				stringstream sss;
				string ss;
				sss << argv[k+1] ;
				sss >> ss;
				int sizeSS=ss.size();
				if(ss.substr(sizeSS-4,4)==".dot")
				{
						pathDot=ss;
						booleanG = true;
						cout << "-g gordum .dot uzantisiyla" << endl;
						//işlemler ....
				}
				else{
						//bunun if i de else'i de zor.
				}
			}
			if(sizeS >5 && s.substr(sizeS-4,4) == ".log")
				{//2 tane ananoy,e.log yazarsa nolur?
					nomFichier=s;
					boolfichier=true;
							//işlemler ....
				}
			else{
				//yukarı da k ları güzel artırırsak burası işe yarar.
				// yani -t den sonra 12e bakmadan sonraki optiona bakar.
			}
		//	printf("argv = %s\n" ,argv[k]);
			k++;
 }

;
if(boolfichier){

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
			//g.OptionG(pathDot);
			g.OptionGTop10(pathDot,booleanG);
		//	g.sansOption(); // use for sort output also
			booleanG=false;
		}
		g.sansOption(booleanG);

   }
   return 0;
}
