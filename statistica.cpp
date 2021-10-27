/*
test
*/
//
// Created by marius on 2021-10-27.
//

#include "statistica.h"

statistica::statistica(const std::vector <fenomen_meteorologic> &date) : date(date) {}

auto statistica::frecventa_cod() const {
    std::unordered_map <cod, int> frecventa;
    for(const auto &data_: date)
        if(frecventa.contains(data_.getCod()))
            frecventa[data_.getCod()]++;
        else
            frecventa[data_.getCod()] = 1;
    return frecventa;
}

std::ostream &operator<<(std::ostream &os, const statistica &statistica) {
    const auto &frecventa = statistica.frecventa_cod();
    for(const auto&[cod, nr]: frecventa) {
        os << cod << ": " << nr << "\n";
    }
    os << "temperatura medie: " << statistica.temperatura_medie() << ", presiunea atmosferica medie: "
       << statistica.presiune_atmosferica_medie() << "\n";
    return os;
}

void statistica::adauga(const fenomen_meteorologic &data) {
    date.push_back(data);
}

double statistica::temperatura_medie() const {
    double medie = 0;
    for(const auto &data: date) {
        medie += data.getTemperatura();
    }
    return medie / date.size();
}

double statistica::presiune_atmosferica_medie() const {
    double medie = 0;
    for(const auto &data: date) {
        medie += data.getPresiuneAtmosferica();
    }
    return medie / date.size();
}

//auto statistica::durata_medie() const {
//    std::for_each(date.begin(), date.end(), [](const fenomen_meteorologic& data){
//      data.getSfarsit().
//    });
//    return nullptr;
//}
