//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Ile - Services
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Ile.h"

// --- Diminution des effectifs debarques
//
int Ile::embarquement(const string& flotte, 
					   const Point&  positionCible,
					   int           effectif)
{
int ancienEffectif, nouvelEffectif;

	// Controler la validite du troisieme parametre
	//
	if (effectif < 0 ) throw -2.3;
							
	// Calculer l'effectif courant
	//
	ancienEffectif = effectifs(flotte, positionCible);
	
	if(effectif > effectifs(flotte, positionCible)) effectif=effectifs(flotte, positionCible);
	
	// Retirer les troupes et calculer le nouvel effectif	
	//
	retirerTroupes(flotte, positionCible, effectif);
	nouvelEffectif = effectifs(flotte, positionCible);
	
    // Restituer le resultat
	//
	return (ancienEffectif- nouvelEffectif);
}
