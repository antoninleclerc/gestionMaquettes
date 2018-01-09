#ifndef ECUE_H
#define ECUE_H

#include "Cours.h"

class ECUE : public Cours {
	public:
		ECUE(const std::string &code, const std::string &intitule, int coefficient, int heuresCM, int heuresTD, int heuresTP);
		~ECUE();
		
		int heuresCM() const;
		int heuresTD() const;
		int heuresTP() const;
		
		void modifierHeuresCM(int heuresCM);
		void modifierHeuresTD(int heuresTD);
		void modifierHeuresTP(int heuresTP);
		
		void affiche(std::ostream& ost) const;
		
	private:
		int d_heuresCM, d_heuresTD, d_heuresTP;
};

#endif
