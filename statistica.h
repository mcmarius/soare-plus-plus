/*
test
*/
//
// Created by marius on 2021-10-27.
//

#ifndef SOARE_PLUS_PLUS_STATISTICA_H
#define SOARE_PLUS_PLUS_STATISTICA_H

#include <vector>
#include "fenomen_meteorologic.h"

class statistica {
    std::vector <fenomen_meteorologic> date;
public:
    statistica(const std::vector <fenomen_meteorologic> &date);

    auto frecventa_cod() const;
//    auto durata_medie() const;
    double temperatura_medie() const;
    double temperatura_aparenta_medie() const;
    double presiune_atmosferica_medie() const;
    void adauga(const fenomen_meteorologic &data);

    friend std::ostream &operator<<(std::ostream &os, const statistica &statistica);
};

#endif //SOARE_PLUS_PLUS_STATISTICA_H
