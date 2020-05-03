//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Tests unitaires des accesseurs de modification (Lot 1)
//                    (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Trafalgar", "1.0.0");

      Tests::Design("Controle des accesseurs de modification / Lot 1", 3);

         Tests::Case("Controle de la methode ajouterIle"); {
         Point O(0, 0), A(1.5, 0), B(0, 1.5);   Triangle OAB(O, A, B);
         Point C(1, 2), D(1, 3.5), E(2.5, 2);   Triangle CDE(C, D, E);

            Tests::Unit(0,  Trafalgar::nombreIles());
			 try{
            Trafalgar::ajouterIle(new Ile("OAB", OAB));
            Tests::Unit(1,  Trafalgar::nombreIles());

            Trafalgar::ajouterIle(new Ile("CDE", CDE));
			 Tests::Unit(2,  Trafalgar::nombreIles());}
			 catch (double e) {
				 cout << e;
			 }
         }

         Tests::Case("Controle de la methode ajouterNavire"); {
         Point P1(2, 0); Vecteur V1(-1, 1);
         Navire* pN1= new Navire(FREGATE_DEFENSE_AERIENNE,"Foch", "bleue", P1, V1, 1100);

            Tests::Unit(0,  Trafalgar::nombreNavires());
            Tests::Unit(0,  Trafalgar::nombreFlottes());
         
            pN1->vitesseMax(1.5);
            Trafalgar::ajouterNavire(pN1);
            
            Tests::Unit(1,  Trafalgar::nombreNavires());
            Tests::Unit(1,  Trafalgar::nombreFlottes());
         }

   Tests::End();
}
