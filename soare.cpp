/*
test
*/
//
// Created by marius on 2021-11-03.
//

#include "soare.h"

int soare::temperaturaAparenta() const {
    std::cout << "soare temp aparenta\n";
    return fenomen_meteorologic::temperaturaAparenta() + 5;
}

soare::soare(const date::year_month_day &inceput, const date::year_month_day &sfarsit, cod cod, int presiuneAtmosferica, int temperatura)
: fenomen_meteorologic("soare", inceput, sfarsit, cod, presiuneAtmosferica, temperatura) {}

soare::soare(const date::year_month_day &inceput, const date::year_month_day &sfarsit)
: fenomen_meteorologic("soare", inceput, sfarsit) {}

soare::~soare() {
    std::cout << "destr soare\n";
}

std::shared_ptr <fenomen_meteorologic> soare::clone() const {
    return std::make_shared <soare>(*this);
}
