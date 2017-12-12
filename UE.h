#ifndef UE_H
#define UE_H

#include <vector>
#include "Cours.h"

class UE : public Cours
{
	public:
		UE();
		UE(const std::string &code, const std::string &intitule, int coefficient, int CM, int TD, int TP, int ECTS);
		virtual string code() const override;
		virtual string intitule() const override;
		virtual int coefficient() const override;
		int ECTS() const;
		int nbECUE() const;
		int nbCMTotal() const;
		int nbTDTotal() const;
		int nbTPTotal() const;
				
		virtual int nbHeuresTotal() const override;
		virtual void afficher(std::ostream &ost) const override;
		
	private:
		int d_ECTS;
		vector <ECUE*> d_UE; //La première case du vecteur est toujours l'UE principale, tout ce qui suit est les ECUE de cet UE.
};

#endif
