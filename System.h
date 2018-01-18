#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

namespace System
{
	void centrerTexte(const std::string &chaine, int largeurConsole);
	void effacerEcran();
	static const int LARGEUR_CONSOLE=130;
	std::string intToString(int i);
}

#endif
