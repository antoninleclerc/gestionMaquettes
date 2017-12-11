#ifndef UECHOIX_H
#define UECHOIX_H

#include <vector>
#include "cours.h"

class UEchoix: public cours
{
    public:
        UEchoix();
        virtual ~UEchoix();
        virtual void afficher(std::ostream &ost) const override;

    private:
        std::vector<UE* >d_UEchoix;
};

#endif // UECHOIX_H
