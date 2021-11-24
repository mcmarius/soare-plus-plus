/*
test
*/
//
// Created by marius on 2021-11-24.
//

#include "furtuna.h"

std::shared_ptr <fenomen_meteorologic> furtuna::clone() const {
    return std::make_shared <furtuna>(*this);
}

furtuna::furtuna(const std::string &nume, const date::year_month_day &inceput, const date::year_month_day &sfarsit)
: fenomen_meteorologic(nume, inceput, sfarsit) {}

furtuna::~furtuna() {
    std::cout << "destr furtuna\n";
}
