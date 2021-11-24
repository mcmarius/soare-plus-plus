/*
test
*/
//
// Created by marius on 2021-11-24.
//

#ifndef SOARE_PLUS_PLUS_FURTUNA_H
#define SOARE_PLUS_PLUS_FURTUNA_H

#include "fenomen_meteorologic.h"

class furtuna : public fenomen_meteorologic {
public:
    furtuna(const std::string &nume, const date::year_month_day &inceput, const date::year_month_day &sfarsit);
    std::shared_ptr <fenomen_meteorologic> clone() const override;
    ~furtuna() override;
};

#endif //SOARE_PLUS_PLUS_FURTUNA_H
