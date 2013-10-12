//============================================================================
// Name        : deneme1.cpp
// Author      : mc
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <string.h>

int main() {
	cout << "!!!Hello World!!! \n \t sadas"<<	sizeof(double) << endl; // prints !!!Hello World!!!
	enum aylar{ocak=3,subat,mart=3};
	cout << ocak << subat << mart << endl; // prints !!!Hello World!!!

	int tab [6]={11,22,33,44,55,66};
	for(int i=0;i<6;i++)
	{
		cout << tab[i]<< endl;
	}

	char ch='a';
	char *pt;
	pt=&ch;
	*(pt+1)='x';
	char * *p1;
	p1=&pt;


	char tablo[]="Mahm \0ut12344";
	cout << sizeof(tablo)<<',' << ','<<*((*p1)+1) <<	strlen(tablo)<< *(pt+1)<< endl ;
	for(int i=0;i<6;i++)
		{
		//	cout << tablo[i]<< endl;
		}
	char tablo2[]= "Mahmute";
	tablo2[0]='x';
	for(int i=0;i<7;i++)
		{
			cout << tablo2[i]<< endl;
		}
	return 0;
}
