//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Tests unitaires des accesseurs de consultation
//                    (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar.Trafalgar", "1.0.0");

      Tests::Design("Controle des accesseurs de consultation", 3);

         Tests::Case("Methode nombreIles"); {

            Tests::Unit(0,  Trafalgar::nombreIles());
         }

         Tests::Case("Methode nombreNavires"); {

            Tests::Unit(0,  Trafalgar::nombreNavires());
         }

         Tests::Case("Methode nombreFlottes"); {

            Tests::Unit(0,  Trafalgar::nombreFlottes());
         }

   Tests::End();
}
