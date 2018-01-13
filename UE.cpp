#include <iomanip>
#include "UE.h"

/**
	Constructeur
	@param[in] code - chaine de caractère représentant le code
	@param[in] intitule - chaine de caractère représentant l'intitulé
	@param[in] coefficient - chaine de caractère représentant le coefficient
	@param[in] CM - un entier représentant le nombre d'heure CM
	@param[in] TD - un entier représentant le nombre d'heure TD
	@param[in] TP - un entier représentant le nombre d'heure TP
	@param[in] ECTS - un entier représentant le nombre d'ECTS
*/
UE::UE(const std::string &code, const std::string &intitule, int coefficient, int CM, int TD, int TP, int ECTS): Cours{code, intitule, coefficient}, d_ECTS{ECTS}
{
	ECUE* ecue= new ECUE{code,intitule,coefficient,CM,TD,TP};
	d_UE.push_back(ecue);
}

/**
	Destructeur
*/
UE::~UE()
{
	for(auto i: d_UE)
	{
		delete i;
	}
}

/**
	Nombre d'ECUE
	@return le nombre total d'ECUE
*/
int UE::nombreECUE() const
{
	return d_UE.size()-1;
}

/**
	Nombre d'ECTS
	@return la valeur ECTS
*/
int UE::ECTS() const
{
	return d_ECTS;
}

/**
	Nombre d'heures CM
	@return le nombre total d'heures CM
*/
int UE::totalHeuresCM() const
{
	int HeuresCM=0;
	for(int i=0; i<nombreECUE(); i++)
	{
		HeuresCM+=d_UE[i]->heuresCM();
	}
	return HeuresCM;
}

/**
	Nombre d'heures TD
	@return le nombre total d'heures TD
*/
int UE::totalHeuresTD() const
{
	int HeuresTD=0;
	for(int i=0; i<nombreECUE(); i++)
	{
		HeuresTD+=d_UE[i]->heuresTD();
	}
	return HeuresTD;
}

/**
	Nombre d'heures TP
	@return le nombre total d'heures TP
*/
int UE::totalHeuresTP() const
{
	int HeuresTP=0;
	for(int i=0; i<nombreECUE(); i++)
	{
		HeuresTP+=d_UE[i]->heuresTP();
	}
	return HeuresTP;
}

/**
	Nombre d'heures
	@return le nombre total d'heures
*/
int UE::totalNombreHeures() const
{
	return totalHeuresCM()+totalHeuresTD()+totalHeuresTP();
}

/**
	Ajoute un ECUE
	@param[out] ecue - un pointeur sur un ECUE
*/
void UE::ajouterECUE(ECUE*ecue)
{
	d_UE.push_back(ecue);
}

/**
	Modifie l'ECTS
	@param[in] ECTS - un entier représentant le nouveau ECTS
*/
void UE::modifierECTS(int ECTS)
{
	d_ECTS=ECTS;
}

/*
	Supprime l'ECUE à partir d'un code
	@param[in] code - une chaine de caractère représentant le code UE
	@return vrai si suppression réussie
*/
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

/*
	Affiche l'UE sur un flot de sortie
	@param[out] ost - un flot de sortie
	@return ost le flot de sortie
*/
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

