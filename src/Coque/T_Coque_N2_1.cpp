//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Coque - Tests unitaires des predicats predefinis
//              (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Coque.h"
#include "../../_Tests/Tests/Tests.h"

void main () {
	
	Tests::Begin("_Trafalgar.Coque", "1.0.0");
	
	Tests::Design("Controle des predicats predefinis", 3);
	Coque x;
	Coque C1(FREGATE);
	
	Tests::Case("Predicat neutre"); {
		
		Tests::Unit(true,  x.neutre());
		Tests::Unit(false, C1.neutre());
	}
	
	Tests::Case("Predicat ok"); {
		
		Tests::Unit(true,  x.ok());
		Tests::Unit(true,  C1.ok());
	}
	
	Tests::Case("Predicat nok"); {
		
		Tests::Unit(false,  x.nok());
		Tests::Unit(false,  C1.nok());
	}
	
	Tests::End();
}
