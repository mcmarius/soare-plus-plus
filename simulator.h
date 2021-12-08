/*
test
*/
//
// Created by marius on 2021-12-08.
//

#ifndef SOARE_PLUS_PLUS_SIMULATOR_H
#define SOARE_PLUS_PLUS_SIMULATOR_H

#include <set>
#include <memory>
#include <random>
#include "fenomen_meteorologic.h"

template <typename T>
class simulator {
    std::set <std::shared_ptr <fenomen_meteorologic>> fenomene;
    std::vector <std::shared_ptr <fenomen_meteorologic>> fenomene_v;
    static const int MAX_ITERATII = 10;
public:
    simulator(const std::set <std::shared_ptr <fenomen_meteorologic>> &fenomene);

    void adauga(const std::shared_ptr <fenomen_meteorologic> &fenomen);

    void simuleaza(int nr_iteratii = MAX_ITERATII);
};

#endif //SOARE_PLUS_PLUS_SIMULATOR_H
