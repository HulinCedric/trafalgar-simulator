//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Service manoeuvrer
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"

// --- Manoeuvre du navire du joueur courant (jeu au tour par tour)
//
void Trafalgar::manoeuvrer (const string& nomNavire, 
                            double consigneAlpha   ,
                            double consigneRho     )
{
	// Controler que la simulation temps reel est active
	//
	if (m_status == false)	throw -3.1;
	
	// Controler le premier parametre
	//
	if(nomNavire.size() == 0)	throw -2.1;

	// Controler l'appartenance du navire cible a la simulation
	//
	if(obtenirNavire(nomNavire) == NULL)	throw -3.3;
	
	// Controler l'etat du navire
	//
	if(obtenirNavire(nomNavire)->etat() == COULE)	return;
	
	// Appliquer les consignes au navire cible
	//
	obtenirNavire(nomNavire)->manoeuvrer(consigneAlpha, consigneRho);
}