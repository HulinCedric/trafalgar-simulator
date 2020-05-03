//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Accesseurs de modification (Lot 2)
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"

// --- Placement d'un navire dans une zone de confrontation
//
void Trafalgar::placer (const string&  nomNavire, 
                        const Point&   P        ,
                        const Vecteur& V        )
{
    // Controler la validite du premier parametre
    //
	if (nomNavire.size() == 0)	throw -3.0;
	
	// Controler la presence du navire cible dans la simulation
	//
	if(obtenirNavire(nomNavire) == NULL)	throw -3.3;

	// Fixer la position initiale du navire cible
	//
	obtenirNavire(nomNavire)->position(P);
	
	// Fixer la vitesse initiale du navire cible
	//
	obtenirNavire(nomNavire)->vitesse(V);
}

   




