#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>

class Interface
{
	public:
		Interface();
		void menuPrincipalChoix(int& choix);
		void menuFormation(int& choix);
		void ajouterFormation(int& choix);
		void menuMaquette(int& choix);
		void menuUE();
    	void menuUEchoix();
    	
    	void affichageCentreConsole(const std::string &chaine) const;
};

#endif
