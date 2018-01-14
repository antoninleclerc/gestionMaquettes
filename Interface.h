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
		
		void menuUE(int& choix, Maquette* maquette);
		void ajouterUE(Maquette* maquette);
		void saisirDonneesDuneUE(std::string& code, std::string& intitule,int& coefficient,int& heuresCM,int& heuresTD,int& heuresTP,int& ECTS);
		void ajouterUEsimple(Maquette* maquette);
		void ajouterUEcomposee(Maquette* maquette);
		void saisirDonneesDuneECUE(std::string& code, std::string& intitule,int& coefficient,int& heuresCM,int& heuresTD,int& heuresTP);
		void ajouterECUE(UE* ue);
		
    	void menuUEchoix(int& choix,Maquette* maquette);
    	void ajouterUEchoix();
    	void supprimerUEchoix();
    	void afficherUEchoix();
    private:
    	std::vector<Formation*> d_formations;	
};

#endif
