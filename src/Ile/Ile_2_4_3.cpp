//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Ile - Accesseurs de modification (Lot 3)
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Ile.h"

// --- Diminution des effectifs debarques
//
void Ile::retirerTroupes(const string& flotte, 
                         const Point&  positionCible,
                         int           effectif) {

   // Controler la validite du troisieme parametre
   //
   if (effectif < 0) throw -2.3;

   // Traiter le cas d'absence eventuelle de la flotte cible sur l'ile
   //
   map <string, list<int> >::iterator i;
   i= m_effectifs.find(flotte);
   if (i == m_effectifs.end()) return;

   // Obtenir la liste courante des effectifs
   //
   list <int> L1= m_effectifs[flotte];

   // Obtenir la liste courante des positions
   //
   list <Point> L2= m_positions[flotte];

   // Parcourir la liste des positions et celle des effectifs courants
   //
   list <int>::iterator   j=L1.begin();
   list <Point>::iterator k=L2.begin();

   while (k != L2.end()) {

       // Controler l'identite du point courant et de la position cible
       //
       if (*k == positionCible) {

          // Soustraire l'effectif transmis en parametre
          //
          *j -= effectif;
          if (*j < 0) *j= 0;
          m_effectifs[flotte]= L1;
          return;
       }
       j++; k++;
   }

   // Traiter le cas de l'absence de troupes au point cible
   //
   return;
}
