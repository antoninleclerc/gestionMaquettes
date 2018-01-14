#include<iostream>
#include <iomanip>
#include "ECUE.h"

namespace GestionMaquettes
{
	ECUE::ECUE(const std::string &code, const std::string &intitule, int coefficient, int heuresCM, int heuresTD, int heuresTP) :
			Cours{code, intitule, coefficient}, d_heuresCM{heuresCM}, d_heuresTD{heuresTD}, d_heuresTP{heuresTP}
	{} 
	
	ECUE::~ECUE()
	{}
	
	int ECUE::heuresCM() const {
		return d_heuresCM;
	}
	
	int ECUE::heuresTD() const {
		return d_heuresTD;
	}
	
	int ECUE::heuresTP() const {
		return d_heuresTP;
	}
	
	void ECUE::modifierHeuresCM(int heuresCM) {
		d_heuresCM = heuresCM;
	}
	
	void ECUE::modifierHeuresTD(int heuresTD) {
		d_heuresTD = heuresTD;
	}
	
	void ECUE::modifierHeuresTP(int heuresTP) {
		d_heuresTP = heuresTP;
	}
	
	void ECUE::affiche(std::ostream& ost) const {
		ost << std::setw(4) << code() << std::setw(4) << coefficient()  << "     ECUE " << std::setw(30) << intitule() <<  std::setw(4) << heuresCM() << std::setw(4) << heuresTD() << std::setw(4) << heuresTP() << std::endl;
	}
}

