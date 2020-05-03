//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Radar - Tests unitaires des predicats predefinis
//                (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Radar.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Radar", "1.0.0");

      Tests::Design("Controle des predicats predefinis", 3);
      Radar R0(100, 2);
      Radar x;

         Tests::Case("Predicat neutre"); {

            Tests::Unit(true,  x.neutre());
            Tests::Unit(false, R0.neutre());
         }

         Tests::Case("Predicat ok"); {

            Tests::Unit(true,  x.ok());
            Tests::Unit(true,  R0.ok());
         }

   Tests::End();
}
