#ifndef FORMATION_H
#define FORMATION_H

#include "Maquette.h"
#include <vector>

namespace GestionMaquettes
{
	class Formation 
	{
		public :
			/** Constructeur d'une formation
			*	@brief Constructeur d'une maquette à partir du nombre d'année, du domaine, de la mention et le parcours
			*	@param[in] nombreAnnee - entier représentant le nombre d'année 
			*	@param[in] domaine - chaine de caractère représentant le domaine
			*	@param[in] mention - chaine de caractère représentant la mention
			*	@param[in] parcours - chaine de caractère représentant le parcours
			**/
			Formation(int nombreAnnee, const std::string domaine, const std::string mention, const std::string parcours); 
			/** Destructeur d'une formation
		
			**/
			~Formation(); 
			/** Fonction nombreAnnee
        		 *	@retourne le nombre d'annee d'une formation
         		*/
			int nombreAnnee() const;
			/** Fonction nombreAnnee
        		 *	@retourne le domaine d'une formation
         		*/
			std::string domaine() const; 
			/** Fonction nombreAnnee
        		 *	@retourne la mention d'une formation
         		*/
			std::string mention() const; 
			/** Fonction nombreAnnee
        		 *	@retourne le parcours d'une formation
         		*/
			std::string parcours() const; 
			/** Fonction maquetteNumero
        		 *	@retourne la maquette
         		*/
			Maquette* maquetteNumero(int numero);
			/** Fonction nombreMaquette
        		 *	@retourne le nombre de maquette
         		*/
			int nombreMaquettes() const;
			/**	Fonction modifierNombreAnnee
			 *	Permet de modifier le nombre d'annee d'une formation
		 	*	@param[in] nombreAnnee-  Le nouveau nombre d'année
		 	*/
			void modifierNombreAnnee(int nombreAnnee); 
			/**	Fonction modifierDomaine
			*	Permet de modifier le domaine d'une formation
		 	*	@param[in] domaine-  Le nouveau domaine d'une formation
		 	*/
			void modifierDomaine(const std::string &domaine);
			/**	Fonction modifierMention
			*	Permet de modifier le domaine d'une formation
		 	*	@param[in] mention-  Le nouveau mention d'une formation
		 	*/
			void modifierMention(const std::string &mention);
			/**	Fonction modifierParcours
			*	Permet de modifier le pacours d'une formation
		 	*	@param[in] parcours-  Le nouveau parcours d'une formation
		 	*/
			void modifierParcours(const std::string &parcours);
			/** Fonction ajouterMaquette
			*	Permet d'ajouter une maquette 
			*	@param[in] maquette - Pointeur sur la maquette à ajouter
			*/
			void ajouterMaquette(Maquette * m); 
			/** Fonction supprimerMaquette
       			*	Retourne vrai si la suppression de la maquette s'est bien passee
        		*	@param[out] numeroSemestre - entier représentant le semestre à supprrimer
      			*/
			bool supprimerMaquette (int numeroSemestre);
			/** Fonction affiche
       			 *	Permet d'afficher la formation
       			 *	@param[in] ost - Le flot à partir duquel va se faiire la lecture
        		*/
			void afficheFormation(std :: ostream & ost) const;
			/** Fonction affiche
        		*	Permet d'afficher la liste des maquettes
        		*	@param[out] ost - Le flot à partir duquel va se faiire la lecture
        		*/
			void afficherListeMaquettes() const;
			
			void sauverDansFichier() const;
		
		private :
			/**
    			* 	nombre d'année
    			*/
			int d_nombreAnnee; 
			/**
    			* 	domaine d'une formation
    			*/
			std::string d_domaine; 
			/**
    			* 	mention d'une formation
    			*/
			std::string d_mention; 
			/**
    			* 	parcours d'une formation
    			*/
			std::string d_parcours; 
			/**
			*	vecteur de pointeur sur maquette
			*/
			std::vector<Maquette*> d_maquettes;	
	};
	
	std::ostream& operator<<(std::ostream& ost, const Formation& f);
}
	

#endif 
