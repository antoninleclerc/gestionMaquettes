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
			 	@param[out] ost - affichage sur le flot 
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
		
			/**	Fonction enregistrerMaquette
			 *	Permet d'enregistrer une maquette dans le fichier txt portant le nom de la mention de la formation à laquelle appartient la maquette
			 *	@param[in] mention : le nom du fichier txt
			 */
			void enregistrerMaquette(const std::string &mention) const;
			/** Fonction UeNumero
        		 *	@retourne l'ue 
			 	@param[out] numero - numero de l'ue 
         		*/
			UE* Maquette::UeNumero(int numero) const ; 
		private :
			/**
			*	vecteur de pointeur sur UE 
			*/
			std::vector<UE*> d_UE; 
	};
	
	std::ostream& operator<<(std::ostream& ost, const Maquette& m);
}
	
#endif 
