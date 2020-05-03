//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Accesseurs de modification (Lot 4)
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"

// --- Modification de l'etat de la meteo lié a une Ile
//
void Trafalgar::modifierMeteo(const string& nomIle, etatMeteo nouvelEtat) 
{	
	// Controler que la simulation temps reel est active
	//
	if (m_status == false)	throw -3.1;
	
	// Controler la validite du premier parametre
    //
	if (nomIle.size() == 0)	throw -2.1;
	
	// Controler l'appartenance de l'ile cible a la simulation
	//
	if(obtenirIle(nomIle) == NULL)	throw -3.4;
	
	// Controler la validite du deuxieme parametre
	//
	if (!_Trafalgar::validiteEtatMeteo(nouvelEtat))	throw -2.2;
	
	// Affecter le nouvel etat meteo
	//
	obtenirIle(nomIle)->modifierMeteo(nouvelEtat);
}