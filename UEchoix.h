#ifndef UECHOIX_H
#define UECHOIX_H

#include <vector>
#include <iomanip>
#include "UE.h"

class UEchoix: public UE
{
    public:
    	/** Constructeur d'un cours
		*	@brief Constructeur de cours � partir d'un code, d'un intitule et d'un coefficient
		*	@param[in] code - chaine de caract�re repr�sentant le code
		*	@param[in] intitule - chaine de caract�re repr�sentant l'intitul�
		*	@param[in] coefficient - chaine de caract�re repr�sentant le coefficient
		*	@param[in] CM - un entier repr�sentant le nombre d'heure CM
		*	@param[in] TD - un entier repr�sentant le nombre d'heure TD
		*	@param[in] TP - un entier repr�sentant le nombre d'heure TP
		*	@param[in] ECTS - un entier repr�sentant le nombre d'ECTS
		*/
        UEchoix(const std::string &code, const std::string &intitule, int coefficient, int CM, int TD, int TP, int ECTS);
        virtual ~UEchoix();

        void ajouterUE(UE *ue);
        bool supprimerUE(const std::string& code);
        virtual void affiche(std::ostream &ost) const override;

    private:
        std::vector<UE*>d_UEchoix;
};

#endif // UECHOIX_H
