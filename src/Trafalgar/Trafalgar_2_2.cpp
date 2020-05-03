//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Accesseurs de modification (Lot 1)
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"

// --- Ajout d'une ile a la description de la zone de confrontation
//
void Trafalgar::ajouterIle (Ile* pIle) {

   // Controler la validite du parametre
   //
   if (pIle == NULL) throw -2.1;

   // Controler la classe du parametre
   //
   if (strcmp(typeid(pIle).name(), "class Ile *") != 0) throw -2.1;

   string* pCle= pIle->nom();
   if (pCle == NULL) throw -1.0;
 
   // Controler que l'ile cible n'est pas deja presente
   //
   map<string, Ile*>::iterator i;
   i= m_pIles.find(*pCle);
   if (i != m_pIles.end()) throw -2.1;

   // Controler que la simulation temps reel n'est pas active
   //
   if (m_status) throw -3.0;
   
   // Inserer la nouvelle ile dans le contexte courant
   //
   m_pIles[*pCle]= pIle;

   // Liberer les variables de travail dynamiques
   // 
   delete pCle;
}

// --- Ajout d'un navire a la description des flottes en confrontation
//
void Trafalgar::ajouterNavire (Navire* pNavire) {

   // Controler la validite du parametre
   //
   if (pNavire == NULL) throw -2.1;

   // Controler la classe du parametre
   //
   if (strcmp(typeid(pNavire).name(), "P6Navire") != 0) throw -2.1;

   char* pCle= pNavire->nom();
   if (pCle == NULL) throw -1.0;

   // Controler que le navire cible n'est pas deja present
   //
   map<string, Navire*>::iterator i;
   string cle(pCle);
   i= m_pNavires.find(cle);
   if (i != m_pNavires.end()) throw -2.1;

   // Controler que la simulation temps reel n'est pas active
   //
   if (m_status) throw -3.0;
   
   // Inserer le nouveau navire dans le contexte courant
   //
   m_pNavires[cle]= pNavire;

   // Liberer les variables de travail dynamiques
   // 
   delete[] pCle;
}

void Trafalgar::ajouterArme  (const string& nomNavire, Arme* pNouvelleArme)
{
	// Controler la validite du premier parametre
	//
	if (nomNavire.size() == 0) throw -2.1;
	
	// Controler la validite du second parametre
	//
	if (pNouvelleArme == NULL)	throw -2.2;
	
	// Controler la classe du parametre
	//
	if (strcmp(typeid(pNouvelleArme).name(), "P4Arme") != 0) throw -2.2;
	
	// Controler que l'arme cible n'est pas deja presente sur un navire
	//
	map<string, Navire*>::iterator i= m_pNavires.begin();
	int nArme=0;
	while (i != m_pNavires.end())
	{
		// Récuperer le nombre d'arme du navire courant
		//
		nArme= (i->second)->nbArmes();
		
		// Verifier la liste des arme du navire courant
		//
		for (int k=1; k<=nArme; k++)
		{
			if((i->second)->arme(k)->numeroArme() == pNouvelleArme->numeroArme())	throw -2.2;
		}
		i++;
	}
	
	// Ajouter l'arme au navire cible
	//
	obtenirNavire(nomNavire)->ajouterArmes(pNouvelleArme);
}

void Trafalgar::ajouterRadar  (const string& nomNavire, Radar* pNouveauRadar)
{
	// Controler la validite du premier parametre
	//
	if (nomNavire.size() == 0) throw -2.1;
	
	// Controler la validite du second parametre
	//
	if (pNouveauRadar == NULL)	throw -2.2;
	
	// Controler la classe du parametre
	//
	if (strcmp(typeid(pNouveauRadar).name(), "P5Radar") != 0) throw -2.2;
	
	// Controler que l'arme cible n'est pas deja presente sur un navire
	//
	map<string, Navire*>::iterator i= m_pNavires.begin();
	int nRadar=0;
	while (i != m_pNavires.end())
	{
		// Récuperer le nombre d'arme du navire courant
		//
		nRadar= (i->second)->nbRadars();
		
		// Verifier la liste des arme du navire courant
		//
		for (int k=1; k<=nRadar; k++)
		{
			if((i->second)->radar(k)->numeroRadar() == pNouveauRadar->numeroRadar())	throw -2.2;
		}
		i++;
	}
	
	// Ajouter l'arme au navire cible
	//
	obtenirNavire(nomNavire)->ajouterRadars(pNouveauRadar);
}




