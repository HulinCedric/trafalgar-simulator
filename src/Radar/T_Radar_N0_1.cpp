//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Radar - Tests unitaires de la methode privee calculerEchoRadar
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Radar.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Radar", "1.0.0");

      Tests::Design("Methode calculerEchoRadar", 3);

         //srand(time(NULL));

         Tests::Case("Cible a mi-portee"); {
         Point positionPorteur(1200, 1200);
         Point positionCible(1230, 1230);
         Radar R0(100, 2);
         complex <int>* pResultat;

            pResultat= R0.calculerEchoRadar(positionPorteur, positionCible);

            Tests::Unit(1231, pResultat->real());
            Tests::Unit(1231, pResultat->imag());
         }

         Tests::Case("Cible voisine de la portee maximale"); {
         Point positionPorteur(1200, 5);
         Point positionCible(1290, 5);
         Radar R0(100, 2);
         complex <int>* pResultat;

            pResultat= R0.calculerEchoRadar(positionPorteur, positionCible);

            Tests::Unit(1292, pResultat->real());
            Tests::Unit(5,    pResultat->imag());
         }

   Tests::End();
}
