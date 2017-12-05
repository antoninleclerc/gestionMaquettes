#ifndef UE_H
#define UE_H

#include "Matiere.h"

class UE : public Matiere
{
public:
	UE();
private:
	int d_ECTS;
	Matiere* d_UE;
};

#endif

