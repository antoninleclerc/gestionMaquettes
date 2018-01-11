#include "maquette.h" 

maquette::maquette() : d_UE{} 
{}

maquette::~maquette() 
{
	for(auto ue : d_UE) 
	{
		delete ue;
	}
}

void maquette::ajouterUE(UE * ue) 
{
	d_UE.push_back(ue); 
}

void maquette::afficheMaquette(std::ostream & ost) const
{
	for (int i = 0; i < d_UE.size(); i++) 
	{
		d_UE[i]->affiche(ost) ; 
	}
}

bool maquette::supprimerUE(std::string & code)
{
	int i=0 ;
	while (i < d_UE.size() && d_UE[i]->code() != code) 
	{
		i++ ;
	}
	if (code == d_UE[i]->code ())
	{
		delete d_UE[i];
		d_UE[i] = d_UE.back();
		d_UE.pop_back();
		return true;
	}
	else 
	{
		return false;
	}
}

int maquette::nombreUEDansMaquette() const
{
	return d_UE.size(); 
}

std::ostream& operator<<(std::ostream& ost, const maquette& m)
{
	m.afficheMaquette(ost);
	return ost;
}
