//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Tests unitaires du service deplacer
//                    Contexte general avec plusieurs navires 
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
   pN1->vitesseMax(1.5);

   // --- Batiment de Projection et de Commandement (BPC) Tonnerre
   //
   Navire* pN2= new Navire(BPC, "Tonnerre", "rouge");
   pN2->vitesseMax(1);
  
      Tests::Design("Mise en place et controle du contexte de simulation", 3);

         // Mettre en place la zone de confrontation
         // 
         Trafalgar::ajouterIle(new Ile("OAB", OAB));
         Trafalgar::ajouterIle(new Ile("CDE", CDE)); 
         Trafalgar::ajouterIle(new Ile("FGH", FGH));

         // Mettre en place le premier navire
         //
         Point P1(15, 14); Vecteur V1(-1, -1);

         Trafalgar::ajouterNavire(pN1);
		 Trafalgar::placer("Cassard", P1, V1);

         // Mettre en place le second navire
         //
         Point P2(-6, 0); Vecteur V2(0.5, 0.5);

         Trafalgar::ajouterNavire(pN2);
		 Trafalgar::placer("Tonnerre", P2, V2);

         // Demarrer la simulation
         //
         Trafalgar::start(2);

         // Controler l'ensemble du contexte
         //
         Tests::Case("Controle du contexte de simulation"); {

            Tests::Unit(3, Trafalgar::nombreIles());
            Tests::Unit(2, Trafalgar::nombreNavires());
         }

      Tests::Design("Controle du service deplacer / Plusieurs navires", 3);

         Tests::Case("Cas initial sans echouage"); {
         
            // Simuler 10 tops horloge H1
            //
            for (int i=0; i < 10; i++) Trafalgar::deplacer();

            // Controler la position des navires
            //
            Point* pF1= Trafalgar::obtenirNavire("Cassard")->position();
            Point* pF2= Trafalgar::obtenirNavire("Tonnerre")->position();

            Tests::Unit("(5, 4)", pF1->toString());
            Tests::Unit("(-1, 5)", pF2->toString());
         }

         Tests::Case("Poursuite avec un echouage"); {
         
            // Simuler 15 tops horloge H1
            //
            for (int i=0; i < 15; i++) Trafalgar::deplacer();

            // Controler la position courante des navires
            //
            Point* pF1= Trafalgar::obtenirNavire("Cassard")->position();
            Point* pF2= Trafalgar::obtenirNavire("Tonnerre")->position();

            Tests::Unit("(2.5, 1.5)", pF1->toString());
            Tests::Unit("(6.5, 12.5)", pF2->toString());
         }

   Tests::End();
}
