#include "ButtonInterface.hpp"
#include "Button.hpp"
#include "constants.hpp"
#include <iostream>

//Construct ButtonInterface
ButtonInterface::ButtonInterface() {
    for(int i = 0; i < BUTTONS; i++) {
        interface.push_back(Button(i));
    }
}

Button ButtonInterface::GetButton(int id) {
    return interface[id];
}