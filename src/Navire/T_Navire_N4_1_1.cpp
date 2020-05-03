//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Tests unitaires de la methode deplacer (Lot 1)
//                 (Cas nominaux / Une seule ile / Sans echouage)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Navire", "1.3.0");
   
      Tests::Design("Controle de la methode deplacer (Lot 1)", 3);
      Point O(0, 0), A(2, 0), B(0, 2);
      Triangle OAB(O, A, B);
      Ile* pIles[]= {new Ile("OAB", OAB), NULL};

         Tests::Case("Cas d'une seule ile / Direction opposee l'ile"); {
         Point P(2, 2); Vecteur vitesse(0.5, 0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(2.5, 2.5)", leFoch.position()->toString());
         }

         Tests::Case("Cas d'une seule ile / Direction vers l'ile"); {
         Point P(2, 2); Vecteur vitesse(-0.5, -0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(1.5, 1.5)", leFoch.position()->toString());
         }

         Tests::Case("Cas d'une seule ile / Direction parallele a l'ile"); {
         Point P(2, 2); Vecteur vitesse(-0.5, 0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(1.5, 2.5)", leFoch.position()->toString());
         }

         Tests::Case("Cas d'une seule ile / Direction vers extremite A de l'ile"); {
         Point P(2, 2); Vecteur vitesse(0, -0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(2, 1.5)", leFoch.position()->toString());
         }

         Tests::Case("Cas d'une seule ile / Direction vers extremite B de l'ile"); {
         Point P(2, 2); Vecteur vitesse(-1, 0);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(1, 2)", leFoch.position()->toString());
         }

   Tests::End();
}
