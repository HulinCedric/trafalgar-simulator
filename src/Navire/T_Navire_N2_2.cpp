//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Tests unitaires des accesseurs de consultation
//                 (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Navire", "1.3.0");

      Tests::Design("Controle des accesseurs de consultation", 3);
      Point A(250, 755); Vecteur V1(-20, -74.5);
      Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", A, V1, 1100);

         Tests::Case("Methode position"); {
   
            Tests::Unit(A.toString(), leFoch.position()->toString());
         }

         Tests::Case("Methode vitesse"); {

            Tests::Unit(V1.toString(), leFoch.vitesse()->toString());
         }

         Tests::Case("Methode effectifs"); {

            Tests::Unit(1100,  leFoch.nbSoldats());
         }

   Tests::End();
}
