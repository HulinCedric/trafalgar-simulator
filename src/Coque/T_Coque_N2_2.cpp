//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Coque - Tests unitaires des accesseurs de consultation
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Coque.h"
#include "../../_Tests/Tests/Tests.h"


void main()
{

	Tests::Begin("_Trafalgar.Coque", "1.0.0");

	Tests::Design("Controle des acesseurs", 3);

	Tests::Case("Controle de l'acesseur de la longueur"); {
		Coque C1(FREGATE);
		Coque C2(FREGATE_DEFENSE_AERIENNE);

		Tests::Unit(50 , C1.longueurNavire());
		Tests::Unit(150, C2.longueurNavire());
	}


	Tests::Case("Controle de l'acesseur de la largeur"); {
		Coque C1(FREGATE);
		Coque C2(FREGATE_DEFENSE_AERIENNE);

		Tests::Unit(50 , C1.largeurNavire());
		Tests::Unit(150, C2.largeurNavire());
	}

	Tests::Case("Controle de l'acesseur du poids"); {
		Coque C1(FREGATE);
		Coque C2(FREGATE_DEFENSE_AERIENNE);

		Tests::Unit(2500 , C1.poidsNavire());
		Tests::Unit(22500, C2.poidsNavire());
	}

	Tests::Case("Controle de l'acesseur du profil"); {
		Coque C1(FREGATE);
		Coque C2(FREGATE_DEFENSE_AERIENNE);

		Tests::Unit(25, C1.profilNavire());
		Tests::Unit(225, C2.profilNavire());
	}

	Tests::Case("Controle de l'acesseur de la furtivite"); {
		Coque C1(FREGATE);
		Coque C2(FREGATE_DEFENSE_AERIENNE);

		Tests::Unit(40, C1.furtiviteNavire());
		Tests::Unit(20, C2.furtiviteNavire());
	}

	Tests::Case("Controle de l'acesseur de la propulsion"); {
		Coque C1(FREGATE);
		Coque C2(FREGATE_DEFENSE_AERIENNE);

		Tests::Unit(3, C1.propulsionNavire());
		Tests::Unit(5, C2.propulsionNavire());
	}

	Tests::Case("Controle de l'acesseur de la puissance"); {
		Coque C1(FREGATE);
		Coque C2(FREGATE_DEFENSE_AERIENNE);

		Tests::Unit(30, C1.puissanceNavire());
		Tests::Unit(50, C2.puissanceNavire());
	}

	Tests::Case("Controle de l'acesseur de la vitesse"); {
		Coque C1(FREGATE);
		Coque C2(FREGATE_DEFENSE_AERIENNE);

		Tests::Unit(300, C1.vitesseNavire());
		Tests::Unit(500, C2.vitesseNavire());
	}

	Tests::Case("Controle de l'acesseur de l'aisance"); {
		Coque C1(FREGATE);
		Coque C2(FREGATE_DEFENSE_AERIENNE);

		Tests::Unit(3, C1.aisanceNavire());
		Tests::Unit(1, C2.aisanceNavire());
	}

	Tests::End();

}