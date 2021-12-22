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
    virtual void f() = 0;
    virtual ~baza() = default;

    std::string getTip() const { return ""; }
};

void baza::f() {}

class der1 : virtual public baza {
public:
    void f() override {
        g();
        baza::f();
        std::cout << "d1\n";
    }

private:
    void g() {}
};
class der2 : virtual public baza {
public:
    void f() override {
        h();
        baza::f();
        std::cout << "d2\n";
    }

private:
    void h() {}
};
class der3 : public baza {
    void hh() {}

public:
    void f() override {
        hh();
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
    baza *bz;
public:
    void f() {
        bz->f();
    }

    abc(int a = 2, float b = 1, double c = 0) : a(a), b(b), c(c) {}
};

template <typename T, typename U>
void f(T x, U y) {
    std::cout << x << " " << y << "\n";
}

template <typename T>
class app {
    T date;
    app() = default;
    static app *app_;
public:
    static app &instance() {
        if(app_ == nullptr)
            app_ = new app();
        return *app_;
    }
};

template <typename T>
app <T> *app <T>::app_ = nullptr;

int main() {
    auto &apl = app <der3>::instance();
    der3 d0;
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
        //throw eroare;
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

    auto &elem = stat[1];
    try {
        auto &elem2 = dynamic_cast<ploaie &>(*elem);
        elem2.ploua();
        std::cout << "\nploaie ok\n";
        auto &elem3 = dynamic_cast<furtuna &>(*elem);
        elem3.tunet();
    }
    catch(std::bad_cast &err) {
        std::cout << "err bad cast!!! " << err.what() << "\n";
    }

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

    std::cout << stat.dim();
    std::cout << "----\?\?\?-----\n";
    std::cout << stat;
    stat.ordoneaza_temperatura();
    std::cout << "---------\n";
    std::cout << stat;
    stat.ordoneaza_pa();
    std::cout << "---------\n";
    std::cout << stat;
    try {
        std::cout << *stat.gaseste(2020_y / 10 / 15);
        std::cout << *stat.gaseste(2023_y / 10 / 15);
        std::cout << *stat.gaseste(2020_y / 10 / 15);
    }
    catch(eroare_fenomen &err) {
        std::cout << err.what() << "\n";
    }
    return 0;
}
