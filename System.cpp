#include <iostream>
#include <fstream>

#include "System.h"


namespace System
{
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
	
}
