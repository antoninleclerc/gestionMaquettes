#ifndef UECHOIX_H
#define UECHOIX_H

#include <vector>
#include <iomanip>
#include "UE.h"

class UEchoix: public UE
{
    public:
        UEchoix(const std::string &code, const std::string &intitule, int coefficient, int CM, int TD, int TP, int ECTS);
        virtual ~UEchoix();

        void ajouterUE(UE *ue);
        bool supprimerUE(const std::string& code);
        virtual void afficher(std::ostream &ost) const override;

    private:
        std::vector<UE* >d_UEchoix;
};

#endif // UECHOIX_H
