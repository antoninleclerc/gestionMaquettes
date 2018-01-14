#include <iostream>
#include <windows.h>
#include <stdio.h>

#include "System.h"
#include "Interface.h"

int main(int argc, char** argv) 
{
	system("MODE CON COLS=160 LINES=70");
	GestionMaquettes::Interface i;
	return 0;
}
