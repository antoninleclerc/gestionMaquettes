#include <iomanip>
#include "UE.h"

UE::UE(const std::string &code, const std::string &intitule, int coefficient, int CM, int TD, int TP, int ECTS)
{
	ECUE* ecue= new ECUE{code,intitule,coefficient,CM,TD,TP};
	d_UE.push_back(ecue):
	d_ECTS=ECTS;
}

int UE::nbECUE() const
{
	return d_UE.size()-1;
}

int UE::ECTS() const
{
	return d_ECTS;
}

int UE::nbCMTotal() const
{
	int CMtotal=0;
	for(int i=0; i<nbECUE(); i++)
	{
		CMtotal+=d_UE[i]->nbCM();
	}
	return CMtotal;
}

int UE::nbTDTotal() const
{
	int TDtotal=0;
	for(int i=0; i<nbECUE(); i++)
	{
		TDtotal+=d_UE[i]->nbTD();
	}
	return TDtotal;
}

int UE::nbTPTotal() const
{
	int TPtotal=0;
	for(int i=0; i<nbECUE(); i++)
	{
		TPtotal+=d_UE[i]->nbTP();
	}
	return TPtotal;
}

int UE::nbHeuresTotal() const
{
	int heuresTotal=0;
	for(int i=0; i<nbECUE(); i++)
	{
		heuresTotal+=nbCMTotal()+nbTDTotal()+nbTPTotal();
	}
	return heuresTotal;
}

void UE::afficher(std::ostream &ost) const
{	
	if(nbECUE>0) //si UE composé de au moins un ECUE
	{
		ost<<setw(4)<<code()<<setw(4)<<coefficient()<<setw(4)<<ECTS()<<setw(4)<<"UE "<<intitule();
		for(int i=0; i<nbECUE(); i++)
		d_UE[i].afficher();
	}
	else //si UE seule
	{
		ost<<setw(4)<<code()<<setw(4)<<coefficient()<<setw(4)<<ECTS()<<setw(4)<<"UE "<<intitule()<<setw(4)<<nbCMTotal()<<setw(4)<<nbTDTotal()<<setw(4)<<nbTPTotal()<<setw(4)<<nbHeuresTotal();
	}
		
}

