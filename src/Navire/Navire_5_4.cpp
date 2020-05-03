//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Service observer
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"

// --- Service observer
//
void Navire::observer()
{
	//Control la validité du support 
	//
	if(nok()) throw -2.0;
	
	list <Radar*>::iterator i = m_pRadars.begin();
	while( i != m_pRadars.end() )
	{
		// Le int etant un parametre 
		// Inutile je met n'importe quoi
		//
		(*i)->observer(nom(),0); 
		i++;
	}
}
