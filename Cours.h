#ifndef COURS_H
#define COURS_H
#include <string>

class Cours
{
    public:
        /*
        Constructeur par défaut
        **/
        Cours();
        /*
        Constructeur à partir d'un code, un intitulé et un coefficient
        **/
        Cours(const std::string& code, const std::string& intitule, int coefficient);
        /*
        destructeur de cours
        **/
        virtual ~Cours();
        /*
        @retourne le code d'un cours
        **/
        std::string code()const;
        /*
        @retourne l'intitulé d'un cours
        **/
        std::string intitule()const;
        /*
        @retourne le coefficient d'un cours
        **/
        int coefficient()const;
        /*
        affiche le contenu d'un cours
        **/
        virtual void affiche(std::ostream& ost) const=0;

    private:
        std::string d_code;
        std::string d_intitule;
        int d_coefficient;
};

std::ostream& operator<<(std::ostream& ost, const Cours& s);

#endif // COURS_H
