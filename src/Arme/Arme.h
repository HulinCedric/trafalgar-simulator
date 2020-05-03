//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Arme : Gestion des tires 
//
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#ifndef __Trafalgar_
#include "../_Trafalgar/_Trafalgar.h"
#endif

#define _Arme_

class Arme {

	typeArmes m_type;
	int m_numero;
	int m_puissance;
	int m_munitions;
	int m_precision;
	etatArme m_etatArme;

public :
	
	// ------ Constructeurs
	//
	Arme();
	Arme(typeArmes);
	Arme(const Arme&) {throw -3.0;}
	
	// ------ Predicats predefinis
	//
	inline bool neutre() {return  m_puissance == 0 && m_precision == 0 && m_numero == 0;}
	inline bool ok() {return m_puissance > 0 && m_precision > 0;}
	inline bool nok(){return !ok();}
	
	// ------ Accesseurs de consultation
	//
	inline int typeArme()      const {return m_type;}
	inline int numeroArme()    const {return m_numero;}
	inline int puissanceArme() const {return m_puissance;}
	inline int munitionsArme() const {return m_munitions;}
	inline int precisionArme() const {return m_precision;}
	inline etatArme etat() { return m_etatArme; }

	// ------ Accesseurs de modification
	//
	inline int munitions(int munitions) { if(etat() == FONCTIONNELLE){ m_munitions -= munitions;} return m_munitions; }
	inline void etat(etatArme nEtat){if(etat() == FONCTIONNELLE){if(_Trafalgar::validiteEtatArme(nEtat)) m_etatArme=nEtat;}}
	
	// ------ Services
	//	
	char* toString();
};