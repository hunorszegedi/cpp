//
// Created by szege on 08/01/2024.
//

#ifndef PROBAKOLLOKVIUM_DOG_H
#define PROBAKOLLOKVIUM_DOG_H

#include "Animal.h"

class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "Dog sound!" << endl;
    }
};


#endif //PROBAKOLLOKVIUM_DOG_H
