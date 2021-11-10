/*
test
*/
//
// Created by marius on 2021-10-27.
//

#include "fenomen_meteorologic.h"

int fenomen_meteorologic::id_max = 1;

std::ostream &operator<<(std::ostream &os, const cod &cod) {
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
        default:
            os << "??";
            break;
    }
    return os;
}

fenomen_meteorologic::fenomen_meteorologic(const std::string &nume, const date::year_month_day &inceput, const date::year_month_day &sfarsit, enum cod cod)
: nume(nume), inceput(inceput), sfarsit(sfarsit), cod_(cod), id(id_max) {
    id_max++;
}

fenomen_meteorologic::fenomen_meteorologic(const std::string &nume, const date::year_month_day &inceput, const date::year_month_day &sfarsit)
: fenomen_meteorologic(nume, inceput, sfarsit, cod::VERDE) {}

fenomen_meteorologic::fenomen_meteorologic(const fenomen_meteorologic &copie)
: nume(copie.nume), inceput(copie.inceput), sfarsit(copie.sfarsit), cod_(copie.cod_), temperatura(copie.temperatura), presiune_atmosferica(copie.presiune_atmosferica),
  id(id_max) {
    id_max++;
    std::cout << "cc fenomen\n";
}

fenomen_meteorologic &fenomen_meteorologic::operator=(const fenomen_meteorologic &copie) {
    std::cout << "op= fenomen\n";
    if(this != &copie) {
        this->nume = copie.nume;
        this->inceput = copie.inceput;
        this->sfarsit = copie.sfarsit;
        this->cod_ = copie.cod_;
        this->temperatura = copie.temperatura;
        this->presiune_atmosferica = copie.presiune_atmosferica;
    }
    return *this;
}

fenomen_meteorologic::~fenomen_meteorologic() {
    std::cout << "destr fenomen\n";
}

std::ostream &operator<<(std::ostream &os, const fenomen_meteorologic &fenomen) {
    os << "id: " << fenomen.id << ": nume: " << fenomen.nume << " inceput: " << fenomen.inceput << " sfarsit: "
       << fenomen.sfarsit << " cod_: " << fenomen.cod_ << "\n";
    return os;
}

enum cod fenomen_meteorologic::getCod() const {
    return cod_;
}

const date::year_month_day &fenomen_meteorologic::getInceput() const {
    return inceput;
}

const date::year_month_day &fenomen_meteorologic::getSfarsit() const {
    return sfarsit;
}

fenomen_meteorologic::fenomen_meteorologic(const std::string &nume, const date::year_month_day &inceput, const date::year_month_day &sfarsit, enum cod cod, int presiuneAtmosferica, int temperatura)
: nume(nume), inceput(inceput), sfarsit(sfarsit), cod_(cod), presiune_atmosferica(presiuneAtmosferica), temperatura(temperatura), id(id_max) {
    id_max++;
}

int fenomen_meteorologic::getPresiuneAtmosferica() const {
    return presiune_atmosferica;
}

int fenomen_meteorologic::getTemperatura() const {
    return temperatura;
}

bool fenomen_meteorologic::operator==(const fenomen_meteorologic &rhs) const {
    return nume == rhs.nume &&
           inceput == rhs.inceput &&
           sfarsit == rhs.sfarsit &&
           cod_ == rhs.cod_ &&
           presiune_atmosferica == rhs.presiune_atmosferica &&
           temperatura == rhs.temperatura;
}

bool fenomen_meteorologic::operator!=(const fenomen_meteorologic &rhs) const {
    return !(rhs == *this);
}

bool fenomen_meteorologic::operator<(const fenomen_meteorologic &rhs) const {
    if(nume < rhs.nume)
        return true;
    if(nume > rhs.nume)
        return false;
    if(inceput < rhs.inceput)
        return true;
    if(inceput > rhs.inceput)
        return false;
    if(sfarsit < rhs.sfarsit)
        return true;
    if(sfarsit > rhs.sfarsit)
        return false;
    if(cod_ < rhs.cod_)
        return true;
    if(cod_ > rhs.cod_)
        return false;
    if(temperatura < rhs.temperatura)
        return true;
    if(temperatura > rhs.temperatura)
        return false;
    if(presiune_atmosferica < rhs.presiune_atmosferica)
        return true;
    if(presiune_atmosferica > rhs.presiune_atmosferica)
        return false;
    return false;
}

int fenomen_meteorologic::temperaturaAparenta() const {
    std::cout << "fenonmen temp aparenta\n";
    return temperatura;
}

std::shared_ptr <fenomen_meteorologic> fenomen_meteorologic::clone() const {
    return std::make_shared <fenomen_meteorologic>(*this);
}

int fenomen_meteorologic::getIdMax() {
    return id_max;
}
