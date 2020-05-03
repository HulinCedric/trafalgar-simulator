//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Accesseurs de modification
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"

// --- Modification du nombre de soldats embarques
//
void Navire::nbSoldats(int effectif)
{
	// Controler que le navire n'est pas deja coulé
	//
	if (etat() == COULE)	return;
	
	// Controler le premier parametre
	//
	if (effectif < 0) throw -2.1;
	
	// Modifier l'attribut
	//
	m_nbSoldats= effectif;
}

// --- Modification de la vitesse maximum
//
void Navire::vitesseMax(double module) 
{
  	// Controler que le navire n'est pas deja coulé
	//
	if (etat() == COULE)	return;
	
	// Controler la validite du parametre
	//
	if (module < EPSILON || module > m_coque.vitesseNavire()) throw -2.1;
	
	// Modifier l'attribut
	//
	m_vitesseMax= module;
}

// --- Modification de la meteo environnante du navire
//
void Navire::modifierMeteo(etatMeteo nouvelEtat)
{	
   // Controler la validite du parametre
   //
	if (!_Trafalgar::validiteEtatMeteo(nouvelEtat)) throw -2.1;
	
   // Controler la progressivite de l'evolution
   //
   if (abs(m_etatMeteo - nouvelEtat) > 1) throw -2.1;

   // Modifier l'attribut cibme
   //
   m_etatMeteo= nouvelEtat;
}

// --- Ajout d'arme propre au navir
//
void Navire::ajouterArmes	(Arme* nouvelleArme)
{
	// Controler que le navire n'est pas deja coulé
	//
	if (etat() == COULE)	return;
	
	// Controler l'objet support
	//
	if (nok())	throw -2.0;
	
	// Controler la validite du parametre
	//
	if (nouvelleArme == NULL || nouvelleArme->nok()) throw -2.1;
	
	// Controler la classe du parametre
	//
	if (strcmp(typeid(nouvelleArme).name(), "class Arme *") != 0) throw -2.1;
	
	// Controler l'état de l'arme
	//
	if (nouvelleArme->etat() == CASSER)	throw -2.1;
	
	// Controler que l'Arme n'est pas deja presente
	//
	list <Arme*>::iterator i= m_pArmes.begin();
	while (i != m_pArmes.end())
	{
		if ((*i)->numeroArme() == nouvelleArme->numeroArme())	throw -2.1;
		i++;
	}
	
	// Ajouter l'arme a l'inventaire du navire
	//
	m_pArmes.push_back(nouvelleArme);	
}

// --- Ajout d'arme propre au navire
//
void Navire::ajouterRadars	(Radar* nouveauRadar)
{
	// Controler que le navire n'est pas deja coulé
	//
	if (etat() == COULE)	return;
	
	// Controler l'objet support
	//
	if (nok())	throw -2.0;
	
	// Controler la validite du parametre
	//
	if (nouveauRadar == NULL || nouveauRadar->nok()) throw -2.1;
	
	// Controler la classe du parametre
	//
	if (strcmp(typeid(nouveauRadar).name(), "class Radar *") != 0) throw -2.1;
	
	// Controler l'état du radar
	//
	if (nouveauRadar->etat() == DETRUIT)	throw -2.1;
	
	// Controler que le radar n'est pas deja present
	//
	list <Radar*>::iterator i= m_pRadars.begin();
	while (i != m_pRadars.end())
	{
		if ((*i)->numeroRadar() == nouveauRadar->numeroRadar())	throw -2.1;
		i++;
	}
	
	// Ajouter le radar a l'inventaire du navire
	//
	m_pRadars.push_back(nouveauRadar);	
}


void Navire::degat (int nouveauDegat)
{
	// Controler l'objet support
	//
	if (nok())	throw -2.0;
	
	// Controler la validite du parametre
	//
	if (nouveauDegat < 0) throw -2.1;

	// Controler que le navire n'est pas deja coulé
	//
	if (etat() == COULE)	return;
	
	// Appliquer les degat sur la coque
	//
	m_coque.degat(nouveauDegat);
	
	// Calculer le nombre de d'arme detruite
	//
	int nArme;
	if (m_coque.flottabilite() == 0) 
	{
		nArme= nbArmes();
	}
	if ( m_coque.flottabilite() > 0 && m_coque.flottabilite() <= 30 )
	{
		nArme= nbArmes()-1;
		if (nArme < 0 )	nArme= 0;
	}
	if ( m_coque.flottabilite() > 30 && m_coque.flottabilite() <= 60 )
	{
		nArme= nbArmes()-2;
		if (nArme < 0 )	nArme= 0;
	}
	if ( m_coque.flottabilite() > 60 && m_coque.flottabilite() <= 90 )
	{
		nArme= nbArmes()-3;
		if (nArme < 0 )	nArme= 0;
	}
	if ( m_coque.flottabilite() > 90 )
	{
		nArme= 0;
	}
	
	// Modifier l'état des armes
	//
	list <Arme*>::iterator i= m_pArmes.begin();
	while (i != m_pArmes.end())
	{
		if( nArme != 0)	{(*i)->etat(CASSER); nArme--;}
		i++;
	}
		
	// Calculer le nombre de radar detruit
	//
	int nRadar;
	if (m_coque.flottabilite() == 0) 
	{
		nRadar= nbRadars();
	}
	if ( m_coque.flottabilite() > 0 && m_coque.flottabilite() <= 30 )
	{
		nRadar= nbRadars()-1;
		if (nRadar < 0 )	nRadar= 0;
	}
	if ( m_coque.flottabilite() > 30 && m_coque.flottabilite() <= 60 )
	{
		nRadar= nbRadars()-2;
		if (nRadar < 0 )	nRadar= 0;
	}
	if ( m_coque.flottabilite() > 60 && m_coque.flottabilite() <= 90 )
	{
		nRadar= nbRadars()-3;
		if (nRadar < 0 )	nRadar= 0;
	}
	if ( m_coque.flottabilite() > 90 )
	{
		nRadar= 0;
	}
		
	// Modifier l'état des radars
	//
	list <Radar*>::iterator k= m_pRadars.begin();
	while (k != m_pRadars.end())
	{
		if( nRadar != 0)	{(*k)->etat(DETRUIT); nRadar--;}
		k++;
	}
	
	// Modifier la vitesse du navire
	//
	if (m_coque.flottabilite() == 0) 
	{
		Vecteur *PV0= new Vecteur(0,0);
		vitesse(*PV0);
		delete PV0;
		vitesseMax(EPSILON);	
	}
	if ( m_coque.flottabilite() > 0 && m_coque.flottabilite() <= 30 )
	{
		vitesseMax(vitesseMax()/3);	
	}
	if ( m_coque.flottabilite() > 60 && m_coque.flottabilite() <= 90 )
	{
		vitesseMax(vitesseMax()/2);	
	}
	
	// Modifier la valeur des effectif
	//
	if (m_coque.flottabilite() == 0) 
	{
		nbSoldats(0);
	}
	if ( m_coque.flottabilite() > 0 && m_coque.flottabilite() <= 30 )
	{
		nbSoldats((int)(nbSoldats()/3));
	}
	if ( m_coque.flottabilite() > 60 && m_coque.flottabilite() <= 90 )
	{
		nbSoldats((int)(nbSoldats()/2));
	}
	
	// Modifier l'état de la coque
	//
	if (m_coque.flottabilite() == 0) 
	{
		m_coque.etat(COULE);
	}
}
	
	

