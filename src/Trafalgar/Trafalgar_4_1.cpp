//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Service start
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"

// --- Demarrage de la phase de simulation
//
void Trafalgar::start (int nbFlottes)
{
	// Controler la validite du parametre
	//
	if (nbFlottes > MAX_FLOTTES || nbFlottes <= 0)	throw -3.2;

	// Controler que la simulation temps reel n'est pas deja active
	//
	if (m_status)	throw -3.1;

	// Controler la presence d'au moins un navire dans la simulation
	//
	if (nombreNavires() <= 0) throw -3.2;
	  
	// Controler que tous les navires sont en eau libre
	//
	map<string, Navire*>::iterator i;

	for (i=m_pNavires.begin(); i != m_pNavires.end(); i++) 
	{	
		// Obtenir la position du navire courant
		//
		Point* pP= (i->second)->position();

		// Parcourir l'ensemble des iles de la zone de confrontation
		//
		map<string, Ile*>::iterator j;

		for (j=m_pIles.begin(); j != m_pIles.end(); j++)
		{
			// Verifier que la position du navire courant n'est pas
			// situee sur l'ile courante
			//
			Triangle* pT= (j->second)->lieux();
			if (pT == NULL) throw -1.0;
			if (pT->appartient(*pP)) throw -3.5;
			
			// Appliquer un etat meteo a chaque Ile
			//
			(j->second)->modifierMeteo(CALME);
		}
		// Appliquer un etat meteo a chaque Navire
		//
		(i->second)->modifierMeteo(CALME);
	}

	// Valider le status de simulation
	//
	m_status= true; 
}