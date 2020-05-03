//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Ile : modelisation d'une ile
//
// Edition  A   : TD_8
//    + Version 1.0.0  : version initiale
//    + Version 1.1.0  : memorisation de l'etat de la meteo
//                       + accesseur meteo
//    + Version 1.2.0  : memorisation des effectifs des troupes sur l'ile
//                       + accesseurs ajouterTroupes et effectifs
//    + Version 1.3.0  : ajout de la localisation des troupes debarquees
//    + Version 1.4.0  : TD14 / modification de type dans la liste des positions
//                       + ajout de la methode privee calculerPertes
//                       + modification du prototype de ajouterTroupes
//                       + ajout de l'accesseur retirerTroupes
//                       + ajout des services debarquement et embarquement
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#ifndef __Trafalgar_
#include "../_Trafalgar/_Trafalgar.h"
#endif

#ifndef _Triangle_
#include "../../_Maths/Triangle/Triangle.h"
#endif

#define _Ile_

class Ile {
private :
string                       m_nom;        // Identification de l'ile
Triangle                     m_lieux;      // Description topologique
etatMeteo                    m_etatMeteo;  // Etat de la meteo dans la zone qui entoure l'ile
map <string, list <int> >    m_effectifs;  // Effectifs des troupes debarquees
map <string, list <Point> >  m_positions;   // Localisations sur l'ile des troupes debarquees

public :

// ------ Constructeurs
//
Ile();
Ile(const string&, const Triangle&);
Ile(const Ile&) {throw -3.0;}

// ------ Predicats predefinis
//
inline bool neutre() {return m_nom=="-";}
inline bool ok()     {return m_lieux.ok();}
inline bool nok()    {return !ok();}

// ------ Accesseurs de consultation
//
inline string*    nom()   const {return new string(m_nom);}
inline Triangle*  lieux() const {return new Triangle(m_lieux);}
inline etatMeteo  meteo() const {return m_etatMeteo;}
inline list <Point> positions(const string& flotte) const {return m_positions.find(flotte)->second;}

int effectifs (const string&);
int effectifs (const string&, const Point&);

// ------ Accesseurs de modification
//
void ajouterTroupes (const string&, const Point&, int);
void retirerTroupes (const string&, const Point&, int);

// ------ Services
//
char* toString();

void  modifierMeteo(etatMeteo); 
	
int calculerPertes(const string&, const Point&, int);
int calculerPertes(const string&, const Point&, int, const string&, const Point&);
int debarquement(const string&, const Point&, int);
int embarquement(const string&, const Point&, int);
};

