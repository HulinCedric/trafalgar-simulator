//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Coque : Maniabilité des navires 
//
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#ifndef __Trafalgar_
#include "../_Trafalgar/_Trafalgar.h"
#endif

#define _Coque_

class Coque {
private:
int m_longueur;			// Longueur du navire
int m_largeur;			// Largeur du navire
int m_poids;			// Poids du navire
int m_profil;			// Coefficient hydro dynamique
int m_furtivite;		// Coefficient de furtivité
int m_propulsion;		// Nombre de moteurs
int m_puissance;		// Puissance des moteurs
int m_flottabilite;		// Coefficient de flottabilité
int m_vitesse;			// Vitesse maximum du navire
int m_aisance;			// Coefficient de manoeuvrabilité
etatCoque m_etatCoque;	// Etat courant de l'equipement

public:
	
// ------ Constructeurs
//
Coque();
Coque(typeNavire);
Coque(const Coque&) {throw -3.0;}


// ------ Predicats predefinis
//
inline bool neutre() {return m_longueur == 0 && m_largeur == 0 && m_propulsion == 0;}
inline bool ok() {return ((m_longueur < 500 && m_longueur >= 0) && (m_largeur < 500 && m_largeur >= 0) && (m_propulsion < 10 && m_propulsion >= 0));}
inline bool nok(){return !ok();}

// ------ Accesseurs de consultation
//
inline int longueurNavire()    const {return m_longueur;}
inline int largeurNavire()     const {return m_largeur;}
inline int poidsNavire()	   const {return m_poids;}
inline int profilNavire()	   const {return m_profil;}
inline int furtiviteNavire()   const {return m_furtivite;}
inline int propulsionNavire()  const {return m_propulsion;}
inline int puissanceNavire()   const {return m_puissance;}
inline int vitesseNavire()	   const {return m_vitesse;}
inline int aisanceNavire()	   const {return m_aisance;}
inline int flottabilite()	   const {return m_flottabilite;}
inline etatCoque etat()		   const {return m_etatCoque;}
		
// ------ Accesseurs de modification
//
inline void etat(etatCoque nEtat){if(etat() == FLOTTE){if(_Trafalgar::validiteEtatCoque(nEtat)) m_etatCoque=nEtat;}}
void degat	(int);

// ------ Surcharges d'operateurs
//
bool operator ==(const Coque&);
bool operator !=(const Coque&);
	
// ------ Services
//	
char* toString();
};
