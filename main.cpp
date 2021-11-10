/*
test
*/
//
// Created by marius on 2021-10-20.
//

#include <vector>
#include <date/date.h>
#include <iostream>
#include <random>
#include <set>
#include "fenomen_meteorologic.h"
#include "statistica.h"
#include "soare.h"
#include "ploaie.h"

using namespace date::literals;

class simulator {
    std::set <fenomen_meteorologic> fenomene;
    std::vector <fenomen_meteorologic> fenomene_v;
    static const int MAX_ITERATII = 10;
public:
    simulator(const std::set <fenomen_meteorologic> &fenomene)
    : fenomene(fenomene), fenomene_v(fenomene.begin(), fenomene.end()) {}

    void adauga(const fenomen_meteorologic &fenomen) {
        fenomene.insert(fenomen);
        if(fenomene.size() != fenomene_v.size())
            fenomene_v.push_back(fenomen);
    }

    void simuleaza(int nr_iteratii = MAX_ITERATII) {
        std::random_device r;
        std::default_random_engine engine(r());
        std::cout << "------------------------\n";
        std::uniform_int_distribution <unsigned> uniform_dist(0, fenomene.size() - 1);
        for(int i = 0; i < nr_iteratii; ++i) {
            unsigned nr = uniform_dist(engine);
            std::cout << fenomene_v[nr].getCod() << "\n";
        }
        std::cout << "------------------------\n";
    }
};

class baza {
    int x = 0;
protected:
    int y = 1;
public:
    void f() {
        std::cout << "baza f\n";
    }

    ~baza() {
        std::cout << "destr baza\n";
    }
};

class derivata : public baza {
public:
    void f() {
        std::cout << y << " derivata f\n";
    }

    ~derivata() {
        std::cout << "destr derivata\n";
    }
};

class baza_v {
    int x = 0;
protected:
    int y = 1;
public:
    virtual void f() {
        std::cout << "baza_v f\n";
    }

    virtual ~baza_v() {
        std::cout << "destr baza_v\n";
    }
};

class derivata_v : public baza_v {
public:
    void f() {
        std::cout << y << " derivata_v f\n";
    }

    ~derivata_v() {
        std::cout << "destr derivata_v\n";
    }
};

class nimic {};
class nimic_v {
    virtual ~nimic_v() = default;
};

int main() {
    //derivata d;
    //d.f();
    //d.g();
//    d.y;
    std::cout << sizeof(baza) << " " << sizeof(derivata) << "\n";
    std::cout << sizeof(baza_v) << " " << sizeof(derivata_v) << "\n";
    std::cout << sizeof(void *) << "\n";
    std::cout << sizeof(nimic) << " " << sizeof(nimic_v)
              << "\n";  // 1 pt ca fiecare obiect nou trebuie sa aiba o adresa unica

    baza *b1 = new derivata;
    baza_v *b2 = new derivata_v;
    std::shared_ptr <baza> b3 = std::make_shared <derivata>();
    std::shared_ptr <baza_v> b4 = std::make_shared <derivata_v>();
    b1->f();
    std::cout << "-----1-----\n";
    b2->f();
    std::cout << "-----2-----\n";
    b3->f();
    std::cout << "-----3-----\n";
    b4->f();
    std::cout << "-----4-----\n";
    delete b1;
    delete b2;

    return 0;

    ploaie p1(2021_y / 10 / 10, 2021_y / 10 / 11, cod::GALBEN, 750, 16);
    fenomen_meteorologic ceata("ceata", 2021_y / 10 / 12, 2021_y / 10 / 14, cod::PORTOCALIU, 740, 14);
    soare s1(2021_y / 10 / 15, 2021_y / 10 / 19, cod::VERDE, 765, 25);
    soare s2(2020_y / 10 / 15, 2020_y / 10 / 19, cod::VERDE, 750, 23);

    std::cout << p1 << ceata << s1.temperaturaAparenta();
    statistica stat{{std::make_shared <fenomen_meteorologic>(ceata)}}; //{p1, ceata, s1, s2, ceata, ceata}};
    stat.adauga(std::make_shared <ploaie>(p1));
    stat.adauga(std::make_shared <soare>(s1));
    stat.adauga(std::make_shared <fenomen_meteorologic>(ceata));
    stat.adauga(std::make_shared <soare>(s2));
    {
        statistica stat2(stat);
    }
    std::cout << "---------\n";
    std::cout << stat << " " << stat.temperatura_aparenta_medie();
    std::cout << "\n---------\n";
    simulator sim{{p1, s1, ceata, s2}};
    sim.simuleaza();
}
