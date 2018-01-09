#include <iostream>

#include "maquette.h" 

int main(int argc, char** argv) 
{
	ECUE *ecue1= new ECUE{"13GUCSI5","CONCEPTION DE SYSTEMES D'INFORMATIONS",1,14,26,0};
	
	UE *ue1= new UE{"13GUTEXP","TECHNIQUES D'EXPRESSION",1,0,0,0,3};
	ue1->ajouterECUE(ecue1);
	
	maquette m;
	m.ajouterUE(ue1);
	std::cout<<m;
	return 0;
}
