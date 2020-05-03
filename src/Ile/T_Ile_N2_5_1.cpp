//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Ile - Tests unitaires de calculerPertes
//              (Premiere forme)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Ile.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Ile", "1.4.0");

      Tests::Design("Controle des accesseurs de modification (Lot 3)", 3);
      Point O(0, 0), A(-4, -7), B(12, -7);
      Triangle OAB(O, A, B);


         Tests::Case("Methode calculerPertes / Cas nominal"); {
         Point P0(0, 0), P1(4.25, 0), P2(0, 3.75);
         Ile laCrete("Crete", OAB);

            laCrete.ajouterTroupes("rouge", P0, 300);
            laCrete.ajouterTroupes("rouge", P1, 200);
            laCrete.ajouterTroupes("bleu",  P2, 1000);

			 Tests::Unit(200,  laCrete.effectifs("rouge", P1));
            Tests::Unit(1000, laCrete.effectifs("bleu",  P2));

			Tests::Unit(0, laCrete.calculerPertes("rouge",P0, 300));
			Tests::Unit(1800, laCrete.calculerPertes("bleu",P2, 1000));

            laCrete.retirerTroupes("rouge",P1, 50);
            Tests::Unit(150,  laCrete.effectifs("rouge", P1));
         }


   Tests::End();
}
