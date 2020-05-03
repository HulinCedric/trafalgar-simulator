//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Service stop
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"

// --- Arret de la phase de simulation
//
void Trafalgar::stop(map <string, Ile*> Iles, map<string, Navire*> Navires)
{	
	// Controler que la simulation temps reel est active
	//
	if(m_status == false) throw -3.1;
	
	// Controler le premier parametre
	//
	if(Iles.size() == 0)	throw -2.1;
		
	// Controler le deuxieme parametre
	//
	if(Navires.size() == 0)	throw -2.2;
	
	// Construire une liste des noms des flottes
	//
	list <string> nomsFlottes;
	
	// Parcourir l'ensemble des navires
	//
	map<string, Navire*>::iterator i;
	
	for (i=m_pNavires.begin(); i != m_pNavires.end(); i++) {
		
		// Enregistrer la flotte du navire courant dans la liste precedente
		//
		nomsFlottes.push_back((i->second)->flotte()); 
	}
	
	// Trier et filtrer la liste des noms de flottes
	//
	nomsFlottes.sort();
	nomsFlottes.unique();
	
	// Trouver le nb d'effectif sur les Iles par flotte
	//
	list <string>::iterator y= nomsFlottes.begin();
	map <string, Ile*>::iterator k= Iles.begin();
	int tab[nomsFlottes.size()];
	int nFlotte=1;
	while (y != nomsFlottes.end())
	{
		while (k != Iles.end())
		{
			tab[nFlotte]= k->second->effectifs(*y);
			k++;
		}
		y++;
	}
	
	for (int t=1; t< nombreFlottes(); t++)
	{
		if(tab[t] < tab[t+1]) nFlotte=t;
	}
	
	y= nomsFlottes.begin();
	int repere=1;
	char* Gagnant;
	while (y != nomsFlottes.end())
	{
		if(repere == nFlotte)	
		{
			Gagnant= new char[y->size()+1];
			strcpy(Gagnant,y->c_str());
		}
		y++;
	}
	
	// Imprimer le resutlat
	//
	string affichage="\n\t\tEquipe Gagnante : ";
	affichage+=Gagnant;
	cout << affichage << endl;
	
	// Arreter la simulation
	//
	m_status= false;
}
