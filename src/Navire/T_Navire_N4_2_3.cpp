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
   
      Tests::Design("Controle de la methode manoeuvrer / Modification vitesse et direction", 3);

         Tests::Case("Changement de direction de -PI/4. et acceleration"); {
         Point P(1, 1); Vecteur V(-1, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, V, 1100);

            leFoch.vitesseMax(3);
            leFoch.manoeuvrer(-PI/4., 0.25);
            
            Tests::Unit("(0, 1.76777)", leFoch.vitesse()->toString());
         }

         Tests::Case("Changement de direction de PI/2 et ralentissement"); {
         Point P(1, 1); Vecteur V(-1, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, V, 1100);

            leFoch.vitesseMax(1.5);
            leFoch.manoeuvrer(PI/2., -0.15);
            
            Tests::Unit("(-0.85, -0.85)", leFoch.vitesse()->toString());
         }

   Tests::End();
}
