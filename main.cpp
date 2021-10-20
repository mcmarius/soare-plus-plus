/*
test
*/
//
// Created by marius on 2021-10-20.
//

#include <string>
#include <vector>
//#include <date/date.h>
#include <ostream>
#include <iostream>
#include <unordered_map>

class data {
    int an;
    int luna;
    int zi;
public:
    data(int an, int luna, int zi) : an(an), luna(luna), zi(zi) {}

    friend std::ostream &operator<<(std::ostream &os, const data &data) {
        os << "an: " << data.an << " luna: " << data.luna << " zi: " << data.zi;
        return os;
    }
};

enum class cod { ROSU, PORTOCALIU, GALBEN, VERDE };

std::ostream& operator<<(std::ostream& os, const enum cod& cod) {
    switch(cod) {
        case cod::ROSU:
            os << "rosu";
            break;
        case cod::PORTOCALIU:
            os << "portocaliu";
            break;
        case cod::GALBEN:
            os << "galben";
            break;
        case cod::VERDE:
            os << "verde";
            break;
    }
    return os;
}

class fenomen_meteorologic {
    std::string nume;
    data inceput;
    data sfarsit;
//    date::year_month_day inceput;
//    date::year_month_day sfarsit;
    cod cod;
public:
    fenomen_meteorologic(const std::string &nume, const data &inceput, const data &sfarsit, enum cod cod)
    : nume(nume), inceput(inceput), sfarsit(sfarsit), cod(cod) {}

    fenomen_meteorologic(const fenomen_meteorologic& copie)
    : nume(copie.nume), inceput(copie.inceput), sfarsit(copie.sfarsit), cod(copie.cod) {
        std::cout << "cc fenomen\n";
    }

    fenomen_meteorologic& operator=(const fenomen_meteorologic& copie) {
        std::cout << "op= fenomen\n";
        if(this != &copie) {
            this->nume = copie.nume;
            this->inceput = copie.inceput;
            this->sfarsit = copie.sfarsit;
            this->cod = copie.cod;
        }
        return *this;
    }

    ~fenomen_meteorologic() {
        std::cout << "destr fenomen\n";
    }

    friend std::ostream &operator<<(std::ostream &os, const fenomen_meteorologic &meteorologic) {
        os << "nume: " << meteorologic.nume << " inceput: " << meteorologic.inceput << " sfarsit: "
           << meteorologic.sfarsit << " cod: " << meteorologic.cod << "\n";
        return os;
    }

    enum cod getCod() const {
        return cod;
    }
};

class statistica {
    std::vector<fenomen_meteorologic> date;
public:
    statistica(const std::vector <fenomen_meteorologic> &date) : date(date) {}

    auto calculeaza_frecventa() const {
        std::unordered_map<cod, int> frecventa;
        for(const auto& data_ : date)
            if(frecventa.contains(data_.getCod()))
                frecventa[data_.getCod()]++;
            else
                frecventa[data_.getCod()] = 1;
        return frecventa;
    }

    friend std::ostream &operator<<(std::ostream &os, const statistica &statistica) {
        const auto& frecventa = statistica.calculeaza_frecventa();
        for(const auto& [cod, nr] : frecventa) {
            std::cout << cod << ": " << nr << "\n";
        }
        return os;
    }
};

class simulator {
    std::vector<fenomen_meteorologic> fenomene;
};

int main() {
    fenomen_meteorologic ploaie("ploaie", {2021, 10, 10}, {2021, 10, 11}, cod::GALBEN);
    fenomen_meteorologic ceata("ceata", {2021, 10, 12}, {2021, 10, 14}, cod::PORTOCALIU);
    fenomen_meteorologic soare("soare", {2021, 10, 15}, {2021, 10, 19}, cod::VERDE);
    fenomen_meteorologic iar_soare("soare", {2020, 10, 15}, {2020, 10, 19}, cod::VERDE);

    std::cout << ploaie << ceata << soare;
    statistica stat {{ploaie, ceata, soare, iar_soare}};
    std::cout << stat;
}
