/*
test
*/
//
// Created by marius on 2021-12-08.
//

#include "simulator.h"

template <typename T>
simulator <T>::simulator(const std::set <std::shared_ptr <fenomen_meteorologic>> &fenomene) {
    for(const auto &fenomen: fenomene)
        this->fenomene.insert(fenomen->clone());
    for(const auto &fenomen: fenomene)
        this->fenomene_v.push_back(fenomen->clone());
}

template <typename T>
void simulator <T>::adauga(const std::shared_ptr <fenomen_meteorologic> &fenomen) {
    fenomene.insert(fenomen->clone());
    if(fenomene.size() != fenomene_v.size())
        fenomene_v.push_back(fenomen->clone());
}

template <typename T>
void simulator <T>::simuleaza(int nr_iteratii) {
    static std::random_device r;
    static std::default_random_engine engine(r());
    std::cout << "------------------------\n";
    std::uniform_int_distribution <T> uniform_dist(0, fenomene.size() - 1);
    for(int i = 0; i < nr_iteratii; ++i) {
        T nr = uniform_dist(engine);
        std::cout << fenomene_v[nr]->getCod() << "\n";
    }
    std::cout << "------------------------\n";
}
