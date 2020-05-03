//
// IUT de Nice / Département informatique / Module APO-C++
// Année 2008_2009 - Package _Trafalgar
//
// Classe Navire - Méthode calculerPertes
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"

// Méthode qui permet de calculer les
// pertes des effectifs lors d'un débarquement
// ou d'un embarquement
//
int Navire::calculerPertes(Ile* pIle, int effectif)
{
	// Contrôler la validité de l'objet support
	//
	if( nok() )	throw -2.0;
	
	// Controler le premier paramètre
	//
	if( pIle->nok() )	throw -2.1;
	
	// Contrôler le deuxième paramètre
	//
	if( effectif < 0 )	throw -2.2;
	
	// Calculer la distance entre l'île et le navire
	//
	double distance = pIle->lieux()->distance( m_position );
	
	// Calcule des coefficients
	//
	if( distance < 0. )	throw -3.1;
	
	// Calculer le nouvel effectif en fonction de la météo de l'île sur lequel
	// on débarque et en fonction de la distance entre l'île et le navire
	//
	if( distance >= 2000. )
	{
		effectif*= 0;
	}
	
	if( distance < 2000. && distance >1700. )
	{
		if((pIle->meteo()) == CALME ) { effectif *= 0.3; }
		if((pIle->meteo()) == AGITEE ) { effectif *= 0.25; }
		if((pIle->meteo()) == TRES_AGITEE ) { effectif *= 0.20; }
		if((pIle->meteo()) == TEMPETE ) { effectif *= 0.10; }
	}
	
	if( distance <=1700. && distance >1300. )
	{
		if((pIle->meteo()) == CALME ) { effectif *= 0.4; }
		if((pIle->meteo()) == AGITEE ) { effectif *= 0.35; }
		if((pIle->meteo()) == TRES_AGITEE ) { effectif *= 0.30; }
		if((pIle->meteo()) == TEMPETE ) { effectif *= 0.25; }
	}
	
	if( distance <=1300. && distance >1000. )
	{
		if((pIle->meteo()) == CALME ) { effectif *= 0.50; }
		if((pIle->meteo()) == AGITEE ) { effectif *= 0.45; }
		if((pIle->meteo()) == TRES_AGITEE ) { effectif *= 0.40; }
		if((pIle->meteo()) == TEMPETE ) { effectif *= 0.35; }
	}
	
	if( distance <=1000. && distance >700. )
	{
		if((pIle->meteo()) == CALME ) { effectif *= 0.65; }
		if((pIle->meteo()) == AGITEE ) { effectif *= 0.6; }
		if((pIle->meteo()) == TRES_AGITEE ) { effectif *= 0.55; }
		if((pIle->meteo()) == TEMPETE ) { effectif *= 0.45; }
	}
	if( distance <=700. && distance >400. )
	{
		if((pIle->meteo()) == CALME ) { effectif *= 0.7; }
		if((pIle->meteo()) == AGITEE ) { effectif *= 0.65; }
		if((pIle->meteo()) == TRES_AGITEE ) { effectif *= 0.6; }
		if((pIle->meteo()) == TEMPETE ) { effectif *= 0.5; }
	}
	if( distance <=400. && distance >0. )
	{
		if((pIle->meteo()) == CALME ) { effectif *= 0.9; }
		if((pIle->meteo()) == AGITEE ) { effectif *= 0.85; }
		if((pIle->meteo()) == TRES_AGITEE ) { effectif *= 0.7; }
		if((pIle->meteo()) == TEMPETE ) { effectif *= 0.6; }
	}
	if( distance == 0. )
	{
		effectif*= 1;
	}
	
	// Restituer le resultat
	//
	return effectif;
}