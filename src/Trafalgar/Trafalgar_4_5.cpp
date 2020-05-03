//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Service embarquer
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"

// --- Embarquement d'effectif d'une Ile sur un Navire
//
void Trafalgar::embarquer  (const string& nomNavire, 
							const string& nomIle, 
							int effectif)
{
	// Controler que la simulation temps reel est active
	//
	if (m_status == false)	throw -3.1;
	
	// Controler le premier parametre
	//
	if(nomNavire.size() == 0)	throw -2.1;
	
	// Controler le deuxieme parametre
	//
	if(nomIle.size() == 0)	throw -2.2;
	
	// Controler l'appartenance du navire cible a la simulation
	//
	if(obtenirNavire(nomNavire) == NULL)	throw -3.3;
	
	// Controler l'appartenance du navire cible a la simulation
	//
	if(obtenirIle(nomIle) == NULL)	throw -3.4;
	
	// Controler le troisieme parametre
	//
	if( effectif < 0 )	throw -2.3;
	
	// Controler l'etat du navire
	//
	if(obtenirNavire(nomNavire)->etat() == COULE)	return;
	
	// Controler si le point P appartient au triangle
	//
	if (obtenirIle(nomIle)->lieux()->appartient(*obtenirNavire(nomNavire)->position()))
	{
		return;
	}
	
	// Obtenir la liste des positions tenu par la flotte
	//
	list <Point> Position= obtenirIle(nomIle)->positions(obtenirNavire(nomNavire)->flotte());
	list <Point>::iterator i= Position.begin();
	Point   pH, pointEffectif;
	int minimum= -1., d;
	
	// Trouver le port le plus proche
	//
	while(i != Position.end())
	{
		pH= *i;
		d= pH.distance(*obtenirNavire(nomNavire)->position());
		if (minimum < 0 || minimum > d) {minimum=d; pointEffectif= pH;}
		i++;
	}
	
	// Controler l'effectif de l'ile
	//
	if( effectif > obtenirIle(nomIle)->effectifs(obtenirNavire(nomNavire)->flotte(), pointEffectif) )	effectif = obtenirIle(nomIle)->effectifs(obtenirNavire(nomNavire)->flotte(), pointEffectif);

	// Debarquer les effectif de l'Ile
	//
	int survivant= obtenirIle(nomIle)->embarquement(obtenirNavire(nomNavire)->flotte(), pointEffectif, effectif);
	
	// Embarquer les effectif sur le Navire
	//
	obtenirNavire(nomNavire)->embarquer(obtenirIle(nomIle), obtenirNavire(nomNavire)->flotte(), pointEffectif, survivant);
}