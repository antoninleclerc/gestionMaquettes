#ifndef FORMATION_H
#define FORMATION_H

#include "Maquette.h"
#include <vector>

namespace GestionMaquettes
{
	class Formation 
	{
		public :
			Formation(int nombreAnnee, const std::string domaine, const std::string mention, const std::string parcours); 
			~Formation(); 
			int nombreAnnee() const;
			std::string domaine() const; 
			std::string mention() const; 
			std::string parcours() const; 
			Maquette* maquetteNumero(int numero);
			int nombreMaquettes() const;
			void modifierNombreAnnee(int nombreAnnee); 
			void modifierDomaine(const std::string &domaine);
			void modifierMention(const std::string &mention);
			void modifierParcours(const std::string &parcours);
			void ajouterMaquette(Maquette * m); 
			bool supprimerMaquette (int numeroSemestre);
			void afficheFormation(std :: ostream & ost) const;
			void afficherListeMaquettes() const;
			void sauverDansFichier() const;
		
		private :
			int d_nombreAnnee; 
			std::string d_domaine; 
			std::string d_mention; 
			std::string d_parcours; 
			std::vector<Maquette*> d_maquettes;	
	};
	
	std::ostream& operator<<(std::ostream& ost, const Formation& f);
}
	

#endif 
