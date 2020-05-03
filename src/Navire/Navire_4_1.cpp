//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Navire - Methode deplacer
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Navire.h"

// --- Calcul du deplacement du navire support 
//
void Navire::deplacer(Ile* pIles[]) {
Vecteur V0(0, 0);

   // Controler la validite de l'objet support
   //
   if (nok()) throw -2.0;

   // Controler la validite du parametre
   //
   if (pIles == NULL) throw -2.1;
	
	// Controler l'etat du navire
	//
	if(etat() == COULE)	return;
	
   // Obtenir la position courante A du navire
   //
   Point* pA= position();
   if (pA==NULL) throw -1.0;

   // Obtenir la vitesse courante du navire
   //
   Vecteur* pV = vitesse();
   if (pV==NULL) {delete pA; throw -1.0;}

   // Controler le cas particulier d'un navire echoue
   //
   if(*pV==V0) {delete pA; delete pV; return;}

   // Determiner la trajectoire du navire
   //
   DemiDroite trajectoire(*pA, *pV);

   // Calculer l'image B par une translation du vecteur vitesse
   //
   Point* pB= pA->translation(*pV);
   if (pB==NULL) {delete pA; delete pV; throw -1.0;}
   delete pV;

   // Controler un echouage eventuel sur une ile de la zone
   // de deplacement, en analysant l'intersection eventuelle 
   // de la trajectoire du navire avec chacune d'elles
   //
   Point* pI;
   double AB, AI;

   for (int i=0; pIles[i] != NULL; i++) {

      // Obtenir le triangle de l'ile courante
      // 
      Triangle* pT= pIles[i]->lieux();
      if (pT==NULL) throw -1.0;

      // Determiner le point d'intersection eventuel de la
      // trajectoire avec le triangle de l'ile courante
      //
      pI= pT->intersection(trajectoire);

      // Traiter l'absence d'intersection de la trajectoire
      // avec le triangle de l'ile courante
      //
      if (pI == NULL) {delete pT; continue;}

      // Traiter le cas d'une intersection, avec l'image B
      // dans le triangle de l'ile courante (echouage)
      //
      if (pT->appartient(*pB)) {
         m_position= *pI; 
         m_vitesse = V0;
         delete pT; delete pI;
         return;
      }

      // Traiter le cas general d'une image B en deca de 
      // l'intersection
      //
      AB= pA->distance(*pB);
      AI= pA->distance(*pI);
      if (AB < AI) { 
         delete pT; delete pI;
         continue;
      }

      // Traiter le cas particulier d'une image B au dela de
      // l'intersection (echouage)
      //
      m_position= *pI; 
      m_vitesse = V0;
	  m_coque.etat(COULE);
      delete pT; delete pI; delete pA; delete pB;
      return;
   }

   // Traiter le cas general (absence d'echouage)
   //
   m_position= *pB;

   delete pA; delete pB;
}


