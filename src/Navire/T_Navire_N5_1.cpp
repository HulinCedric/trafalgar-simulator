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
   
      Tests::Design("Controle de la methode calculerPertes", 3);
      Point O(0, 0), A(1.5, 0), B(0, 1.5);   Triangle OAB(O, A, B);
      Point C(-200, -200), D(-215, -200), E(-200, -215);   Triangle CDE(C, D, E);
      Point F(-300, -300), G(-310, -300), H(-300, -312); Triangle FGH(F, G, H);
	  Point I(-400, -400), J(-410, -400), K(-400, -412); Triangle IJK(I, J, K);
	  Point L(-600, -600), M(-610, -600), N(-600, -612); Triangle LMN(L, M, N);
      Point P(-850, -850), Q(-870, -850), R(-850, -870); Triangle PQR(P, Q, R);

      Ile* laCrete = new Ile("Crete", OAB);
      Ile* laCorse = new Ile("Corse", CDE);
      Ile* laReunion = new Ile("Reunion", FGH);
	  Ile* laMartinique = new Ile("Martinique", IJK);
	  Ile* lesBahamas = new Ile("Bahamas", LMN);
	  Ile* laGuadeloupe = new Ile("Guadeloupe", PQR);


         Tests::Case("calculerPertes : distance : 0"); {
         Point P(0, 0); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laCrete->modifierMeteo(CALME);
            
            Tests::Unit(100, leFoch.calculerPertes(laCrete,100));

         }

		 Tests::Case("calculerPertes : distance : 400-0 meteo : CALME"); {
         Point P(200, 200); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laCrete->modifierMeteo(CALME);
            
            Tests::Unit(90, leFoch.calculerPertes(laCrete,100));

         }

		 Tests::Case("calculerPertes : distance : 400-0 meteo : AGITEE"); {
         Point P(200, 200); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laCrete->modifierMeteo(AGITEE);
            
            Tests::Unit(85, leFoch.calculerPertes(laCrete,100));

         }

		 Tests::Case("calculerPertes : distance : 400-0 meteo : TRES_AGITEE"); {
         Point P(200, 200); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laCrete->modifierMeteo(TRES_AGITEE);
            
            Tests::Unit(70, leFoch.calculerPertes(laCrete,100));

         }

		 Tests::Case("calculerPertes : distance : 400-0 meteo : TEMPETE"); {
         Point P(200, 200); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laCrete->modifierMeteo(TEMPETE);
            
            Tests::Unit(60, leFoch.calculerPertes(laCrete,100));

         }
//////////////////////////////////////////////////////////////////////////////////////////

		 Tests::Case("calculerPertes : distance : 700-400 meteo : CALME"); {
         Point P(200, 200); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laCorse->modifierMeteo(CALME);
            
            Tests::Unit(70, leFoch.calculerPertes(laCorse,100));

         }

		 Tests::Case("calculerPertes : distance : 700-400 meteo : AGITEE"); {
		 Point P(200, 200); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laCorse->modifierMeteo(AGITEE);
            
            Tests::Unit(65, leFoch.calculerPertes(laCorse,100));

         }

		 Tests::Case("calculerPertes : distance : 700-400 meteo : TRES_AGITEE"); {
         Point P(200, 200); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laCorse->modifierMeteo(TRES_AGITEE);
            
            Tests::Unit(60, leFoch.calculerPertes(laCorse,100));

         }

		 Tests::Case("calculerPertes : distance : 700-400 meteo : TEMPETE"); {
         Point P(200, 200); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laCorse->modifierMeteo(TEMPETE);
            
            Tests::Unit(50, leFoch.calculerPertes(laCorse,100));

         }

//////////////////////////////////////////////////////////////////////////////////////////

		 Tests::Case("calculerPertes : distance : 1000-700 meteo : CALME"); {
         Point P(300, 300); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laReunion->modifierMeteo(CALME);
            
            Tests::Unit(65, leFoch.calculerPertes(laReunion,100));

         }

		 Tests::Case("calculerPertes : distance : 1000-700 meteo : AGITEE"); {
		 Point P(300, 300); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laReunion->modifierMeteo(AGITEE);
            
            Tests::Unit(60, leFoch.calculerPertes(laReunion,100));

         }

		 Tests::Case("calculerPertes : distance : 1000-700 meteo : TRES_AGITEE"); {
         Point P(300, 300); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laReunion->modifierMeteo(TRES_AGITEE);
            
            Tests::Unit(55, leFoch.calculerPertes(laReunion,100));

         }

		 Tests::Case("calculerPertes : distance : 1000-700 meteo : TEMPETE"); {
         Point P(300, 300); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laReunion->modifierMeteo(TEMPETE);
            
            Tests::Unit(45, leFoch.calculerPertes(laReunion,100));

         }

//////////////////////////////////////////////////////////////////////////////////////////

		 Tests::Case("calculerPertes : distance : 1300-1000 meteo : CALME"); {
         Point P(400, 400); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laMartinique->modifierMeteo(CALME);
            
            Tests::Unit(50, leFoch.calculerPertes(laMartinique,100));

         }

		 Tests::Case("calculerPertes : distance : 1300-1000 meteo : AGITEE"); {
		 Point P(400, 400); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laMartinique->modifierMeteo(AGITEE);
            
            Tests::Unit(45, leFoch.calculerPertes(laMartinique,100));

         }

		 Tests::Case("calculerPertes : distance : 1300-1000 meteo : TRES_AGITEE"); {
         Point P(400, 400); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laMartinique->modifierMeteo(TRES_AGITEE);
            
            Tests::Unit(40, leFoch.calculerPertes(laMartinique,100));

         }

		 Tests::Case("calculerPertes : distance : 1300-1000 meteo : TEMPETE"); {
         Point P(400, 400); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laMartinique->modifierMeteo(TEMPETE);
            
            Tests::Unit(35, leFoch.calculerPertes(laMartinique,100));

         }

//////////////////////////////////////////////////////////////////////////////////////////

		 Tests::Case("calculerPertes : distance : 1700-1300 meteo : CALME"); {
         Point P(400, 400); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			lesBahamas->modifierMeteo(CALME);
            
            Tests::Unit(40, leFoch.calculerPertes(lesBahamas,100));

         }

		 Tests::Case("calculerPertes : distance : 1700-1300 meteo : AGITEE"); {
		 Point P(400, 400); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			lesBahamas->modifierMeteo(AGITEE);
            
            Tests::Unit(35, leFoch.calculerPertes(lesBahamas,100));

         }

		 Tests::Case("calculerPertes : distance : 1700-1300 meteo : TRES_AGITEE"); {
         Point P(400, 400); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			lesBahamas->modifierMeteo(TRES_AGITEE);
            
            Tests::Unit(30, leFoch.calculerPertes(lesBahamas,100));

         }

		 Tests::Case("calculerPertes : distance : 1700-1300 meteo : TEMPETE"); {
         Point P(400, 400); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			lesBahamas->modifierMeteo(TEMPETE);
            
            Tests::Unit(25, leFoch.calculerPertes(lesBahamas,100));

         }

//////////////////////////////////////////////////////////////////////////////////////////

		 Tests::Case("calculerPertes : distance : 2000-1700 meteo : CALME"); {
         Point P(500, 500); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laGuadeloupe->modifierMeteo(CALME);
            
            Tests::Unit(30, leFoch.calculerPertes(laGuadeloupe,100));

         }

		 Tests::Case("calculerPertes : distance : 2000-1700 meteo : AGITEE"); {
		 Point P(400, 400); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laGuadeloupe->modifierMeteo(AGITEE);
            
            Tests::Unit(25, leFoch.calculerPertes(laGuadeloupe,100));

         }

		 Tests::Case("calculerPertes : distance : 2000-1700 meteo : TRES_AGITEE"); {
         Point P(400, 400); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laGuadeloupe->modifierMeteo(TRES_AGITEE);
            
            Tests::Unit(20, leFoch.calculerPertes(laGuadeloupe,100));

         }

		 Tests::Case("calculerPertes : distance : 2000-1700 meteo : TEMPETE"); {
         Point P(400, 400); Vecteur V(0, 1);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P, V, 1100);

			laGuadeloupe->modifierMeteo(TEMPETE);
            
            Tests::Unit(10, leFoch.calculerPertes(laGuadeloupe,100));

         }


   Tests::End();
}
