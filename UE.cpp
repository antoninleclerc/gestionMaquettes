#include <iomanip>
#include "UE.h"


UE::UE(const std::string &code, const std::string &intitule, int coefficient, int CM, int TD, int TP, int ECTS): Cours{code, intitule, coefficient}, d_ECTS{ECTS}
{
	ECUE* ecue= new ECUE{code,intitule,coefficient,CM,TD,TP};
	d_UE.push_back(ecue);
}


UE::~UE()
{
	for(auto i: d_UE)
	{
		delete i;
	}
}


int UE::nombreECUE() const
{
	return d_UE.size()-1;
}


int UE::ECTS() const
{
	return d_ECTS;
}


int UE::totalHeuresCM() const
{
	int HeuresCM=0;
	for(int i=0; i<=nombreECUE(); i++)
	{
		HeuresCM+=d_UE[i]->heuresCM();
	}
	return HeuresCM;
}


int UE::totalHeuresTD() const
{
	int HeuresTD=0;
	for(int i=0; i<=nombreECUE(); i++)
	{
		HeuresTD+=d_UE[i]->heuresTD();
	}
	return HeuresTD;
}

int UE::totalHeuresTP() const
{
	int HeuresTP=0;
	for(int i=0; i<=nombreECUE(); i++)
	{
		HeuresTP+=d_UE[i]->heuresTP();
	}
	return HeuresTP;
}


int UE::totalNombreHeures() const
{
	return totalHeuresCM()+totalHeuresTD()+totalHeuresTP();
}


void UE::ajouterECUE(ECUE*ecue)
{
	d_UE.push_back(ecue);
}


void UE::modifierECTS(int ECTS)
{
	d_ECTS=ECTS;
}


bool UE::supprimerECUE(const std::string &code)
{
	int i=0;
	while(i<d_UE.size() || code!=d_UE[i]->code())
	{
		i++;
	}
	if(code==d_UE[i]->code())
	{
		delete d_UE[i];
		d_UE[i] = d_UE.back();
	 	d_UE.pop_back();
		return true;
	}
	else
		return false;
}


void UE::affiche(std::ostream &ost) const
{	
	if(nombreECUE()>0) //si UE composé de au moins un ECUE
	{
		ost<<std::setw(4)<<d_UE[0]->code()<<std::setw(4)<<d_UE[0]->coefficient()<<std::setw(4)<<ECTS()<<std::setw(20)<<" UE "<<d_UE[0]->intitule()<<std::endl;
		for(int i=1; i<=nombreECUE(); i++)
		d_UE[i]->affiche(ost);
	}
	else //si UE seule
	{
		ost<<std::setw(4)<<d_UE[0]->code()<<std::setw(4)<<d_UE[0]->coefficient()<<std::setw(4)<<ECTS()<<std::setw(20)<<"UE "<<d_UE[0]->intitule()<<std::setw(4)<<totalHeuresCM()<<std::setw(4)<<totalHeuresTD()<<std::setw(4)<<totalHeuresTP()<<std::setw(4)<<totalNombreHeures()<<std::endl;
	}		
}

void UE::enregistrerUE(const std::string &mention) {
	std::ofstream fichier;
	fichier.open("Sauvegarde/" + mention, std::ios::out | std::ios::app);	
		
	if(fichier){
		if(nombreECUE()>0) //si UE composé de au moins un ECUE
		{
			fichier << std::setw(10) << std::left << d_UE[0]->code() << std::setw(12) << std::left << d_UE[0]->coefficient() << std::setw(5) << std::left << ECTS() << std::setw(45) << std::left << "UE " + d_UE[0]->intitule() << std::endl;
			for(int i = 1; i <= nombreECUE(); i++)
				d_UE[i]->enregistrerECUE(mention);
		}
		else //si UE seule
		{
			fichier << std::setw(10) << std::left << d_UE[0]->code() << std::setw(12) << std::left << d_UE[0]->coefficient() << std::setw(5) << std::left << ECTS() << std::setw(45) << std::left << "UE " + d_UE[0]->intitule() << std::setw(10) << std::left << totalHeuresCM() << std::setw(10) << std::left << totalHeuresTD() << std::setw(10) << std::left << totalHeuresTP() << std::setw(13) << std::left << totalNombreHeures() << std::endl;
		}
	}
	else
		std::cout << "Impossible d'ouvrir le fichier" << std::endl;
	fichier.close();
}

