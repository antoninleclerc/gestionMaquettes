#ifndef MATIERE_H
#define MATIERE_H

class Matiere
{
public:
	Matiere(const std::string &code, const std::string &intitule, int CM = 0, int TD = 0, int TP = 0);
	virtual int nbHeuresTotal() const;
	virtual void afficher() const;
private:
	std::string d_code, d_intule;
	int d_coefficient, d_CM, d_TD, d_TP;
	Matiere* d_ECUEsuivant;
};

#endif