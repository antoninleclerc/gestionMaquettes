#include "catch.hpp"
#include "UEchoix.h"
#include "UE.h"

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
/**
TEST_CASE("Ajout d'une UE")
{
	std::string code = "13GULANG";
	std::string intitule = "Langues";
	int coefficient = 1;
	int heuresCM = 20;
	int heuresTD = 10;
	int heuresTP = 15;
	int ECTS = 3;
	UEchoix uechoix{code, intitule, coefficient, heuresCM, heuresTD, heuresTP, ECTS};
	
	std::string codeUE = "13GUALL";
	std::string intituleUE = "Allemand";
	int coefficientUE = 1;
	int heuresCMUE = 10;
	int heuresTDUE = 10;
	int heuresTPUE = 0;
	int ECTSUE = 1;
	UE* ue = new UE{codeUE, intituleUE, coefficientUE, heuresCMUE, heuresTDUE, heuresTPUE, ECTSUE};
	SECTION("L'UE a bien ete ajoute a l'UE a choix")
	{
		uechoix.ajouterUE(ue);
		REQUIRE(uechoix.nombreUE()==1);
	}	
}

TEST_CASE("Suppression d'une UE")
{
	std::string code = "13GULANG";
	std::string intitule = "Langues";
	int coefficient = 1;
	int heuresCM = 20;
	int heuresTD = 10;
	int heuresTP = 15;
	int ECTS = 3;
	UEchoix uechoix{code, intitule, coefficient, heuresCM, heuresTD, heuresTP, ECTS};
	
	std::string codeUE = "13GUALL";
	std::string intituleUE = "Allemand";
	int coefficientUE = 1;
	int heuresCMUE = 10;
	int heuresTDUE = 10;
	int heuresTPUE = 0;
	int ECTSUE = 1;
	UE* ue = new UE{codeUE, intituleUE, coefficientUE, heuresCMUE, heuresTDUE, heuresTPUE, ECTSUE};
	SECTION("L'UE a bien ete supprimee de l'UE a choix")
	{
		if(uechoix.supprimerUE(codeUE)==true)
		{
			REQUIRE(uechoix.nombreUE()==0);
		}
	}
}
*/
