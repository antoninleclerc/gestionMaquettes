#ifndef FORMATION_H
#define FORMATION_H

#include "Maquette.h"
#include <vector>

class Formation 
{
	public :
		Formation(int nombreAnnee, const std::string intitule); 
		~Formation(); 
		int nombreAnnee() const;
		std::string intitule() const; 
		void modifierNombreAnnee(int nombreAnnee); 
		void modifierIntitule(std::string intitule);
		void ajouterMaquette(Maquette * m); 
		bool supprimerMaquette (int numeroSemestre);
		void afficheFormation(std :: ostream & ost) const;
	
	private :
		int d_nombreAnnee; 
		std::string d_intitule; 
		std::vector<Maquette*> d_maquettes;	
};



#endif 
