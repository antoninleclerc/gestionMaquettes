#ifndef MAQUETTE_H
#define MAQUETTE_H

#include "UE.h" 
#include "Cours.h"
#include <vector> 

class Maquette 
{
	public : 
		Maquette();
		~Maquette();
		void ajouterUE(UE * ue); 
		void afficheMaquette(std::ostream & ost) const; 
		bool supprimerUE(std::string & code);
		int nombreUEDansMaquette() const; 
			
	private :
		std::vector<UE*> d_UE; 
};

std::ostream& operator<<(std::ostream& ost, const Maquette& m);

#endif 
