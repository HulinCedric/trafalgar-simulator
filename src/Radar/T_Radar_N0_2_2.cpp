//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Radar - Tests unitaires de la methode de classe privee cibleCachee (Lot 2)
//                 (Cas nominaux / Plusieurs iles)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Radar.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Radar", "1.0.0");
   
      Tests::Design("Controle de la methode de classe privee cibleCachee (Lot 2)", 3);
      Point O(0, 0), A(2, 0), B(0, 2), C(1, 2), D(2, 2), E(1, 3);
      Triangle OAB(O, A, B), CDE(C, D, E);

         Tests::Case("Cas de plusieurs iles / Point cible cache par une seule ile"); {
         Point positionPorteur(2, 3), positionCible(1.5, 1);

         list <Triangle> topologie;

            topologie.push_back(OAB);
            topologie.push_back(CDE);
   
            Tests::Unit(true, Radar::cibleCachee(positionPorteur, positionCible, topologie));
         }

         Tests::Case("Cas de plusieurs iles / Point cible cache par plusieurs iles"); {
         Point positionPorteur(2, 3), positionCible(-1, -1);

         list <Triangle> topologie;

            topologie.push_back(OAB);
            topologie.push_back(CDE);
   
            Tests::Unit(true, Radar::cibleCachee(positionPorteur, positionCible, topologie));
         }

         Tests::Case("Cas de plusieurs iles / Point cible visible"); {
         Point positionPorteur(2, 3), positionCible(-1, 3.5);

         list <Triangle> topologie;

            topologie.push_back(OAB);
            topologie.push_back(CDE);
   
            Tests::Unit(false, Radar::cibleCachee(positionPorteur, positionCible, topologie));
         }

   Tests::End();
}
