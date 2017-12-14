#include "cours.h"

cours::cours() : d_code{}, d_intitule{}, d_coefficient{}
{}

cours :: cours(const std::string& code, const std::string& intitule, int coefficient):
    d_code{code},
    d_intitule{intitule},
    d_coeff{coefficient}
{}

cours::~cours()
{}

std::string cours ::code()const
{
    return d_code;
}

std::string cours ::intitule()const
{
    return d_intitule;
}

int cours ::coefficient()const
{
    return d_coefficient;
}
