
/*************************************************************************
                           Cartography  -  description
                             -------------------
    début                : 7 oct. 2013
    copyright            : (C) 2013 par ymarion1
*************************************************************************/

//---------- Réalisation de la classe <Cartography> (fichier B3107_class.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "B3107_class.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Cartography::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Cartography::Display ()
{
	cout << "azerty" << endl;
	for(long i = 1; i <= last; i++)
	{
		cout << tab_mesure[i].x << " " << tab_mesure[i].y << " "  << tab_mesure[i].dmp << endl;
	}
}

void Cartography::Add(float x1, float y1, char *dmp1)
{
	Mesure mes1 = { dmp1, x1, y1 };
	if(last==tailleMax)
	{
		tailleMax += TAILLE_STD;
		Mesure temp[tailleMax];
		for(long i=0; i<last; i++)
		{
			temp[i]=tab_mesure[i];
		}
		tab_mesure = temp;
		last++;
		tab_mesure[last] = mes1;
		// Delete temp ?
	}
	else if(last < tailleMax)
	{
		last++;
		tab_mesure[last] = mes1;
	}
}

long Cartography::Count()
{
	return last;
}

long Cartography::Count(char *dmp1)
{
	Mesure *pointeur = tab_mesure;
	int nb_Valeur = 0;
	for(long i = 0; i < last; i++)
	{
		if(*dmp1 == *pointeur->dmp)
		{
			nb_Valeur++;
		}
		pointeur++;
	}
	return nb_Valeur;
}

char* Cartography::GetData(float x1, float y1)
{
	for(long i=0 ; i < last ; i++)
	{
		if(x1==tab_mesure[i].x && y1==tab_mesure[i].y)
		{
			return tab_mesure[i].dmp;
		}
	}
	return '\0';
}

long Cartography::FindDMP(char *dmp1, int index, float &x1, float &y1)
{
	for(long i=index+1 ; i <= last ; i++)
	{
		if(dmp1 == tab_mesure[i].dmp)
		{
			cout << "Hello ! "<< i << endl;
			x1 = tab_mesure[i].x;
			y1 = tab_mesure[i].y;
			return i-1;
		}
	}
	return -1;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Cartography::Cartography ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cartography>" << endl;
#endif
	last = 0;
	TAILLE_STD = 64;
	tailleMax = TAILLE_STD;
	tab_mesure = new Mesure[tailleMax];
	dmp = new char;


} //----- Fin de Cartography


Cartography::~Cartography ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cartography>" << endl;
#endif
} //----- Fin de ~Cartography


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

