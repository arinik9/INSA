#include "LectureEcriture.h"
#include "Graph.h"
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{

	int nbarg=argc;
	string nomFichier=argv[nbarg-1]; // sans option için kullandim, if'in kosullarindan biri olcak
	Graph g;
	LectureEcriture l(nomFichier);
// -l option'u her zaman -t den sonra gelcek !!
		while(!l.EstFini())
	{
		UnLog ul;
		ul=l.ProchainLog();
		if(ul.aQuelHeure != "" && ul.cible_url != "" && ul.extension != "" && ul.source_url!= ""){
			g.Ajouter(ul.aQuelHeure,ul.cible_url,ul.extension,ul.source_url);
		}
	}
		//g.OptionT(18);
		//cout << g;
		//g.sansOption();
		cout << "--------------------- "  << endl;

		//cout << g;
		cout << "--------------------- "  << endl;
		g.OptionL(200);
		//g.OptionT(18);
		cout << g;

	cout<<"ARG-C "<<argc<<endl;
	//copy(argv,argv+argc-1,ostream_iterator<char *>(cout,";"));

	int k=1;

	while (k<argc)
			    {
		stringstream ss;
		string s;
		ss <<argv[k] ;
		ss >> s;
				if(s.compare("-x") == 0)
				{
					cout << "-x gordum";
					//işlemler ....
				}
				if(s.compare("-t") == 0)
				{
					string b;
					b += argv[k+1];
					int c=atoi(b.c_str());
					if(c>=0 && c<=23)
					{
						cout << "-t gordum sonrasında 0-23 arası sayı ile ! " << endl;
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
					if(c>0)
					{
						cout << "-l gordum sonrasında 0'dan büyük  sayı ile ! " << endl;
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
					if(ss.compare("mahmut") == 0)
					{
						cout << "-g gordum mahmut yazısı ile" << endl;
						//işlemler ....
					}
					else{
						//bunun if i de else'i de zor.
					}
				}
				else{
					//yukarı da k ları güzel artırırsak burası işe yarar.
					// yani -t den sonra 12e bakmadan sonraki optiona bakar.
				}
				printf("argv = %s\n" ,argv[k]);
				k++;
			    }

		  return 0;
}
