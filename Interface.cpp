#include <iostream>
#include <fstream>

#include "Interface.h"
#include "Formation.h"
#include "UEchoix.h"
#include "System.h"

namespace GestionMaquettes
{
	Interface::Interface(): d_formations()
	{
		chargeFormations();
	  	menuPrincipalChoix();
	}
	
	void Interface::menuPrincipalChoix()
	{
		int choix;
		do
	  	{
	  		System::effacerEcran();
	  		std::cout<<std::endl;
	  		System::centrerTexte("-------------------------------------------------------------",System::LARGEUR_CONSOLE);
	  		System::centrerTexte("|           Maquettes des formations universitaires           |",System::LARGEUR_CONSOLE);
	  		System::centrerTexte("-------------------------------------------------------------",System::LARGEUR_CONSOLE);
			System::centrerTexte("---------------------- Le menu principal --------------------",System::LARGEUR_CONSOLE);
	    	System::centrerTexte("Menu formation",System::LARGEUR_CONSOLE-42);
	  		System::centrerTexte("\t (1) Ajouter une formation",System::LARGEUR_CONSOLE-42);
	  		System::centrerTexte("\t (2) Modifier une formation",System::LARGEUR_CONSOLE-42);
	  		System::centrerTexte("\t (3) Supprimer une formation",System::LARGEUR_CONSOLE-42);
	  		System::centrerTexte("\t (4) Afficher une formation",System::LARGEUR_CONSOLE-42);
	  		System::centrerTexte("\t (5) Quitter",System::LARGEUR_CONSOLE-49);
	  		System::centrerTexte("\t Votre choix : ",System::LARGEUR_CONSOLE-47);
	    	std::cin >> choix;
	  	}
	  	while (choix < 1 || choix > 5);
	  	switch (choix)
		{
	  		case 1: ajouterFormation(); break;
	  		case 2: modifierFormation(); break;
	  		case 3: supprimerFormation(); break;
	  		case 4: afficherFormation(); break;
		}
	  	System::effacerEcran();
		if(choix==5)
			return;
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
		std::cout << "Formation creee avec succes !" << std::endl;
		std::cout << "Vous allez passez a la saisie des maquettes." << std::endl;
		system("pause");
		for(int numeroAnnee=1; numeroAnnee<=formation->nombreAnnee();numeroAnnee++)
		{
			for(int numeroSemestre=1; numeroSemestre<=2;numeroSemestre++)
			{
				System::effacerEcran();
				std::cout<<formation->mention()<<" "<<numeroAnnee<<" "<<formation->parcours()<<" Semestre "<<numeroSemestre<<std::endl;
				formation->ajouterMaquette(MaquetteCree());
			}
		}
		d_formations.push_back(formation);
	  	mettreAJourFichierListeFormations();
		std::cout << "Les maquettes ont ete bien enregistrees." << std::endl;
		system("pause");
		menuPrincipalChoix();
	}
	
	
	void Interface::modifierFormation()
	{
		afficherListeFormations();
		if(d_formations.size()!=0)
		{
			std::cout << std::endl << "Tapez le numero de la formation que vous voulez modifier :" << std::endl;
			std::cout << "Votre choix : " << std::endl;
			int numeroFormation;
			std::cin >> numeroFormation;
			while(numeroFormation<1 || numeroFormation>d_formations.size())
			{
				afficherListeFormations();
				std::cout << std::endl << "Tapez le numero de la formation que vous voulez modifier :" << std::endl;
				std::cout << "Votre choix : " << std::endl;
				std::cin >> numeroFormation;
			}
			choixModification(d_formations[numeroFormation-1]);
			
			d_formations[numeroFormation-1]->afficherListeMaquettes();
			if(d_formations[numeroFormation-1]->nombreMaquettes()!=0)
			{
				std::cout << std::endl << "Tapez le numero de la maquette que vous voulez modifier :" << std::endl;
				std::cout << "Votre choix : " << std::endl;
				int numeroMaquette;
				std::cin >> numeroMaquette;
				while(numeroMaquette<1 || numeroMaquette>d_formations[numeroFormation-1]->nombreMaquettes())
				{
					d_formations[numeroFormation-1]->afficherListeMaquettes();
					std::cout << std::endl << "Tapez le numero de la maquette que vous voulez modifier :" << std::endl;
					std::cout << "Votre choix : " << std::endl;
					std::cin >> numeroMaquette;
				}
				System::effacerEcran();
				//modification
			}
		}
		menuPrincipalChoix();
	}
	
	void Interface::choixModification(Formation *formation)
	{
		System::effacerEcran();
		std::cout << std::endl << "Que voulez-vous modifier?" << std::endl;
		std::cout << std::endl << "(1) Modifier le domaine" << std::endl;
		std::cout << std::endl << "(2) Modifier la mention" << std::endl;
		std::cout << std::endl << "(3) Modifier le parcours" << std::endl;
		std::cout << std::endl << "(4) Modifier une maquette" << std::endl;
		std::cout << "Votre choix : " << std::endl;
		int choix;
		std::cin >> choix;
		while(choix<1 || choix>4)
		{
			System::effacerEcran();
			std::cout << std::endl << "Que voulez-vous modifier?" << std::endl;
			std::cout << std::endl << "(1) Modifier le domaine" << std::endl;
			std::cout << std::endl << "(2) Modifier la mention" << std::endl;
			std::cout << std::endl << "(3) Modifier le parcours" << std::endl;
			std::cout << std::endl << "(4) Modifier une maquette" << std::endl;
			std::cout << std::endl << "(5) Retour" << std::endl;
			std::cout << "Votre choix : " << std::endl;
			std::cin >> choix;
		}
		while (choix < 1 || choix > 5);
	  	switch (choix)
		{
	  		case 1: modifierDomaine(formation); break;
	  		case 2: modifierMention(formation); break;
	  		case 3: modifierParcours(formation); break;
	  		case 4: modifierMaquette(formation); break;
	  		case 5: modifierFormation(); break;
		}
		menuPrincipalChoix();
	}
	
	void Interface::modifierDomaine(Formation *formation)
	{
		System::effacerEcran();
		std::cout << "Nouveau domaine : " << std::endl;
		std::string nouveauDomaine;
		std::cin >> nouveauDomaine;
		formation->modifierDomaine(nouveauDomaine);
		std::cout << "Domaine mis a jour. " << std::endl;
		system("pause");
	}
	
	void Interface::modifierMention(Formation *formation)
	{
		System::effacerEcran();
		std::cout << "Nouvelle mention : " << std::endl;
		std::string nouveauMention;
		std::cin >> nouveauMention;
		formation->modifierMention(nouveauMention);
		mettreAJourFichierListeFormations();
		std::cout << "Mention mise a jour. " << std::endl;
		system("pause");
	}
	
	void Interface::modifierParcours(Formation *formation)
	{
		System::effacerEcran();
		std::cout << "Nouveau parcours : " << std::endl;
		std::string nouveauParcours;
		std::cin >> nouveauParcours;
		formation->modifierParcours(nouveauParcours);
		mettreAJourFichierListeFormations();
		std::cout << "Parcours mis a jour. " << std::endl;
		system("pause");
	}
	
	void Interface::modifierMaquette(Formation *formation)
	{
		
	}
	
	void Interface::supprimerFormation()
	{
		afficherListeFormations();
		if(d_formations.size()!=0)
		{
			std::cout << std::endl << "Tapez le numero de la formation que vous voulez supprimer :" << std::endl;
			std::cout << "Votre choix : " << std::endl;
			int numeroFormation;
			std::cin >> numeroFormation;
			while(numeroFormation<1 || numeroFormation>d_formations.size())
			{
				afficherListeFormations();
				std::cout << std::endl << "Tapez le numero de la formation que vous voulez supprimer :" << std::endl;
				std::cout << "Votre choix : " << std::endl;
				std::cin >> numeroFormation;
			}
			if(supprimerFormationNumero(numeroFormation)==true)
				std::cout << "La formation  a bien ete supprimee." << std::endl;
			else
				std::cout << "La formation n'a pas pu etre supprimee." << std::endl;
			system("pause");
			menuPrincipalChoix();
		}
		
	}
	
	bool Interface::supprimerFormationNumero(int numeroFormation)
	{
		if (numeroFormation <= d_formations.size())
		{
			delete d_formations[numeroFormation-1] ; 
			for (int i = numeroFormation; i < d_formations.size(); i++) 
			{
				d_formations[i-1] = d_formations[i];
			}
			d_formations.pop_back();
			mettreAJourFichierListeFormations();
			return true;
		}
		else 
		{
			return false; 
		}
		
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
	  		case 1: ajouterMaquette(); break;
	  		case 2: /*modifierMaquette*/; break;
	  		case 3: /*supprimerMaquette*/; break;
		}
		System::effacerEcran();
	  	if(choix==4)
			return;
		else if(choix=5)
			menuPrincipalChoix();
	}
	
	void Interface :: ajouterMaquette()
	{
		
	}
	
	Maquette* Interface :: MaquetteCree()
	{
		Maquette* maquette = new Maquette{};
		std::cout << "Voulez-vous :" << std::endl;
		std::cout << "\t (1) Ajouter une UE simple" << std::endl;
		std::cout << "\t (2) Ajouter une UE composee" << std::endl;
		std::cout << "\t (3) Ajouter une UE choix " << std::endl;
		std::cout << "Votre choix : " << std::endl;
		int choix;
		std::cin >> choix;
		switch(choix)
		{
			case 1:
				ajouterUEsimple(maquette);
				break;
			case 2:
				ajouterUEcomposee(maquette);
				break;
			case 3:
				ajouterUEchoix(maquette);
				break;
		}
		do
		{
			std::cout << std::endl << "Voulez-vous :" << std::endl;
			std::cout << "\t (1) Continuer a ajouter" << std::endl;
			std::cout << "\t (2) Passer a la maquette suivante" << std::endl;
			std::cout << "Votre choix : " << std::endl;
			std::cin >> choix;
			if(choix==1)
			{
				System::effacerEcran();
				std::cout << "(1) Ajouter une UE simple" << std::endl;
				std::cout << "(2) Ajouter une UE composee" << std::endl;
				std::cout << "(3) Ajouter une UE choix " << std::endl;
				std::cout << "Votre choix : " << std::endl;
				std::cin >> choix;
				switch(choix)
				{
					case 1:
						ajouterUEsimple(maquette);
						break;
					case 2:
						ajouterUEcomposee(maquette);
						break;
					case 3:
						ajouterUEchoix(maquette);
						break;
				}
			}
		}
		while(choix==1);		
		return maquette;
	}
	
		
	void Interface::menuUE(int& choix,Maquette* maquette)
	{
		do
	  	{
	  		System::effacerEcran();
	    	std::cout<<std::endl;
			System::centrerTexte("------------------------- Menu UE -----------------------",System::LARGEUR_CONSOLE);
	  		System::centrerTexte("\t (1) Traitement d'une UE",System::LARGEUR_CONSOLE-42);
	  		System::centrerTexte("(2) Retour",System::LARGEUR_CONSOLE-51);
	  		System::centrerTexte("(3) Quitter",System::LARGEUR_CONSOLE-51);
	  		System::centrerTexte("Votre choix : ",System::LARGEUR_CONSOLE-47);
	    	std::cin >> choix;
	  	}
	  	while (choix < 1 || choix > 3);
	  	switch (choix)
		{
	  		case 1: 
				ajouterUE(maquette);
				break;
	  		case 2: 
				menuPrincipalChoix();	
		   		break;
	  		case 3:
				return;
				break;
		}
		System::effacerEcran();
	}	
			
	void Interface :: ajouterUE(Maquette* maquette)
	{
		System::effacerEcran();
		System::centrerTexte("Ajout UE",System::LARGEUR_CONSOLE);
		std::cout << "Voulez-vous :" << std::endl;
		std::cout << "\t (1) Ajouter une UE simple" << std::endl;
		std::cout << "\t (2) Ajouter une UE composée " << std::endl;
		std::cout << "\t (3) Modifier une UE" << std::endl;
		std::cout << "\t (4) Supprimer une UE" << std::endl;
		std::cout << "Votre choix : " << std::endl;
		int choix;
		std::cin>>choix;
		switch(choix)
		{
			case 1:
				ajouterUEsimple(maquette);
				break;
			case 2:
				ajouterUEcomposee(maquette);
				break;
		}
		System::effacerEcran();
	}
	
	void Interface :: saisirDonneesDuneUE(std::string& code, std::string& intitule,int& coefficient,int& heuresCM,int& heuresTD,int& heuresTP,int& ECTS )
	{
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
	}
	
	void Interface :: ajouterUEsimple(Maquette* maquette)
	{
		System::effacerEcran();
		System::centrerTexte("Ajout UE simple",System::LARGEUR_CONSOLE);
		std::string code,intitule;
		int coefficient,heuresCM,heuresTD,heuresTP,ECTS;
		saisirDonneesDuneUE(code,intitule,coefficient,heuresCM,heuresTD,heuresTP,ECTS);
		UE* ue = new UE{code,intitule,coefficient,heuresCM,heuresTD,heuresTP,ECTS};
		std::cout << "UE creee avec succes ! " << std::endl;
		maquette->ajouterUE(ue);
	}
	
	void Interface :: ajouterUEcomposee(Maquette* maquette)
	{
		System::effacerEcran();
		System::centrerTexte("Ajout UE composee",System::LARGEUR_CONSOLE);
		std::string code,intitule;
		int coefficient,heuresCM,heuresTD,heuresTP,ECTS;
		saisirDonneesDuneUE(code,intitule,coefficient,heuresCM,heuresTD,heuresTP,ECTS);
		UE* ue = new UE{code,intitule,coefficient,heuresCM,heuresTD,heuresTP,ECTS};
		std::cout << "Voulez-vous Ajouter une ECUE ?" << std::endl;
		std::cout << "\t (1) Oui " << std::endl;
		std::cout << "\t (2) Non " << std::endl;
		std::cout << "Votre choix : " << std::endl;
		int choix;
		std::cin>>choix;
		switch(choix)
		{
			case 1:
				ajouterECUE(ue);
				break;
			case 2:
				break;
		}
		do
		{
			System::effacerEcran();
			std::cout << std::endl << "Voulez-vous :" << std::endl;
			std::cout << "\t (1) Continuer a ajouter une ECUE" << std::endl;
			std::cout << "\t (2) Passer a l'UE suivant" << std::endl;
			std::cout << "Votre choix : " << std::endl;
			std::cin >> choix;
			if(choix==1)
			{
				ajouterECUE(ue);
			}
		}
		while(choix==1);
		System::effacerEcran();	
		maquette->ajouterUE(ue);
	}
	
	void Interface :: saisirDonneesDuneECUE(std::string& code, std::string& intitule,int& coefficient,int& heuresCM,int& heuresTD,int& heuresTP)
	{
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
	}
	
	void Interface::ajouterECUE(UE* ue)
	{
		System::effacerEcran();
		System::centrerTexte("Ajout ECUE",System::LARGEUR_CONSOLE);
		std::string code,intitule;
		int coefficient,heuresCM,heuresTD,heuresTP;
		saisirDonneesDuneECUE(code,intitule,coefficient,heuresCM,heuresTD,heuresTP);
		ECUE* ecue = new ECUE{code,intitule,coefficient,heuresCM,heuresTD,heuresTP};
		std::cout << "ECUE creee avec succes ! " << std::endl;
		ue->ajouterECUE(ecue);
	}
			//Menu UEchoix	
	void Interface::menuUEchoix(int& choix,Maquette* maquette)
	{
		do
		{
		  	System::effacerEcran();
	    	std::cout<<std::endl;
			System::centrerTexte("------------------------- Menu UE choix -----------------------",System::LARGEUR_CONSOLE);
			std::cout<<"Voulez-vous :"<<std::endl;
	  		System::centrerTexte("\t (1) Ajouter une UE choix",System::LARGEUR_CONSOLE-42);
	  		System::centrerTexte("\t (2) Supprimer une UE choix",System::LARGEUR_CONSOLE-42);
	  		System::centrerTexte("(3) Quitter",System::LARGEUR_CONSOLE-51); 
	  		System::centrerTexte("(4) Retour",System::LARGEUR_CONSOLE-51);	
	  		System::centrerTexte("Votre choix : ",System::LARGEUR_CONSOLE-47);	
			std::cin>>choix;	
		}while (choix < 1 || choix >4);
		switch(choix)
		{
					case 1 :
						ajouterUEchoix(maquette);
						break;
					case 2 :
						//supprimerUEchoix();
						break;
		}
		System::effacerEcran();
	  	if(choix==3)
			return;
		else if(choix=4)
			menuPrincipalChoix();
	}
	
	void Interface::ajouterUEchoix(Maquette* maquette)
	{
		System::effacerEcran();
		System::centrerTexte("Ajout UE choix",System::LARGEUR_CONSOLE);
		std::string code, intitule;
		int coefficient, heuresCM, heuresTD, heuresTP, ECTS;
		saisirDonneesDuneUE(code,intitule,coefficient,heuresCM,heuresTD,heuresTP,ECTS);
		UEchoix* uechoix = new UEchoix{code,intitule,coefficient,heuresCM,heuresTD,heuresTP,ECTS};
		std::cout << "UE choix creee avec succes ! " << std::endl;
		std::cout << "Voulez-vous ajouter une UE a votre UE choix ?" << std::endl;
		std::cout << "\t (1) Oui " << std::endl;
		std::cout << "\t (2) Non " << std::endl;
		std::cout << "Votre choix : " << std::endl;
		int choix;
		std::cin>>choix;
		std::string codeChoix, intituleChoix;
		int coefficientChoix, heuresCMChoix, heuresTDChoix, heuresTPChoix, ECTSChoix;
		if(choix==1)
		{
				saisirDonneesDuneUE(codeChoix,intituleChoix,coefficientChoix,heuresCMChoix,heuresTDChoix,heuresTPChoix,ECTSChoix);
				UE* ue = new UE{codeChoix,intituleChoix,coefficientChoix,heuresCMChoix,heuresTDChoix,heuresTPChoix,ECTSChoix};
				uechoix->ajouterUE(ue);
		}
			do
			{
				System::effacerEcran();
				std::cout << std::endl << "Voulez-vous :" << std::endl;
				std::cout << "\t (1) Continuer a ajouter une UE a votre UE choix" << std::endl;
				std::cout << "\t (2) Quitter" << std::endl;
				std::cout << "Votre choix : " << std::endl;
				std::cin >> choix;
				if(choix==1)
				{
					saisirDonneesDuneUE(codeChoix,intituleChoix,coefficientChoix,heuresCMChoix,heuresTDChoix,heuresTPChoix,ECTSChoix);
					UE* ue = new UE{codeChoix,intituleChoix,coefficientChoix,heuresCMChoix,heuresTDChoix,heuresTPChoix,ECTSChoix};
					uechoix->ajouterUE(ue);
				}
			}while(choix==1);
		maquette->ajouterUE(uechoix);
	}
	
	 void Interface::mettreAJourFichierListeFormations() const
	 {
		std::ofstream fListeFormations;
		fListeFormations.open ("Liste formations.txt");
		std::string nouveauContenu="";
		for(int i=0; i<d_formations.size();i++)
		{
		 	nouveauContenu+= d_formations[i]->mention() + " " + d_formations[i]->parcours() + "\n";
		}
		fListeFormations << nouveauContenu;
		fListeFormations.close();
	 }
	 
	  void Interface::mettreAJourFichierListeMaquettes() const
	 {	
	 
		std::ofstream fListeMaquettes;
		fListeMaquettes.open ("Liste maquettes.txt");
		std::string annee="", semestre="", titreMaquette="";
		for(int numeroAnnee=1; numeroAnnee<=d_formations[numeroAnnee-1]->nombreAnnee(); numeroAnnee++)
			for(int numeroSemestre=1; numeroSemestre<=d_formations[numeroAnnee-1]->nombreMaquettes(); numeroSemestre++)
		 	{
		 		annee+= d_formations[numeroAnnee-1]->mention() + " " + System::intToString(numeroAnnee);
				semestre+= d_formations[numeroAnnee]->parcours() + "Semestre" + System::intToString(numeroSemestre) + "\n";
				titreMaquette+=annee + " " + semestre;
			}
		fListeMaquettes << annee << semestre;
		fListeMaquettes.close();
	 }

	void Interface::chargeFormations()
	{
		/*int nbArrets, nbTramways, posX, posY, duree, vitesse;
		string nomArret;
		ifstream f(nomFichier.c_str());
	
		// On charge les 3 variables nbTramways, nbArrets et vitesse à partir du fichier
		f >> nbTramways >> nbArrets >> vitesse;*/
	}
	

	void Interface :: afficherListeFormations() const
	{
		System::effacerEcran();
		std::cout<<"Liste formations"<<std::endl<<std::endl;
		if(d_formations.size()==0)
		{
	 		std::cout<<"Il n'y aucune formations dans la liste."<<std::endl;
			system("pause");
		}
		else
			for(int i=0; i<d_formations.size(); i++)
			{
				std::cout<<"("<<i+1<<") "<<d_formations[i]->mention()<<" "<<d_formations[i]->parcours()<<std::endl;
			}
	}
	
	void Interface::afficherFormation()
	{
		afficherListeFormations();
		if(d_formations.size()!=0)
		{
			std::cout << std::endl << "Tapez le numero de la formation que vous voulez afficher :" << std::endl;
			std::cout << "Votre choix : " << std::endl;
			int numeroFormation;
			std::cin >> numeroFormation;
			while(numeroFormation<1 || numeroFormation>d_formations.size())
			{
				afficherListeFormations();
				std::cout << std::endl << "Tapez le numero de la formation que vous voulez afficher :" << std::endl;
				std::cout << "Votre choix : " << std::endl;
				std::cin >> numeroFormation;
			}
			afficherMaquettesDeLaFormationNumero(numeroFormation);
		}
		menuPrincipalChoix();
	}
	
	void Interface::afficherMaquettesDeLaFormationNumero(int numeroFormation) const
	{
		System::effacerEcran();
		std::cout<<*d_formations[numeroFormation-1]<<std::endl;
		system("pause");
	}

}

	
