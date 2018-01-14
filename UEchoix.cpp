#include "UEchoix.h"


UEchoix::UEchoix(const std::string &code, const std::string &intitule, int coefficient, int CM, int TD, int TP, int ECTS):UE{code, intitule, coefficient, CM, TD, TP, ECTS}
{
    UE* ueChoix = new UE{code, intitule, coefficient, CM, TD, TP, ECTS};
    d_UEchoix.push_back(ueChoix);
}

UEchoix::~UEchoix()
{}

int UEchoix::nombreUE() const
{
	return d_UEchoix.size()-1;
}

void UEchoix::affiche(std::ostream &ost) const
{
    ost<<std::setw(4)<<code()<<std::setw(4)<<coefficient()<<std::setw(4)<<ECTS()<<std::setw(4)<<"UE CHOIX"<<std::endl;
    for(int i=0; i<d_UEchoix.size()-1; i++)
    {
        d_UEchoix[i]->affiche(ost);
        ost<<std::endl;
        ost<<std::setw(16)<<"OU"<<std::endl;
    }
    d_UEchoix[d_UEchoix.size()-1]->affiche(ost);
}

void UEchoix::ajouterUE(UE *ue)
{
    d_UEchoix.push_back(ue);
}

bool UEchoix::supprimerUE(const std::string& code)
{
    int i=0;
    while(i<d_UEchoix.size() && d_UEchoix[i]->code() != code)
    {
        i++;
    }
    if(i >= d_UEchoix.size())
        return false;
    else
    {
        delete d_UEchoix[i];
        d_UEchoix[i]=d_UEchoix.back();
        d_UEchoix.pop_back();
        return true;
    }
}

