//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Ile - Accesseurs de calculerPertes (deuxieme forme)
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Ile.h"


int Ile::calculerPertes(const string& flotte, const Point& positionCible, int effectif, const string& assaillant, const Point& positionAssasillant)
{
	// Controler la validite du premier parametre
	//
	if (flotte.size() == 0) throw -2.1;
	
	// Controler la validite du troisieme parametre
	//
	if (effectif < 0) throw -2.3;

	// Controler la validite du quatrieme parametre
	//
	if (assaillant.size() == 0) throw -2.4;
	
	// Calculer l'effectif ami courant au point cible
	//
	int ancienEffectif= effectifs(flotte, positionCible);
	effectif+=ancienEffectif;
	
	// Calculer l'effectif ennemie courant au point cible
	//
	int effectifEnnemie= effectifs(assaillant, positionAssasillant);
	
	// Calculer le coeficient de perte au combat
	// des effectifs ennemis
	//
	float coefPerte= (float)effectifEnnemie/(float)effectif;

	// Calculer le nouvel effectfis ennemie selon
	// le nombre de combattant amis
	//
	if (coefPerte <= 1.f)	effectifEnnemie*= 1;
	if (coefPerte > 1.f && coefPerte <= 1.4f)	effectifEnnemie*= 0.9;
	if (coefPerte > 1.4f && coefPerte <= 1.6f)	effectifEnnemie*= 0.7;
	if (coefPerte > 1.6f && coefPerte <= 1.8f)	effectifEnnemie*= 0.6;
	if (coefPerte > 1.8f && coefPerte <= 2.f)	effectifEnnemie*= 0.4;
	if (coefPerte > 2.f && coefPerte <= 4.f)	effectifEnnemie*= 0.2;
	if (coefPerte > 4.f)	effectifEnnemie*= 0;
	
	// Restituer le resultat
	//
	return effectifEnnemie;
}
