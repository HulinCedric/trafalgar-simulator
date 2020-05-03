//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Tests unitaires de la methode deplacer (Lot 6)
//                 (Cas nominaux / Trois iles)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Navire", "1.3.0");
   
      Tests::Design("Controle de la methode deplacer (Lot 6)", 3);
      Point O(0, 0), A(1.5, 0), B(0, 1.5);   Triangle OAB(O, A, B);
      Point C(1, 2), D(1, 3.5), E(2.5, 2);   Triangle CDE(C, D, E);
      Point F(2, 1), G(2.5, 1.5), H(3, 0.5); Triangle FGH(F, G, H);

      Ile* pIles[]= {new Ile("OAB", OAB), 
                     new Ile("CDE", CDE), 
                     new Ile("FGH", FGH), NULL};

         Tests::Case("Cas de trois iles / Sans echouage"); {
         Point P(2.5, 0); Vecteur vitesse(-0.2, 0.2);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);

            leFoch.deplacer(pIles);	 
            leFoch.deplacer(pIles);
            leFoch.deplacer(pIles);
            leFoch.deplacer(pIles);
            leFoch.deplacer(pIles);
            leFoch.deplacer(pIles);
            leFoch.deplacer(pIles);

            Tests::Unit("(1.1, 1.4)", leFoch.position()->toString());
         }

         Tests::Case("Cas de trois iles / Avec echouage sur OAB"); {
         Point P(2.5, 0); Vecteur vitesse(-0.3, 0.15);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, vitesse, 1100);

            leFoch.deplacer(pIles);	 
            leFoch.deplacer(pIles);
            leFoch.deplacer(pIles);
            leFoch.deplacer(pIles);
            leFoch.deplacer(pIles);
            leFoch.deplacer(pIles);
            leFoch.deplacer(pIles);

            Tests::Unit("(0.5, 1)", leFoch.position()->toString());
         }

   Tests::End();
}
