//
// Created by szege on 08/01/2024.
//

#ifndef PROBAKOLLOKVIUM_ANIMAL_H
#define PROBAKOLLOKVIUM_ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    virtual void makeSound() const {
        cout << "Animal sound!" << endl;
    }
};


#endif //PROBAKOLLOKVIUM_ANIMAL_H
