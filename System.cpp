#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>


#include "System.h"


namespace System
{
	void centrerTexte(const std::string &chaine, int largeurConsole)
	{
	    int n;
	    for (n = 0; n < (largeurConsole-chaine.size())/2 ; n++)
	    {
	        std::cout<<" ";
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


	std::string intToString(int i)
	{
		std::ostringstream oss;
		oss << i;
		return oss.str();
	}
}
