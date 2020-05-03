//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Ile - Accesseurs de calculerPertes (premiere forme)
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Ile.h"


int Ile::calculerPertes(const string&	flotte, const Point&	positionCible, int effectif)
{
list <int> L2;
list <int>::iterator k;
list <Point> L1;
list <Point>::iterator y;
double ecartPosition=0.;
int effectifEnnemie=0;
	
	// Controler la validite du premier parametre
	//
	if (flotte.size() == 0) throw -2.1;
	
	// Controler la validite du troisieme parametre
	//
	if (effectif < 0) throw -2.3;
	
	// Calculer l'effectif ami courant au point cible
	//
	int ancienEffectif= effectifs(flotte, positionCible);
	effectif+=ancienEffectif;

	// Initialiser l'itterateur du dictionnaire effectif
	//
	map <string, list<int> >::iterator i= m_effectifs.begin();
	
	// Parcourir le dictionnaire des effectifs
	//
	while (i != m_effectifs.end())
	{
		// Controler si c'est une flotte ennemie
		//
		if(i->first != flotte)
		{
			// Initialiser les dictionnaire des effectifs ennemies
			// et positions ennemies
			//
			L2= m_effectifs[i->first];
			k= L2.begin();
			L1= m_positions[i->first];
			y= L1.begin();
				
			// Parcourir les dictionnaires des ennemies
			//
			while( y != L1.end() )
			{
				// Recuperer la position de l'ennemie courant
				//
				Point position= *y;
				
				// Controler la distance entre la position cible
				// et la position de l'ennemie courante et ajouter
				// a l'effectif ennemie de combat
				//
				ecartPosition= position.distance(positionCible);
				if( (int)ecartPosition <= RAYON_MINIMUM_ACTION)	effectifEnnemie+= *k;
				y++;
			}
		}
		i++;
	}
	
	// Calculer le coeficient de perte au combat
	// des effectifs amis
	//
	float coefPerte= (float)effectif/(float)effectifEnnemie;

	// Calculer le nouvel effectfis ami selon
	// le nombre de combattant ennemies
	//
	if (coefPerte <= 1.f)	effectif=0;
	if (coefPerte > 1.f && coefPerte <= 1.4f)	effectif*= 0.2;
	if (coefPerte > 1.4f && coefPerte <= 1.6f)	effectif*= 0.4;
	if (coefPerte > 1.6f && coefPerte <= 1.8f)	effectif*= 0.6;
	if (coefPerte > 1.8f && coefPerte <= 2.f)	effectif*= 0.7;
	if (coefPerte > 2.f && coefPerte <= 4.f)	effectif*= 0.9;
	if (coefPerte > 4.f)	effectif*= 1;
	
	// Restituer le resultat
	//
	return effectif;
}