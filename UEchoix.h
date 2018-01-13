#ifndef UECHOIX_H
#define UECHOIX_H

#include <vector>
#include <iomanip>
#include "UE.h"

class UEchoix: public UE
{
    public:
    	/** Constructeur d'une UE choix
		*	@brief Constructeur d'une UE choix � partir d'un code, d'un intitule, d'un coefficient,des heures CM, des heures TD, des heures TP et d'un ECTS
		*	@param[in] code - chaine de caract�re repr�sentant le code
		*	@param[in] intitule - chaine de caract�re repr�sentant l'intitul�
		*	@param[in] coefficient - chaine de caract�re repr�sentant le coefficient
		*	@param[in] heuresCM - un entier repr�sentant le nombre d'heure CM
		*	@param[in] heuresTD - un entier repr�sentant le nombre d'heure TD
		*	@param[in] heuresTP - un entier repr�sentant le nombre d'heure TP
		*	@param[in] ECTS - un entier repr�sentant le nombre d'ECTS
		*/
        UEchoix(const std::string &code, const std::string &intitule, int coefficient, int heuresCM, int heuresTD, int heuresTP, int ECTS);
        
        /** destructeur d'UE choix
        */
        virtual ~UEchoix();
        
		/** Fonction ajouterUE
		*	Permet d'ajouter une UE au vecteur d'UE choix
		*	@param[in] ue - Pointeur d=sur l'ue � ajouter
		*/  
        void ajouterUE(UE *ue);
        
        /** Fonction supprimerUE
        *	Retourne vrai si la suppression de l'UE s'est bien passee
        *	@param[in] code - chaine de caract�re repr�sentant le code de l'UE a supprrimer
        */
        bool supprimerUE(const std::string& code);
        
        /** Fonction affiche
        *	Permet d'afficher le contenu d'une UE choix
        *	@param[in] ost - Le flot � partir duquel va se faiire la lecture
        */
        void affiche(std::ostream &ost) const;

    private:
    	/**
    	* 	Vecteur de pointeurs sur UE
    	*/
        std::vector<UE*>d_UEchoix;
};

#endif // UECHOIX_H
