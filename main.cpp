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
#include "exceptii.h"
#include "ceata.h"

using namespace date::literals;

class simulator {
    std::set <std::shared_ptr <fenomen_meteorologic>> fenomene;
    std::vector <std::shared_ptr <fenomen_meteorologic>> fenomene_v;
    static const int MAX_ITERATII = 10;
public:
    simulator(const std::set <std::shared_ptr <fenomen_meteorologic>> &fenomene) {
        for(const auto &fenomen: fenomene)
            this->fenomene.insert(fenomen->clone());
        for(const auto &fenomen: fenomene)
            this->fenomene_v.push_back(fenomen->clone());
    }

    void adauga(const std::shared_ptr <fenomen_meteorologic> &fenomen) {
        fenomene.insert(fenomen->clone());
        if(fenomene.size() != fenomene_v.size())
            fenomene_v.push_back(fenomen->clone());
    }

    void simuleaza(int nr_iteratii = MAX_ITERATII) {
        std::random_device r;
        std::default_random_engine engine(r());
        std::cout << "------------------------\n";
        std::uniform_int_distribution <unsigned> uniform_dist(0, fenomene.size() - 1);
        for(int i = 0; i < nr_iteratii; ++i) {
            unsigned nr = uniform_dist(engine);
            std::cout << fenomene_v[nr]->getCod() << "\n";
        }
        std::cout << "------------------------\n";
    }
};

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

int main() {

    try {
        std::cout << "inainte de f1\n";
        soare soare0_main(2020_y / 11 / 17, 2020_y / 11 / 17);
        f1();
        std::cout << "dupa f1\n";
    }
    catch(eroare_fenomen &eroare) {
        std::cout << eroare.what() << "\n";
    }
    catch(std::exception &eroare) {
        std::cout << eroare.what() << "\n";
    }

    std::cout << fenomen_meteorologic::getIdMax() << "\n";
    auto p1 = std::make_shared <ploaie>(2021_y / 10 / 10, 2021_y / 10 / 11, cod::GALBEN, 750, 16);
    std::cout << fenomen_meteorologic::getIdMax() << "\n";
    auto ceata_ = std::make_shared <ceata>(2021_y / 10 / 12, 2021_y / 10 / 14, cod::PORTOCALIU, 740, 14);
    auto s1 = std::make_shared <soare>(2021_y / 10 / 15, 2021_y / 10 / 19, cod::VERDE, 765, 25);
    auto s2 = std::make_shared <soare>(2020_y / 10 / 15, 2020_y / 10 / 19, cod::VERDE, 750, 23);

    std::cout << *p1 << *ceata_ << s1->temperaturaAparenta();
    statistica stat{{ceata_}}; //{p1, ceata, s1, s2, ceata, ceata}};
    stat.adauga(p1);
    stat.adauga(s1);
    stat.adauga(ceata_);
    stat.adauga(s2);
    {
        statistica stat2(stat);
    }
    std::cout << "---------\n";
    std::cout << stat << " " << stat.temperatura_aparenta_medie();
    std::cout << "\n---------\n";
    simulator sim{std::set <std::shared_ptr <fenomen_meteorologic>>{p1, s1, ceata_, s2}};
    sim.simuleaza();
    return 0;
}
