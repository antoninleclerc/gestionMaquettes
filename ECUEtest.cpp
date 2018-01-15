#include "catch.hpp"
#include "ECUE.h"
#include <string.h>

void lesDonneesDeECUEsontExactement(const ECUE& ecue, std::string code, std::string intitule, int coefficient, int heuresCM, int heuresTD, int heuresTP)
{
	REQUIRE( ecue.code() == code );
	REQUIRE( ecue.intitule() == intitule );
	REQUIRE( ecue.coefficient() == coefficient );
	REQUIRE( ecue.heuresCM() == heuresCM );
	REQUIRE( ecue.heuresTD() == heuresTD );
	REQUIRE( ecue.heuresTP() == heuresTP );
}

TEST_CASE("Les ECUEs sont bien construites", "[ECUE]"){
	std::string code = "13GUCSI5";
	std::string intitule = "Qualité de programmation";
	int coefficient = 2;
	int heuresCM = 10, heuresTD = 6, heuresTP = 2;
	ECUE ecue {code, intitule, coefficient, heuresCM, heuresTD, heuresTP};
	
	lesDonneesDeECUEsontExactement(ecue, code, intitule, coefficient, heuresCM, heuresTD, heuresTP);
}

TEST_CASE("Les fonctions permettant de modifier les données d une ECUE fonctionnent", "[ECUE]"){
	std::string code = "13GUCSI5";
	std::string intitule = "Qualité de programmation";
	int coefficient = 2;
	int heuresCM = 10, heuresTD = 6, heuresTP = 2;
	ECUE ecue {code, intitule, coefficient, heuresCM, heuresTD, heuresTP};
	
	SECTION("La fonction modifierHeuresCM(int heuresCM) change le nombre d heuresCM"){
		int nouveauNombreHeuresCM = 20;
		ecue.modifierHeuresCM(nouveauNombreHeuresCM);
		REQUIRE( ecue.heuresCM() == nouveauNombreHeuresCM );
	}
	SECTION("La fonction modifierHeuresTD(int heuresTD) change le nombre d heuresTD"){
		int nouveauNombreHeuresTD = 10;
		ecue.modifierHeuresTD(nouveauNombreHeuresTD);
		REQUIRE( ecue.heuresTD() == nouveauNombreHeuresTD );
	}
	SECTION("La fonction modifierHeuresTP(int heuresTP) change le nombre d heuresTP"){
		int nouveauNombreHeuresTP = 4;
		ecue.modifierHeuresTP(nouveauNombreHeuresTP);
		REQUIRE( ecue.heuresTP() == nouveauNombreHeuresTP );
	}
}
