#include "Animal.hpp"

#include <iostream>

void Dog::make_noise() {
    std::cout << "woof" << std::endl;    
}

void Fox::make_noise() {
    std::cout << "what does the fox say?" << std::endl;    
}

void speak(Animal* a) {
    a->make_noise();
}
