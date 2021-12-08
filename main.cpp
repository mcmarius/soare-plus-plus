/*
test
*/
//
// Created by marius on 2021-10-20.
//

#include <date/date.h>
#include <iostream>
#include "fenomen_meteorologic.h"
#include "statistica.h"
#include "soare.h"
#include "ploaie.h"
#include "exceptii.h"
#include "ceata.h"
#include "furtuna.h"
#include "simulator.h"

using namespace date::literals;

void f1();
void f2();

void f2() {
    std::cout << "in f2 inainte\n";
    soare soare0(2020_y / 11 / 17, 2020_y / 11 / 17);
    {
        soare soare00(2020_y / 11 / 17, 2020_y / 11 / 17, cod::VERDE, 777, 777);
        soare soare1(2021_y / 11 / 17, 2020_y / 11 / 17);
        std::cout << "in f2 acolada dupa\n";
    }
    std::cout << "in f2 dupa\n";
}

void f1() {
    soare soare0_f1(2020_y / 11 / 15, 2020_y / 11 / 17);
    try {
        std::cout << "inainte de f2\n";
        soare soare1_f1(2020_y / 11 / 16, 2020_y / 11 / 17);
        f2();
        std::cout << "dupa f2\n";
    }
    catch(std::runtime_error &eroare) {
        std::cout << "in f1: " << eroare.what() << "\n";
    }
}

class baza {
protected:
    int x;
public:
    virtual void f() {
        std::cout << "baza\n";
    }
};

class der1 : virtual public baza {
public:
    void f() override {
        baza::f();
        std::cout << "d1\n";
    }
};
class der2 : virtual public baza {
public:
    void f() override {
        baza::f();
        std::cout << "d2\n";
    }
};
class der_multipla : public der1, public der2 {
public:
    void f() override {
        der1::f();
        der2::f();
        x;
        //der3::x;
    }
};

class abc {
    int a;
    float b;
    double c;
public:
    abc(int a = 2, float b = 1, double c = 0) : a(a), b(b), c(c) {}
};

template <typename T, typename U>
void f(T x, U y) {
    std::cout << x << " " << y << "\n";
}

int main() {
    f <int, int>(2, 3);
    f <int, double>(2, 3);
    f <float, double>(2, 3);
//    abc a = builder.set_c(2).build();
    der_multipla d;
    d.f();
    //fenomen_meteorologic
    // ce face new:
    // aloca memorie (suficienti bytes pt acel obiect) si apoi
    // apeleaza constructorul
    fenomen_meteorologic *s0 = new soare{2021_y / 4 / 4, 2021_y / 5 / 5};
    furtuna fr{"abc", 2021_y / 3 / 3, 2021_y / 4 / 5};

    int *x = new int;
    int *vec = new int[20];
    delete x;
    delete[] vec;
    // de ce avem si new/delete, si new[]/delete[]?
    // pt ca pot fi suprascrisi separat pt a optimiza modul in care se fac alocarile


    // ce face delete:
    // apeleaza destructorul si apoi
    // elibereaza memoria alocata cu new
    delete s0;

    // constr: baza, der1, der2
    // destr: der2, der1, baza

    try {
        std::cout << "inainte de f1\n";
        soare soare0_main(2020_y / 11 / 17, 2020_y / 11 / 17);
        f1();
        std::cout << "dupa f1\n";
    }
    catch(eroare_fenomen &eroare) {
        std::cout << eroare.what() << "\n";
        //throw std::runtime_error("");
    }
    catch(std::exception &eroare) {
        std::cout << eroare.what() << "\n";
        //throw;
    }

    std::cout << fenomen_meteorologic::getIdMax() << "\n";
    auto p1 = std::make_shared <ploaie>(2021_y / 10 / 10, 2021_y / 10 / 11, cod::GALBEN, 750, 16);
    std::cout << fenomen_meteorologic::getIdMax() << "\n";
    auto ceata_ = std::make_shared <ceata>(2021_y / 10 / 12, 2021_y / 10 / 14, cod::PORTOCALIU, 740, 14);
    auto s1 = std::make_shared <soare>(2021_y / 10 / 15, 2021_y / 10 / 19, cod::VERDE, 765, 25);
    auto s2 = std::make_shared <soare>(2020_y / 10 / 15, 2020_y / 10 / 19, cod::VERDE, 750, 23);

    s1 = s2;

    std::cout << s1->getTemperatura() << " " << s2->getTemperatura();
    s1->adauga_vant();
    std::cout << s1->getTemperatura() << " " << s2->getTemperatura();

    std::cout << *p1 << *ceata_ << s1->temperaturaAparenta();
    statistica stat{{ceata_}}; //{p1, ceata, s1, s2, ceata, ceata}};
    stat.adauga(p1);
    stat.adauga(s1);
    stat.adauga(ceata_);
    stat.adauga(s2);
    stat.adauga(std::make_shared <furtuna>(fr));
    {
        statistica stat2(stat);
    }
    std::cout << "---------\n";
    std::cout << stat << " " << stat.temperatura_aparenta_medie();
    std::cout << "\n---------\n";
    simulator <unsigned> sim{std::set <std::shared_ptr <fenomen_meteorologic>>{p1, s1, ceata_, s2}};
    simulator <unsigned short> sim2{std::set <std::shared_ptr <fenomen_meteorologic>>{p1, s1, ceata_, s2}};
    sim.simuleaza();
    return 0;
}
