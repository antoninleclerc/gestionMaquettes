#include "formation.h"

formation::formation(int nombreAnnee, const std::string intitule) : d_nombreAnnee{nombreAnnee}, d_intitule{intitule}, d_maquettes{} 
{}

formation::~formation()
{
	for(auto m : d_maquettes)
	{
		delete m;
	}
}

int formation::nombreAnnee() const
{
	return d_nombreAnnee;
}

std::string formation::intitule() const 
{
	return d_intitule;
}

void formation::ajouterMaquette(maquette * m) 
{
	d_maquettes.push_back(m);
}

void formation::modifierNombreAnnee(int nombreAnnee) 
{
	d_nombreAnnee = nombreAnnee; 
}

void formation::modifierIntitule(std::string intitule) 
{
	d_intitule = intitule; 
}

bool formation::supprimerMaquette(int numeroSemestre)
{
	if (numeroSemestre <= d_formations.size())
	{
		delete d_formations[numeroSemestre-1] ; 
		for (int i = numeroSemestre; i < d_formations.size(); i++) 
		{
			d_maquettes[i-1] = i;
		}
		return true;
	}
	else 
	{
		return false; 
	}	
}
