#include <iterator>
#include <algorithm>
#include <vector>
#include "ButtonInterface.hpp"
#include "constants.hpp"

// Construct ButtonInterface
ButtonInterface::ButtonInterface() {
    for(int i = 0; i < BUTTONS; i++) {
        interface.push_back(std::make_unique<Button>(i));
        //std::cout << i << std::endl; // DEBUG
    }
    base = DEFAULT_BASE;
    mode = DEFAULT_MODE;
}

// Destructor
ButtonInterface::~ButtonInterface() { } 

Button& ButtonInterface::getButton(int id) {
    return *interface[id];
}

std::string ButtonInterface::getButtonConfiguration(int id) {
    Button b = *interface[id];
    std::string config = b.getConfiguration()[mode];
    return config;
}

int ButtonInterface::getMode() {
    return mode;
}

// Increment mode from every Button.
void ButtonInterface::incrementMode() {
    if (mode < MODES - 1) {
        mode++;
    } else {
        mode = 0;
    }
}

int ButtonInterface::getBase() {
    return base;
}

// Increment base acconrding to "BASES" vector.
void ButtonInterface::incrementBase() {
    // Iterator to current base in the "BASES" vector
    auto itr = std::find(BASES.begin(), BASES.end(), base);
    // Index of the iterator / current base in the "BASES" vector
    int index = std::distance(BASES.begin(), itr);
    if (index < BASES.size() - 1) {
        base = BASES[index + 1];
    } else {
        base = BASES[0];
    }
}