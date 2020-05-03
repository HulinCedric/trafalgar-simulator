//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire : modelisation d'un navire
//
// Edition  A   : TD_8 / description limitee aux deplacements
//    + Version 1.0.0  : version initiale
//    + Version 1.1.0  : gestion du nombre de soldats embarques
//    + Version 1.2.0  : gestion des manoeuvres et d'une vitesse
//                       maximum modifiable dynamiquement
//    + Version 1.3.0  : TD 13 / introduction compatibilite STL
//                       + ajout d'un second constructeur normal
//                       + ajout des proprietes de la coque
//                       + ajout des accesseurs de gestion "coque"
//                       + ajout de la propriete "meteo locale"
//                       + ajout des accesseurs de gestion "meteo"
//                       + ajout des controles de validite dans "deplacer"
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#ifndef _Ile_
#include "../Ile/Ile.h"
#endif

#ifndef _Radar_
#include "../Radar/Radar.h"
#endif

#ifndef _Coque_
#include "../Coque/Coque.h"
#endif

#ifndef _Arme_
#include "../Arme/Arme.h"
#endif

#define _Navire_

class Trafalgar;

class Navire {
	
private :
string      m_nom;              // Identification du bateau
string      m_drapeau;          // Designation de la flotte
Point       m_position;         // Position courante du navire
Vecteur     m_vitesse;          // Vitesse courante du navire
double      m_vitesseMax;       // Vitesse maximum du navire
int         m_nbSoldats;        // Effectif des troupes de debarquement

typeNavire  m_typeNavire;       // Type de navire
Coque		m_coque;			// Coque du navire
int         m_poidsNavire;      // Poids du navire
etatMeteo   m_etatMeteo;        // Etat courant de la meteo autour du navire

list <Arme*>	m_pArmes;		// Liste des armes du navire
list <Radar*>	m_pRadars;		// Liste des radars du navire

public :

// ------ Constructeurs
//
Navire();
Navire(const string&, const string&, const Point&, const Vecteur&, int);	
Navire(const string&, const string&);
Navire(typeNavire, const string&, const string&, const Point&, const Vecteur&, int);
Navire(typeNavire, const string&, const string&);
Navire(const Navire&) {throw -3.0;}

// ------ Predicats predefinis
//
inline bool neutre() {return m_nom == "-" && m_drapeau == "-";}
inline bool ok()     {return m_drapeau.length() != 0;}
inline bool nok()    {return !ok();}

// ------ Accesseurs de consultation
//
inline Point*     position	()  const	{return new Point(m_position);}
inline Vecteur*   vitesse	()  const	{return new Vecteur(m_vitesse);}
inline int        nbSoldats	()			{return m_nbSoldats;}
inline etatMeteo  meteo		()			{return m_etatMeteo;}
inline double     vitesseMax()			{return m_vitesseMax;}
inline typeNavire type		()			{return m_typeNavire;}
inline int        poids		()			{return m_poidsNavire;}
inline int		  flottabilite()		{return m_coque.flottabilite();}
inline int		  nbArmes	()			{return m_pArmes.size();}
inline int		  nbRadars	()			{return m_pRadars.size();}
inline etatCoque  etat		()			{return m_coque.etat();}
Arme*			  arme		(int);
Radar*			  radar		(int);
char*             nom		();
char*             flotte	();

// ------ Accesseurs de modification
//
inline	void position		(const Point& P)   {m_position= P;}
inline	void vitesse		(const Vecteur& V) {m_vitesse = V;}
		void vitesseMax		(double);
		void nbSoldats		(int);
		void modifierMeteo	(etatMeteo);
		void ajouterArmes	(Arme*);
		void ajouterRadars	(Radar*);
		void degat			(int);

// ------ Services
//
void  deplacer   (Ile**);
void  manoeuvrer (double, double);
int   debarquer  (string, int);

int calculerPertes(Ile*, int);
int debarquer(Ile*, const string&, const Point&, int);
int embarquer(Ile*, const string&, const Point&, int);

void observer();
	
char* toStringEcho();
char* toString();
};

