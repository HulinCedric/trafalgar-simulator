//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe _Trafalgar - Service validiteEtatMeteo et validiteTypeNavire
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "_Trafalgar.h" 

// --- Controle de validite d'un etat de la meteo
//
bool _Trafalgar::validiteEtatMeteo(int etat) {

   if (etat < INF_ETATS_METEO || etat > SUP_ETATS_METEO) return false;
   return true;
}

// --- Controle de validite d'un type de navire
//
bool _Trafalgar::validiteTypeNavire(int type) {

   if (type < INF_TYPES_NAVIRES || type > SUP_TYPES_NAVIRES) return false;
   return true;
}

// --- Controle de validite d'un type d'arme
//
bool _Trafalgar::validiteTypeArmes(int type) {
	
	if (type < INF_TYPES_ARMES || type > SUP_TYPES_ARMES) return false;
	return true;
}

// --- Controle de validite d'un etat du radar
//
bool _Trafalgar::validiteEtatRadar(int etat) {
	
	if (etat < INF_ETATS_RADAR || etat > SUP_ETATS_RADAR) return false;
	return true;
}

// --- Controle de validite d'un etat de la coque
//
bool _Trafalgar::validiteEtatCoque(int etat) {
	
	if (etat < INF_ETATS_COQUE || etat > SUP_ETATS_COQUE) return false;
	return true;
}

// --- Controle de validite d'un etat de la arme
//
bool _Trafalgar::validiteEtatArme(int etat) {
	
	if (etat < INF_ETATS_ARME || etat > SUP_ETATS_ARME) return false;
	return true;
}