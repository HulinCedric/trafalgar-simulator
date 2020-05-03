//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Ile - Accesseurs modifierMeteo
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Ile.h"

// --- Modification de l'etat de la meteo
//
void Ile::modifierMeteo(etatMeteo nouvelEtat) 
{	
	// Controler la validite du parametre
	//
	if (!_Trafalgar::validiteEtatMeteo(nouvelEtat))	throw -2.1;
	
	// Controler la progressivite de l'evolution
	//
	if (abs(m_etatMeteo - nouvelEtat) > 1) throw -2.1;
	
	// Affecter le nouvel etat meteo
	//
	m_etatMeteo= nouvelEtat;
}