#include "Maquette.h" 

namespace GestionMaquettes
{
	Maquette::Maquette() : d_UE{} 
	{}
	
	Maquette::~Maquette() 
	{
		for(auto ue : d_UE) 
		{
			delete ue;
		}
	}
	
	void Maquette::ajouterUE(UE * ue) 
	{
		d_UE.push_back(ue); 
	}
	
	void Maquette::afficheMaquette(std::ostream & ost) const
	{
		for (int i = 0; i < d_UE.size(); i++) 
		{
			d_UE[i]->affiche(ost) ; 
		}
	}
	
	bool Maquette::supprimerUE(std::string & code)
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
	
	int Maquette::nombreUEDansMaquette() const
	{
		return d_UE.size(); 
	}
	
	std::ostream& operator<<(std::ostream& ost, const Maquette& m)
	{
		m.afficheMaquette(ost);
		return ost;
	}
	
	void Maquette::enregistrerMaquette(const std::string &mention) const {
		for (int i = 0; i < d_UE.size(); i++){
			d_UE[i]->enregistrerUE(mention); 
		}
	}
	
}

