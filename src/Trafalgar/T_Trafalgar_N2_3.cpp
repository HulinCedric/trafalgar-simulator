//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Tests unitaires des accesseurs de modification (Lot 2)
//                    (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Trafalgar", "1.0.0");

   Point O(0, 0), A(1.5, 0), B(0, 1.5);   Triangle OAB(O, A, B);
   Point C(1, 2), D(1, 3.5), E(2.5, 2);   Triangle CDE(C, D, E);
   Point F(2, 1), G(2.5, 1.5), H(3, 0.5); Triangle FGH(F, G, H);

      Tests::Design("Mise en place du contexte de simulation", 3);

         // Ajouter les iles
         // 
         Trafalgar::ajouterIle(new Ile("OAB", OAB));
         Trafalgar::ajouterIle(new Ile("CDE", CDE)); 
         Trafalgar::ajouterIle(new Ile("FGH", FGH));

         // Ajouter les navires
         //
         Navire* pN1= new Navire(FREGATE_DEFENSE_AERIENNE, "Cassard", "bleue");
         Navire* pN2= new Navire(BPC, "Tonnerre", "rouge");

         Trafalgar::ajouterNavire(pN1);
         Trafalgar::ajouterNavire(pN2);

         // Controler l'ensemble du contexte
         //
         Tests::Case("Controle du contexte de simulation"); {

            Tests::Unit(3, Trafalgar::nombreIles());
            Tests::Unit(2, Trafalgar::nombreNavires());
         }

      Tests::Design("Controle des accesseurs de modification (Lot 2)", 3);

         Tests::Case("Methode placer"); {
         Point P1(15, 14); Vecteur V1(-1, -1);
         Point P2(-5, 0); Vecteur V2(0.5, 0.5);
         Point* pP; Vecteur* pV;

            Trafalgar::placer("Cassard",  P1, V1);
            Trafalgar::placer("Tonnerre", P2, V2);

            pP= Trafalgar::obtenirNavire("Cassard")->position();
            Tests::Unit(P1.toString(), pP->toString());

            pV= Trafalgar::obtenirNavire("Tonnerre")->vitesse();
            Tests::Unit(V2.toString(), pV->toString());
         }

   Tests::End();
}
