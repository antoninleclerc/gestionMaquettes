#include "cours.h"

cours::cours() : d_code{}, d_intitule{}, d_coeff{}
{}

cours :: cours(const std::string& code, const std::string& intitule, int coeff):
    d_code{code},
    d_intitule{intitule},
    d_coeff{coeff}
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
    return d_coeff;
}
