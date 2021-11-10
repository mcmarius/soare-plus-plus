/*
test
*/
//
// Created by marius on 2021-11-03.
//

#ifndef SOARE_PLUS_PLUS_PLOAIE_H
#define SOARE_PLUS_PLUS_PLOAIE_H

#include "fenomen_meteorologic.h"

class ploaie : public fenomen_meteorologic {
public:
    ploaie(const date::year_month_day &inceput, const date::year_month_day &sfarsit, cod cod_, int presiuneAtmosferica, int temperatura);

    int temperaturaAparenta() const;
    std::shared_ptr <fenomen_meteorologic> clone() const override;
};

#endif //SOARE_PLUS_PLUS_PLOAIE_H
