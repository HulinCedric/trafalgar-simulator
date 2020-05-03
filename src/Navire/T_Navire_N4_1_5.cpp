//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Tests unitaires de la methode deplacer (Lot 5)
//                 (Cas nominaux / Deux iles / Avec echouage)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Navire", "1.3.0");
   
      Tests::Design("Controle de la methode deplacer (Lot 5)", 3);
      Point O(0, 0), A(2, 0), B(0, 2); Triangle OAB(O, A, B);
      Point C(4, 0), D(4, 4), E(0, 4); Triangle CDE(C, D, E);

      Ile* pIles[]= {new Ile("OAB", OAB), new Ile("CDE", CDE), NULL};

         Tests::Case("Cas de deux iles / Echouage sur la cote AB de OAB"); {
         Point P(1.2, 1.2); Vecteur vitesse(-0.5, -0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(1, 1)", leFoch.position()->toString());
         }

         Tests::Case("Cas de deux iles / Echouage sur la cote OA de OAB"); {
         Point P(1, -0.2); Vecteur vitesse(0, 0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(1, 0)", leFoch.position()->toString());
         }

         Tests::Case("Cas de deux iles / Echouage sur la cote OB de OAB"); {
         Point P(-0.5, 1); Vecteur vitesse(1, 0);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(0, 1)", leFoch.position()->toString());
         }

         Tests::Case("Cas de deux iles / Echouage sur extremite A de OAB"); {
         Point P(2, 0.2); Vecteur vitesse(0, -0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(2, 0)", leFoch.position()->toString());
         }

         Tests::Case("Cas de deux iles / Echouage sur extremite B de OAB"); {
         Point P(0, 2.2); Vecteur vitesse(0, -0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(0, 2)", leFoch.position()->toString());
         }

         Tests::Case("Cas de deux iles / Echouage sur extremite O de OAB"); {
         Point P(-0.2, -0.2); Vecteur vitesse(0.5, 0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(0, 0)", leFoch.position()->toString());
         }

         Tests::Case("Cas de deux iles / Echouage sur la cote CE de CDE"); {
         Point P(3, 0.5); Vecteur vitesse(0, 0.8);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(3, 1)", leFoch.position()->toString());
         }

         Tests::Case("Cas de deux iles / Echouage sur la cote CD de CDE"); {
         Point P(4.5, 3); Vecteur vitesse(-0.8, 0);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(4, 3)", leFoch.position()->toString());
         }

         Tests::Case("Cas de deux iles / Echouage sur la cote ED de CDE"); {
         Point P(1, 4.04); Vecteur vitesse(0, -0.75);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(1, 4)", leFoch.position()->toString());
         }

         Tests::Case("Cas de deux iles / Echouage sur extremite D de CDE"); {
         Point P(4.2, 4.2); Vecteur vitesse(-0.5, -0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(4, 4)", leFoch.position()->toString());
         }

   Tests::End();
}
