//
// Created by szege on 08/01/2024.
//

#ifndef PROBAKOLLOKVIUM_BASE_H
#define PROBAKOLLOKVIUM_BASE_H

#include <iostream>

using namespace std;

class Base {
public:
    virtual void print() const {
        cout << "Base" << endl;
    }
};


#endif //PROBAKOLLOKVIUM_BASE_H
