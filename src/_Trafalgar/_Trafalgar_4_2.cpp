//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe _Trafalgar - Methodes de generation de valeurs aleatoires entieres
//                     (basees sur la fonction rand de la librairie C)
//
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "_Trafalgar.h" 

// --- Generation aleatoire d'un nombre int au sein d'un intervalle
//     fixe par parametres (bornes incluses)
//
int _Trafalgar::alea(int borneInf, int borneSup) {

   // Controle de validite de l'intervalle
   //
   if (borneInf >= borneSup) throw -3.0;

   // Restituer le resultat
   //
   return borneInf + rand()%(borneSup - borneInf + 1);
}

// --- Generation aleatoire d'un nombre reel au sein d'un intervalle
//     centre sur la valeur du premier parametre
//
int _Trafalgar::alea(int centre, double ecart) {

  // Controle de validite de l'intervalle
   //
   if (ecart <= 0) throw -3.0;
   ;
   return alea ((int)(centre - ecart), (int)(centre + ecart));
}

// --- Generation d'un point dans un cercle d'incertitude de centre O
//     et de rayon R fourni en parametre
//
echo& _Trafalgar::alea(int R) {
echo* pResultat;
double x, y;

   // Generer un point dans le carre de centre O(0, 0) et de cote 2*R
   // et controler ensuite son appartenance au disque inscrit
   //
   do {
      // Generer aleatoirement une abscisse entiere dans le carre 
      //
      x= _Trafalgar::alea(0., R);

      // Generer aleatoirement une ordonnee entiere dans le carre 
      //
      y= _Trafalgar::alea(0., R);

     // Controler que le couple de coordonnees (x, y) definit un point
     // contenu dans la grille de centre O et de rayon R 
     //
     pResultat= new echo(x, y);
   } while (norm(*pResultat) <= R);

   // Restituer le resultat
   //
   return *pResultat;
}




