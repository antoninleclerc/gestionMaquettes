#include <iostream>

#include "Interface.h"
#include "Formation.h"
#include "Maquette.h" 
#include "System.h"
#include "UEchoix.h"

Interface::Interface(): d_formations()
{
	int choix;
  	menuPrincipalChoix(choix);
}

void Interface::menuPrincipalChoix(int& choix)
{
	do
  	{
  		std::cout<<std::endl;
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
  		case 1: ajouterFormation(); break;
  		case 2: /*modifierFormation*/; break;
  		case 3: supprimerFormation(); break;
	}
  	System::effacerEcran();
	if(choix==4)
		return;
	else if(choix=5)
		menuPrincipalChoix(choix);
		
}

void Interface::ajouterFormation()
{
	System::effacerEcran();
	System::centrerTexte("Ajout formation",System::LARGEUR_CONSOLE);
	std::string domaineFormation,mentionFormation,parcoursFormation;
	int nombreAnnee;
	std::cout << "Domaine : ";
	std::cin >> domaineFormation;
	std::cout << "Mention (Licence, Master, ...): ";
	std::cin >> mentionFormation;
	std::cout << "Parcours (MIAGE, Informatique, Physique, ...): ";
	std::cin >> parcoursFormation;
	std::cout << "Entrez le nombre d'annee de cette formation: ";
	std::cin >> nombreAnnee;
	Formation* formation= new Formation{nombreAnnee, domaineFormation, mentionFormation ,parcoursFormation};
	System::effacerEcran();
	std::cout << "Formation creee avec succes ! " << std::endl;
	std::cout << "Souhaitez vous ajouter une maquette? " << std::endl;
	std::cout << "\t (1) Oui" << std::endl;
	std::cout << "\t (2) Non" << std::endl;
	std::cout << "Votre choix : " << std::endl;
	int choix;
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
		ajouterMaquette();
	}
	d_formations.push_back(formation);
  	formation->sauverDansFichier();
}

void Interface::supprimerFormation()
{
	System::afficherListeFormations("Liste formations.txt");
	std::cout << "Tapez le numero de la formation que vous voulez supprimer :" << std::endl;
	std::cout << "Votre choix : " << std::endl;
	int choix;
	std::cin >> choix;
	//supprimerFormationNumero(choix);
	system("pause");
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
  		case 1:
		  ajouterMaquette();
		  break;
  		case 2: /*modifierMaquette*/; break;
  		case 3: /*supprimerMaquette*/; break;
	}
	System::effacerEcran();
  	if(choix==4)
		return;
	else if(choix=5)
		menuPrincipalChoix(choix);
}

void Interface :: ajouterMaquette()
{
	System::effacerEcran();
	System::centrerTexte("Ajout maquette",System::LARGEUR_CONSOLE);
	Maquette* maquette = new Maquette{};
	std::cout << "Voulez-vous :" << std::endl;
	std::cout << "\t (1) Rajouter une UE" << std::endl;
	std::cout << "\t (2) Rajouter une UE choix " << std::endl;
	std::cout << "Votre choix : " << std::endl;
	int choix;
	std::cin >> choix;
	switch(choix)
	{
		case 1:
			menuUE(choix);
			break;
		case 2:
			menuUEchoix(choix);
			break;
	}
}


void Interface::menuUE(int& choix)
{
	do
  	{
  		System::effacerEcran();
    	std::cout<<std::endl;
		System::centrerTexte("------------------------- Menu UE -----------------------",System::LARGEUR_CONSOLE);
  		System::centrerTexte("\t (1) Ajouter une UE",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t (2) Modifier une UE",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t (3) Supprimer une UE",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("(4) Quitter",System::LARGEUR_CONSOLE-51);
  		System::centrerTexte("(5) Retour",System::LARGEUR_CONSOLE-51);
  		System::centrerTexte("Votre choix : ",System::LARGEUR_CONSOLE-47);
    	std::cin >> choix;
  	}
  	while (choix < 1 || choix > 5);
  	switch (choix)
	{
  		case 1: 
		  ajouterUE();
		  break;
  		case 2: /*modifierMaquette*/; break;
  		case 3: /*supprimerMaquette*/; break;
	}
	System::effacerEcran();
  	if(choix==4)
		return;
	else if(choix=5)
		menuPrincipalChoix(choix);	
}	
		
void Interface :: ajouterUE()
{

	System::centrerTexte("Ajout UE",System::LARGEUR_CONSOLE);
	std::cout << "Voulez-vous :" << std::endl;
	std::cout << "\t (1) Ajouter une UE simple" << std::endl;
	std::cout << "\t (2) Ajouter une UE composée " << std::endl;
	std::cout << "Votre choix : " << std::endl;
	int choix;
	switch(choix)
	{
		case 1:
			ajouterUEsimple();
			break;
		case 2:
			ajouterUEcomposee();
			break;
	}
}

void Interface :: saisirDonneesDuneUE()
{
	std::string code,intitule;
	int coefficient,heuresCM,heuresTD,heuresTP,ECTS;
	std::cout << "Code : ";
	std::cin >> code;
	std::cout << "Intitule : ";
	std::cin >> intitule;
	std::cout << "Coefficient : ";
	std::cin >> coefficient;
	std::cout << "Heures CM : ";
	std::cin >> heuresCM;
	std::cout << "Heures TD : ";
	std::cin >> heuresTD;
	std::cout << "Heures TP : ";
	std::cin >> heuresTP;
	std::cout << "ECTS : ";
	std::cin >> ECTS;
	UE* ue = new UE{code,intitule,coefficient,heuresCM,heuresTD,heuresTP,ECTS};
}

void Interface :: ajouterUEsimple()
{
	System::effacerEcran();
	System::centrerTexte("Ajout UE simple",System::LARGEUR_CONSOLE);
	saisirDonneesDuneUE();
	std::cout << "UE creee avec succes ! " << std::endl;
}

void Interface :: ajouterUEcomposee()
{
	System::effacerEcran();
	System::centrerTexte("Ajout UE composée",System::LARGEUR_CONSOLE);
	saisirDonneesDuneUE();
	std::cout << "Voulez-vous Ajouter une ECUE ?" << std::endl;
	std::cout << "\t (1) Oui " << std::endl;
	std::cout << "\t (2) Non " << std::endl;
	std::cout << "Votre choix : " << std::endl;
	int choix;
	switch(choix)
	{
		case 1:
			ajouterECUE();
			break;
		case 2:
			break;
	}
}

void Interface :: saisirDonneesDuneECUE()
{
	std::string code,intitule;
	int coefficient,heuresCM,heuresTD,heuresTP;
	std::cout << "Code : ";
	std::cin >> code;
	std::cout << "Intitule : ";
	std::cin >> intitule;
	std::cout << "Coefficient : ";
	std::cin >> coefficient;
	std::cout << "Heures CM : ";
	std::cin >> heuresCM;
	std::cout << "Heures TD : ";
	std::cin >> heuresTD;
	std::cout << "Heures TP : ";
	std::cin >> heuresTP;
	ECUE* ecue = new ECUE{code,intitule,coefficient,heuresCM,heuresTD,heuresTP};
}

void Interface::ajouterECUE()
{
	System::effacerEcran();
	System::centrerTexte("Ajout ECUE",System::LARGEUR_CONSOLE);
	saisirDonneesDuneECUE();
	std::cout << "ECUE creee avec succes ! " << std::endl;
}
		//Menu UEchoix	
void Interface::menuUEchoix(int& choix)
{
	do
	{
	  	System::effacerEcran();
    	std::cout<<std::endl;
		System::centrerTexte("------------------------- Menu UE choix -----------------------",System::LARGEUR_CONSOLE);
		std::cout<<"Voulez-vous :"<<std::endl;
  		System::centrerTexte("\t (1) Ajouter une UE choix",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t (2) Supprimer une UE choix",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("\t (3) Afficher une UE choix",System::LARGEUR_CONSOLE-42);
  		System::centrerTexte("(4) Quitter",System::LARGEUR_CONSOLE-51); 
  		System::centrerTexte("(5) Retour",System::LARGEUR_CONSOLE-51);	
  		System::centrerTexte("Votre choix : ",System::LARGEUR_CONSOLE-47);	
		std::cin>>choix;	
	}while (choix < 1 || choix >5);
	switch(choix)
	{
				case 1 :
					ajouterUEchoix();
					break;
				case 2 :
					supprimerUEchoix();
					break;
				case 3 :
					/*AfficherUEchoix()**/
					break;
	}
	System::effacerEcran();
  	if(choix==4)
		return;
	else if(choix=5)
		menuPrincipalChoix(choix);
}

void Interface::ajouterUEchoix()
{
	std::string code, intitule;
	int coefficient, heuresCM, heuresTD, heuresTP, ECTS;
	std::cout<<"Veuillez saisir le code de l'UE :"<<std::endl;
	std::cin>>code;
	std::cout<<"Veuillez saisir l'intitule de l'UE :"<<std::endl;
	std::cin>>intitule;	
	std::cout<<"Veuillez saisir le coefficient de l'UE :"<<std::endl;
	std::cin>>coefficient;	
	std::cout<<"Veuillez saisir le nombre d'heures CM de l'UE :"<<std::endl;
	std::cin>>heuresCM;
	std::cout<<"Veuillez saisir le nombre d'heures TD de l'UE :"<<std::endl;
	std::cin>>heuresTD;
	std::cout<<"Veuillez saisir le nombre d'heures TP de l'UE :"<<std::endl;
	std::cin>>heuresTP;
	UEchoix ueChoix{code, intitule, coefficient, heuresCM, heuresTD, heuresTP, ECTS};
	//afficher l'UE	
	//faire appel au menu UE
}

void Interface::supprimerUEchoix()
{
	std::string code;
	std::cout<<"Veuillez saisir le code de l'UE choix à supprimer :"<<std::endl;
	std::cin>>code;
	/*
	while (UEchoix::supprimerUE(code) == false)
	{
		std::cout<<"Attention !! l'UE choix est introuvable"<<std::endl;
		std::cout<<"Veuillez saisir le code de l'UE choix à supprimer :"<<std::endl;
		std::cin>>code;
	}
	**/
}

void Interface::afficherUEchoix()
{
	/*
	UEchoix::affiche(std::cout);
	**/
}
