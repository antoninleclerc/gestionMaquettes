#include "catch.hpp"
#include "UE.h"
#include "ECUE.h"

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

TEST_CASE ("Construction d'une UE ") {
	SECTION("L'UE construite a les bonnes donnees")
	{
		std::string code = "13GUPOO5";
		std::string intitule = "POO";
		int coefficient = 1;
		int heuresCM = 20;
		int heuresTD = 10;
		int heuresTP = 15;
		int ECTS = 3;
		UE ue{code, intitule, coefficient, heuresCM, heuresTD, heuresTP, ECTS};
		LUEAlesBonnesDonnes(ue, code, intitule, coefficient, heuresCM, heuresTD, heuresTP, ECTS);		
	}
}

TEST_CASE("Modification d'une UE")
{
	std::string code = "13GUPOO5";
	std::string intitule = "POO";
	int coefficient = 1;
	int heuresCM = 20;
	int heuresTD = 10;
	int heuresTP = 15;
	int ECTS = 3;
	UE ue{code, intitule, coefficient, heuresCM, heuresTD, heuresTP, ECTS};
	SECTION("L'ECTS a bien ete modife'")
	{
		ue.modifierECTS(6);
		REQUIRE(ue.ECTS()==6);
	}
}

TEST_CASE("Ajout d'une ECUE")
{
	std::string code = "13GUPROG";
	std::string intitule = "Programmation";
	int coefficient = 1;
	int heuresCM = 20;
	int heuresTD = 10;
	int heuresTP = 15;
	int ECTS = 3;
	UE ue{code, intitule, coefficient, heuresCM, heuresTD, heuresTP, ECTS};
	
	std::string codeECUE = "13GPJAVE";
	std::string intituleECUE = "JAVA";
	int coefficientECUE = 1;
	int heuresCMECUE = 10;
	int heuresTDECUE = 10;
	int heuresTPECUE = 0;
	ECUE* ecue = new ECUE{codeECUE, intituleECUE, coefficientECUE, heuresCMECUE, heuresTDECUE, heuresTPECUE};
	SECTION("L'ECUE a bien ete ajoute a l'UE")
	{
		ue.ajouterECUE(ecue);
		REQUIRE(ue.nombreECUE()==1);
	}	
}

TEST_CASE("Suppression d'une ECUE")
{
	std::string code = "13GUPROG";
	std::string intitule = "Programmation";
	int coefficient = 1;
	int heuresCM = 20;
	int heuresTD = 10;
	int heuresTP = 15;
	int ECTS = 3;
	UE ue{code, intitule, coefficient, heuresCM, heuresTD, heuresTP, ECTS};
	
	std::string codeECUE = "13GPJAVE";
	std::string intituleECUE = "JAVA";
	int coefficientECUE = 1;
	int heuresCMECUE = 10;
	int heuresTDECUE = 10;
	int heuresTPECUE = 0;
	ECUE* ecue = new ECUE{codeECUE, intituleECUE, coefficientECUE, heuresCMECUE, heuresTDECUE, heuresTPECUE};
	SECTION("L'ECUE a bien ete supprimee de l'UE")
	{
		if(ue.supprimerECUE(codeECUE)==true)
		{
			REQUIRE(ue.nombreECUE()==0);
		}
	}
}
