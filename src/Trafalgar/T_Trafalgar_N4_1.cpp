//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Tests unitaires du service start
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

   // --- Fregate anti aerienne Cassard
   //
   Navire* pN1= new Navire(FREGATE_DEFENSE_AERIENNE, "Cassard", "bleue");
   
   // --- Batiment de Projection et de Commandement (BPC) Tonnerre
   //
   Navire* pN2= new Navire(BPC, "Tonnerre", "rouge");
  
      Tests::Design("Mise en place et controle du contexte de simulation", 3);

         // Mettre en place la zone de confrontation
         // 
         Trafalgar::ajouterIle(new Ile("OAB", OAB));
         Trafalgar::ajouterIle(new Ile("CDE", CDE)); 
         Trafalgar::ajouterIle(new Ile("FGH", FGH));

         // Mettre en place le premier navire
         //
         Point P1(15, 14); Vecteur V1(-1, -1);

         pN1->position(P1);
         pN1->vitesse(V1);
         pN1->vitesseMax(1.5);

         Trafalgar::ajouterNavire(pN1);

         // Mettre en place le second navire
         //
         Point P2(-6, 0); Vecteur V2(0.5, 0.5);

         pN2->position(P2);
         pN2->vitesse(V2);
         pN2->vitesseMax(1);

         Trafalgar::ajouterNavire(pN2);

         // Controler l'ensemble du contexte
         //
         Tests::Case("Controle du contexte de simulation"); {

            Tests::Unit(3, Trafalgar::nombreIles());
            Tests::Unit(2, Trafalgar::nombreNavires());
         }

      Tests::Design("Lancement de la simulation", 3);

         Tests::Case("Controle du service start"); {

            Trafalgar::start(2);

            Tests::Unit(2, Trafalgar::nombreFlottes());
         }

   Tests::End();
}
