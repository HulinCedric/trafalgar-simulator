//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Service deplacer
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"

// --- Deplacement de tous les navires en jeu
//
void Trafalgar::deplacer ()
{
	// Controler que la simulation temps reel est active
	//
	if (m_status == false)	throw -3.1;

	// Allouer un tableau dynamique de toutes les iles
	//
	int cardinal= nombreIles(); 
	Ile** pIles= new Ile*[cardinal + 1];
	if (pIles == NULL) throw -1.0;

	// Renseigner les elements du tableau
	//
	map<string, Ile*>::iterator i;
	int e;
	
	for (i=m_pIles.begin(), e=0; i != m_pIles.end(); i++, e++)
	{
		// Faire progresser le navire courant suivant son vecteur vitesse
		//
		pIles[e]=i->second;
	}

	// Marquer la fin du tableau
	//
	pIles[cardinal]= NULL;

	// Parcourir l'ensemble des navires
	//
	map<string, Navire*>::iterator k;

	for (k=m_pNavires.begin(); k != m_pNavires.end(); k++)
	{
		// Faire progresser le navire courant suivant son vecteur vitesse
		//
		(k->second)->deplacer(pIles);
	}

	// Liberer le tableau de travail
	//
	delete[] pIles;
}