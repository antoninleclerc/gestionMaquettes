#ifndef UE_H
#define UE_H

#include <vector>
#include "Cours.h"
#include "ECUE.h"

class UE : public Cours
{
	public:
		UE(const std::string &code, const std::string &intitule, int coefficient, int CM, int TD, int TP, int ECTS);
		~UE();
		int ECTS() const;
		int nombreECUE() const;
		int totalHeuresCM() const;
		int totalHeuresTD() const;
		int totalHeuresTP() const;
		
		void ajouterECUE(ECUE* ecue);
		void modifierECTS(int ECTS);
		bool supprimerECUE(const std::string &code);
			
		int totalNombreHeures() const;
		virtual void affiche(std::ostream &ost) const override;
		
	private:
		int d_ECTS;
		std::vector <ECUE*> d_UE; //La premiere case du vecteur est toujours l'UE principale, tout ce qui suit est les ECUE de cet UE.
};



#endif
