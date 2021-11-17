/*
test
*/
//
// Created by marius on 2021-11-17.
//

#ifndef SOARE_PLUS_PLUS_CEATA_H
#define SOARE_PLUS_PLUS_CEATA_H

#include "fenomen_meteorologic.h"

class ceata : public fenomen_meteorologic {
public:
    ceata(const date::year_month_day &inceput, const date::year_month_day &sfarsit, cod cod, int presiuneAtmosferica, int temperatura);
    std::shared_ptr <fenomen_meteorologic> clone() const override;
};

#endif //SOARE_PLUS_PLUS_CEATA_H
