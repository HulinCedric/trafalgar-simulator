//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Radar - Tests unitaires des accesseurs de consultation
//                (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Radar.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Radar", "1.0.0");

      Tests::Design("Controle des accesseurs de consultation", 3);
      Radar R0(100, 2);

         Tests::Case("Methode etat"); {
   
            Tests::Unit(1, R0.etat());
         }

         Tests::Case("Methode portee"); {

            Tests::Unit(100, R0.portee());
         }

         Tests::Case("Methode precision"); {

            Tests::Unit(2, R0.precision());
         }

   Tests::End();
}
