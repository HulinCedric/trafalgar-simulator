//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Service diffuser
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"

// --- Diffuse l'etat des Iles
//
map <string, Ile*>   Trafalgar::diffuser ()
{
	// Controler que la simulation temps reel est active
	//
	if(m_status == false) throw -3.1;
	
	// Restituer le resultat
	//
	return m_pIles;
}

// --- Diffuse l'etat des Navires
//
map <string, Navire*> Trafalgar::diffuser (const string& flotte)
{
	// Controler que la simulation temps reel est active
	//
	if(m_status == false) throw -3.1;
	
	// Controler le premier parametre
	//
	if(flotte.length() == 0) throw -2.1;

	// Restituer le resultat
	//
	return m_pNavires;
}
