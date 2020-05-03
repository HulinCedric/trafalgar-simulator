//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Service observer (premiere&seconde forme)
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"

// --- Liste l'etat des echo radar de tous les navires
//
void Trafalgar::observer()
{
	// Controler que la simulation temps reel est active
	//
	if( m_status == false ) throw -3.1;
	
	map <string,Navire*>::iterator i = m_pNavires.begin();
	while ( i != m_pNavires.end() )
	{
		i->second->observer();
		i++;
	}
}

// --- Liste l'etat des echo radar d'un navires
//
void Trafalgar::observer   (const string& nomNavire)
{
	//Control validitÈ support
	//
	if( m_status == false ) throw -3.1;
	
	// Controler l'appartenance du navire cible a la simulation
	//
	if(obtenirNavire(nomNavire) == NULL)	throw -3.3;	
	
	//Appelle de la fonction observer du navire passÈ en parametre
	//
	obtenirNavire(nomNavire)->observer();
}