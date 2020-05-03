//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Radar - Methode de classe privee cibleCachee
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Radar.h"

// --- Controle de la visibilite d'un navire cible par rapport
// --- a la topologie des iles de la zone de confrontation
//
bool Radar::cibleCachee(const Point&      positionPorteur,
                        const Point&      positionCible,
                        list <Triangle>&  topologie) {

Triangle triangleCourant;
Vecteur V;
DemiDroite D;
Point* pI;

   // Parcourir la topologie de toutes les iles
   //
   list <Triangle> ::iterator i= topologie.begin();

	while (i != topologie.end())
	{
	   // Obtenir le triangle de l'ile courante
	   //
	   triangleCourant= *i;

	   // Construire la demi droite issue de la position du porteur
	   // et qui passe par la position de la cible
	   //
	   V= Vecteur(positionPorteur, positionCible);
	   D= DemiDroite(positionPorteur, V);

	   // Controler la visibilite de la cible par rapport a l'ile courante
	   //
	   pI= triangleCourant.intersection(D);
	   if (pI != NULL) 
	   {
		   // Restituer le resultat dans le cas ou l'ile courante cache la cible
		   // vis a vis du navire porteur
		   //
		   if (positionPorteur.distance(*pI) < positionPorteur.distance(positionCible)) 
		   {
			   delete pI; return true;
		   }
	   }
	   // Passer a l'ile suivante
	   //
	   delete pI;
	   i++;
	}
	// Restituer le resultat dans le cas d'une cible visible
	//
	return false;	
}






