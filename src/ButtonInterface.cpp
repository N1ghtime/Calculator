#include "ButtonInterface.hpp"
#include "constants.hpp"
//#include <iostream> //DEBUG

// Construct ButtonInterface
ButtonInterface::ButtonInterface() {
    for(int i = 0; i < BUTTONS; i++) {
        interface.push_back(std::make_unique<Button>(i));
        //std::cout << i << std::endl; // DEBUG
    }
}

// Destructor
ButtonInterface::~ButtonInterface() { } 

Button& ButtonInterface::getButton(int id) {
    return *interface[id];
}

// Increment mode from every Button.
void ButtonInterface::incrementModes() {
    for(int i = 0; i < BUTTONS; i++) {
        interface[i]->incrementMode();
    }
}