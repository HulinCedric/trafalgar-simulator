//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Tests unitaires de la methode deplacer (Lot 2)
//                 (Cas nominaux / Une seule ile / Avec echouage)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Navire", "1.3.0");
   
      Tests::Design("Controle de la methode deplacer (Lot 2)", 3);
      Point O(0, 0), A(2, 0), B(0, 2);
      Triangle OAB(O, A, B);
      Ile* pIles[]= {new Ile("OAB", OAB), NULL};

         Tests::Case("Cas d'une seule ile / Echouage sur la cote AB de l'ile"); {
         Point P(1.2, 1.2); Vecteur vitesse(-0.5, -0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(1, 1)", leFoch.position()->toString());
         }

         Tests::Case("Cas d'une seule ile / Echouage sur la cote OA de l'ile"); {
         Point P(1, -0.2); Vecteur vitesse(0, 0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(1, 0)", leFoch.position()->toString());
         }

         Tests::Case("Cas d'une seule ile / Echouage sur la cote OB de l'ile"); {
         Point P(-0.5, 1); Vecteur vitesse(1, 0);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(0, 1)", leFoch.position()->toString());
         }

         Tests::Case("Cas d'une seule ile / Echouage sur extremite A de l'ile"); {
         Point P(2, 0.2); Vecteur vitesse(0, -0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(2, 0)", leFoch.position()->toString());
         }

         Tests::Case("Cas d'une seule ile / Echouage sur extremite B de l'ile"); {
         Point P(0, 2.2); Vecteur vitesse(0, -0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(0, 2)", leFoch.position()->toString());
         }

         Tests::Case("Cas d'une seule ile / Echouage sur extremite O de l'ile"); {
         Point P(-0.2, -0.2); Vecteur vitesse(0.5, 0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(0, 0)", leFoch.position()->toString());
         }

   Tests::End();
}
