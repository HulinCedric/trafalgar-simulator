//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Ile - Tests unitaires des constructeurs
//              (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Ile.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Ile", "1.4.0");

      Tests::Design("Controle des constructeurs", 3);

         Tests::Case("Constructeur par defaut"); {
         Ile x;

            Tests::Unit("---",  x.toString());
         }

         Tests::Case("Constructeur normal"); {
         Point O(0, 0), A(-4, -7), B(12, -7);
         Triangle OAB(O, A, B);
         Ile laCrete("Crete", OAB);

            Tests::Unit("[Crete / [(0, 0), (-4, -7), (12, -7)]]", laCrete.toString());
         }

   Tests::End();
}
