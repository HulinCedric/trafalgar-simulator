//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe _Trafalgar - Tests unitaires des methodes de generation de 
//                     valeurs aleatoires (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "_Trafalgar.h"
#include "../../_Tests/Tests/Tests.h"

void main () {

   Tests::Begin("_Trafalgar._Trafalgar", "1.2.0");

      Tests::Design("Controle de la generation de valeurs aleatoires", 3);

         //srand(time(NULL));
      
         Tests::Case("Methode alea / Premiere forme (intervalle)"); {

            Tests::Unit(10, _Trafalgar::alea(5, 10));
         }

         Tests::Case("Methode alea / Seconde forme (intervalle)"); {

            Tests::Unit(1, _Trafalgar::alea(0., 6));
         }

         Tests::Case("Methode alea / Troisieme forme (disque)"); {
         complex <int> resultat;

            resultat= _Trafalgar::alea(3);

            Tests::Unit(2, resultat.real());
            Tests::Unit(0, resultat.imag());

            resultat= _Trafalgar::alea(5);

            Tests::Unit(5, resultat.real());
            Tests::Unit(4, resultat.imag());
         }

   Tests::End();
}
