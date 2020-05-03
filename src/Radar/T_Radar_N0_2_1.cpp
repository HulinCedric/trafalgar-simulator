//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Radar - Tests unitaires de la methode de classe privee cibleCachee (Lot 1)
//                 (Cas nominaux / Une seule ile)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Radar.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Radar", "1.0.0");
   
      Tests::Design("Controle de la methode de classe privee cibleCachee (Lot 1)", 3);
      Point O(0, 0), A(2, 0), B(0, 2);
      Triangle OAB(O, A, B);

         Tests::Case("Cas d'une seule ile / Point cible cache par l'ile"); {
         Point positionPorteur(1, 3), positionCible(1, -1);

         list <Triangle> topologie;

            topologie.push_back(OAB);
   
            Tests::Unit(true, Radar::cibleCachee(positionPorteur, positionCible, topologie));
         }

         Tests::Case("Cas d'une seule ile / Point cible cache par une extremite de l'ile"); {
         Point positionPorteur(2, 2), positionCible(2, -1);

         list <Triangle> topologie;

            topologie.push_back(OAB);
   
            Tests::Unit(true, Radar::cibleCachee(positionPorteur, positionCible, topologie));
         }

         Tests::Case("Cas d'une seule ile / Point cible visible"); {
         Point positionPorteur(2, 2), positionCible(3, -1);

         list <Triangle> topologie;

            topologie.push_back(OAB);
   
            Tests::Unit(false, Radar::cibleCachee(positionPorteur, positionCible, topologie));
         }

   Tests::End();
}
