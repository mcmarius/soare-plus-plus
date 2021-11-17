/*
test
*/
//
// Created by marius on 2021-11-17.
//

#include "exceptii.h"
#include <string>

using namespace std::string_literals;

eroare_fenomen::eroare_fenomen(const std::string &arg) : runtime_error("Eroare fenomen: "s + arg) {}

eroare_senzor::eroare_senzor(int temperatura) : eroare_fenomen(
"Eroare senzor: temperatura citita este "s + std::to_string(temperatura)) {}

eroare_interval::eroare_interval() : eroare_fenomen("Data de inceput nu poate fi dupa data de sfarsit") {}
