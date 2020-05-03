//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Tests unitaires des constructeurs
//                 (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Navire", "1.3.0");

      Tests::Design("Controle des constructeurs", 3);

         Tests::Case("Constructeur par defaut"); {
         Navire x;

            Tests::Unit("---",  x.toString());
         }

         Tests::Case("Premier constructeur normal"); {
         Point A(250, 755); Vecteur V(-20, -74.5);
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", A, V, 1100);

         char attendu[]= "[Flotte bleue / Foch : (250, 755) (-20, -74.5) / 1100][FLOTTE]";

            Tests::Unit(attendu, leFoch.toString());
         }

         Tests::Case("Second constructeur normal"); {
         Navire leFoch(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue");

         char attendu[]= "[Flotte bleue / Foch : (0, 0) (0, 0) / 0][FLOTTE]";

            Tests::Unit(attendu, leFoch.toString());
         }

   Tests::End();
}
