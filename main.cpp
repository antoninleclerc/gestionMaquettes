#include <iostream>
#include <windows.h>
#include <stdio.h>

#include "System.h"
#include "Interface.h"


#include "UE.h"


int main(int argc, char** argv) 
{
	system("MODE CON COLS=130 LINES=60");
	GestionMaquettes::Interface i;
	
	/*
	GestionMaquettes::Formation *f = new GestionMaquettes::Formation{1, "SCIENCES ET TECHNOLOGIE, SANTE", "Licence Informatique", "Informatique"};
	
	GestionMaquettes::UE *ue1= new GestionMaquettes::UE{"13GUTUIO","QUALITE DE PROGRAMMATION",1,10,6,0,3};
	GestionMaquettes::UE *ue2= new GestionMaquettes::UE{"125ERDF9","PROGRAMMATION ORIENTEE OBJET",1,14,20,0,3};
	GestionMaquettes::UE *ue3= new GestionMaquettes::UE{"125UIFD9","ALGORITHMIQUE ET STRUCTURE RECURSIVE",1,14,22,0,3};
	GestionMaquettes::UE *ue4= new GestionMaquettes::UE{"89AZAZD9","CONCEPTION DE SYSTEME D INFORMATION",1,14,26,0,3};
	GestionMaquettes::UE *ue5= new GestionMaquettes::UE{"89ARESD9","INTRODUCTION AUX RESEAU",1,18,10,0,3};
	GestionMaquettes::UE *ue6= new GestionMaquettes::UE{"89ARESD9","INTELLIGENCE ARTIFICIELLE",1,15,15,0,3};
	GestionMaquettes::UE *ue7= new GestionMaquettes::UE{"89ARO5D9","RECHERCHE OPERATIONNELLE",1,15,20,0,3};
	GestionMaquettes::UE *ue8= new GestionMaquettes::UE{"13GUTEXP","TECHNIQUES D'EXPRESSION",1,0,0,0,3};
	
	GestionMaquettes::ECUE *ecue1 = new GestionMaquettes::ECUE{"13GUCSI5","Anglais computing",2,0,20,0};
	GestionMaquettes::ECUE *ecue2 = new GestionMaquettes::ECUE{"13ALLSI5","Allemand",2,0,20,0};
	GestionMaquettes::ECUE *ecue3 = new GestionMaquettes::ECUE{"13TECSI5","TECHNIQUE DE STAGE",2,0,10,0};
	
	ue8->ajouterECUE(ecue1);
	ue8->ajouterECUE(ecue2);
	ue8->ajouterECUE(ecue3);

	
	GestionMaquettes::Maquette *m = new GestionMaquettes::Maquette{};
	GestionMaquettes::Maquette *m1 = new GestionMaquettes::Maquette{};
	
	m->ajouterUE(ue1);
	m->ajouterUE(ue2);
	m->ajouterUE(ue3);
	m->ajouterUE(ue4);
	m->ajouterUE(ue5);
	m->ajouterUE(ue6);
	m->ajouterUE(ue7);
	m->ajouterUE(ue8);
	
	GestionMaquettes::UE *ue9 = new GestionMaquettes::UE{"13GERRIO","DEVELOPPEMENT DE SITE WEB",1,12,18,0,3};
	GestionMaquettes::UE *ue10 = new GestionMaquettes::UE{"125ERDF9","PROGRAMMATION",1,0,0,0,3};
	GestionMaquettes::ECUE *ecue4 = new GestionMaquettes::ECUE{"13DFFSI5","Java",1,10,10,0};
	GestionMaquettes::ECUE *ecue5 = new GestionMaquettes::ECUE{"13APRGS5","Programmation smartphone",2,12,8,0};
	GestionMaquettes::UE *ue11 = new GestionMaquettes::UE{"125U8999","GRAPHES ET ALGO",1,10,20,0,3};
	GestionMaquettes::UE *ue12 = new GestionMaquettes::UE{"89AZAZD9","ALGORITHME SUR LES FICHIERS",1,12,18,0,3};
	GestionMaquettes::UE *ue13 = new GestionMaquettes::UE{"89ARESD9","AUTOMATES",1,16,14,0,3};
	GestionMaquettes::UE *ue14 = new GestionMaquettes::UE{"89ARESD9","ANALYSE ET TRAITEMENT D IMAGES",1,15,15,0,3};
	GestionMaquettes::UE *ue15 = new GestionMaquettes::UE{"89ARO5D9","LIBRE",1,0,24,0,3};
	GestionMaquettes::UE *ue16 = new GestionMaquettes::UE{"13GUTEXP","STAGE",2,0,0,0,6};
	
	ue10->ajouterECUE(ecue4);
	ue10->ajouterECUE(ecue5);
	
	m1->ajouterUE(ue9);
	m1->ajouterUE(ue10);
	m1->ajouterUE(ue11);
	m1->ajouterUE(ue12);
	m1->ajouterUE(ue13);
	m1->ajouterUE(ue14);
	m1->ajouterUE(ue15);
	m1->ajouterUE(ue16);
	
	f->ajouterMaquette(m);
	f->ajouterMaquette(m1);
	
	f->sauverDansFichier();
	*/
	
	return 0;
}
