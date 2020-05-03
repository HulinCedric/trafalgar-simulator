//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Accesseurs de consultation
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"

// --- Consultation de la designation du navire
//
char* Navire::nom() {
char* pResultat;
	
   pResultat= new char[m_nom.length()+1];
   if (pResultat==NULL) throw -1.0; 
   strcpy(pResultat, m_nom.c_str());

   return pResultat;
}

// --- Consultation de la flotte de rattachement
//
char* Navire::flotte() {
char* pResultat;
	
   pResultat= new char[m_drapeau.length()+1];
   if (pResultat==NULL) throw -1.0; 
   strcpy(pResultat, m_drapeau.c_str());

   return pResultat;
}

Arme* Navire::arme (int numeroArme)
{
	// Controler l'objet support
	//
	if (nok())	throw -2.0;
	
	// Controler la validite du parametre
	//
	if (numeroArme < 1) throw -2.1;
	if (numeroArme > nbArmes()) throw -2.1;
	
	// Controler que l'Arme n'est pas deja presente
	//
	Arme* pResultat= NULL;
	list <Arme*>::iterator i= m_pArmes.begin();
	int nArme=1;
	while (i != m_pArmes.end())
	{
		if (nArme == numeroArme)	pResultat=*i;
		nArme++;
		i++;
	}
	// Restituer le resultat
	//
	return pResultat;
}

Radar* Navire::radar (int numeroRadar)
{
	// Controler l'objet support
	//
	if (nok())	throw -2.0;
	
	// Controler la validite du parametre
	//
	if (numeroRadar < 1) throw -2.1;
	if (numeroRadar > nbRadars()) throw -2.1;
	
	// Controler que le radar n'est pas deja present
	//
	Radar* pResultat= NULL;
	list <Radar*>::iterator i= m_pRadars.begin();
	int nRadar=1;
	while (i != m_pRadars.end())
	{
		if (nRadar == numeroRadar)	pResultat=*i;
		nRadar++;
		i++;
	}
	// Restituer le resultat
	//
	return pResultat;
}