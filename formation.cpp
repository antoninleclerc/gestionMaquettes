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
void formation :: afficheFormation(std :: ostream & ost) const
{
	ost << std :: setw(4) << d_intitule << std :: endl ;
	for (int i=0 ; i< d_maquettes.size() ; i++ )
	{
		ost << std::setw(4)<< " Semestre " << i+1 <<std ::endl ;
		d_maquettes.afficheMaquette (ost) ; 
	}	ost<< std :: endl ; 
}
