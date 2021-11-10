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

int main() {
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
