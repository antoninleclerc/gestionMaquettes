#include "catch.hpp"
#include "UE.h"

void LUEAlesBonnesDonnes(const UE &ue, const std::string &code, const std::string &intitule, int coefficient, int heuresCM, int heuresTD, int heuresTP, int ECTS)
{
	REQUIRE(ue.code()==code);
	REQUIRE(ue.intitule()==intitule);
	REQUIRE(ue.coefficient()==coefficient);
	REQUIRE(ue.totalHeuresCM()==heuresCM);	
	REQUIRE(ue.totalHeuresTD()==heuresTD);
	REQUIRE(ue.totalHeuresTP()==heuresTP);
	REQUIRE(ue.ECTS()==ECTS);
}
