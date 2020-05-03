//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Radar - Tests unitaires de la methode de classe privee cibleMasquee
//                 (Cas nominaux / Un seul navire tiers)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Radar.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Radar", "1.0.0");
   
      Tests::Design("Controle de la methode de classe privee cibleMasquee", 3);

         Tests::Case("Cas d'un seul navire tiers / Point cible masque par ce navire"); {
         Point positionPorteur(1, 1), positionCible(3, 3);
         Point positionTiers(2, 2);
         Point* pResultat;

         list <Point> positionsNavires;

            positionsNavires.push_back(positionPorteur);
            positionsNavires.push_back(positionCible);
            positionsNavires.push_back(positionTiers);

            pResultat= Radar::cibleMasquee(positionPorteur, positionCible, positionsNavires);
            Tests::Unit(positionTiers.toString(), pResultat->toString());
         }

         Tests::Case("Cas d'un seul navire tiers / Point cible visible"); {
         Point positionPorteur(1, 1), positionCible(3, 3);
         Point positionTiers(2, 3);
         Point* pResultat;

         list <Point> positionsNavires;

            positionsNavires.push_back(positionPorteur);
            positionsNavires.push_back(positionCible);
            positionsNavires.push_back(positionTiers);

            pResultat= Radar::cibleMasquee(positionPorteur, positionCible, positionsNavires);
            Tests::Unit((int)NULL, (int)pResultat);
         }

         Tests::Case("Cas d'un seul navire tiers / Point cible visible a l'oppose de ce navire"); {
         Point positionPorteur(1, 1), positionCible(3, 3);
         Point positionTiers(-2, -2);
         Point* pResultat;

         list <Point> positionsNavires;

            positionsNavires.push_back(positionPorteur);
            positionsNavires.push_back(positionCible);
            positionsNavires.push_back(positionTiers);

            pResultat= Radar::cibleMasquee(positionPorteur, positionCible, positionsNavires);
            Tests::Unit((int)NULL, (int)pResultat);
         }

   Tests::End();
}
