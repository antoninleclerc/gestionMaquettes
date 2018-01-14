#include <iomanip>
#include <fstream>

#include "Formation.h"
#include "System.h"

namespace GestionMaquettes
{
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
	
	Maquette* Formation::maquetteNumero(int numero)
	{
		return d_maquettes[numero-1];
	}
	
	int Formation::nombreMaquettes() const
	{
		return d_maquettes.size();
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
			d_maquettes.pop_back();
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
	
	void Formation :: afficherListeMaquettes() const
	{
		System::effacerEcran();
		std::cout<<"Liste maquettes"<<std::endl<<std::endl;
		if(d_maquettes.size()==0)
		{
	 		std::cout<<"Il n'y aucune maquette dans la liste."<<std::endl;
			system("pause");
		}
		else
			for(int numeroAnnee=1; numeroAnnee<=nombreAnnee();numeroAnnee++)
			{
				for(int numeroSemestre=1; numeroSemestre<=d_maquettes.size();numeroSemestre++)
				{
					std::cout<<"("<<numeroSemestre<<") "<<mention()<<" "<<numeroAnnee<<" "<<parcours()<<" Semestre "<<numeroSemestre<<std::endl;
				}
			}
	}
	
	void Formation :: sauverDansFichier() const
	{
		
		//Puis ajouter les maquettes en parcourant le tableau des maquettes et en appelant une m�thode sauverMaquette (A CREER)	
		
		system("pause");
	}
	
	std::ostream& operator<<(std::ostream& ost, const Formation& f)
	{
		f.afficheFormation(ost);
		return ost;
	}
}
	
