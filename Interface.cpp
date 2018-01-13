#include <iostream>

#include "Interface.h"
#include "Formation.h"
#include "System.h"


Interface::Interface()
{
	int choix;
  	menuPrincipalChoix(choix);
}

void Interface::menuPrincipalChoix(int& choix)
{
	do
  	{
  		System::centrerTexte("-------------------------------------------------------------",System::LARGEUR_CONSOLE);
  		System::centrerTexte("|           Maquettes des formations universitaires           |",System::LARGEUR_CONSOLE);
  		System::centrerTexte("-------------------------------------------------------------",System::LARGEUR_CONSOLE);
		System::centrerTexte("---------------------- Le menu principal --------------------",System::LARGEUR_CONSOLE);
    	System::centrerTexte("(1) Menu formation",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t Ajouter une formation",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t Modifier une formation",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t Supprimer une formation",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("(2) Menu maquette",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte(" Ajouter une maquette",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t Modifier une maquette",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t Supprimer une maquette",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("(3) Quitter",System::LARGEUR_CONSOLE-49);
  		System::centrerTexte("Votre choix : ",System::LARGEUR_CONSOLE-47);
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
		System::centrerTexte("------------------------- Menu formation -----------------------",System::LARGEUR_CONSOLE);
  		System::centrerTexte("\t (1) Ajouter une formation",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t (2) Modifier une formation",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t (3) Supprimer une formation",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("(4) Quitter",System::LARGEUR_CONSOLE-51);
  		System::centrerTexte("(5) Retour",System::LARGEUR_CONSOLE-51);
  		System::centrerTexte("Votre choix : ",System::LARGEUR_CONSOLE-47);
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
	System::centrerTexte("Ajout formation",System::LARGEUR_CONSOLE);
	std::string domaineFormation,mentionFormation,parcoursFormation;
	int nombreAnnee;
	std::cout << "Domaine : ";
	std::cin >> domaineFormation;
	std::cout << "Mention (Licence, Master, DUT, BTS ...): ";
	std::cin >> mentionFormation;
	std::cout << "Parcours (MIAGE, Informatique, Physique, GE2I ...): ";
	std::cin >> parcoursFormation;
	std::cout << "Entrez le nombre d'annee de cette formation: ";
	std::cin >> nombreAnnee;
	Formation formation{nombreAnnee, domaineFormation, mentionFormation ,parcoursFormation};
	System::effacerEcran();
	std::cout << "Formation creee avec succes ! " << std::endl;
	std::cout << "Souhaitez vous ajouter une maquette? " << std::endl;
	std::cout << "\t (1) Oui" << std::endl;
	std::cout << "\t (2) Non" << std::endl;
	std::cout << "Votre choix : " << std::endl;
	std::cin >> choix;
	while(choix !=1 && choix !=2)
	{
		System::effacerEcran();
		std::cout << "Souhaitez vous ajouter une maquette? " << std::endl;
		std::cout << "\t (1) Oui" << std::endl;
		std::cout << "\t (2) Non" << std::endl;
		std::cout << "Votre choix : " << std::endl;
		std::cin >> choix;
	}
	if(choix == 1)
	{
		/*ajouterMaquette(formation)*/
	}
  	formation.sauverDansFichier();
}

void Interface::menuMaquette(int& choix)
{
	do
  	{
  		System::effacerEcran();
    	std::cout<<std::endl;
		System::centrerTexte("------------------------- Menu maquette -----------------------",System::LARGEUR_CONSOLE);
  		System::centrerTexte("\t (1) Ajouter une maquette",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t (2) Modifier une maquette",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t (3) Supprimer une maquette",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("(4) Quitter",System::LARGEUR_CONSOLE-51);
  		System::centrerTexte("(5) Retour",System::LARGEUR_CONSOLE-51);
  		System::centrerTexte("Votre choix : ",System::LARGEUR_CONSOLE-47);
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

