//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Coque - Constructeurs et methode toString
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Coque.h"

// --- Constructeur par defaut
//
Coque::Coque() {

	m_longueur = 0;
	m_largeur = 0;
	m_poids = 0;
	m_profil = 0;
	m_furtivite = 0;
	m_flottabilite= 0;
	m_propulsion = 0;
	m_puissance = 0;
	m_vitesse = 0;
	m_aisance = 0;
	
	// Valuer l'etat courant
	//
	m_etatCoque= COULE;
}

// --- Constructeur normal
//
Coque::Coque(typeNavire type) 
{
	// Controle de validite du parametre
	//
	if(!_Trafalgar::validiteTypeNavire(type))	throw -2.1;

	switch (type)
	{
		// Afectation de parametre pour un Navire de type FREGATE
		//
		case FREGATE:
			m_longueur = 50;
			m_largeur = 50;
			m_poids = (m_longueur * m_largeur);
			m_profil = (m_poids / 100);
			if( m_profil <= 0) m_profil = 1;
			m_furtivite = 40;
			m_flottabilite= 100;
			m_propulsion = 3;
			m_puissance = m_propulsion * 10;
			m_vitesse = m_puissance * 10;
			m_aisance = m_vitesse / (m_longueur + m_largeur);
			if( m_aisance <= 0) m_aisance = 1;
			break;
			
		// Afectation de parametre pour un Navire de type FREGATE_DEFENSE_AERIENNE
		//
		case FREGATE_DEFENSE_AERIENNE:
			m_longueur = 150;
			m_largeur = 150;
			m_poids = (m_longueur * m_largeur);
			m_profil = (m_poids / 100);
			if( m_profil <= 0) m_profil = 1;
			m_furtivite = 20;
			m_flottabilite= 100;
			m_propulsion = 5;
			m_puissance = m_propulsion * 10;
			m_vitesse = m_puissance * 10;
			m_aisance = m_vitesse / (m_longueur + m_largeur);
			if( m_aisance <= 0) m_aisance = 1;
			break;
			
		// Afectation de parametre pour un Navire de type FREGATE_ANTI_SOUS_MARINE
		//
		case FREGATE_ANTI_SOUS_MARINE:
			m_longueur = 300;
			m_largeur = 300;
			m_poids = (m_longueur * m_largeur);
			m_profil = (m_poids / 100);
			if( m_profil <= 0) m_profil = 1;
			m_furtivite = 10;
			m_flottabilite= 100;
			m_propulsion = 8;
			m_puissance = m_propulsion * 10;
			m_vitesse = m_puissance * 10;
			m_aisance = m_vitesse / (m_longueur + m_largeur);
			if( m_aisance <= 0) m_aisance = 1;
			break;
		
		// Afectation de parametre pour un Navire de type CHASSEUR_DE_MINES
		//
		case CHASSEUR_DE_MINES:
			m_longueur = 50;
			m_largeur = 50;
			m_poids = (m_longueur * m_largeur);
			m_profil = (m_poids / 100);
			if( m_profil <= 0) m_profil = 1;
			m_furtivite = 40;
			m_flottabilite= 100;
			m_propulsion = 3;
			m_puissance = m_propulsion * 10;
			m_vitesse = m_puissance * 10;
			m_aisance = m_vitesse / (m_longueur + m_largeur);
			if( m_aisance <= 0) m_aisance = 1;
			break;
			
		// Afectation de parametre pour un Navire de type AVISO
		//	
		case AVISO:
			m_longueur = 50;
			m_largeur = 50;
			m_poids = (m_longueur * m_largeur);
			m_profil = (m_poids / 100);
			if( m_profil <= 0) m_profil = 1;
			m_furtivite = 40;
			m_flottabilite= 100;
			m_propulsion = 3;
			m_puissance = m_propulsion * 10;
			m_vitesse = m_puissance * 10;
			m_aisance = m_vitesse / (m_longueur + m_largeur);
			if( m_aisance <= 0) m_aisance = 1;
			break;
		
		// Afectation de parametre pour un Navire de type CORVETTE
		//		
		case CORVETTE:
			m_longueur = 50;
			m_largeur = 50;
			m_poids = (m_longueur * m_largeur);
			m_profil = (m_poids / 100);
			if( m_profil <= 0) m_profil = 1;
			m_furtivite = 40;
			m_flottabilite= 100;
			m_propulsion = 3;
			m_puissance = m_propulsion * 10;
			m_vitesse = m_puissance * 10;
			m_aisance = m_vitesse / (m_longueur + m_largeur);
			if( m_aisance <= 0) m_aisance = 1;
			break;
		
		// Afectation de parametre pour un Navire de type BPC
		//
		case BPC:
			m_longueur = 50;
			m_largeur = 50;
			m_poids = (m_longueur * m_largeur);
			m_profil = (m_poids / 100);
			if( m_profil <= 0) m_profil = 1;
			m_furtivite = 40;
			m_flottabilite= 100;
			m_propulsion = 3;
			m_puissance = m_propulsion * 10;
			m_vitesse = m_puissance * 10;
			m_aisance = m_vitesse / (m_longueur + m_largeur);
			if( m_aisance <= 0) m_aisance = 1;
			break;
		
		// Afectation de parametre pour un Navire de type CROISEUR
		//
		case CROISEUR:
			m_longueur = 50;
			m_largeur = 50;
			m_poids = (m_longueur * m_largeur);
			m_profil = (m_poids / 100);
			if( m_profil <= 0) m_profil = 1;
			m_furtivite = 40;
			m_flottabilite= 100;
			m_propulsion = 3;
			m_puissance = m_propulsion * 10;
			m_vitesse = m_puissance * 10;
			m_aisance = m_vitesse / (m_longueur + m_largeur);
			if( m_aisance <= 0) m_aisance = 1;
			break;
			
		// Afectation de parametre pour un Navire de type CUIRASSE
		//
		case CUIRASSE:
			m_longueur = 50;
			m_largeur = 50;
			m_poids = (m_longueur * m_largeur);
			m_profil = (m_poids / 100);
			if( m_profil <= 0) m_profil = 1;
			m_furtivite = 40;
			m_flottabilite= 100;
			m_propulsion = 3;
			m_puissance = m_propulsion * 10;
			m_vitesse = m_puissance * 10;
			m_aisance = m_vitesse / (m_longueur + m_largeur);
			if( m_aisance <= 0) m_aisance = 1;
			break;
			
		// Afectation de parametre pour un Navire de type DESTROYER
		//
		case DESTROYER:
			m_longueur = 50;
			m_largeur = 50;
			m_poids = (m_longueur * m_largeur);
			m_profil = (m_poids / 100);
			if( m_profil <= 0) m_profil = 1;
			m_furtivite = 40;
			m_flottabilite= 100;
			m_propulsion = 3;
			m_puissance = m_propulsion * 10;
			m_vitesse = m_puissance * 10;
			m_aisance = m_vitesse / (m_longueur + m_largeur);
			if( m_aisance <= 0) m_aisance = 1;
			break;
			
		// Afectation de parametre pour un Navire de type PORTE_AVIONS
		//
		case PORTE_AVIONS:
			m_longueur = 50;
			m_largeur = 50;
			m_poids = (m_longueur * m_largeur);
			m_profil = (m_poids / 100);
			if( m_profil <= 0) m_profil = 1;
			m_furtivite = 40;
			m_flottabilite= 100;
			m_propulsion = 3;
			m_puissance = m_propulsion * 10;
			m_vitesse = m_puissance * 10;
			m_aisance = m_vitesse / (m_longueur + m_largeur);
			if( m_aisance <= 0) m_aisance = 1;
			break;
			
		// Afectation de parametre pour un Navire de type PORTE_HELICOPTERES
		//
		case PORTE_HELICOPTERES:
			m_longueur = 50;
			m_largeur = 50;
			m_poids = (m_longueur * m_largeur);
			m_profil = (m_poids / 100);
			if( m_profil <= 0) m_profil = 1;
			m_furtivite = 40;
			m_flottabilite= 100;
			m_propulsion = 3;
			m_puissance = m_propulsion * 10;
			m_vitesse = m_puissance * 10;
			m_aisance = m_vitesse / (m_longueur + m_largeur);
			if( m_aisance <= 0) m_aisance = 1;
			break;
			
		// Afectation de parametre pour un Navire de type CHALAN_DE_DEBARQUEMENT
		//
		case CHALAN_DE_DEBARQUEMENT:
			m_longueur = 50;
			m_largeur = 50;
			m_poids = (m_longueur * m_largeur);
			m_profil = (m_poids / 100);
			if( m_profil <= 0) m_profil = 1;
			m_furtivite = 40;
			m_flottabilite= 100;
			m_propulsion = 3;
			m_puissance = m_propulsion * 10;
			m_vitesse = m_puissance * 10;
			m_aisance = m_vitesse / (m_longueur + m_largeur);
			if( m_aisance <= 0) m_aisance = 1;
			break;
			
		// Afectation de parametre pour un Navire de type VEDETTE_RAPIDE
		//
		case VEDETTE_RAPIDE:
			m_longueur = 50;
			m_largeur = 50;
			m_poids = (m_longueur * m_largeur);
			m_profil = (m_poids / 100);
			if( m_profil <= 0) m_profil = 1;
			m_furtivite = 40;
			m_flottabilite= 100;
			m_propulsion = 3;
			m_puissance = m_propulsion * 10;
			m_vitesse = m_puissance * 10;
			m_aisance = m_vitesse / (m_longueur + m_largeur);
			if( m_aisance <= 0) m_aisance = 1;
			break;
			
		// Afectation de parametre pour un Navire de type ETRACO
		//
		case ETRACO:
			m_longueur = 50;
			m_largeur = 50;
			m_poids = (m_longueur * m_largeur);
			m_profil = (m_poids / 100);
			if( m_profil <= 0) m_profil = 1;
			m_furtivite = 40;
			m_flottabilite= 100;
			m_propulsion = 3;
			m_puissance = m_propulsion * 10;
			m_vitesse = m_puissance * 10;
			m_aisance = m_vitesse / (m_longueur + m_largeur);
			if( m_aisance <= 0) m_aisance = 1;
			break;
			
		// Afectation de parametre pour un Navire de type TRANSPORT_DE_CHALANS
		//
		case TRANSPORT_DE_CHALANS:
			m_longueur = 50;
			m_largeur = 50;
			m_poids = (m_longueur * m_largeur);
			m_profil = (m_poids / 100);
			if( m_profil <= 0) m_profil = 1;
			m_furtivite = 40;
			m_flottabilite= 100;
			m_propulsion = 3;
			m_puissance = m_propulsion * 10;
			m_vitesse = m_puissance * 10;
			m_aisance = m_vitesse / (m_longueur + m_largeur);
			if( m_aisance <= 0) m_aisance = 1;
			break;
		default:
			break;
	}
	
	// Valuer l'etat courant
	//
	m_etatCoque= FLOTTE;
}

// --- Methode toString pour les tests unitaires
//
char* Coque::toString() {
char* pBuffer;	
	
	// Allouer le resultat
	//
	pBuffer= new char[140];
	if (pBuffer==NULL) return NULL;
	
	// Controler le cas particulier de l'element neutre
	//
	if (neutre()) strcpy(pBuffer, "---");
	else if (m_etatCoque == FLOTTE)
		sprintf(pBuffer, "[[FLOTTE][L : %d l : %d][Poids : %d][Profil : %d][Furtivite : %d][Propulsion : %d][Puissance : %d][VitesseMax : %d][Aisance : %d]]",
					 m_longueur, m_largeur,m_poids,
					 m_profil, m_furtivite, m_propulsion,
					 m_puissance, m_vitesse, m_aisance); 
		else
		sprintf(pBuffer, "[[COULE][L : %d l : %d][Poids : %d][Profil : %d][Furtivite : %d][Propulsion : %d][Puissance : %d][VitesseMax : %d][Aisance : %d]]",
					 m_longueur, m_largeur,m_poids,
					 m_profil, m_furtivite, m_propulsion,
					 m_puissance, m_vitesse, m_aisance); 
	return pBuffer;
}

