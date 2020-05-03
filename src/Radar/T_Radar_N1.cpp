//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Radar - Tests unitaires des constructeurs
//                (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Radar.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Radar", "1.0.0");

      Tests::Design("Controle des constructeurs", 3);

         Tests::Case("Constructeur par defaut"); {
         Radar x;

            Tests::Unit("---",  x.toString());
         }

         Tests::Case("Constructeur normal"); {
         Radar R0(100, 2);

         char attendu[]= "<OPERATIONNEL / 100 - 2>";

            Tests::Unit(attendu, R0.toString());
         }

   Tests::End();
}
