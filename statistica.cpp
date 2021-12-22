/*
test
*/
//
// Created by marius on 2021-10-27.
//

#include "statistica.h"
#include "exceptii.h"
#include <unordered_map>

using namespace std::string_literals;

statistica::statistica(const std::vector <std::shared_ptr <fenomen_meteorologic>> &date) : date(date) {}

auto statistica::frecventa_cod() const {
    std::unordered_map <cod, int> frecventa;
    for(const auto &data: date)
        if(frecventa.find(data->getCod()) != frecventa.end())
            frecventa[data->getCod()]++;
        else
            frecventa[data->getCod()] = 1;
    return frecventa;
}

std::ostream &operator<<(std::ostream &os, const statistica &statistica) {
    const auto &frecventa = statistica.frecventa_cod();
    for(const auto&[cod, nr]: frecventa) {
        os << cod << ": " << nr << "\n";
    }
    for(const auto &data: statistica.date) {
        os << *data;
    }
    os << "temperatura medie: " << statistica.temperatura_medie() << ", presiunea atmosferica medie: "
       << statistica.presiune_atmosferica_medie() << "\n";
    return os;
}

void statistica::adauga(const std::shared_ptr <fenomen_meteorologic> &data) {
    date.push_back(data);
}

double statistica::temperatura_medie() const {
    double medie = 0;
    for(const auto &data: date) {
        medie += data->getTemperatura();
    }
    return medie / date.size();
}

double statistica::presiune_atmosferica_medie() const {
    double medie = 0;
    for(const auto &data: date) {
        medie += data->getPresiuneAtmosferica();
    }
    return medie / date.size();
}

double statistica::temperatura_aparenta_medie() const {
    double medie = 0;
    for(const auto &data: date) {
        medie += data->temperaturaAparenta();
    }
    return medie / date.size();
}

statistica::~statistica() {
}

statistica::statistica(const statistica &copie) {
    for(const auto &data: copie.date)
        date.push_back(data->clone());
}

statistica &statistica::operator=(const statistica &copie) {
    if(this != &copie) {
        auto date_noi = std::vector <std::shared_ptr <fenomen_meteorologic>>();
        for(const auto &data: copie.date)
            date_noi.push_back(data->clone());
        date = date_noi;
    }
    return *this;
}

void statistica::ordoneaza_temperatura() {
    std::sort(date.begin(), date.end(), [](const auto &a, const auto &b)
    {
      return a->temperaturaAparenta() < b->temperaturaAparenta();
    });
}

void statistica::ordoneaza_pa() {
    std::sort(date.begin(), date.end(), [](const auto &a, const auto &b)
    {
      return a->getPresiuneAtmosferica() < b->getPresiuneAtmosferica();
    });
}

std::shared_ptr <fenomen_meteorologic> statistica::gaseste(const date::year_month_day &data_fen) {
    // std::execution::par ca prim parametru pt a rula in paralel; trebuie inclus <execution>
    auto it = std::find_if(date.begin(), date.end(), [&](const std::shared_ptr <fenomen_meteorologic> &elem)
    {
      return elem->getInceput() == data_fen;
    });
    if(it != date.end())
        return *it;
    // return (*it)->clone();

    std::stringstream s;
    s << "fenomenul " << data_fen << " nu a fost gasit";
    throw eroare_fenomen(s.str());
}

//auto statistica::durata_medie() const {
//    std::for_each(date.begin(), date.end(), [](const fenomen_meteorologic& data){
//      data.getSfarsit().
//    });
//    return nullptr;
//}
