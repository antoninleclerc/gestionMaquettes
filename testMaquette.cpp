#include "catch.hpp"
#include "Maquette.h"
#include "Ue.h"

TEST_CASE("Ajout d'une ue")
{
	Maquette m;
	std :: code = "1121" ; 
	std:: string intitule = "Algo" ; 
	int CM = 14 ; 
	int TD = 15 ;
	int TP = 18 ; 
	int ECTS = 3 ; 
	UE ue {code, intitule, coefficient, CM, TD, TP, ECTS} ;
	m.ajouterUE(ue) ; 
	REQUIRE(m.UeNumero(m.nombreUEDansMaquette())== ue) ; 
}

TEST_CASE("Suppression d'une UE")
{
	Maquette  m ; 
	std :: code = "1121" ; 
	std:: string intitule = "Algo" ; 
	int CM = 14 ; 
	int TD = 15 ;
	int TP = 18 ; 
	int ECTS = 3 ; 
	UE ue {code, intitule, coefficient, CM, TD, TP, ECTS} ;
	m.ajouterUE(ue) ;  
	if (m.supprimerUE(code) == true) 
	{
		REQUIRE(m.UeNumero(m.nombreUEDansMaquette().code()!=code ) ;
	 } 
	
	
}
