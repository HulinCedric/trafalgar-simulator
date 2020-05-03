//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Ile - Accesseurs de modification (Lot 2)
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Ile.h"

// --- Augmentation des effectifs debarques
//
void Ile::ajouterTroupes(const string& flotte, 
                         const Point&  positionCible,
                         int           effectif) {

   // Controler la validite du troisieme parametre
   //
   if (effectif < 0) throw -2.3;

   // Traiter le cas d'absence eventuelle de la flotte cible sur l'ile
   //
   map <string, list<int> >::iterator i;
   i= m_effectifs.find(flotte);
   if (i == m_effectifs.end()) {

      // Creer et initialiser la liste des effectifs
      //
      list <int>* pL1= new list <int>;
      if (pL1 == NULL) throw -1.0;

      // Ajouter les nouvelles troupes
      //
      pL1->push_back(effectif);
      m_effectifs[flotte]= *pL1;

      // Creer la liste des positions
      //
      list <Point>* pL2= new list <Point>;
      if (pL2 == NULL) throw -1.0;

      // Ajouter la nouvelle position
      //
      pL2->push_back(positionCible);
      m_positions[flotte]= *pL2;
      return;
   }

   // Obtenir la liste courante des effectifs
   //
   list <int> L1= m_effectifs[flotte];

   // Obtenir la liste courante des positions
   //
   list <Point> L2= m_positions[flotte];

   // Rechercher la presence eventuelle de troupes de la
   // flotte cible deja presentes au point cible
   //
   list <int>::iterator   j=L1.begin();
   list <Point>::iterator k=L2.begin();

   while (k != L2.end()) {

       // Traiter le cas particulier de troupes de la flotte cible
       // deja presentes au point cible
       //
       if (*k == positionCible) {
          *j += effectif;
          m_effectifs[flotte]= L1;
          return;
       }

       j++; k++;
   }

   // Traiter le cas general d'une nouvelle position
   // de la flotte cible
   //
   L1.push_back(effectif);
   m_effectifs[flotte]= L1;

   L2.push_back(positionCible);
   m_positions[flotte]= L2;
}
