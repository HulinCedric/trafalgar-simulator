//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Tests unitaires de la methode deplacer (Lot 3)
//                 (Cas nominaux / Cas particuliers d'echouage)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Navire", "1.3.0");
   
      Tests::Design("Controle de la methode deplacer (Lot 3)", 3);
      Point O(0, 0), A(10, 0.5), B(0, 1);
      Triangle OAB(O, A, B);
      Ile* pIles[]= {new Ile("OAB", OAB), NULL};

         Tests::Case("Cas d'une echouage sur franchissement"); {
         Point P(9.5, 0.25); Vecteur vitesse(1, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(9.73684, 0.486842)", leFoch.position()->toString());
         }

         Tests::Case("Cas d'une echouage sur une extremite"); {
         Point P(0.5, -0.5); Vecteur vitesse(-1, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(0, 0)", leFoch.position()->toString());
         }

   Tests::End();
}
