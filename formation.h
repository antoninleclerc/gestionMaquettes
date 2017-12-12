#ifndef FORMATION_H
#define FORMATION_H

#include "maquette.h"
#include <vector>

class formation 
{
	public : 
		formation (int nbAnnee, const std:: string intitule ) ; 
		~formation() ; 
		int nbAnnee() const ;
		std:: string intitule() ; 
		void ajouterFormation (int nbAnnee, const std :: string intitule, const maquette & m) ; 
			
	
	private : 
		int d_nbAnnee ; 
		std:: string d_intitule ; 
		vector <maquette> d_formations ;
		
	
}



#endif 
