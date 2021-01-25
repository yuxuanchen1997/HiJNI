#pragma once
#include <iostream>
#include <string>
#include <vector>

class Animal {
public:
    virtual void make_noise() = 0;
};

class Dog : public Animal {
public:
    void make_noise() override;
};

class Fox : public Animal {
public:
    void make_noise() override;
};

void speak(Animal*);
