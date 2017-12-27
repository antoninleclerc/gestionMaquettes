#include "Interface.h"

#include<iostream>
#include "Interface.h"

void Interface::menuPrincipalBoucle()
{	
  	int choix;
  	menuPrincipalChoix(choix);
  	while (choix != 3)
  	{
    	switch (choix)
    	{
      		case 1: /*fonction ajout maquette */; break;
      		case 2: /*fonction ajout formation */; break;
    	}
    	menuPrincipalChoix(choix);
  	}
}

void Interface::menuPrincipalChoix(int& choix)
{
	do
  	{
    	std::cout << "Menu Principal" << std::endl;
    	std::cout << "Voulez-vous :" << std::endl;
    	std::cout << "(1) Ajouter une maquette" << std::endl;
    	std::cout << "(2) Ajouter une formation" << std::endl;
    	std::cout << "(3) Quitter" << std::endl;
    	std::cout << "Votre choix : " << std::endl;
    	std::cin >> choix;
  	}
  	while (choix < 1 || choix > 3);
}
