/*
test
*/
//
// Created by marius on 2021-11-17.
//

#ifndef SOARE_PLUS_PLUS_EXCEPTII_H
#define SOARE_PLUS_PLUS_EXCEPTII_H

#include <stdexcept>

class eroare_fenomen : public std::runtime_error {
public:
    explicit eroare_fenomen(const std::string &arg);
};

class eroare_senzor : public eroare_fenomen {
public:
    explicit eroare_senzor(int temperatura);
};

class eroare_interval : public eroare_fenomen {
public:
    eroare_interval();
};

#endif //SOARE_PLUS_PLUS_EXCEPTII_H
