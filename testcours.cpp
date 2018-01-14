#include "doctest.h"
#include "cours.h" 


TEST_CASE {"Construction d'un cours "}
{
	
	std:: string code ="1122S" ; 
	std:: string intitule = "Algortihmique" ; 
	int coeff = 2 ;
	cours c {code, intitule, coeff} ; 
	REQUIRE_EQ(f.code(), code) ; 
	REQUIRE_EQ(f.intitule(), intitule) ; 
	REQUIRE_EQ(f.coefficient(), coeff) ; 
 
}
