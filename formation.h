#ifndef FORMATION_H
#define FORMATION_H

#include "maquette.h"
#include <vector>

class formation 
{
	public : 
		formation (int nbAnnee, const std:: string intitule ) ; 
		~formation() ; 
		int nombreAnnee() const ;
		std:: string intitule() const ; 
		void modifierNombreAnnee (int nombreAnnee) ; 
		void modifierIntitule(std :: string intitule) ;
		void ajouterMaquette (const maquette & m) ; 
		bool supprimerMaquette (int numeroSemestre) ;	
	
	private : 
		int d_nombreAnnee ; 
		std:: string d_intitule ; 
		vector <maquette*> d_formations ;
		
	
}



#endif 
