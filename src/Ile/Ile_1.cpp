//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Ile - Constructeurs et methode toString
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Ile.h"

// --- Constructeur par defaut
//
Ile::Ile() {

   // Valuer le nom
   //	
   m_nom= "-";

   // Initialiserla meteo
   //
   m_etatMeteo= INF_ETATS_METEO;
}

// --- Premier constructeur normal
//
Ile::Ile(const string& nom, const Triangle& lieux) {

   // Valuer le nom
   //
   m_nom= nom;

   // Affecter la description topologique
   //
   m_lieux= lieux;

   // Initialiserla meteo
   //
   m_etatMeteo= INF_ETATS_METEO;
}

// --- Methode toString pour les tests unitaires
//
char* Ile::toString() {
char* pBuffer;

   // Allouer le resultat
   //
   pBuffer= new char[80];
   if (pBuffer==NULL) return NULL;

   // Controler le cas particulier de l'element neutre
   //
   if (neutre()) strcpy(pBuffer, "---");
   else sprintf(pBuffer, "[%s / %s]", m_nom.c_str(), m_lieux.toString()); 

   return pBuffer;
}




