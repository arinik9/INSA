/*************************************************************************
                           Cartography  -  description
                             -------------------
    début                : 7 oct. 2013
    copyright            : (C) 2013 par ymarion1
*************************************************************************/

//---------- Interface de la classe <Cartography> (fichier B3107_class.h) ------
#if ! defined ( B3107_CLASS_H_ )
#define B3107_CLASS_H_
#define MAP

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
struct Mesure
{
	char *dmp;
	float x;
	float y;
};

//------------------------------------------------------------------------ 
// Rôle de la classe <Cartography>
//
//
//------------------------------------------------------------------------ 

class Cartography
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
void Display();

void Add(float x1, float y1, char *dmp1);

long Count();

long Count(char *dmp1);

char* GetData(float x1, float y1);

long FindDMP(char *dmp1, int index, float *x1, float *y1);

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


    Cartography ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Cartography ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    long tailleMax;
    int TAILLE_STD;
    long last;
    Mesure *tab_mesure;



};

//--------------------------- Autres définitions dépendantes de <Cartography>

#endif // B3107_CLASS_H_

