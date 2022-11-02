#include "ButtonInterface.hpp"
#include "constants.hpp"
//#include <iostream> //DEBUG

// Construct ButtonInterface
ButtonInterface::ButtonInterface() {
    for(int i = 0; i < BUTTONS; i++) {
        Button* button = new Button(i);
        interface.push_back(button);
        //std::cout << i << std::endl; // DEBUG
    }
}

// Destructor: frees allocated memory
ButtonInterface::~ButtonInterface() {
   for(int i = 0; i < BUTTONS; i++) {
        delete interface[i];
    } 
}

Button* ButtonInterface::GetButton(int id) {
    return interface[id];
}

// Increment mode from every Button.
void ButtonInterface::incrementModes() {
    for(int i = 0; i < BUTTONS; i++) {
        interface[i]->IncrementMode();
    }
}