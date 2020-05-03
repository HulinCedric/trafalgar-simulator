//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Tests unitaires de la methode deplacer (Lot 4)
//                 (Cas nominaux / Deux iles / Sans echouage)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Navire", "1.3.0");
   
      Tests::Design("Controle de la methode deplacer (Lot 4)", 3);
      Point O(0, 0), A(2, 0), B(0, 2); Triangle OAB(O, A, B);
      Point C(4, 0), D(4, 4), E(0, 4); Triangle CDE(C, D, E);

      Ile* pIles[]= {new Ile("OAB", OAB), new Ile("CDE", CDE), NULL};

         Tests::Case("Cas de deux iles / Direction opposee aux deux iles"); {
         Point P(3, 0); Vecteur vitesse(0, -0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(3, -0.5)", leFoch.position()->toString());
         }

         Tests::Case("Cas de deux iles / Direction vers la premiere ile"); {
         Point P(1.5, 1.5); Vecteur vitesse(-0.2, -0.2);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(1.3, 1.3)", leFoch.position()->toString());
         }

         Tests::Case("Cas de deux iles / Direction vers la seconde ile"); {
         Point P(1.5, 1.5); Vecteur vitesse(0.2, 0.2);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(1.7, 1.7)", leFoch.position()->toString());
         }

         Tests::Case("Cas de deux iles / Direction parallele aux deux iles"); {
         Point P(1.5, 1.5); Vecteur vitesse(-0.2, 0.2);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(1.3, 1.7)", leFoch.position()->toString());
         }

         Tests::Case("Cas de deux iles / Direction vers extremite A de OAB"); {
         Point P(1.5, 1); Vecteur vitesse(0, -0.2);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(1.5, 0.8)", leFoch.position()->toString());
         }

         Tests::Case("Cas de deux iles / Direction vers extremite B de OAB"); {
         Point P(1.5, 1); Vecteur vitesse(-0.2, 0);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(1.3, 1)", leFoch.position()->toString());
         }

         Tests::Case("Cas de deux iles / Direction vers extremite C de CDE"); {
         Point P(3, 0); Vecteur vitesse(0.5, 0);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(3.5, 0)", leFoch.position()->toString());
         }

         Tests::Case("Cas de deux iles / Direction vers extremite D de CDE"); {
         Point P(4.5, 4.5); Vecteur vitesse(0, -0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(4.5, 4)", leFoch.position()->toString());
         }

         Tests::Case("Cas de deux iles / Direction vers extremite E de CDE"); {
         Point P(0, 3); Vecteur vitesse(0, 0.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);
   
            leFoch.deplacer(pIles);
            Tests::Unit("(0, 3.5)", leFoch.position()->toString());
         }

   Tests::End();
}
