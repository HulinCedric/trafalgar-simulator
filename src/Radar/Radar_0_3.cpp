//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Radar - Methode de classe privee cibleMasquee
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Radar.h"

// --- Controle de la visibilite d'un navire cible un navire porteur
// --- en prenant en compte un eventuel masquage par un navire tiers
//
Point* Radar::cibleMasquee(const Point&   positionPorteur,
                           const Point&   positionCible,
                           list <Point>&  positionsNavires) {
	Point positionCourante;
	Vecteur V;
	DemiDroite D;
	
	// Parcourir la liste des positions de tous les navires
	//
	list <Point> ::iterator i= positionsNavires.begin();
	
	while (i != positionsNavires.end()) {
		
		// Obtenir la position du navire courant
		//
		positionCourante= *i;
		
		// Traiter le cas particulier du navire porteur lui meme
		//
		if (positionPorteur == positionCourante) {
			
			// Passer au navire suivant
			//
			i++; continue;
		}
		
		// Traiter le cas particulier du navire cible lui meme
		//
		if (positionCible == positionCourante) {
			
			// Passer au navire suivant
			//
			i++; continue;
		}
		
		// Construire la demi droite D issue de la position du porteur
		// et qui passe par la position de la cible
		//
		V= Vecteur(positionPorteur, positionCible);
		D= DemiDroite(positionPorteur, V);
		
		// Controler l'appartenance eventuelle du point courant a la demi droite D 
		//
		if (D.appartient(positionCourante)) {
			
			// Restituer le resultat dans le cas ou le navire courant cache la cible
			// vis a vis du navire porteur
			//
			return new Point(positionCourante);
		}
		
		// Passer a l'ile suivante
		//
		i++;
	}
	
	// Restituer le resultat dans le cas d'une cible visible
	//
	return NULL; 	
}






