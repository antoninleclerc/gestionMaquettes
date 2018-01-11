#include <iostream>
#include <windows.h>
#include <stdio.h>

#include "System.h"
#include "Interface.h"

int main(int argc, char** argv) 
{
	/*ECUE *ecue1= new ECUE{"13GUCSI5","CONCEPTION DE SYSTEMES D'INFORMATIONS",1,14,26,0};
	
	UE *ue1= new UE{"13GUTEXP","TECHNIQUES D'EXPRESSION",1,0,0,0,3};
	ue1->ajouterECUE(ecue1);
	
	maquette m;
	m.ajouterUE(ue1);
	std::cout<<m;*/
	system("MODE CON COLS=160 LINES=70");
	std::string nomFichier="Licence 3 MIAGE";
	System::charge(nomFichier.c_str());
	Interface i;
	return 0;
}
