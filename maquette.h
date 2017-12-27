#ifndef MAQUETTE_H
#define MAQUETTE_H

#include "UE.h" 
#include "Cours.h"
#include <vector> 

class maquette 
{
	public : 
		maquette();
		~maquette();
		void ajouterUE(UE * ue); 
		void afficherMaquette(std::ostream & ost) const; 
		bool supprimerUE(std::string & code);
		int nombreUEDansMaquette() const; 
			
	private :
		std::vector<UE*> d_maquettes; 
};

#endif 
