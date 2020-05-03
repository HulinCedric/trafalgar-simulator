//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Service debarquer
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"

// --- Debarquement d'effectif d'un navire sur une ile
//
void Trafalgar::debarquer  (const string& nomNavire, 
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
	
	// Controler l'effectif du navire
	//
	if( effectif > obtenirNavire(nomNavire)->nbSoldats() ) effectif= obtenirNavire(nomNavire)->nbSoldats();
	
	// Controler si le navire est echoué
	//
	if (obtenirIle(nomIle)->lieux()->appartient(*obtenirNavire(nomNavire)->position()))
	{
		obtenirNavire(nomNavire)->debarquer(obtenirIle(nomIle), obtenirNavire(nomNavire)->flotte(), *obtenirNavire(nomNavire)->position(), effectif);
		obtenirIle(nomIle)->embarquement(obtenirNavire(nomNavire)->flotte(), *obtenirNavire(nomNavire)->position(), effectif);
		return;
	}

	// Calculer le minimum des projections sur les aretes
	//
	double minimum= -1., d;
	Segment* pArete;
	Point*   pH;
	int cas=0;
	for (int j=1; j<=3; j++)
	{
		pArete= obtenirIle(nomIle)->lieux()->arete(j);
		pH= pArete->projection(*obtenirNavire(nomNavire)->position());
		delete pArete;
		if (pH != NULL) 
		{ 
			d= pH->distance(*obtenirNavire(nomNavire)->position());
			delete pH;
			if (minimum < 0 || minimum > d) {minimum=d; cas= j;}
		}
	}
	
	// Recuperer le point le plus proche du navire sur l'Ile
	//
	pArete= obtenirIle(nomIle)->lieux()->arete(cas);
	pH= pArete->projection(*obtenirNavire(nomNavire)->position());
	
	// Debarquer les effectif du Navire
	//
	int survivant= obtenirNavire(nomNavire)->debarquer(obtenirIle(nomIle), obtenirNavire(nomNavire)->flotte(), *pH , effectif);
	
	// Embarquer les effectif sur l'Ile
	//
	obtenirIle(nomIle)->debarquement(obtenirNavire(nomNavire)->flotte(), *pH, survivant);
	
	// Supprimer les variables de travailles
	//
	delete pArete;
	delete pH;
}