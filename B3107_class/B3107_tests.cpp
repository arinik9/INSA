/*************************************************************************
                           B3107_tests  -  description
                             -------------------
    début                : 7 oct. 2013
    copyright            : (C) 2013 par ymarion1
*************************************************************************/

//---------- Réalisation de la classe <B3107_tests> (fichier B3107_tests.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "B3107_class.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int main()
{
	cout << "coucou" << endl;
	Cartography cart;
	cart.Add(124.5, 60, (char*)"h2o");
	cart.Add(128, 45789.54, (char*)"SiO2");
	cart.Add(124.6, 60, (char*)"h2o");
	cart.Add(300, -456.2, (char*)"SiO2");

	cart.Display();



	float fX(124.5);
	float fY(60);
	long lPos= cart.FindDMP((char*)"SiO2",4,fX,fY);
	cout << lPos<< fX << " " << fY << endl;
	//fX=300;
	//fY=-465.2;
	//long lPos=cart.FindDMP((char*)"SiO2",0,&fX,&fY);
	//cout << lPos << endl;
	char *tabc;
	tabc=cart.GetData(124.6,60);
	cout << *tabc<<*(tabc+1) << endl;


}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

