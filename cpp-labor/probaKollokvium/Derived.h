//
// Created by szege on 08/01/2024.
//

#ifndef PROBAKOLLOKVIUM_DERIVED_H
#define PROBAKOLLOKVIUM_DERIVED_H

#include "Base.h"

class Derived : public Base {
public:
    void print() const override {
        std::cout << "Derived" << std::endl;
    }
};


#endif //PROBAKOLLOKVIUM_DERIVED_H
