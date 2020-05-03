//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Tests unitaires des accesseurs de modification
//                 (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Navire", "1.3.0");

      Tests::Design("Controle des accesseurs de modification", 3);
      Point P1(250, 755); 
      Vecteur V1(-2, -1.5);
      Navire leFoch(FREGATE_DEFENSE_AERIENNE, "Foch", "bleue", P1, V1, 1100);
		Arme* mitra= new Arme(MITRAILLEUSE);
		Arme* canon= new Arme(CANON);

         Tests::Case("Methode position"); {
         Point P2(250, 755);
   
            leFoch.position(P2);
            Tests::Unit(P2.toString(), leFoch.position()->toString());
         }

         Tests::Case("Methode vitesse"); {
         Vecteur V2(-2, -1.25);

            leFoch.vitesse(V2);
            Tests::Unit(V2.toString(), leFoch.vitesse()->toString());
         }

         Tests::Case("Methode effectifs"); {

            leFoch.nbSoldats(200);
            Tests::Unit(200,  leFoch.nbSoldats());
         }

         Tests::Case("Methode vitesseMax"); {

            leFoch.vitesseMax(5.);
            Tests::Unit(5.,  leFoch.vitesseMax());
         }

		 Tests::Case("Methode meteo"); {

            leFoch.modifierMeteo(CALME);
            Tests::Unit(1,  leFoch.meteo());
         }
	
		Tests::Case("Methode ajouterArmes"); {
		
			leFoch.ajouterArmes(mitra);
			leFoch.ajouterArmes(canon);
			Tests::Unit(2,  leFoch.nbArmes());
		}

   Tests::End();
}
