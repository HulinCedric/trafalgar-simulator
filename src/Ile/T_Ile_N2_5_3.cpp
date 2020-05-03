//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Tests unitaires de la methode calculerPertes
//                 (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Ile.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Navire", "1.3.0");
   
      Tests::Design("Controle des methode Debarquer/Embarquer", 3);
		Point O(0, 0), A(-4, -7), B(12, -7);
		Triangle OAB(O, A, B);
		Ile laCrete("Crete", OAB);



         Tests::Case("Debarquer : distance : 0"); {
         Point P(0, 0); Vecteur V(0, 1);


				 Tests::Unit(1000, laCrete.debarquement("rouge", O, 1000));
				 Tests::Unit(1000, laCrete.effectifs("rouge",O));
				 Tests::Unit(0, laCrete.effectifs("bleu",A));

				 Tests::Unit(1080, laCrete.debarquement("bleu", A, 1800));
				 Tests::Unit(0, laCrete.effectifs("rouge",O));
				 Tests::Unit(1080, laCrete.effectifs("bleu",A));
				 
				 Tests::Unit(1180, laCrete.debarquement("bleu", A, 100));
				 Tests::Unit(0, laCrete.effectifs("rouge",O));
				 Tests::Unit(1180, laCrete.effectifs("bleu",A));
				 
				 Tests::Unit(240, laCrete.debarquement("rouge", O, 1200));
				 Tests::Unit(240, laCrete.effectifs("rouge",O));
				 Tests::Unit(0, laCrete.effectifs("bleu",A));
				 
				 Tests::Unit(240, laCrete.embarquement("rouge", O, 500));
				 Tests::Unit(0, laCrete.effectifs("rouge",O));
				 Tests::Unit(0, laCrete.effectifs("bleu",A));
         }


   Tests::End();
}
