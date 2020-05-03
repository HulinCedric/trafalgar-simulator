//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Ile - Tests unitaires des accesseurs de modification
//              (Lot 1 / Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Ile.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Ile", "1.4.0");

      Tests::Design("Controle des accesseurs de modification (Lot 1)", 3);
      Point O(0, 0), A(-4, -7), B(12, -7);
      Triangle OAB(O, A, B);
      
         Tests::Case("Methode meteo"); {
         Ile laCrete("Crete", OAB);

            laCrete.modifierMeteo(CALME);
            Tests::Unit(CALME, laCrete.meteo());
         }

   Tests::End();
}
