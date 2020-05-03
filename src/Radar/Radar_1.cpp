//
// IUT de Nice / Departement informatique / Module APO-C++
// Annee 2008_2009 - Package _Trafalgar
//
// Classe Radar - Constructeurs et methode toString
//    
// Auteur : C. Hulin, C. Fouco, L. Souquet
//
#include "Radar.h"

// --- Constructeur par defaut
//
Radar::Radar() {

   // Valuer la portee
   //	
   m_portee= 0;

   // Valuer la precision
   //
   m_precision= 0;
	
	// Valuer le numero du radar
	//
	m_numero=0;

   // Valuer l'etat courant
   //
   m_etatRadar= DETRUIT;
}

// --- Constructeur normal
//
Radar::Radar(int portee, int precision) {

   // Controler la validite du premier parametre
   //	
   if (portee <= 0) throw -2.1;

   // Valuer la portee
   //	
   m_portee= portee;

   // Controler la validite du second parametre
   //	
   if (precision <= 0) throw -2.2;

   // Valuer la precision
   //
   m_precision= precision;
	
	// Valuer le numero du radar
	//
	m_numero=_Trafalgar::numeroRadar();

   // Valuer l'etat courant
   //
   m_etatRadar= OPERATIONNEL;
}

// --- Methode toString pour les tests unitaires
//
char* Radar::toString() {
char* pBuffer;

   // Allouer le resultat
   //
   pBuffer= new char[80];
   if (pBuffer==NULL) return NULL;

   // Controler le cas particulier de l'element neutre
   //
   if (neutre()) strcpy(pBuffer, "---");
   else if (m_etatRadar == OPERATIONNEL) 
           sprintf(pBuffer, "<%s / %d - %d>", "OPERATIONNEL", m_portee, m_precision);
        else sprintf(pBuffer, "<%s / %d - %d>", "DETRUIT", m_portee, m_precision); 

   return pBuffer;
}

char* Radar::toStringEcho()
{
	char* pResultat= new char[1000];
	if (pResultat==NULL) return NULL;
	char* Place;

	list <echo*>::iterator i=m_pEchos.begin();
	while (i != m_pEchos.end())
	{
		Point* temp= new Point((*i)->real(),(*i)->imag());
		if (temp==NULL) return NULL;
		
		Place= new char[strlen(temp->toString())+1];
		if (Place==NULL) return NULL;

		strcpy(Place, temp->toString());
		
		strcat(pResultat,Place);
		
		delete Place;
		delete temp;
		i++;
	}
	
	return pResultat;
}
