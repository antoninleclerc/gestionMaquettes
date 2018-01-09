#include "maquette.h" 

maquette::maquette() : d_maquettes{} 
{}

maquette::~maquette() 
{
	for(auto ue : d_maquettes) 
	{
		delete ue;
	}
}

void maquette::ajouterUE(UE * ue) 
{
	d_maquettes.push_back(ue); 
}

void maquette::afficheMaquette(std::ostream & ost) const
{
	for (int i = 0; i < d_maquettes.size(); i++) 
	{
		d_maquettes[i]->affiche(ost) ; 
	}
}

bool maquette::supprimerUE(std::string & code)
{
	int i=0 ;
	while (i < d_maquettes.size() && d_maquettes[i]->code() != code) 
	{
		i++ ;
	}
	if (code == d_maquettes[i]->code ())
	{
		delete d_maquettes[i];
		d_maquettes[i] = d_maquettes.back();
		d_maquettes.pop_back();
		return true;
	}
	else 
	{
		return false;
	}
}

int maquette::nombreUEDansMaquette() const
{
	return d_maquettes.size(); 
}

std::ostream& operator<<(std::ostream& ost, const maquette& m)
{
	m.afficheMaquette(ost);
	return ost;
}
