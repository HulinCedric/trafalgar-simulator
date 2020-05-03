//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Radar - Methode privee calculerEchoRadar
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Radar.h"

// --- Calculer les coordonnees (en unites d'espace) de l'echo radar genere par
// --- un navire cible vis a vis d'un radar embarque sur un navire porteur 
//
echo* Radar::calculerEchoRadar (const Point& positionPorteur, 
								const Point& positionCible) {

   // Obtenir la portee du radar support
   //
   int porteeRadar= portee();

   // Obtenir l'erreur theorique maximum du radar support
   //
   int precisionTheorique= precision();

   // Calculer la distance du navire porteur au navire cible
   //
   double distance= positionPorteur.distance(positionCible);

   // Calculer la precision courante en fonction de la distance 
   // du navire porteur au navire cible
   //
   int precisionCourante= (int)((precisionTheorique*2*distance)/porteeRadar);
   if(precisionCourante == 0) precisionCourante = 1;
   
   // Calculer l'incertitude de la mesure
   //
   echo incertitude= _Trafalgar::alea(precisionCourante);

   // Determiner le resultat en fonction de la position reelle de la cible
   // et de l'incertitude sur la mesure
   //
   int x= (int)positionCible.abscisse() + incertitude.real();
   int y= (int)positionCible.ordonnee() + incertitude.imag();

   // Restituer le resultat
   //
   return new echo(x, y); 	
}






