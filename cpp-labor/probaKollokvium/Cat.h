//
// Created by szege on 08/01/2024.
//

#ifndef PROBAKOLLOKVIUM_CAT_H
#define PROBAKOLLOKVIUM_CAT_H

#include "Animal.h"

class Cat : public Animal {
    void makeSound() const override {
        cout << "Cat sound!" << endl;
    }
};


#endif //PROBAKOLLOKVIUM_CAT_H
