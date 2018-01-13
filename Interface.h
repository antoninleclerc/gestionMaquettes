#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <vector>

#include "Formation.h"
#include "Maquette.h" 


class Interface
{
	public:
		Interface();
		void menuPrincipalChoix(int& choix);
		
		void menuFormation(int& choix);
		void ajouterFormation();
		void supprimerFormation();
		
		void menuMaquette(int& choix);
		Maquette* MaquetteCree();
		
		void menuUE(int& choix);
		void ajouterUE();
		void saisirDonneesDuneUE();
		void ajouterUEsimple();
		void ajouterUEcomposee();
		void saisirDonneesDuneECUE();
		void ajouterECUE();
		
    	void menuUEchoix(int& choix);
    	void ajouterUEchoix();
    	void supprimerUEchoix();
    	void afficherUEchoix();
    private:
    	std::vector<Formation*> d_formations;	
};

#endif
