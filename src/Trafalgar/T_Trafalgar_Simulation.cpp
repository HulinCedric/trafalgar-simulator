//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Tests unitaires Simulation Complete
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"
#include "../../_Tests/Tests/Tests.h"

void main () {
	
	srand(time(NULL));
	
	Tests::Begin("_Trafalgar.Navire", "1.3.0");
	
	Point O(0, 0), A(1.5, 0), B(0, 1.5);   Triangle OAB(O, A, B);
	Point C(1, 2), D(1, 3.5), E(2.5, 2);   Triangle CDE(C, D, E);
	Point F(2, 1), G(2.5, 1.5), H(3, 0.5); Triangle FGH(F, G, H);
	Point P1(15, 14); Vecteur V1(-1, -1);
	Point P2(-6, 0); Vecteur V2(0.5, 0.5);
	Point P3(17, 19); Vecteur V3(2, 2);
	Point P4(19, 17); Vecteur V4(4, 4);
	
	// --- Fregate anti aerienne Cassard
	//
	Navire* pN1= new Navire(FREGATE_DEFENSE_AERIENNE, "Cassard", "bleue");
	
	// --- Batiment de Projection et de Commandement (BPC) Tonnerre
	//
	Navire* pN2= new Navire(BPC, "Tonnerre", "rouge");
	
	// --- Croiseur Abats
	//
	Navire* pN3= new Navire(CROISEUR, "Abats", "bleue");
	
	// --- Chalan de debarquement FireArmor
	//
	Navire* pN4= new Navire(CHALAN_DE_DEBARQUEMENT, "FireArmor", "bleue");
	
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
	Trafalgar::ajouterNavire(pN3);
	Trafalgar::ajouterNavire(pN4);
	
	// Mettre en position les navires
	//
	Trafalgar::placer("Cassard",P1,V1);
	Trafalgar::placer("Tonnerre",P2,V2);
	Trafalgar::placer("Abats",P3,V3);
	Trafalgar::placer("FireArmor",P4,V4);
	
	// Mise en place d'effectif sur navire
	//
	Trafalgar::obtenirNavire("Cassard")->nbSoldats(1000);
	Trafalgar::obtenirNavire("Tonnerre")->nbSoldats(1800);
	
	// Controler l'ensemble du contexte
	//
	Tests::Case("Controle du contexte de simulation"); {
		
		Tests::Unit(3, Trafalgar::nombreIles());
		Tests::Unit(4, Trafalgar::nombreNavires());
	}
	
	Tests::Design("Lancement de la simulation", 3);
	
	Tests::Case("Controle du service start"); {
		
		Trafalgar::start(2);
		
		Tests::Unit(2, Trafalgar::nombreFlottes());
	}
	
	Tests::Design("Mise en place de conflit de territoire", 3);
	
	Tests::Case("Service debarquer - Navire occupé –> Ile vierge - Meteo CALME"); {
		
		Tests::Unit(1000, Trafalgar::obtenirNavire("Cassard")->nbSoldats());
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("bleue"));
		
		Trafalgar::debarquer("Cassard","OAB", 1000);
		
		Tests::Unit(0, Trafalgar::obtenirNavire("Cassard")->nbSoldats());
		Tests::Unit(900, Trafalgar::obtenirIle("OAB")->effectifs("bleue"));
	}
	
	Tests::Case("Service debarquer - Navire occupé –> Ile occupée - Meteo CALME"); {
		
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(900, Trafalgar::obtenirIle("OAB")->effectifs("bleue"));
		
		Trafalgar::debarquer("Tonnerre","OAB", 1200);
		
		Tests::Unit(216, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("bleue"));
	}
	
	Tests::Case("Service debarquer - Navire occupé –> Ile prise - Meteo CALME"); {
		
		Tests::Unit(216, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("bleue"));
		
		Trafalgar::debarquer("Tonnerre","OAB", 600);
		
		Tests::Unit(756, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("bleue"));
	}
	
	Tests::Design("Changement de meteo", 3);
	
	// Mise en place meteo AGITEE
	//
	Trafalgar::modifierMeteo("OAB",AGITEE);
	Trafalgar::appliquer("Tonnerre",AGITEE);
	
	Tests::Case("Service debarquer - Navire vide –> Ile prise - Meteo CALME"); {
		
		Tests::Unit(756, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("bleue"));
		
		Trafalgar::debarquer("Tonnerre","OAB", 1000);
		
		Tests::Unit(756, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("bleue"));
	}
	
	Tests::Case("Service embarquer - Ile prise –> Navire vide - Meteo CALME"); {
		
		Tests::Unit(756, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(0, Trafalgar::obtenirNavire("Tonnerre")->nbSoldats());
		
		Trafalgar::embarquer("Tonnerre","OAB", 756);
		
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(642, Trafalgar::obtenirNavire("Tonnerre")->nbSoldats());
	}
	
	Tests::Case("Service embarquer - Ile vide –> Navire occupé - Meteo CALME"); {
		
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(642, Trafalgar::obtenirNavire("Tonnerre")->nbSoldats());
		
		Trafalgar::embarquer("Tonnerre","OAB", 10000);
		
		Tests::Unit(0, Trafalgar::obtenirIle("OAB")->effectifs("rouge"));
		Tests::Unit(642, Trafalgar::obtenirNavire("Tonnerre")->nbSoldats());
	}
	
	Tests::Design("Remise a Niveau des Joueurs", 3);
	
	// Remise a Niveau des effectif sur les Navires
	//
	Trafalgar::obtenirNavire("Cassard")->nbSoldats(1000);
	
	Tests::Case("Controle des etats Generaux"); {
		
		Tests::Unit(1000, Trafalgar::obtenirNavire("Cassard")->nbSoldats());
		Tests::Unit(642, Trafalgar::obtenirNavire("Tonnerre")->nbSoldats());
	}
	
	Tests::Design("Mise en place de conflit maritime", 3);
	
	// Creation des armes
	//
	Arme* canon= new Arme(CANON);
	Arme* roquette= new Arme(LANCE_ROQUETTES);
	Arme* mitralle= new Arme(MITRAILLEUSE);
	
	// Ajout d'arme au navire
	// 
	Trafalgar::ajouterArme("Tonnerre",canon);
	Trafalgar::ajouterArme("Cassard",roquette);
	Trafalgar::ajouterArme("Tonnerre",mitralle);
	
	Tests::Case("Controle des armes des navires"); {
		
		Tests::Unit(1, Trafalgar::obtenirNavire("Cassard")->nbArmes());
		Tests::Unit(2, Trafalgar::obtenirNavire("Tonnerre")->nbArmes());
	}
	
	Tests::Case("Service tirer - CANON"); {
		
		Tests::Unit(Trafalgar::obtenirNavire("Cassard")->vitesseMax(), Trafalgar::obtenirNavire("Cassard")->vitesseMax());
		
		Trafalgar::tirer("Tonnerre",1, *Trafalgar::obtenirNavire("Cassard")->position());
		
		Tests::Unit(Trafalgar::obtenirNavire("Cassard")->nbSoldats(), Trafalgar::obtenirNavire("Cassard")->nbSoldats());
		Tests::Unit(Trafalgar::obtenirNavire("Cassard")->vitesseMax(), Trafalgar::obtenirNavire("Cassard")->vitesseMax());
		Tests::Unit(Trafalgar::obtenirNavire("Cassard")->flottabilite(), Trafalgar::obtenirNavire("Cassard")->flottabilite());
		Tests::Unit(Trafalgar::obtenirNavire("Cassard")->toString(), Trafalgar::obtenirNavire("Cassard")->toString());
	}
	
	Tests::Case("Service tirer - LANCE_ROQUETTES"); {
		
		Trafalgar::tirer("Cassard",1, *Trafalgar::obtenirNavire("Tonnerre")->position());
		
		Tests::Unit(Trafalgar::obtenirNavire("Tonnerre")->nbSoldats(), Trafalgar::obtenirNavire("Tonnerre")->nbSoldats());
		Tests::Unit(Trafalgar::obtenirNavire("Tonnerre")->vitesseMax(), Trafalgar::obtenirNavire("Tonnerre")->vitesseMax());
		Tests::Unit(Trafalgar::obtenirNavire("Tonnerre")->flottabilite(), Trafalgar::obtenirNavire("Tonnerre")->flottabilite());
		Tests::Unit(Trafalgar::obtenirNavire("Tonnerre")->toString(), Trafalgar::obtenirNavire("Tonnerre")->toString());
	}
	
	try{Tests::Case("Service tirer - MITRAILLEUSE"); {
		
		Trafalgar::tirer("Tonnerre",2, *Trafalgar::obtenirNavire("Cassard")->position());
		
		Tests::Unit(Trafalgar::obtenirNavire("Cassard")->nbSoldats(), Trafalgar::obtenirNavire("Cassard")->nbSoldats());
		Tests::Unit(Trafalgar::obtenirNavire("Cassard")->vitesseMax(), Trafalgar::obtenirNavire("Cassard")->vitesseMax());
		Tests::Unit(Trafalgar::obtenirNavire("Cassard")->flottabilite(), Trafalgar::obtenirNavire("Cassard")->flottabilite());
		Tests::Unit(Trafalgar::obtenirNavire("Cassard")->toString(), Trafalgar::obtenirNavire("Cassard")->toString());
	}
	}
	catch (double e) {
		cout << e << endl;
	}
	Tests::Case("Service tirer - Navire coule"); {
		
		Trafalgar::tirer("Tonnerre",1, *Trafalgar::obtenirNavire("Cassard")->position());
		Trafalgar::tirer("Tonnerre",1, *Trafalgar::obtenirNavire("Cassard")->position());
		Trafalgar::tirer("Tonnerre",1, *Trafalgar::obtenirNavire("Cassard")->position());
		Trafalgar::tirer("Tonnerre",1, *Trafalgar::obtenirNavire("Cassard")->position());
		Trafalgar::tirer("Tonnerre",1, *Trafalgar::obtenirNavire("Cassard")->position());
		Trafalgar::tirer("Tonnerre",1, *Trafalgar::obtenirNavire("Cassard")->position());
		Trafalgar::tirer("Tonnerre",1, *Trafalgar::obtenirNavire("Cassard")->position());
		Trafalgar::tirer("Tonnerre",1, *Trafalgar::obtenirNavire("Cassard")->position());
		Trafalgar::tirer("Tonnerre",1, *Trafalgar::obtenirNavire("Cassard")->position());
		
		// Test de tire avec arme vide
		//
		Trafalgar::tirer("Tonnerre",1, *Trafalgar::obtenirNavire("Cassard")->position());
		
		// Test de tire avec arme casser
		//
		Tests::Unit(Trafalgar::obtenirNavire("Tonnerre")->flottabilite(), Trafalgar::obtenirNavire("Tonnerre")->flottabilite());
		Trafalgar::tirer("Cassard",1, *Trafalgar::obtenirNavire("Tonnerre")->position());
		Tests::Unit(Trafalgar::obtenirNavire("Tonnerre")->flottabilite(), Trafalgar::obtenirNavire("Tonnerre")->flottabilite());
		
		
		Tests::Unit(Trafalgar::obtenirNavire("Cassard")->nbSoldats(), Trafalgar::obtenirNavire("Cassard")->nbSoldats());
		Tests::Unit(Trafalgar::obtenirNavire("Cassard")->vitesseMax(), Trafalgar::obtenirNavire("Cassard")->vitesseMax());
		Tests::Unit(Trafalgar::obtenirNavire("Cassard")->flottabilite(), Trafalgar::obtenirNavire("Cassard")->flottabilite());
		Tests::Unit(Trafalgar::obtenirNavire("Cassard")->toString(), Trafalgar::obtenirNavire("Cassard")->toString());
	}
	
	
	Tests::Design("Observons", 3);

	// Creation des radar
	//
	Radar* R0= new Radar(100, 2);
	Radar* R1= new Radar(20, 1);
	Radar* R2= new Radar(50, 2);
	
	// Ajout de radar au navire
	// 
	Trafalgar::ajouterRadar("Tonnerre",R0);
	Trafalgar::ajouterRadar("Cassard",R1);
	Trafalgar::ajouterRadar("Tonnerre",R2);
	
	Tests::Case("Service observer"); {
		
		// Mise a jour des echo radars
		//
		Trafalgar::observer();
		
		// Mise a jour des echo radars
		//
		Trafalgar::observer();
	}
	
	Tests::Design("Arret de la simulation", 3);

	Tests::Case("Service stop"); {
		
		// Mise a jour du statut du simulateur
		//
		Trafalgar::stop(Trafalgar::diffuser(),Trafalgar::diffuser("stop"));
	}
	
	Tests::End();
}
