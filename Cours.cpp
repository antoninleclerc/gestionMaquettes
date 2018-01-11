#include "Cours.h"


Cours::Cours(const std::string& code, const std::string& intitule, int coefficient) :
    d_code{code},
    d_intitule{intitule},
    d_coefficient{coefficient}
{}

Cours::~Cours()
{}

std::string Cours::code()const
{
    return d_code;
}

std::string Cours::intitule()const
{
    return d_intitule;
}

int Cours::coefficient()const
{
    return d_coefficient;
}

std::ostream& operator<<(std::ostream& ost, const Cours& c)
{
	c.affiche(ost);
	return ost;
}
