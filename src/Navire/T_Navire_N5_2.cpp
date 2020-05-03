//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Tests unitaires de la methode calculerPertes
//                 (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Navire", "1.3.0");
   
      Tests::Design("Controle des methode Debarquer/Embarquer", 3);
      Point O(0, 0), A(1.5, 0), B(0, 1.5);   Triangle OAB(O, A, B);
    

      Ile* laCrete = new Ile("Crete", OAB);
      


         Tests::Case("Debarquer : distance : 0"); {
         Point P(0, 0); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, V, 1100);

			laCrete->modifierMeteo(CALME);
            
            Tests::Unit(25, leFoch.debarquer(laCrete,"bleue",O,25));
			Tests::Unit(1075, leFoch.nbSoldats());
         }

		 Tests::Case("Debarquer : distance : 400-0 meteo : CALME"); {
         Point P(200, 200); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, V, 1100);

			laCrete->modifierMeteo(CALME);
            
            Tests::Unit(90, leFoch.debarquer(laCrete,"bleue",O,100));
			Tests::Unit(1000, leFoch.nbSoldats());

			Tests::Unit(90, leFoch.debarquer(laCrete,"bleue",A,100));
			Tests::Unit(900, leFoch.nbSoldats());
         }

		 Tests::Case("Embarquer : distance : 400-0 meteo : AGITEE"); {
         Point P(200, 200); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P, V, 1100);

			laCrete->modifierMeteo(AGITEE);

			leFoch.debarquer(laCrete,"bleue",B,100);
			leFoch.debarquer(laCrete,"bleue",A,100);
			leFoch.debarquer(laCrete,"bleue",B,40);

			Tests::Unit(51, leFoch.embarquer(laCrete,"bleue",B,60));
			Tests::Unit(911, leFoch.nbSoldats());
         }

   Tests::End();
}
