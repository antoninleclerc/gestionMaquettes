#include "catch.hpp"
#include "Formation.h" 
#include "Maquette.h"
using namespace GestionFormation ; 

TEST_CASE ("Construction d'une formation ")
{
	int nbAnnee=3 ; 
	std:: string domaine="fst" ; 
	std:: string mention= "Licence Informatique" ; 
	std::string parcours = "Informatique" ;
	Formation f {nbAnnee, domaine, mention, parcours} ; 
	REQUIRE(f.nombreAnnee()== nbAnnee) ; 
	REQUIRE(f.domaine()== domaine) ; 
	REQUIRE(f.mention()== mention) ; 
	REQUIRE(f.parcours()== parcours) ; 
}

TEST_CASE("Ajout d'une maquette")
{
	int nbAnnee=3 ; 
	std:: string domaine="fst" ; 
	std:: string mention= "Licence Informatique" ; 
	std::string parcours = "Informatique" ;
	Formation f {nbAnnee, domaine, mention, parcours} ; 
	int n =f.nombreMaquettes() ; 
	Maquette *m ; 
	f.ajouterMaquette(m) ; 
	REQUIRE(f.nombreMaquettes()== n+1 ) ; 
}

TEST_CASE("Modification d'une formation")
{
	int nbAnnee=3 ; 
	std:: string domaine="fst" ; 
	std:: string mention= "Licence Informatique" ; 
	std::string parcours = "Informatique" ;
	Formation f {nbAnnee, domaine, mention, parcours} ; 
	SECTION ("nombre d'année modifié")
	{
		f.modifierNombreAnnee(2) ; 
		REQUIRE(f.nombreAnnee()== 2) ;
	}
	SECTION("Domaine modifié")
	{
		f.modifierDomaine ("flsh") ; 
		REQUIRE(f.domaine()=="flsh" ) ;
	}
	SECTION("Mention modifié"
	{
		f.modifierMention("Licence Anglais") ; 
		REQUIRE(f.mention()== "Licence Anglais") ;
	}
	SECTION("Parcours modifié")
	{
		f.modifierParcours("Anglais") ; 
		REQUIRE(f.parcours()=="Anglais" ) ;
	}
	
}
TEST_CASE ("Suppression d'une maquette") 
{
	Maquette *m ;
	int nbAnnee=3 ; 
	std:: string domaine="fst" ; 
	std:: string mention= "Licence Informatique" ; 
	std::string parcours = "Informatique" ;
	Formation f {nbAnnee, domaine, mention, parcours} ; 
	f.ajouterMaquette(m) ;
	
	int n = nombreMaquettes();
	(if supprimerMaquette(nombreMaquettes() == true )
	{
		REQUIRE( nombreMaquettes()== n-1 ) ; 
	}
}
	 
	



