/*
test
*/
//
// Created by marius on 2021-10-27.
//

#ifndef SOARE_PLUS_PLUS_FENOMEN_METEOROLOGIC_H
#define SOARE_PLUS_PLUS_FENOMEN_METEOROLOGIC_H

#include <iostream>
#include <date/date.h>

enum class cod { ROSU, PORTOCALIU, GALBEN, VERDE };

std::ostream &operator<<(std::ostream &os, const enum cod &cod);

class fenomen_meteorologic {
    std::string nume;
//    data inceput;
//    data sfarsit;
    date::year_month_day inceput;
    date::year_month_day sfarsit;
    cod cod;
    int presiune_atmosferica{760};
    int temperatura{20};
public:
    fenomen_meteorologic(const std::string &nume, const date::year_month_day &inceput, const date::year_month_day &sfarsit, enum cod cod, int presiuneAtmosferica, int temperatura);
    fenomen_meteorologic(const std::string &nume, const date::year_month_day &inceput, const date::year_month_day &sfarsit, enum cod cod);
    fenomen_meteorologic(const std::string &nume, const date::year_month_day &inceput, const date::year_month_day &sfarsit); //nume(nume), inceput(inceput), sfarsit(sfarsit) {}
    fenomen_meteorologic(const fenomen_meteorologic &copie);
    fenomen_meteorologic(fenomen_meteorologic &&) = delete;

    fenomen_meteorologic &operator=(const fenomen_meteorologic &copie);
    ~fenomen_meteorologic();

    friend std::ostream &operator<<(std::ostream &os, const fenomen_meteorologic &meteorologic);

    enum cod getCod() const;
    const date::year_month_day &getInceput() const;
    const date::year_month_day &getSfarsit() const;
    int getPresiuneAtmosferica() const;
    int getTemperatura() const;
    bool operator==(const fenomen_meteorologic &rhs) const;
    bool operator!=(const fenomen_meteorologic &rhs) const;
    bool operator<(const fenomen_meteorologic &rhs) const;
};

#endif //SOARE_PLUS_PLUS_FENOMEN_METEOROLOGIC_H
