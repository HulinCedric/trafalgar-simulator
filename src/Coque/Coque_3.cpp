//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Coque - Surchage d'opérateurs =, ==, !=
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Coque.h"

bool Coque::operator ==(const Coque& C)
{
	// Controler l'objet support
	//
	if(nok())	throw -2.0;
	
	// Controler chaque attribut entre eux
	//
	if(	m_longueur  ==	C.longueurNavire()	&&
		m_largeur	==	C.largeurNavire()	&&
		m_poids		==	C.poidsNavire()		&&
		m_profil	==	C.profilNavire()	&&
		m_furtivite	==	C.furtiviteNavire()	&&
		m_propulsion==	C.propulsionNavire()&&
		m_puissance	==	C.puissanceNavire()	&&
		m_vitesse	==	C.vitesseNavire()	&&
		m_aisance	==	C.aisanceNavire())	return true;

	return false;
}

bool Coque::operator != (const Coque& C) {return !(*this == C);}
