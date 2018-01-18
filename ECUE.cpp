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
		ost << std::setw(15) << std::left << code() << std::setw(10) << std::left << coefficient()  << std::setw(5) << std::left << " "  << std::setw(40) << std::left << " ECUE " + intitule() <<  std::setw(10) << std::left << heuresCM() << std::setw(10) << std::left << heuresTD() << std::setw(10) << std::left << heuresTP() << std::endl;
	}
	void ECUE::enregistrerECUE(const std::string &mention) const 
	{
	 	std::ofstream fichier;
	 	fichier.open("Sauvegarde/" + mention, std::ios::out | std::ios::app);
	 	if(fichier){
	 		fichier << std::setw(10) << std::left << code() << std::setw(12) << std::left << coefficient() << std::setw(5) << std::left << " "  << std::setw(45) << std::left << " ECUE " + intitule() <<  std::setw(10) << std::left << heuresCM() << std::setw(10) << std::left << heuresTD() << std::setw(10) << std::left << heuresTP() << std::endl;
	 		fichier.close();
	 	}
	 	else
	 		std::cout << "Impossible d'ouvrir le fichier" << std::endl;
	}
}
