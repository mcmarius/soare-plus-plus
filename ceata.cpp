/*
test
*/
//
// Created by marius on 2021-11-17.
//

#include "ceata.h"

std::shared_ptr <fenomen_meteorologic> ceata::clone() const {
    return std::make_shared <ceata>(*this);
}

ceata::ceata(const date::year_month_day &inceput, const date::year_month_day &sfarsit, cod cod, int presiuneAtmosferica, int temperatura)
: fenomen_meteorologic("ceata", inceput, sfarsit, cod, presiuneAtmosferica, temperatura) {}
