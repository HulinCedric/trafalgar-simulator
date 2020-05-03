//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Coque - Tests unitaires des constructeurs
//              (Cas nominaux)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Coque.h"
#include "../../_Tests/Tests/Tests.h"

void main()
{

	Tests::Begin("_Trafalgar.Coque", "1.0.0");

	Tests::Design("Controle des constructeurs", 3);

	Tests::Case("Controle du constructeur par defaut"); {
		Coque C1;

		Tests::Unit("---", C1.toString());
	}


	Tests::Case("Controle du constructeur normal"); {
		Coque C1(FREGATE);
		Coque C2(FREGATE_DEFENSE_AERIENNE);
		Coque C3(FREGATE_ANTI_SOUS_MARINE);

		
		Tests::Unit("[[FLOTTE][L : 50 l : 50][Poids : 2500][Profil : 25][Furtivite : 40][Propulsion : 3][Puissance : 30][VitesseMax : 300][Aisance : 3]]", C1.toString());
		Tests::Unit("[[FLOTTE][L : 150 l : 150][Poids : 22500][Profil : 225][Furtivite : 20][Propulsion : 5][Puissance : 50][VitesseMax : 500][Aisance : 1]]", C2.toString());
		Tests::Unit("[[FLOTTE][L : 300 l : 300][Poids : 90000][Profil : 900][Furtivite : 10][Propulsion : 8][Puissance : 80][VitesseMax : 800][Aisance : 1]]", C3.toString());
	}

	Tests::End();
}
