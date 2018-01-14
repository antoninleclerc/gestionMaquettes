#include "catch.hpp"
#include "UEchoix.h"

void LUEchoixAlesBonnesDonnes(const UEchoix &uechoix, const std::string &code, const std::string &intitule, int coefficient, int heuresCM, int heuresTD, int heuresTP, int ECTS)
{
	REQUIRE(uechoix.code()==code);
	REQUIRE(uechoix.intitule()==intitule);
	REQUIRE(uechoix.coefficient()==coefficient);
	REQUIRE(uechoix.totalHeuresCM()==heuresCM);	
	REQUIRE(uechoix.totalHeuresTD()==heuresTD);
	REQUIRE(uechoix.totalHeuresTP()==heuresTP);
	REQUIRE(uechoix.ECTS()==ECTS);
}


TEST_CASE ("Construction d'une UE a choix ") {
	SECTION("L'UE a choix construite a les bonnes donnees")
	{
		std::string code = "13GUPOO5";
		std::string intitule = "POO";
		int coefficient = 1;
		int heuresCM = 14;
		int heuresTD = 20;
		int heuresTP = 0;
		int ECTS = 3;
		UEchoix uechoix{code, intitule, coefficient, heuresCM, heuresTD, heuresTP, ECTS};
		LUEchoixAlesBonnesDonnes(uechoix, code, intitule, coefficient, heuresCM, heuresTD, heuresTP, ECTS);		
	}

}

