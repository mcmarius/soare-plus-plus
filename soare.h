/*
test
*/
//
// Created by marius on 2021-11-03.
//

#ifndef SOARE_PLUS_PLUS_SOARE_H
#define SOARE_PLUS_PLUS_SOARE_H

#include "fenomen_meteorologic.h"

class soare : public fenomen_meteorologic {
public:
    soare(const date::year_month_day &inceput, const date::year_month_day &sfarsit, cod cod, int presiuneAtmosferica, int temperatura);
    int temperaturaAparenta() const;
    ~soare();
    std::shared_ptr <fenomen_meteorologic> clone() const override;
};

#endif //SOARE_PLUS_PLUS_SOARE_H
