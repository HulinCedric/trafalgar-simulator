//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Ile - Accesseurs de consultation (Lot 2)
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Ile.h"

// --- Obtenir le total des effectifs d'une flotte
//
int Ile::effectifs(const string& flotte) {

   // Traiter le cas d'absence eventuelle de la flotte sur l'ile
   //
   map <string, list<int> >::iterator i;
   i= m_effectifs.find(flotte);
   if (i == m_effectifs.end()) return 0;

   // Parcourir la liste des effectifs de la flotte cible
   //
   int somme= 0;
   list<int>::iterator k= (i->second).begin(); 

   while (k != (i->second).end()) {
	   
      // Cumuler tous les effectifs de la flotte cible
      //
      somme += *k++;
   }

   // Restituer le resultat
   //
   return somme;
}

// --- Obtenir les effectifs d'une flotte stationnee sur une position cible
//
int Ile::effectifs(const string& flotte, const Point& P) {

   // Traiter le cas d'absence eventuelle de la flotte sur l'ile
   //
   map <string, list<Point> >::iterator i;
   i= m_positions.find(flotte);
   if (i == m_positions.end()) return 0;

   map <string, list<int> >::iterator j;
   j= m_effectifs.find(flotte);
   if (j == m_effectifs.end()) return 0;

   // Parcourir en parallele la liste des positions de 
   // la flotte cible et la liste des effectifs
   //
   list<Point>::iterator	k1= (i->second).begin(); 
   list<int>::iterator		k2= (j->second).begin();
   
   int somme= 0;
   double ecartPosition;
   while (k1 != (i->second).end())
   {
      // Obtenir la position courante de la flotte cible
      //
      Point position= *k1;

      // Controler la distance entre la position cible
      // et la position courante
      //
	  ecartPosition= position.distance(P);
      if (ecartPosition < 0.1) somme += *k2;
	   
      // Passer a la position suivante
      //
      k1++; k2++;
   }
   // Restituer le resultat
   //
   return somme;
}