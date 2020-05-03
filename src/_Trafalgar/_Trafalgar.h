//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe _Trafalgar : constantes fonctionnelles et servitudes
//
// Edition  A   : TD_8
//    + Version 1.0.0  : version initiale
//    + Version 1.1.0  : introduction des fichiers header necessaires
//                       aux classes string, list et map (librairie STL)
//                       + ajout des litteraux de gestion de la meteo
//                       + ajout des litteraux associes a la distance et
//                         a la vitesse maximale de debarquement
//                       + ajout de l'enumeration des types de navires
//    + Version 1.2.0  : introduction des unites de temps et d'espace (TD15)
//                       + methodes de generation de valeurs aleatoires
//                       + ajout des litteraux d'etat d'un radar
//                       + modification de la vitesse maximale de transfert
//                       + ajout d'un rayon minimum d'action terrestre des 
//                         troupes deja debarquees  
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
// --- Header standards
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// --- Compatibilite STL
//
#pragma warning (disable : 4786)
#include <iostream>
#include <complex>
#include <string>
#include <list>
#include <map>

using namespace std;

// --- Litteraux de description des types de navires
//
enum TypesNavires {INF_TYPES_NAVIRES= 0,
                   FREGATE, 
                   FREGATE_DEFENSE_AERIENNE,
                   FREGATE_ANTI_SOUS_MARINE,
                   CHASSEUR_DE_MINES,
                   AVISO,
                   CORVETTE,
                   BPC,
                   CROISEUR,
                   CUIRASSE,
                   DESTROYER,
                   PORTE_AVIONS,
                   PORTE_HELICOPTERES,
                   CHALAN_DE_DEBARQUEMENT,
                   VEDETTE_RAPIDE,
                   ETRACO,
                   TRANSPORT_DE_CHALANS,
                   SUP_TYPES_NAVIRES};

typedef enum TypesNavires typeNavire;

// --- Litteraux de description des types de navires
//
enum TypesArmes {INF_TYPES_ARMES= 0,
				 MITRAILLEUSE, 
				 LANCE_ROQUETTES,
				 CANON,
				 SUP_TYPES_ARMES};

typedef enum TypesArmes typeArmes;

// --- Litteraux de gestion de la meteo
//
enum EtatsMeteo {INF_ETATS_METEO= 0, 
                 CALME, AGITEE, TRES_AGITEE, TEMPETE, 
                 SUP_ETATS_METEO};

typedef enum EtatsMeteo etatMeteo;

// --- Litteraux de description des etats d'un equipement radar
//
enum EtatsRadar {INF_ETATS_RADAR= 0, 
                 OPERATIONNEL, DETRUIT, 
                 SUP_ETATS_RADAR};

typedef enum EtatsRadar etatRadar;

// --- Litteraux de description des etats d'un équipement arme
//
enum EtatsArme {INF_ETATS_ARME= 0, 
				FONCTIONNELLE, CASSER, 
				SUP_ETATS_ARME};

typedef enum EtatsArme etatArme;

// --- Litteraux de description des etats d'un équipement arme
//
enum EtatsCoque {INF_ETATS_COQUE= 0, 
				 FLOTTE, COULE, 
				 SUP_ETATS_COQUE};

typedef enum EtatsCoque etatCoque;

// --- Distance maximum pour le transfert de troupes (en unites espace)
//
#define DISTANCE_MAXIMUM_TRANSFERT 2000

// --- Vitesse maximum pour le transfert de troupes (en unites d'espace / unites de temps)
//
#define VITESSE_MAXIMUM_TRANSFERT 1.5

// --- Rayon minimum d'action des troupes au sol (en unites espace)
//
#define RAYON_MINIMUM_ACTION 250

// --- Nombre maximum de flottes en competition
//
#define MAX_FLOTTES 5


#define echo complex<int>
#define __Trafalgar_

class _Trafalgar {
private :

static	double	m_uniteTemps;    // Intervalle temps entre deux tops H1
static	double	m_uniteEspace;   // Intervalle espace entre deux points de grille d'une carte 
static	int		m_numeroArme;
static	int		m_numeroRadar;
	
public :

// ------ Accesseurs de consultation
//
inline static double uniteTemps () {return m_uniteTemps;}
inline static double uniteEspace() {return m_uniteEspace;}

// ------ Accesseurs de modification
//
inline static void uniteTemps  (double);
inline static void uniteEspace (double);

// ------ Services
//
static bool validiteEtatMeteo(int);
static bool validiteTypeNavire(int);
static bool validiteTypeArmes(int);
static bool validiteEtatRadar(int);
static bool validiteEtatCoque(int);
static bool validiteEtatArme(int);
	
static int				alea(int, int);
static int				alea(int, double);
static echo&			alea(int);
	
static	int	numeroArme();
static	int	numeroRadar();

virtual void verrouiller()=0;

};

