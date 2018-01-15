#include "catch.hpp"
#incldue "Maquette.h"
#include "Ue.h"

TEST_CASE("Ajout d'une ue")
{
	UE ue ; 
	ajouterUE(u) ; 
	REQUIRE_EQ(UeNumero(nombreUEDansMaquette()), ue) ; 
}

TEST_CASE("Suppression d'une UE")
{
	std :: code = "1121" ; 
	std:: string intitule = "Algo" ; 
	int CM = 14 ; 
	int TD = 15 ;
	int TP = 18 ; 
	int ECTS = 3 ; 
	UE ue (code, intitule, coefficient, CM, TD, TP, ECTS) ;
	ajouterUE(ue) ; 
	int n=nombreUEDansMaquette() ; 
	if (supprimerUE(code) == true) 
	{
		REQUIRE(UeNumero(nombreUEDansMaquette().code()!=code ) ;
	 } 
	
	
}
