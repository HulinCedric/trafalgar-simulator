//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Ile - Tests unitaires des predicats predefinis
//              (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Ile.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Ile", "1.4.0");

      Tests::Design("Controle des predicats predefinis", 3);
      Point O(0, 0), A(-4, -7), B(12, -7);
      Triangle OAB(O, A, B);
      Ile x, laCrete("Crete", OAB);

         Tests::Case("Predicat neutre"); {

            Tests::Unit(true,  x.neutre());
            Tests::Unit(false, laCrete.neutre());
         }

         Tests::Case("Predicat ok"); {

            Tests::Unit(true,  x.ok());
            Tests::Unit(true,  laCrete.ok());
         }

   Tests::End();
}
