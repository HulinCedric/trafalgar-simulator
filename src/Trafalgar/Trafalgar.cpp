//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Trafalgar - Allocation des attributs de classe
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Trafalgar.h"

map <string, Ile*>    Trafalgar::m_pIles;  
map <string, Navire*> Trafalgar::m_pNavires;
bool                  Trafalgar::m_status= false;



