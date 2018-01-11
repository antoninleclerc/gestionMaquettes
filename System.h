#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

namespace System
{
	void charge(const std::string &nomFichier);
	//méthode save à rajouter
	void centrerTexte(const std::string &chaine, int largeurConsole);
	void effacerEcran();
}

#endif
