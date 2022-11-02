#include "Button.hpp"
#include "constants.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

// Constructor:
// 1. Initializes button mode to default
// 2. Loads button ID and button configuration
Button::Button(int id) {
    mode = DEFAULT_MODE;
    int row = 0;
    // Search desired row by ID to "line" 
    std::string line;
    std::ifstream button_map ("button_map.txt");
    if(!button_map) std::cout << "could not open: button_map.txt" << std::endl;
    while (row <= id + 1) {
        std::getline(button_map, line);
        row++;
    }

    // Load ID and configuration to vector "configuration"
    size_t pos = 0;
    while ((pos = line.find(FILE_DELIMETER)) != std::string::npos) {
        configuration.push_back(line.substr(0, pos));
        line.erase(0, pos + 1);
    }
    configuration.push_back(line);

    // Load ID to "ID"
    if (id != stoi(configuration[0])) {
        std::cout << "Mismaching id:s - " << id << std::endl;
    } else {
        ID = id;
    }
    // Erase ID from "configuration"
    configuration.erase(configuration.begin());

    button_map.close();
}

std::vector<std::string> Button::GetConfiguration() {
    return configuration;
}

// Increment mode. If mode tries to increment over max mode, reset mode to default.
void Button::incrementMode() {
    if (mode < MODES) {
        this->mode++;
    } else {
        this->mode = DEFAULT_MODE;
    }
}

int Button::GetMode() {
    return mode;
}

int Button::GetID() {
    return ID;
}