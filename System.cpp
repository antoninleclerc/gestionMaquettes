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
}
