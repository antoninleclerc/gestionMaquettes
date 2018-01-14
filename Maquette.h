#ifndef MAQUETTE_H
#define MAQUETTE_H

#include "UE.h" 
#include "Cours.h"
#include <vector> 

namespace GestionMaquettes
{
	class Maquette 
	{
		public : 
			/**	Constructeur d'une maquette
			*/
			Maquette();
			/**	Destructeur d'une maquette
			*/
			~Maquette();
			/** Fonction ajouterUE
			*	Permet d'ajouter une UE au vecteur d'UE choix
			*	@param[in] ue - Pointeur sur l'ue à ajouter
			*/
			void ajouterUE(UE * ue); 
			/** Fonction affiche
       			 *	@Permet d'afficher une maquette
       			 */
			void afficheMaquette(std::ostream & ost) const; 
			/** Fonction supprimerUE
       			*	Retourne vrai si la suppression de l'UE s'est bien passee
        		*	@param[in] code - chaine de caractère représentant le code de l'UE a supprrimer
      			*/
			bool supprimerUE(std::string & code);
			/** Fonction nombreUEDansMaquette
        		 *	@retourne le nombre d'UE dans une maquette
         		*/
			int nombreUEDansMaquette() const; 
				
		private :
			/**
			*	vecteur de pointeur sur UE 
			*/
			std::vector<UE*> d_UE; 
	};
	
	std::ostream& operator<<(std::ostream& ost, const Maquette& m);
}
	
#endif 
