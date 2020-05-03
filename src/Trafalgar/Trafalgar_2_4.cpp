//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Accesseurs de modification (Lot 3)
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"

// --- Installation de troupes sur une Ile
//
void Trafalgar::installer (const string& nomNavire, 
						   const string& nomIle, 
						   int effectif				)
{
    // Controler la validite du premier parametre
    //
	if (nomNavire.size() == 0)	throw -2.1;
	
	// Controler la validite du deuxieme parametre
    //
	if (nomIle.size() == 0)	throw -2.2;
	
	// Controler la validite du deuxieme parametre
    //
	if (effectif < 0)	throw -2.3;
	
	// Controler la presence du navire cible dans la simulation
	//
	if(obtenirNavire(nomNavire) == NULL)	throw -3.3;
	
	// Controler la presence du navire cible dans la simulation
	//
	if(obtenirIle(nomIle) == NULL)	throw -3.4;
	
	// Installer les troupes
	//
	obtenirIle(nomIle)->ajouterTroupes(obtenirNavire(nomNavire)->flotte(), *obtenirIle(nomIle)->lieux()->sommet(_Trafalgar::alea(1,3)), effectif);
}






