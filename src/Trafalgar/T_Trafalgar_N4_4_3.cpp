//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Tests unitaires de la methode embarquer, debarquer 
//					(Meteo TRES_AGITEE)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"
#include "../../_Tests/Tests/Tests.h"

void main () {
	
   Tests::Begin("_Trafalgar.Navire", "1.3.0");
   
	Point O(0, 0), A(1.5, 0), B(0, 1.5);   Triangle OAB(O, A, B);
	Point C(1, 2), D(1, 3.5), E(2.5, 2);   Triangle CDE(C, D, E);
	Point F(2, 1), G(2.5, 1.5), H(3, 0.5); Triangle FGH(F, G, H);
	Point P1(15, 14); Vecteur V1(-1, -1);
	Point P2(-6, 0); Vecteur V2(0.5, 0.5);
	
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
	
	// Mettre en place les navires
	//
	Trafalgar::ajouterNavire(pN1);
	Trafalgar::ajouterNavire(pN2);
	
	// Mettre en position les navires
	//
	Trafalgar::placer("Cassard",P1,V1);
	Trafalgar::placer("Tonnerre",P2,V2);
		
	// Mise en place d'effectif sur navire
	//
	Trafalgar::obtenirNavire("Cassard")->nbSoldats(1000);
	Trafalgar::obtenirNavire("Tonnerre")->nbSoldats(1800);
	
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
		
	Tests::Design("Mouvement d'effectif", 3);
	
	// Mise en place meteo TRES_AGITEE
	//
	Trafalgar::modifierMeteo("OAB",AGITEE);
	Trafalgar::appliquer("Cassard",AGITEE);
	Trafalgar::appliquer("Tonnerre",AGITEE);
	Trafalgar::modifierMeteo("OAB",TRES_AGITEE);
	Trafalgar::appliquer("Cassard",TRES_AGITEE);
	Trafalgar::appliquer("Tonnerre",TRES_AGITEE);
	
	Tests::Case("Service debarquer - Navire occupé –> Ile vierge - Meteo TRES_AGITEE"); {
		
		Tests::Unit(1000, Trafalgar::obtenirNavire("Cassard")->nbSoldats());
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("bleue"));
		
		Trafalgar::debarquer("Cassard","OAB", 1000);
		
		Tests::Unit(0, Trafalgar::obtenirNavire("Cassard")->nbSoldats());
		Tests::Unit(700, Trafalgar::obtenirIle("OAB")->effectifs("bleue"));
	}
	
	Tests::Case("Service debarquer - Navire occupé –> Ile occupée - Meteo TRES_AGITEE"); {
		
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(700, Trafalgar::obtenirIle("OAB")->effectifs("bleue"));

		Trafalgar::debarquer("Tonnerre","OAB", 1200);
	
		Tests::Unit(168, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("bleue"));
	}
	
	Tests::Case("Service debarquer - Navire occupé –> Ile prise - Meteo TRES_AGITEE"); {
		
		Tests::Unit(168, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("bleue"));
		
		Trafalgar::debarquer("Tonnerre","OAB", 600);
		
		Tests::Unit(588, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("bleue"));
	}
	
	Tests::Case("Service debarquer - Navire vide –> Ile prise - Meteo TRES_AGITEE"); {
		
		Tests::Unit(588, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("bleue"));
		
		Trafalgar::debarquer("Tonnerre","OAB", 1000);
		
		Tests::Unit(588, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("bleue"));
	}
	
	Tests::Case("Service embarquer - Ile prise –> Navire vide - Meteo TRES_AGITEE"); {
		
		Tests::Unit(588, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(0, Trafalgar::obtenirNavire("Tonnerre")->nbSoldats());
		
		Trafalgar::embarquer("Tonnerre","OAB", 588);
		
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(411, Trafalgar::obtenirNavire("Tonnerre")->nbSoldats());
	}
	
	Tests::Case("Service embarquer - Ile vide –> Navire occupé - Meteo TRES_AGITEE"); {
		
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(411, Trafalgar::obtenirNavire("Tonnerre")->nbSoldats());
		
		Trafalgar::embarquer("Tonnerre","OAB", 10000);
		
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(411, Trafalgar::obtenirNavire("Tonnerre")->nbSoldats());
	}

   Tests::End();
}
