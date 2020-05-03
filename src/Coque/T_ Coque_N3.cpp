//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Coque - Tests unitaires des operateurs
//                   (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Coque.h"
#include "../../_Tests/Tests/Tests.h"

void main()
{

	Tests::Begin("_Trafalgar.Coque", "1.0.0");

	Tests::Design("Controle des operateurs", 3);

	Tests::Case("Controle de l'operator ="); {
		Coque C1(FREGATE);
		Coque C2(FREGATE_DEFENSE_AERIENNE);
		Coque C3(FREGATE_ANTI_SOUS_MARINE);
		C2 = C1;

		Tests::Unit("[[FLOTTE][L : 50 l : 50][Poids : 2500][Profil : 25][Furtivite : 40][Propulsion : 3][Puissance : 30][VitesseMax : 300][Aisance : 3]]", C2.toString());

		C2 = C3;

		Tests::Unit("[[FLOTTE][L : 300 l : 300][Poids : 90000][Profil : 900][Furtivite : 10][Propulsion : 8][Puissance : 80][VitesseMax : 800][Aisance : 1]]", C2.toString());
	}
	
	Tests::Case("Controle de l'operator =="); {
		Coque C1(FREGATE);
		Coque C2(FREGATE);
		Coque C3(FREGATE_ANTI_SOUS_MARINE);
	
		
		Tests::Unit(true, C1 == C2);
				
		Tests::Unit(false, C1 == C3);
	}
	
	Tests::Case("Controle de l'operator =="); {
		Coque C1(FREGATE);
		Coque C2(FREGATE);
		Coque C3(FREGATE_ANTI_SOUS_MARINE);
		
		
		Tests::Unit(false, C1 != C2);
		
		Tests::Unit(true, C1 != C3);
	}

	Tests::End();
}
