//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe _Trafalgar - Accesseurs de modification
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "_Trafalgar.h" 

// --- Modification de l'unite d'espace
//
void _Trafalgar::uniteEspace(double distance) {

   // Controle de validite du parametre
   //
   if (distance <= 0) throw -2.1;

   // Modifier l'attribut correspondant
   //
   m_uniteEspace= distance;
}

// --- Modification de l'unite de temps
//
void _Trafalgar::uniteTemps(double duree) {

   // Controle de validite du parametre
   //
   if (duree <= 0) throw -2.1;

   // Modifier l'attribut correspondant
   //
   m_uniteTemps= duree;
}

// Obtenir le numero de l'arme courante
//
int	_Trafalgar::numeroArme()
{
	// Restituer le numero d'arme courant
	//
	return ++m_numeroArme;
}

// Obtenir le numero du radar courant
//
int	_Trafalgar::numeroRadar()
{
	// Restituer le numero de radar courant
	//
	return ++m_numeroRadar;
}