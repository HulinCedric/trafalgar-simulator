//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Ile - Tests unitaires des accesseurs de modification
//              (Lot 2 / Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Ile.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Ile", "1.4.0");

      Tests::Design("Controle des accesseurs de modification (Lot 2)", 3);
      Point O(0, 0), A(-4, -7), B(12, -7);
      Triangle OAB(O, A, B);

         Tests::Case("Methode ajouterTroupes / Cas de positions distinctes"); {
         Point P0(0, 0), P1(4.25, 0), P2(0, 3.75);
         Ile laCrete("Crete", OAB);

            laCrete.ajouterTroupes("rouge", P0, 300);
            Tests::Unit(300,  laCrete.effectifs("rouge", P0));

            laCrete.ajouterTroupes("rouge", P1, 200);
            Tests::Unit(500,  laCrete.effectifs("rouge"));

            laCrete.ajouterTroupes("bleu", P2, 1000);
            Tests::Unit(1000,  laCrete.effectifs("bleu",P2));

            laCrete.ajouterTroupes("rouge",P1, 100);
            Tests::Unit(600,  laCrete.effectifs("rouge"));
         }

         Tests::Case("Methode ajouterTroupes / Cas d'une position identique"); {
         Point P0(0, 0), P1(4.25, 0), P2(0, 3.75);
         Ile laCrete("Crete", OAB);

            laCrete.ajouterTroupes("rouge", P0, 300);
            Tests::Unit(300,  laCrete.effectifs("rouge"));

            laCrete.ajouterTroupes("rouge", P1, 200);
            Tests::Unit(500,  laCrete.effectifs("rouge"));

            laCrete.ajouterTroupes("bleu", P2, 1000);
            Tests::Unit(1000,  laCrete.effectifs("bleu"));

            laCrete.ajouterTroupes("rouge",P0, 600);
            Tests::Unit(1100,  laCrete.effectifs("rouge"));
         }

   Tests::End();
}
