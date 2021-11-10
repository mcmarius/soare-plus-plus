/*
test
*/
//
// Created by marius on 2021-11-03.
//

#include "ploaie.h"

int ploaie::temperaturaAparenta() const {
    std::cout << "ploaie temp aparenta\n";
    return fenomen_meteorologic::temperaturaAparenta() - 3;
}

ploaie::ploaie(const date::year_month_day &inceput, const date::year_month_day &sfarsit, cod cod_, int presiuneAtmosferica, int temperatura)
: fenomen_meteorologic("ploaie", inceput, sfarsit, cod_, presiuneAtmosferica, temperatura) {}

std::shared_ptr <fenomen_meteorologic> ploaie::clone() const {
    return std::make_shared <ploaie>(*this);
}
