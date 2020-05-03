//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Coque - Accesseurs de modification degat
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Coque.h"

// --- Application de degat
//
void Coque::degat(int nouveauDegat)
{
	if (etat() == COULE)	return;
	
	// Controler l'objet support
	//
	if (nok())	throw -2.0;
	
	// Controler la validite du parametre
	//
	if (nouveauDegat < 0) throw -2.1;
	
	// Controler le degat infligé
	// 
	if (nouveauDegat > m_flottabilite) nouveauDegat= m_flottabilite;
	
	// Appliquer les degat sur la coque
	//
	m_flottabilite-= nouveauDegat;
}


