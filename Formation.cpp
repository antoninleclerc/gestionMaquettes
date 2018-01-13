#include <iomanip>
#include <fstream>

#include "Formation.h"
#include "System.h"

Formation::Formation(int nombreAnnee, const std::string domaine, const std::string mention, const std::string parcours) : d_nombreAnnee{nombreAnnee}, d_domaine{domaine}, d_mention{mention}, d_parcours{parcours}, d_maquettes{} 
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

std::string Formation::domaine() const 
{
	return d_domaine;
}

std::string Formation::mention() const 
{
	return d_mention;
}

std::string Formation::parcours() const 
{
	return d_parcours;
}

void Formation::ajouterMaquette(Maquette * m) 
{
	d_maquettes.push_back(m);
}

void Formation::modifierNombreAnnee(int nombreAnnee) 
{
	d_nombreAnnee = nombreAnnee; 
}

void Formation::modifierDomaine(const std::string & domaine) 
{
	d_domaine = domaine; 
}

void Formation::modifierMention(const std::string & mention) 
{
	d_mention = mention; 
}

void Formation::modifierParcours(const std::string & parcours) 
{
	d_parcours = parcours; 
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
	System::centrerTexte(d_domaine,System::LARGEUR_CONSOLE);
	System::centrerTexte(d_mention,System::LARGEUR_CONSOLE);
	System::centrerTexte(d_parcours,System::LARGEUR_CONSOLE);
	for (int i=0 ; i< d_maquettes.size() ; i++ )
	{
		ost << std::setw(4)<< " Semestre " << i+1 <<std ::endl ;
		d_maquettes[i]->afficheMaquette (ost) ; 
	}	ost<< std :: endl ; 
}

void Formation :: sauverDansFichier() const
{
	std::string chaine=d_mention+" "+d_parcours;
	System::ajouterFinFichier(chaine, "Liste formations.txt");
	
	//Puis ajouter les maquettes en parcourant le tableau des maquettes et en appelant une méthode sauverMaquette (A CREER)	
	
	std::cout << std::endl << "La formation a ete correcement sauvegardee ! "<<std::endl;
	system("pause");
}

std::ostream& operator<<(std::ostream& ost, const Formation& f)
{
	f.afficheFormation(ost);
	return ost;
}
