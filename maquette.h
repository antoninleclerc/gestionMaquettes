#ifndef MAQUETTE_H
#define MAQUETTE_H

#include "ue.h" 
#include "cours.h"
#include <vector> 

class maquette 
{
	public : 
		maquette () ; 
		void ajouterUE (const UE & ue) ; 
		void afficherMaquette (std::ostream & ost) const ; 
		bool supprimerUE (std :: string & code) ; 
		void nombreUEDansMaquette () const ; 
		
		
	private : 
		std :: vector <UE*> d_maquettes ; 
}

#endif 
