//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Radar : modelisation d'un equipement radar
//
// Edition  A   : TD_15
//    + Version 1.0.0  : version initiale
//    + Version 1.1.0  : introduction de la memorisation des echos radar
//                       + modification de la methode observer
//                       + correction bug des obstacles arriere 
//
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#ifndef __Trafalgar_
#include "../_Trafalgar/_Trafalgar.h"
#endif

#ifndef _Triangle_
#include "../../_Maths/Triangle/Triangle.h"
#endif

#define _Radar_

class Radar {
	private :
	int			  m_numero;
	int           m_portee;        // Portee maximale    (en unite d'espace Trafalgar)
	int           m_precision;     // Precision maximale (en unite d'espace Trafalgar)
	etatRadar     m_etatRadar;     // Etat courant de l'equipement
	list <echo* > m_pEchos;        // Liste des echos recueillis lors du dernier top H1   
	
	
	// ------ Methodes de classe privees
	//
	static bool   cibleCachee  (const Point&, const Point&, list <Triangle>&);
	static Point* cibleMasquee (const Point&, const Point&, list <Point>&);
	
	// ------ Methodes d'instance privees
	//
	echo* calculerEchoRadar(const Point&, const Point&);
	list <echo* >* observer (const Point&, list <Triangle>&, list <Point>&); 
	
	public :
	
	// ------ Constructeurs
	//
	Radar();
	Radar(int, int);
	Radar(const Radar&) {throw -3.0;}
	
	// ------ Predicats predefinis
	//
	inline bool neutre() {return m_portee==0 &&  m_numero == 0;}
	inline bool ok()     {return m_portee >= 0 && m_precision >= 0;}
	inline bool nok()    {return !ok();}
	
	// ------ Accesseurs de consultation
	//
	inline int		 numeroRadar()const {return m_numero;}
	inline int       portee()    const {return m_portee;}
	inline int       precision() const {return m_precision;}
	inline etatRadar etat()      const {return m_etatRadar;}
	
	// ------ Accesseurs de modification
	//
	inline void etat(etatRadar nEtat){if(etat() == OPERATIONNEL){if(_Trafalgar::validiteEtatRadar(nEtat)) m_etatRadar=nEtat;}}
	
	// ------ Services
	//
	void           observer (const string&, int);
	
	char* toString();
	char* toStringEcho();
};

