#ifndef FORMATION_H
#define FORMATION_H

#include "maquette.h"
#include <vector>

class formation 
{
	public :
		formation(int nombreAnnee, const std::string intitule); 
		~formation(); 
		int nombreAnnee() const;
		std::string intitule() const; 
		void modifierNombreAnnee(int nombreAnnee); 
		void modifierIntitule(std::string intitule);
		void ajouterMaquette(maquette * m); 
		bool supprimerMaquette (int numeroSemestre);	
		void afficherFormation(std :: ostream & ost) const; 
	private :
		int d_nombreAnnee; 
		std::string d_intitule; 
		std::vector<maquette*> d_maquettes ;	
};



#endif 
