//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Service de debarquement
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"

// --- Service de debarquement
//
int Navire::debarquer(Ile* pIle, const string& flotte, const Point& positionCible, int effectif)
{
	// Controler la validite de l'objet support
	//
	if (nok())	throw -2.0;
	
	// Controler la validite du premier parametre
	//
	if (pIle == NULL) throw -2.1;
	
	// Controler la validite du second parametre
	//
	if (flotte.size() == 0) throw -2.2;
	
	// Controler la validite du quatrieme parametre
	//
	if (effectif < 0) throw -2.4;
	if (effectif > nbSoldats())	effectif=nbSoldats();
	
	// Calculer les pertes du debarquement
	//
	int pertes= calculerPertes(pIle, effectif);
	
	// Retirer les effectifs donnee en parametre
	//
	nbSoldats(nbSoldats()-effectif);
	
	// Restituer le resultat
	//
	return pertes;
}