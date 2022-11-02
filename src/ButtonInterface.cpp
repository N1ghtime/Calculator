#include "ButtonInterface.hpp"
#include "Button.hpp"
#include "constants.hpp"
#include <iostream>

//Construct ButtonInterface
ButtonInterface::ButtonInterface() {
    for(int i = 0; i < BUTTONS; i++) {
        Button* button = new Button(i);
        interface.push_back(button);
        std::cout << i << std::endl; //debug
    }
}

ButtonInterface::~ButtonInterface() {
   for(int i = 0; i < BUTTONS; i++) {
        delete interface[i];
    } 
}

Button* ButtonInterface::GetButton(int id) {
    return interface[id];
}