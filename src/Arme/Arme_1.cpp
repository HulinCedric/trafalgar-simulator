//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Arme - Constructeurs et methode toString
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Arme.h"

// --- Constructeur par defaut
//
Arme::Arme()
{
	m_numero=0;
	m_puissance=0;
	m_munitions=0;
	m_precision=0;
	m_etatArme= CASSER;
}

Arme::Arme(typeArmes type)
{
	// Controle de validite du parametre
	//
	if(!_Trafalgar::validiteTypeArmes(type))	throw -2.1;
	
	switch (type)
	{
		// Afectation de parametre pour une Amre de type MITRAILLEUSE
		//
		case MITRAILLEUSE:
			m_puissance= 5;
			m_munitions= 500;
			m_precision= 5;
			break;
			
		// Afectation de parametre pour une Arme de type LANCE_ROQUETTES
		//
		case LANCE_ROQUETTES:
			m_puissance= 50;
			m_munitions= 50;
			m_precision= 10;
			break;
			
		// Afectation de parametre pour une Arme de type CANON
		//
		case CANON:
			m_puissance= 200;
			m_munitions= 10;
			m_precision= 20;
			break;
		default:
			break;
	}
	// Valuer le type de l'arme
	//
	m_type = type;
	
	// Valuer le numero de l'Arme
	//
	m_numero=_Trafalgar::numeroArme();

	// Valuer l'etat courant
	//
	m_etatArme= FONCTIONNELLE;
}

char* Arme::toString() {

	char* pBuffer = new char[20];
	if(pBuffer == NULL) throw -1.0;
	
	// Controler le cas particulier de l'element neutre
	//
	if (neutre()) strcpy(pBuffer, "---");
	
	// Controler le cas d'une arme Fonctionnelle
	//
	else if (m_etatArme == FONCTIONNELLE)
		sprintf(pBuffer, "[[FONCTIONNELLE][N° : %d][Puissance : %d][Munition : %d][Precision : %d]]", m_numero, m_puissance, m_munitions, m_precision);
	else
		sprintf(pBuffer, "[[CASSER][N° : %d][Puissance : %d][Munition : %d][Precision : %d]]", m_numero, m_puissance, m_munitions, m_precision);

	return pBuffer;
}