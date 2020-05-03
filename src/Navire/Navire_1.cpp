//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Constructeurs et methode toString
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"

// --- Constructeur par defaut
//
Navire::Navire() {
Point P0(0, 0);
Vecteur V0(0, 0);

   // Valuer le nom du navire
   //	
   m_nom= "-";

   // Valuer le nom de la flotte d'appartenance (drapeau)
   //	
   m_drapeau= "-";

   // Valuer la position initiale
   //
   m_position= P0;

   // Valuer la vitesse initiale
   //
   m_vitesse= V0;

   // Valuer l'effectif initial des troupes embarquees
   //
   m_nbSoldats= 0;

   // Valuer la vitesse maximum
   //
   m_vitesseMax=0;

   // Valuer les conditions meteo autour du navire
   //
   m_etatMeteo= INF_ETATS_METEO;
}

// --- Premier constructeur normal
//
Navire::Navire(const string& nom, 
               const string& flotte, 
               const Point& position, 
               const Vecteur& vitesse,
               int   nbSoldats) {
Coque coque(DESTROYER);
	
	// Controler la validite du premier parametre
	//
   	if(!_Trafalgar::validiteTypeNavire(DESTROYER))	throw -2.1;
	
	// Controler la validite du second parametre
	//
	if (nom.length()==0) throw -2.2;

	// Controler la validite du quatrieme parametre
	//
	if (nom.length()==0) throw -2.3;

	// Controler la validite du cinquieme parametre
	//
	if (vitesse.norme() < EPSILON) throw -2.5;

	// Controler la validite du sixieme parametre
	//
	if (nbSoldats < 0) throw -2.6;

	//	Valuer le type du navire
	//
	m_typeNavire= DESTROYER;
	
	//	Valuer le type de coque du navire
	//
	m_coque= coque;
	
	// Valuer le nom du navire
	//	
	m_nom= nom;

	// Valuer la flotte d'appartenance (drapeau)
	//	
	m_drapeau= flotte;

	// Valuer la position initiale
	//
	m_position= position;

	// Valuer la vitesse initiale
	//
	m_vitesse= vitesse;

	// Valuer l'effectif initial des troupes embarquees
	//
	m_nbSoldats= nbSoldats;

	// Valuer la vitesse maximum
	//
	m_vitesseMax= coque.vitesseNavire();
	
	// Valuer le poid du navire
	//
	m_poidsNavire= coque.poidsNavire();

   // Valuer la meteo initiale
   //
   m_etatMeteo= INF_ETATS_METEO;
}

// --- Second constructeur normal
//
Navire::Navire(const string& nom, 
			   const string& flotte) 
{
Point P0(0, 0);
Vecteur V0(0, 0);
Coque coque(DESTROYER);
	
	// Controler la validite du premier parametre
	//
	if(!_Trafalgar::validiteTypeNavire(DESTROYER))	throw -2.1;

	// Controler la validite du second parametre
	//
	 if (nom.length()==0) throw -2.2;
	
	// Controler la validite du second parametre
	//
	if (flotte.length()==0) throw -2.3;

	//	Valuer le type du navire
	//
	m_typeNavire= DESTROYER;
	
	//	Valuer le type de coque du navire
	//
	m_coque= coque;
	
   // Valuer le nom du navire
   //	
   m_nom= nom;

   // Valuer la flotte d'appartenance (drapeau)
   //	
   m_drapeau= flotte;

   // Valuer la position initiale
   //
   m_position= P0;

   // Valuer la vitesse initiale
   //
   m_vitesse= V0;

   // Valuer l'effectif initial des troupes embarquees
   //
   m_nbSoldats= 0;

	// Valuer la vitesse maximum
	//
	m_vitesseMax= coque.vitesseNavire();
	
	// Valuer le poid du navire
	//
	m_poidsNavire= coque.poidsNavire();

   // Valuer la meteo initiale
   //
   m_etatMeteo= INF_ETATS_METEO;
}

// --- Troisieme constructeur normal
//
Navire::Navire(typeNavire type,
			   const string& nom, 
               const string& flotte, 
               const Point& position, 
               const Vecteur& vitesse,
               int   nbSoldats) {
	Coque coque(type);
	
	// Controler la validite du premier parametre
	//
   	if(!_Trafalgar::validiteTypeNavire(type))	throw -2.1;
	
	// Controler la validite du second parametre
	//
	if (nom.length()==0) throw -2.2;
	
	// Controler la validite du quatrieme parametre
	//
	if (nom.length()==0) throw -2.3;
	
	// Controler la validite du cinquieme parametre
	//
	if (vitesse.norme() < EPSILON) throw -2.5;
	
	// Controler la validite du sixieme parametre
	//
	if (nbSoldats < 0) throw -2.6;
	
	//	Valuer le type du navire
	//
	m_typeNavire= type;
	
	//	Valuer le type de coque du navire
	//
	m_coque= coque;
	
	// Valuer le nom du navire
	//	
	m_nom= nom;
	
	// Valuer la flotte d'appartenance (drapeau)
	//	
	m_drapeau= flotte;
	
	// Valuer la position initiale
	//
	m_position= position;
	
	// Valuer la vitesse initiale
	//
	m_vitesse= vitesse;
	
	// Valuer l'effectif initial des troupes embarquees
	//
	m_nbSoldats= nbSoldats;
	
	// Valuer la vitesse maximum
	//
	m_vitesseMax= coque.vitesseNavire();
	
	// Valuer le poid du navire
	//
	m_poidsNavire= coque.poidsNavire();
	
	// Valuer la meteo initiale
	//
	m_etatMeteo= INF_ETATS_METEO;
}

// --- Quatrieme constructeur normal
//
Navire::Navire(typeNavire type, 
			   const string& nom, 
			   const string& flotte) 
{
	Point P0(0, 0);
	Vecteur V0(0, 0);
	Coque coque(type);
	
	// Controler la validite du premier parametre
	//
	if(!_Trafalgar::validiteTypeNavire(type))	throw -2.1;
	
	// Controler la validite du second parametre
	//
	if (nom.length()==0) throw -2.2;
	
	// Controler la validite du second parametre
	//
	if (flotte.length()==0) throw -2.3;
	
	//	Valuer le type du navire
	//
	m_typeNavire= type;
	
	//	Valuer le type de coque du navire
	//
	m_coque= coque;
	
	// Valuer le nom du navire
	//	
	m_nom= nom;
	
	// Valuer la flotte d'appartenance (drapeau)
	//	
	m_drapeau= flotte;
	
	// Valuer la position initiale
	//
	m_position= P0;
	
	// Valuer la vitesse initiale
	//
	m_vitesse= V0;
	
	// Valuer l'effectif initial des troupes embarquees
	//
	m_nbSoldats= 0;
	
	// Valuer la vitesse maximum
	//
	m_vitesseMax= coque.vitesseNavire();
	
	// Valuer le poid du navire
	//
	m_poidsNavire= coque.poidsNavire();
	
	// Valuer la meteo initiale
	//
	m_etatMeteo= INF_ETATS_METEO;
}


// --- Methode toString pour les tests unitaires
//
char* Navire::toString() {
char* pBuffer;

   // Allouer le resultat
   //
   pBuffer= new char[80];
   if (pBuffer==NULL) return NULL;

   // Controler le cas particulier de l'element neutre
   //
   if (neutre()) {strcpy(pBuffer, "---"); return pBuffer;}

   // Traiter le cas general
   //
	if( m_coque.etat() == COULE)
	{
		sprintf(pBuffer, "[Flotte %s / %s : %s %s / %d][COULE]", 
				m_drapeau.c_str(), 
				m_nom.c_str(),
				m_position.toString(),
				m_vitesse.toString(),
				m_nbSoldats);
	}
	else
	{
		sprintf(pBuffer, "[Flotte %s / %s : %s %s / %d][FLOTTE]", 
				m_drapeau.c_str(), 
				m_nom.c_str(),
				m_position.toString(),
				m_vitesse.toString(),
				m_nbSoldats);
	}
   return pBuffer;
}

char* Navire::toStringEcho()
{
	char* pResultat= new char[1000];
	if (pResultat==NULL) return NULL;
	
	char* Place;

	list <Radar*>::iterator i= m_pRadars.begin();
	int nResu=1;
	while (i != m_pRadars.end()) {
		Place= new char[strlen("Radar n°00 : [")+1];
		if (Place==NULL) return NULL;
		sprintf(Place, "Radar n°%d : [", nResu);
		strcat(pResultat, Place);
		strcat(pResultat,(*i)->toStringEcho());
		strcat(pResultat, "] ");
		
		delete Place;
		nResu++;
		i++;
	}
	return pResultat;
}
