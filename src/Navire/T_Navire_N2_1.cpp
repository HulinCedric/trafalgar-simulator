//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Tests unitaires des predicats predefinis
//                 (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Navire", "1.3.0");

      Tests::Design("Controle des predicats predefinis", 3);
      Point A(250, 755); Vecteur V(-20, -74.5);
      Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", A, V, 1100);
      Navire x;

         Tests::Case("Predicat neutre"); {

            Tests::Unit(true,  x.neutre());
            Tests::Unit(false, leFoch.neutre());
         }

         Tests::Case("Predicat ok"); {

            Tests::Unit(true,  x.ok());
            Tests::Unit(true,  leFoch.ok());
         }

   Tests::End();
}
