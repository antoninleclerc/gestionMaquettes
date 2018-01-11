#include <iomanip>

#include "Formation.h"

Formation::Formation(int nombreAnnee, const std::string intitule) : d_nombreAnnee{nombreAnnee}, d_intitule{intitule}, d_maquettes{} 
{}

Formation::~Formation()
{
	for(auto m : d_maquettes)
	{
		delete m;
	}
}

int Formation::nombreAnnee() const
{
	return d_nombreAnnee;
}

std::string Formation::intitule() const 
{
	return d_intitule;
}

void Formation::ajouterMaquette(Maquette * m) 
{
	d_maquettes.push_back(m);
}

void Formation::modifierNombreAnnee(int nombreAnnee) 
{
	d_nombreAnnee = nombreAnnee; 
}

void Formation::modifierIntitule(std::string intitule) 
{
	d_intitule = intitule; 
}

bool Formation::supprimerMaquette(int numeroSemestre)
{
	if (numeroSemestre <= d_maquettes.size())
	{
		delete d_maquettes[numeroSemestre-1] ; 
		for (int i = numeroSemestre; i < d_maquettes.size(); i++) 
		{
			d_maquettes[i-1] = d_maquettes[i];
		}
		return true;
	}
	else 
	{
		return false; 
	}	
}

void Formation :: afficheFormation(std :: ostream & ost) const
{
	ost << std :: setw(4) << d_intitule << std :: endl ;
	for (int i=0 ; i< d_maquettes.size() ; i++ )
	{
		ost << std::setw(4)<< " Semestre " << i+1 <<std ::endl ;
		d_maquettes[i]->afficheMaquette (ost) ; 
	}	ost<< std :: endl ; 
}
