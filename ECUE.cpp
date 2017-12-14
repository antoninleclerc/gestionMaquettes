#include<iostream>
#include "ECUE.h"

ECUE::ECUE(const std::string &code, const std::string &intitule, int coefficient, int heuresCM, int heuresTD, int heuresTP) :
			cours{code, intitule, coefficient}, d_heuresCM{heuresCM}, d_heuresTD{heuresTD}, d_heuresTP{heuresTP}
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
	ost << "Code ECUE : " << code() << std::endl;
	ost << "Intitule ECUE : " << intitule() << std::endl;
	ost << "Coefficient ECUE : " << coefficient() << std::endl;
	ost << "Nombre heures CM : " << heuresCM() << std::endl;
	ost << "Nombre heures TD : " << heuresTD() << std::endl;
	ost << "Nombre heures TP : " << heuresTP() << std::endl;
}
