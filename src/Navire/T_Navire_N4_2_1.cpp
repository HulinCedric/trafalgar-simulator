//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Tests unitaires de la methode manoeuvrer
//                 (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Navire", "1.3.0");
   
      Tests::Design("Controle de la methode manoeuvrer / Aucune consigne", 3);

	 Tests::Case("Aucune consigne"); {
         Point P(1, 1); Vecteur V(-1, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, V, 1100);

            leFoch.vitesseMax(1.5);
            leFoch.manoeuvrer(0, 0);
            
            Tests::Unit("(-1, 1)", leFoch.vitesse()->toString());
         }
		 
      Tests::Design("Controle de la methode manoeuvrer / Modification de la vitesse", 3);

         Tests::Case("Reduction de vitesse de 10%"); {
         Point P(1, 1); Vecteur V(-1, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, V, 1100);

            leFoch.vitesseMax(1.5);
            leFoch.manoeuvrer(0, -0.1);
            
            Tests::Unit("(-0.9, 0.9)", leFoch.vitesse()->toString());
         }

         Tests::Case("Augmentation de vitesse de 20% / Sans depasser Vmax"); {
         Point P(1, 1); Vecteur V(-1, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, V, 1100);

            leFoch.vitesseMax(2.);
            leFoch.manoeuvrer(0, 0.2);
            
            Tests::Unit("(-1.2, 1.2)", leFoch.vitesse()->toString());
         }

         Tests::Case("Augmentation de vitesse de 20% / En depassant Vmax"); {
         Point P(1, 1); Vecteur V(-1, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, V, 1100);

            leFoch.vitesseMax(1.5);
            leFoch.manoeuvrer(0, 0.2);
            
            Tests::Unit("(-1.06066, 1.06066)", leFoch.vitesse()->toString());
         }

   Tests::End();
}
