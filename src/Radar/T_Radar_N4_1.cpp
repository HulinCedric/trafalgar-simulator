//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Radar - Tests unitaires du service observer (Lot 1)
//                 (Cas nominaux / Une seule ile)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Radar.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Radar", "1.0.0");
   
      Tests::Design("Controle du service observer (Lot 1)", 3);
      Point O(0, 0), A(2, 0), B(0, 2);
      Triangle OAB(O, A, B);

         Tests::Case("Cas d'une seule ile et deux navires / Cible cachee par l'ile"); {
         list <Triangle> topologie; 
         list <Point>    positionsNavires;
         Point positionPorteur(1, 3), positionCible(1, -1);

         Radar R0(20, 1);
         list <echo* >* pResultat;

            topologie.push_back(OAB);

            positionsNavires.push_back(positionPorteur);
            positionsNavires.push_back(positionCible);

            pResultat= R0.observer(positionPorteur, topologie, positionsNavires);
   
            Tests::Unit(0, pResultat->size());
         }

		 Tests::Case("Cas d'une seule ile et deux navires / Cible visible"); {
         list <Triangle> topologie; 
         list <Point>    positionsNavires;
         Point positionPorteur(1, 3), positionCible(3, 2);

         Radar R0(20, 1);
         list <echo* >* pResultat;

            topologie.push_back(OAB);

            positionsNavires.push_back(positionPorteur);
            positionsNavires.push_back(positionCible);

            pResultat= R0.observer(positionPorteur, topologie, positionsNavires);
   
            Tests::Unit(1, pResultat->size());

			list <echo* >::iterator k= pResultat->begin();

            Tests::Unit(4., (double)(*k)->real());
			Tests::Unit(3., (double)(*k)->imag());
         }

   Tests::End();
}
