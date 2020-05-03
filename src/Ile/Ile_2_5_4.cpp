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
int Ile::debarquement(const string& flotte, 
					  const Point& positionCible, 
					  int effectif)
{
	// Controler la validite du troisieme parametre
	//
	if(effectif < 0)	throw -2.3;
		
	// Recupere ancienne effectif
	//
	int ancienneEffectif= effectifs(flotte,positionCible);
	
	// Calculer les pertes subies par le béligerant
	//
	int survivant= calculerPertes(flotte, positionCible, effectif);
	if (survivant < ancienneEffectif) survivant= ancienneEffectif;
	
	//On debarque !
	//
	ajouterTroupes(flotte, positionCible, survivant-ancienneEffectif);
		
	// Calculer les pertes subies par les autres flottes
	//
	map <string, list <Point> >::iterator i= m_positions.begin();
	string adversaire;
		
	while (i != m_positions.end())
	{		
		// Obtenir le nom de la flotte courante
		//
		adversaire = i->first;
		
		// Traiter le cas particulier de l'assaillant
		//
		if (adversaire == flotte)
		{
			i++; 
			continue;
		}
		
		// Determiner si l'adversaire possede des troupes au voisinage
		// du point de debarquement
		//
		list<Point> Lpos = m_positions.find(adversaire)->second;   	//liste des points de l'adversaire
		list<int> Leff = m_effectifs.find(adversaire)->second;     	//liste des effectifs de l'adversaire
		
		list <Point>::iterator j=Lpos.begin();                      //position courante
		list <int>::iterator   k=Leff.begin();                      //effectif courant
	
		//on boucle, pour 1 flotte adverse, sur toutes ses positions de l'ile
		//
		while(j != Lpos.end())
		{
				
			Point PositionAdversaire ;              	//position a verifier
			int   distance;                                 	//distance positionCible-pos a verifier
			int   effectifAdversaire, pertesAdversaire;
				
			PositionAdversaire = *j;     //position courante
			effectifAdversaire = *k;      //effectif courant
				
			// Si la position adverse est dans un rayon RAYON_COMBAT autour de la position cible (de debarquement)
			//
			distance = PositionAdversaire.distance(positionCible);
			if (distance <= RAYON_MINIMUM_ACTION)
			{				
				// Calcul des pertes
				//
				pertesAdversaire = calculerPertes(flotte, positionCible, effectif, adversaire, PositionAdversaire);  
								
				// Mise a jour du resultat (si pertes)
				//
				if (pertesAdversaire > 0)	retirerTroupes(adversaire, PositionAdversaire, pertesAdversaire);
			}
		j++;
		k++;
		}  
	i++;
	}
	// Restituer le resultat
	//
	return survivant;
}
