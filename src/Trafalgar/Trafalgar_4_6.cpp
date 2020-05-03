//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Service Tirer
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"

// --- Tirer sur un flotte
//
void Trafalgar::tirer  (const string& nomNavire, 
						int numeroArme, 
						const Point& positionCible) 
{
	// Controler que la simulation temps reel est active
	//
	if (m_status == false)	throw -3.1;
	
	// Controler le premier parametre
	//
	if(nomNavire.size() == 0)	throw -2.1;
	
	// Controler le deuxieme parametre
	//
	if(numeroArme < 1)	throw -2.2;
	
	// Controler l'appartenance du navire cible a la simulation
	//
	if(obtenirNavire(nomNavire) == NULL)	throw -3.3;
	
	// Controler l'appartenance de l'arme au navire cible
	//
	if(obtenirNavire(nomNavire)->arme(numeroArme) == NULL)	throw -3.3;
	
	// Controler l'etat du navire
	//
	if(obtenirNavire(nomNavire)->etat() == COULE)	return;
	
	// Controler l'etat de l'arme
	//
	if(obtenirNavire(nomNavire)->arme(numeroArme)->etat() == CASSER) return;
	
	// Controler les munitions de l'arme
	//
	if(obtenirNavire(nomNavire)->arme(numeroArme)->munitionsArme() == 0) return;
	
	// Connaitre le nombre de munitions tirer selon l'arme
	//
	int munition=0;
	switch(obtenirNavire(nomNavire)->arme(numeroArme)->typeArme())
	{
		case MITRAILLEUSE: munition=10;
			break;
		case LANCE_ROQUETTES: munition= 5;
			break;
		case CANON: munition= 1;
			break;
		default: throw -2.2;
			break;
	}
	// Controler les munitions de l'arme
	//
	if(obtenirNavire(nomNavire)->arme(numeroArme)->munitionsArme() < munition) munition= obtenirNavire(nomNavire)->arme(numeroArme)->munitionsArme();
	
	// Calculer les degats infligée par l'arme
	//
	int degat= obtenirNavire(nomNavire)->arme(numeroArme)->puissanceArme()*munition;

	// Reduire le stock de munition de l'arme
	//
	obtenirNavire(nomNavire)->arme(numeroArme)->munitions(munition);
	
	// Calcul du point d'impact
	//
	echo incertitude= _Trafalgar::alea(obtenirNavire(nomNavire)->arme(numeroArme)->precisionArme());
	Point* pImpact=new Point((int)positionCible.abscisse() + incertitude.real(), (int)positionCible.ordonnee() +incertitude.imag());

	// Trouver les navire proche du point d'impact
	//
	int degatNavire;
	map <string, Navire*>::iterator i= m_pNavires.begin();
	while (i != m_pNavires.end())
	{
		if((i->second)->position()->distance(*pImpact) <= obtenirNavire(nomNavire)->arme(numeroArme)->puissanceArme())
		{
			degatNavire=	degat/(i->second)->position()->distance(*pImpact);
			if ((i->second)->flottabilite() < degatNavire) degatNavire= (i->second)->flottabilite();
			if (degatNavire < 0) degatNavire=0;
			(i->second)->degat(degatNavire);	
		}
		i++;
	}
	// Liberer les variables de travail
	//
	delete pImpact;
}