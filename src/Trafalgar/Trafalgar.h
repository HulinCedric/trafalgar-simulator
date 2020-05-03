//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar : simulateur temps reel de bataille navale
//
// Edition  A   : TD_13
//    + Version 1.0.0  : version initiale
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#ifndef _Ile_
#include "../Ile/Ile.h"
#endif

#ifndef _Navire_
#include "../Navire/Navire.h"
#endif

#define _Trafalgar_
class Trafalgar {
friend class Ile;
friend class Navire;
private :
static map <string, Ile*>    m_pIles;       // Ensemble des iles des zones de confrontation
static map <string, Navire*> m_pNavires;    // Ensemble des navires engages dans le jeu
static bool m_status;						// Indicateur de demarrage de la simulation

// ------ Methodes de classe privees
//
static void observer   (const string&);
	
public :

// ------ Accesseurs de consultation
//
static inline  int nombreIles   () {return m_pIles.size();}
static inline  int nombreNavires() {return m_pNavires.size();}
static         int nombreFlottes() ;
	
static Navire* obtenirNavire (const string&);
static Ile*    obtenirIle    (const string&);

// ------ Accesseurs de modification
//
static void ajouterIle    (Ile*);
static void ajouterNavire (Navire*);
static void ajouterArme	  (const string&, Arme*);
static void ajouterRadar  (const string&, Radar*);
static void placer        (const string&, const Point&, const Vecteur&);
static void installer     (const string&, const string&, int);

// ------ Services
//
static void start      (int);
static void deplacer   ();
static void manoeuvrer (const string&, double, double);
	
static void observer   ();

static map <string, Ile*>   diffuser ();
static map <string, Navire*> diffuser (const string&);

static void debarquer  (const string&, const string&, int);
static void embarquer  (const string&, const string&, int);
static void tirer      (const string&, int, const Point&);
static void appliquer  (const string&, etatMeteo);				
static void stop       (map <string, Ile*>, map<string, Navire*>);
static void modifierMeteo (const string&, etatMeteo);

virtual void verrouiller()= 0;
};

