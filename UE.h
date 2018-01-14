#ifndef UE_H
#define UE_H

#include <vector>
#include "Cours.h"
#include "ECUE.h"

namespace GestionMaquettes
{
	class UE : public Cours
	{
		public:
			/**
				Constructeur
				@param[in] code - chaine de caractère représentant le code
				@param[in] intitule - chaine de caractère représentant l'intitulé
				@param[in] coefficient - chaine de caractère représentant le coefficient
				@param[in] CM - un entier représentant le nombre d'heure CM
				@param[in] TD - un entier représentant le nombre d'heure TD
				@param[in] TP - un entier représentant le nombre d'heure TP
				@param[in] ECTS - un entier représentant le nombre d'ECTS
			*/	
			UE(const std::string &code, const std::string &intitule, int coefficient, int CM, int TD, int TP, int ECTS);
			
			/**
				Destructeur
			*/
			~UE();
	
			/**
				Nombre d'ECTS
				@return la valeur ECTS
			*/
			int ECTS() const;
			
			/**
				Nombre d'ECUE
				@return le nombre total d'ECUE
			*/
			int nombreECUE() const;
			
			/**
				Nombre d'heures CM
				@return le nombre total d'heures CM
			*/
			int totalHeuresCM() const;
			
			/**
				Nombre d'heures TD
				@return le nombre total d'heures TD
			*/
			int totalHeuresTD() const;
			
			/**
				Nombre d'heures TP
				@return le nombre total d'heures TP
			*/
			int totalHeuresTP() const;
			
			/**
				Nombre d'heures
				@return le nombre total d'heures
			*/
			int totalNombreHeures() const;
			
			
			/**
				Ajoute un ECUE
				@param[out] ecue - un pointeur sur un ECUE
			*/
			void ajouterECUE(ECUE* ecue);
			
			/**
				Modifie l'ECTS
				@param[in] ECTS - un entier représentant le nouveau ECTS
			*/
			void modifierECTS(int ECTS);
			
			/*
				Supprime l'ECUE à partir d'un code
				@param[in] code - une chaine de caractère représentant le code UE
				@return vrai si suppression réussie
			*/
			bool supprimerECUE(const std::string &code);
				
			/*
				Affiche l'UE sur un flot de sortie
				@param[out] ost - un flot de sortie
				@return ost le flot de sortie
			*/
			virtual void affiche(std::ostream &ost) const override;
			
		private:
			int d_ECTS;
			std::vector <ECUE*> d_UE; //La premiere case du vecteur est toujours l'UE principale, tout ce qui suit est les ECUE de cet UE.
	};

}
	


#endif
