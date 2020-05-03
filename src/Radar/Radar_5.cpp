//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Radar - Service observer (second forme)
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Radar.h"
#include "../Trafalgar/Trafalgar.h"

// --- Acquisition de la liste des echos recus par le radar support
//
void Radar::observer (const string& nomNavire, int numero)
{	
	// Controler l'objet support
	//
	if ( nok() )	throw -2.0;
	
	// Controler l'etat courant du radar
	//
	if( etat() != OPERATIONNEL) return;
	
	// Controler le premier parametre
	//
	if( nomNavire.size() == 0)	throw -2.1;
	
	// Controler l'appartenance du navire cible a la simulation
	//
	if(Trafalgar::obtenirNavire(nomNavire) == NULL)	throw -3.3;
	
	//Construction de la map qui contient la lisst des Iles
	//
	map <string, Ile*> Iles = Trafalgar::diffuser();
	
	//Construction de la map qui contient la liste des Navires
	//
	map <string,Navire*> Navires = Trafalgar::diffuser(nomNavire);
	
	//Appelle de la fonction obtenirNavire de Tafalgar
	//pour recuperer le Point de position du navire;
	
	Point  PositionNavire = *(Trafalgar::obtenirNavire(nomNavire)->position());
	if( PositionNavire == NULL)	throw -2.1;
	
	//Creation d'une liste qui contient la list des Topologies des Iles
	//
	list<Triangle> ListeTopologie;
	
	//Creation d'une liste qui contient la liste des positions des navires du jeux
	//
	list<Point> ListePositionNavires;
	
	//Recuperation de la liste des Topologie des Iles du jeux
	//
	map <string,Ile*>::iterator i = Iles.begin();
	while(i != Iles.end())
	{
		ListeTopologie.push_back(*(i->second->lieux()));
		i++;
	}
	
	//Recuperation de la liste des positions des navires du jeux
	//
	map <string,Navire*>::iterator j = Navires.begin();
	while(j != Navires.end())
	{
		ListePositionNavires.push_back(*(j->second->position()));
		j++;
	}
	
	// Mettre a jour les echos radars
	//
	m_pEchos= *(observer(PositionNavire, ListeTopologie, ListePositionNavires));
}