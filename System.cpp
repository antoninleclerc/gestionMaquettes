#include <iostream>
#include <fstream>

#include "System.h"


namespace System
{
	void charge(const std::string &nomFichier)
	{
		/*int nbArrets, nbTramways, posX, posY, duree, vitesse;
		string nomArret;
		ifstream f(nomFichier.c_str());
	
		// On charge les 3 variables nbTramways, nbArrets et vitesse à partir du fichier
		f >> nbTramways >> nbArrets >> vitesse;*/
	}
	
	//méthode save à rajouter
	
	
	void centrerTexte(const std::string &chaine, int largeurConsole)
	{
	    int n;
	    for (n = 0; n < (largeurConsole-chaine.size()) / 2; n++)
	    {
	        std::cout<<' ';
	    }
	    std::cout<<chaine<<std::endl<<std::endl;
	}
	
	void effacerEcran()
	{
	  	#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
	}
	
	void ajouterFinFichier(const std::string &chaineAajouter, const std::string &nomFichier)
	{
		std::ifstream fi;
	 	fi.open (nomFichier.c_str());
	 	std::string ligneTemporaire;
	 	std::string ancienContenu="";
	 	getline( fi, ligneTemporaire);
		while (ligneTemporaire != "" )
	  	{
		    ancienContenu=ancienContenu+ligneTemporaire+"\n";
	  		getline( fi, ligneTemporaire);
	  	}
		fi.close();
		
	  	std::ofstream fo;
	 	fo.open (nomFichier.c_str());
	 	fo << ancienContenu + chaineAajouter + "\n";
		fo.close();
	}		
	
	void afficherListeFormations(const std::string &nomFichier)
	{
		std::cout<<"Liste formations"<<std::endl;
		std::ifstream fi;
	 	fi.open (nomFichier.c_str());
	 	std::string formation;
	 	int numeroFormation=1;
	 	getline( fi, formation);
		while (formation != "" )
	  	{
		    std::cout<<"("<<numeroFormation<<") "<<formation<<std::endl;
	  		getline( fi, formation);
	  		numeroFormation++;
	  	}
		fi.close();
	}
}
