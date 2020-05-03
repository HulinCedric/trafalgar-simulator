//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Radar - Service observer (premiere forme)
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Radar.h"

// --- Acquisition de la liste des echos recus par le radar support
//
list < echo* >* Radar::observer (const Point&      positionPorteur, 
                                        list <Triangle>&  topologie, 
                                        list <Point>&     positionsNavires) {
Point  positionCible;
double distanceCible;
complex <int>* pEchoGenere;
Point* pPositionMasque;

   // Controler l'etat courant du radar
   //
   if( etat() != OPERATIONNEL) return NULL;

   // Allouer la liste resultante
   //
   list < echo* > * pResultats = new list <echo*>;
   if(pResultats == NULL) throw -1.0;

   // Calculer la portee operationnelle du radar (en metres)
   //
   double porteeRadar= portee()*_Trafalgar::uniteEspace();

   // Parcourir la liste des positions des navires sur zone
   //
   list <Point>::iterator i= positionsNavires.begin();
 
   while (i != positionsNavires.end()) {

      // Obtenir la position du navire cible
      //
      positionCible= *i;

      // Traiter le cas particulier du navire porteur lui meme
      //
      if (positionPorteur == positionCible) {
	  
         // Passer a la cible suivante
         //
         i++;
		 continue;
      }

      // Calculer la distance du navire porteur au navire cible 
      //
      distanceCible= positionPorteur.distance(positionCible);

      // Controler cette distance vis a vis de la portee du radar
      //
      if (distanceCible > porteeRadar) {

         // Passer a la cible suivante
         //
         i++;
		 continue;
      }

      // Traiter le cas particulier d'une cible cachee par la topologie
      //
      if (cibleCachee(positionPorteur, positionCible, topologie)) {

         // Traiter le cas particulier d'un navire tiers, interpose entre le navire
         // porteur et le navire cible
         //
         pPositionMasque= cibleMasquee(positionPorteur, positionCible, positionsNavires); 
                                       
         if (pPositionMasque != NULL) {
			 
            // Calculer l'echo radar genere par le navire tiers
            //
            pEchoGenere= calculerEchoRadar(positionPorteur, *pPositionMasque);
			
            // Enregistrer l'echo dans la liste resultante
            //
            pResultats->push_back(pEchoGenere);
			delete pPositionMasque;
            
         }

         // Passer a la cible suivante
         //
         i++;
		 continue;
      }

      // Traiter le cas general d'un echo genere par la cible
      //
      pEchoGenere= calculerEchoRadar(positionPorteur, positionCible);
			
      // Enregistrer l'echo dans la liste resultante
      //
       pResultats->push_back(pEchoGenere);

      // Passer a la cible suivante
      //
	  i++;
   }

   // Restituer le resultat
   //
   return pResultats; 	
}






