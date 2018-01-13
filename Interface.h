#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <vector>

#include "Formation.h"

class Interface
{
	public:
		Interface();
		void menuPrincipalChoix(int& choix);
		void menuFormation(int& choix);
		void ajouterFormation();
		void supprimerFormation();
		void menuMaquette(int& choix);
		void menuUE();
    	void menuUEchoix();
    private:
    	std::vector<Formation*> d_formations;	
};

#endif
