#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <vector>

#include "Formation.h"


namespace GestionMaquettes
{
	class Interface
	{
		public:
			Interface();
			void menuPrincipalChoix(int& choix);
			void menuFormation(int& choix);
			void ajouterFormation();
			void supprimerFormation();
			bool supprimerFormationNumero(int numeroFormation);
			void modifierFormation();
			
			void menuMaquette(int& choix);
			Maquette* MaquetteCree();
			
			void menuUE(int& choix, Maquette* maquette);
			void ajouterUE(Maquette* maquette);
			void saisirDonneesDuneUE(std::string& code, std::string& intitule,int& coefficient,int& heuresCM,int& heuresTD,int& heuresTP,int& ECTS);
			void ajouterUEsimple(Maquette* maquette);
			void ajouterUEcomposee(Maquette* maquette);
			void saisirDonneesDuneECUE(std::string& code, std::string& intitule,int& coefficient,int& heuresCM,int& heuresTD,int& heuresTP);
			void ajouterECUE(UE* ue);
		
	    	void menuUEchoix(int& choix, Maquette* maquette);
	    	void ajouterUEchoix(Maquette* maquette);
	    	void supprimerUEchoix();
	    	void afficherUEchoix();
	    	
	    	void mettreAJourFichierListeFormations() const;
	    	void chargeFormations();
	    	void afficherListeFormations() const;
	    private:
	    	std::vector<Formation*> d_formations;	
	};
}


#endif
