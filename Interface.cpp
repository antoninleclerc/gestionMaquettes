#include <iostream>
#include <fstream>

#include "Interface.h"
#include "Formation.h"
#include "System.h"

namespace GestionMaquettes
{
	Interface::Interface(): d_formations()
	{
		chargeFormations();
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
	  		case 2: modifierFormation(); break;
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
		std::cout << "Souhaitez vous ajouter les maquettes? " << std::endl;
		std::cout << "\t (1) Oui" << std::endl;
		std::cout << "\t (2) Non" << std::endl;
		std::cout << "Votre choix : " << std::endl;
		int choix;
		std::cin >> choix;
		while(choix !=1 && choix !=2)
		{
			System::effacerEcran();
			std::cout << "Souhaitez vous ajouter les maquettes? " << std::endl;
			std::cout << "\t (1) Oui" << std::endl;
			std::cout << "\t (2) Non" << std::endl;
			std::cout << "Votre choix : " << std::endl;
			std::cin >> choix;
		}
		if(choix == 1)
		{
			for(int numeroAnnee=1; numeroAnnee<=formation->nombreAnnee();numeroAnnee++)
			{
				for(int numeroSemestre=1; numeroSemestre<=formation->nombreAnnee()*2;numeroSemestre++)
				{
					System::effacerEcran();
					std::cout<<formation->mention()<<" "<<numeroAnnee<<" "<<formation->parcours()<<" Semestre "<<numeroSemestre<<std::endl;
					formation->ajouterMaquette(MaquetteCree());
				}
			}
			std::cout << "Les maquettes ont ete bien enregistrees." << std::endl;
			system("pause");
		}
		d_formations.push_back(formation);
	  	mettreAJourFichierListeFormations();
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
				std::cout<<"Vous etes sur le point de modifier la maquette "<< d_formations[numeroFormation-1]->mention()<<" "<<numeroMaquette<<" "<<d_formations[numeroFormation-1]->parcours()<<std::endl;
				//modification
			}
		}
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
	  		case 1: /*ajouterMaquette*/; break;
	  		case 2: /*modifierMaquette*/; break;
	  		case 3: /*supprimerMaquette*/; break;
		}
		System::effacerEcran();
	  	if(choix==4)
			return;
		else if(choix=5)
			menuPrincipalChoix(choix);
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
				//ajouterUEchoix(maquette);
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
						//ajouterUEchoix(maquette);
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
				menuPrincipalChoix(choix);	
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
		System::centrerTexte("Ajout UE composée",System::LARGEUR_CONSOLE);
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
			std::cout << "\t (1) Continuer a ajouter un ECUE" << std::endl;
			std::cout << "\t (2) Passer a l'UE suivant" << std::endl;
			std::cout << "Votre choix : " << std::endl;
			std::cin >> choix;
			if(choix==1)
			{
				ajouterECUE(ue);
			}
		}
		while(choix==1);	
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
	  		System::centrerTexte("\t (3) Afficher une UE choix",System::LARGEUR_CONSOLE-42);
	  		System::centrerTexte("(4) Quitter",System::LARGEUR_CONSOLE-51); 
	  		System::centrerTexte("(5) Retour",System::LARGEUR_CONSOLE-51);	
	  		System::centrerTexte("Votre choix : ",System::LARGEUR_CONSOLE-47);	
			std::cin>>choix;	
		}while (choix < 1 || choix >5);
		switch(choix)
		{
					case 1 :
						//ajouterUEchoix();
						break;
					case 2 :
						//supprimerUEchoix();
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
	
	 void Interface::mettreAJourFichierListeFormations() const
	 {
		std::ofstream fo;
		fo.open ("Liste formations.txt");
		std::string nouveauContenu="";
		for(int i=0; i<d_formations.size();i++)
		{
		 	nouveauContenu+= d_formations[i]->mention() + " " + d_formations[i]->parcours() + "\n";
		}
		fo << nouveauContenu;
		fo.close();
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
		std::cout<<"Liste maquettes"<<std::endl<<std::endl;
		if(d_formations.size()==0)
		{
	 		std::cout<<"Il n'y aucune maquette dans la liste."<<std::endl;
			system("pause");
		}
		else
			for(int i=0; i<d_formations.size(); i++)
			{
				std::cout<<"("<<i+1<<") "<<d_formations[i]->mention()<<" "<<d_formations[i]->parcours()<<std::endl;
			}
	}

}

	
