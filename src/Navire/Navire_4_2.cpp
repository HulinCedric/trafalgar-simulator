//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Methode manoeuvrer
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"

// Methode qui permet de manoeuvrer le navire avec
// alpha : angle d'orientation du navire en radians
// deltaRho : ++ ou -- la vitesse du navire en %
//
void Navire::manoeuvrer (double alpha, double deltaRho)
{
	// Controler l'etat du navire
	//
	if(etat() == COULE)	return;
	
	// Controler le premier parametre
	//
	if (alpha == 0. && deltaRho == 0.)	return;

	// Obtenir la position courante A du navire
	//
	Point* pA= position();
	if (pA==NULL) throw -1.0;
	
	// Obtenir la vitesse courante du navire
	//
	Vecteur* pV = vitesse();
	if (pV==NULL) {delete pA; throw -1.0;}
	
	// Creer un vecteur nulle
	//
	Vecteur *pV0= new Vecteur(0, 0);
	if (pV0 == NULL) {delete pA; delete pV; throw -1.0;}
	
	// Controler le cas particulier d'un navire echoue
	//
	if(*pV==*pV0) {delete pA; delete pV; delete pV0; return;}
	
	// Determiner le point de fin du vecteur vitesse
	//
	Point* pFin= new Point(pV->abscisse() + pA->abscisse(), pV->ordonnee() + pA->ordonnee());
	if (pFin == NULL)	{delete pA; delete pV; delete pV0; throw -1.0;}
	
	// Calculer la vitesse courante vC du navire
	//
	double vC = pV->norme();
	
	// Verifier si il y a depassement de la vitesseMax
	//
	if ( (deltaRho >= 0.) && (vC + deltaRho) > vitesseMax() ) deltaRho = m_vitesseMax / vC -1;
	
	// Calculer la longueur du vecteur vitesse avec deltaRho
	//
	pFin= pFin->homothetie(*pA, 1+deltaRho);
	
	// Calculer l'orientation du vecteur vitesse avec alpha
	//
	pFin= pFin->rotation(*pA, alpha);
	
	// Affecter le nouveau vecteur vitesse
	vitesse(*new Vecteur(*pA, *pFin));
	
	// Detruire les variables de construction
	//
	delete pA;
	delete pV;
	delete pV0;
	delete pFin;
	
	return;
}