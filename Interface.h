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
			void menuPrincipalChoix();
			void ajouterFormation();
			void supprimerFormation();
			bool supprimerFormationNumero(int numeroFormation);
			void modifierFormation();
			void choixModification(Formation *formation);
			void modifierDomaine(Formation *formation);
			void modifierMention(Formation *formation);
			void modifierParcours(Formation *formation);
			void modifierMaquette(Formation *formation);
			
			void menuMaquette(int& choix);
			void ajouterMaquette();
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
	    	void mettreAJourFichierListeFormations() const;
	    	void mettreAJourFichierListeMaquettes() const;
	    	void chargeFormations();
	    	void afficherListeFormations() const;
	    	void afficherFormation();
	    	void afficherMaquettesDeLaFormationNumero(int numeroFormation) const;
	    private:
	    	std::vector<Formation*> d_formations;	
	};
}


#endif
