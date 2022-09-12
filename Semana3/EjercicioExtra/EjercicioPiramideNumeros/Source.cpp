#include "pch.h"
#include <iostream>
#include "ArrNumeros.h"

int main() {
    ArrNumeros* vec = new ArrNumeros();
    for (int i = 0; i < 11; ++i) {
        vec->push_back(i);
    }

    while (vec->size()) {
        for (int i = 0; i < vec->size(); ++i) {
            std::cout << vec->at(i) << ' ';
        }
        std::cout << '\n';
        vec->pop_back();
    }
    delete vec;
    system("pause>0");
    return 0;
}
