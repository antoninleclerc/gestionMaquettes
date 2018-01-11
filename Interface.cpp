#include<iostream>
#include "Interface.h"
#include "Formation.h"
#include "System.h"

#define LARGEUR_CONSOLE 160

Interface::Interface()
{
	int choix;
  	menuPrincipalChoix(choix);
}

void Interface::menuPrincipalChoix(int& choix)
{
	do
  	{
  		System::centrerTexte("-------------------------------------------------------------",LARGEUR_CONSOLE);
  		System::centrerTexte("|           Maquettes des formations universitaires           |",LARGEUR_CONSOLE);
  		System::centrerTexte("-------------------------------------------------------------",LARGEUR_CONSOLE);
		System::centrerTexte("---------------------- Le menu principal --------------------",LARGEUR_CONSOLE);
    	System::centrerTexte("(1) Menu formation",LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t Ajouter une formation",LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t Modifier une formation",LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t Supprimer une formation",LARGEUR_CONSOLE-42);
  		System::centrerTexte("(2) Menu maquette",LARGEUR_CONSOLE-42);
  		System::centrerTexte(" Ajouter une maquette",LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t Modifier une maquette",LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t Supprimer une maquette",LARGEUR_CONSOLE-42);
  		System::centrerTexte("(3) Quitter",LARGEUR_CONSOLE-49);
  		System::centrerTexte("Votre choix : ",LARGEUR_CONSOLE-47);
    	std::cin >> choix;
  	}
  	while (choix < 1 || choix > 3);
	switch (choix)
	{
  		case 1: menuFormation(choix); break;
  		case 2: menuMaquette(choix); break;
	}
  	System::effacerEcran();
	if(choix==3)
		return;
}

void Interface::menuFormation(int& choix)
{
	do
  	{
  		System::effacerEcran();
  		std::cout<<std::endl;
		System::centrerTexte("------------------------- Menu formation -----------------------",LARGEUR_CONSOLE);
  		System::centrerTexte("\t (1) Ajouter une formation",LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t (2) Modifier une formation",LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t (3) Supprimer une formation",LARGEUR_CONSOLE-42);
  		System::centrerTexte("(4) Quitter",LARGEUR_CONSOLE-51);
  		System::centrerTexte("(5) Retour",LARGEUR_CONSOLE-51);
  		System::centrerTexte("Votre choix : ",LARGEUR_CONSOLE-47);
    	std::cin >> choix;
  	}
  	while (choix < 1 || choix > 5);
  	switch (choix)
	{
  		case 1: ajouterFormation(choix); break;
  		case 2: /*modifierFormation*/; break;
  		case 3: /*supprimerFormation*/; break;
	}
  	System::effacerEcran();
	if(choix==4)
		return;
	else if(choix=5)
		menuPrincipalChoix(choix);
		
}

void Interface::ajouterFormation(int& choix)
{
	System::effacerEcran();
	System::centrerTexte("Ajout formation",LARGEUR_CONSOLE);
	std::string intituleFormation;
	int nombreAnnee;
	std::cout << "Entrez l'intitule de la formation (DUT, Licence, Master ...): ";
	std::cin >> intituleFormation;
	std::cout << "Entrez le nombre d'annee de cette formation: ";
	std::cin >> nombreAnnee;
	Formation formation{nombreAnnee, intituleFormation};
	
}

void Interface::menuMaquette(int& choix)
{
	do
  	{
  		System::effacerEcran();
    	std::cout<<std::endl;
		System::centrerTexte("------------------------- Menu maquette -----------------------",LARGEUR_CONSOLE);
  		System::centrerTexte("\t (1) Ajouter une maquette",LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t (2) Modifier une maquette",LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t (3) Supprimer une maquette",LARGEUR_CONSOLE-42);
  		System::centrerTexte("(4) Quitter",LARGEUR_CONSOLE-51);
  		System::centrerTexte("(5) Retour",LARGEUR_CONSOLE-51);
  		System::centrerTexte("Votre choix : ",LARGEUR_CONSOLE-47);
    	std::cin >> choix;
  	}
  	while (choix < 1 || choix > 5);
  	switch (choix)
	{
  		case 1: /*ajouterMaquette(choix)*/; break;
  		case 2: /*modifierMaquette*/; break;
  		case 3: /*supprimerMaquette*/; break;
	}
	System::effacerEcran();
  	if(choix==4)
		return;
	else if(choix=5)
		menuPrincipalChoix(choix);
}

