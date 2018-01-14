#include "doctest.h"
#include "formation.h" 
#include "maquette.h"


TEST_CASE {"Construction d'une formation "}
{
	int nbAnnee=3 ; 
	std:: string domaine="fst" ; 
	std:: string mention= "Licence Informatique" ; 
	std::string parcours = "Informatique" ;
	formation f {nbAnnee, domaine, mention, parcours} ; 
	REQUIRE_EQ(f.nombreAnnee(), nbAnnee) ; 
	REQUIRE_EQ(f.domaine(), domaine) ; 
	REQUIRE_EQ(f.mention(), mention) ; 
	REQUIRE_EQ(f.parcours(), parcours) ; 
}

TEST_CASE("Ajout d'une maquette")
{
	maquette m ; 
	ajouterMaquette(m) ; 
	REQUIRE_EQ(maquetteNumero(nombreMaquettes), m) ; 
}

TEST_CASE("Modification d'une formation")
{
	int nbAnnee=3 ; 
	std:: string domaine="fst" ; 
	std:: string mention= "Licence Informatique" ; 
	std::string parcours = "Informatique" ;
	formation f {nbAnnee, domaine, mention, parcours} ; 
	SUBCASE{"nombre d'année modifié"}
	{
		f.modifierNombreAnnee(2) ; 
		REQUIRE_EQ(f.nombreAnnee(), 2) ;
	}
	SUBCASE{"Domaine modifié"}
	{
		f.modifierDomaine ("flsh") ; 
		REQUIRE_EQ(f.domaine(),"flsh" ) ;
	}
	SUBCASE{"Mention modifié"}
	{
		f.modifierMention("Licence Anglais") ; 
		REQUIRE_EQ(f.mention(), "Licence Anglais") ;
	}
	SUBCASE{"Parcours modifié"}
	{
		f.modifierParcours("Anglais") ; 
		REQUIRE_EQ(f.parcours(),"Anglais" ) ;
	}
	
}




