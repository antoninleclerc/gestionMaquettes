#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

namespace System
{
	void centrerTexte(const std::string &chaine, int largeurConsole);
	void effacerEcran();
	void ajouterFinFichier(const std::string &chaineAajouter, const std::string &nomFichier);
	static const int LARGEUR_CONSOLE=160;
}

#endif
