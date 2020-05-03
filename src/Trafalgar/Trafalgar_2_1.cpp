//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Accesseurs de consultation
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"

// --- Calcul du nombre de flottes en confrontation
//
int Trafalgar::nombreFlottes () {

   // Construire une liste des noms des flottes
   //
   list <string> nomsFlottes;

   // Parcourir l'ensemble des navires
   //
   map<string, Navire*>::iterator i;

   for (i=m_pNavires.begin(); i != m_pNavires.end(); i++) {
      
      // Enregistrer la flotte du navire courant dans la liste precedente
      //
      nomsFlottes.push_back((i->second)->flotte()); 
   }

   // Trier et filtrer la liste des noms de flottes
   //
   nomsFlottes.sort();
   nomsFlottes.unique(); 

   // Restituer le resultat
   //
   return nomsFlottes.size(); 
}

// ---  Obtention d'un navire engage dans la confrontation
//
Navire* Trafalgar::obtenirNavire (const string& nomNavire) {

   // Rechercher le navire cible dans le dictionnaire de simulation
   //
   map <string, Navire*>::iterator i;
   
   i= m_pNavires.find(nomNavire);

   // Traiter le cas d'erreur d'un navire inconnu du simulateur
   //
   if (i == m_pNavires.end()) return NULL;
   
   // Restituer le resultat
   //
   return i->second;
}

// ---  Obtention d'une des ile des zones de la confrontation
//
Ile* Trafalgar::obtenirIle (const string& nomIle) {

   // Rechercher l'ile cible dans le dictionnaire de simulation
   //
   map <string, Ile*>::iterator i;
   
   i= m_pIles.find(nomIle);

   // Traiter le cas d'erreur d'une ile inconnue du simulateur
   //
   if (i == m_pIles.end()) return NULL;
   
   // Restituer le resultat
   //
   return i->second;
}
   




