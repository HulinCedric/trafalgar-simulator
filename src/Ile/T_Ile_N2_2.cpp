//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Ile - Tests unitaires des accesseurs de consultation
//              (Lot 1 / Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Ile.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Ile", "1.4.0");

      Tests::Design("Controle des accesseurs de consultation (Lot 1)", 3);
      Point O(0, 0), A(-4, -7), B(12, -7);
      Triangle OAB(O, A, B);
      Ile laCrete("Crete", OAB);

         Tests::Case("Methode nom"); {

            Tests::Unit("Crete", (char*)laCrete.nom()->c_str());
         }

         Tests::Case("Methode lieux"); {

            Tests::Unit(OAB.toString(), laCrete.lieux()->toString());
         }

         Tests::Case("Methode meteo"); {

            Tests::Unit(0, laCrete.meteo());
         }

   Tests::End();
}
