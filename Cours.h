#ifndef COURS_H
#define COURS_H
#include <string>
#include <iostream>
class Cours
{
    public:
        /** Constructeur d'un cours
		 *	@brief Constructeur de cours à partir d'un code, d'un intitule et d'un coefficient
		 *	@param[in] code - chaine de caractère représentant le code
		 *	@param[in] intitule - chaine de caractère représentant l'intitulé
		 *	@param[in] coefficient - chaine de caractère représentant le coefficient
		 */
        Cours(const std::string& code, const std::string& intitule, int coefficient);
        
        /** destructeur de cours
        */
        virtual ~Cours();
        
        /** Fonction code
         *	@retourne le code d'un cours
         */
        std::string code()const;
        
        /**	Fonction intitule
       	 *	@Retourne l'intitule d'un cours
         */
        std::string intitule()const;
        
        /** Fonction coefficient
         *	@Retourne le coefficient d'un cours
         */
        int coefficient()const;
        
        /** Fonction affiche
       	 *	@Permet d'afficher le contenu d'un cours
         */
        virtual void affiche(std::ostream& ost) const = 0;

    private:
    	/**
		 *Code d'un cours
		 */
        std::string d_code;
        //Intitule d'un cours
        std::string d_intitule;
        //Coefficient d'un cours
        int d_coefficient;
};

std::ostream& operator<<(std::ostream& ost, const Cours& s);

#endif // COURS_H
