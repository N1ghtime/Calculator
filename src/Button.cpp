#include "Button.hpp"
#include "constants.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

// Constructor:
// 1. Initializes button mode to default
// 2. Loads buttons id and button configuration
Button::Button(int id) {
    mode = DEFAULT_MODE;
    int row = 0;
    // Search row by id
    std::string line;
    std::ifstream button_map ("button_map.txt");
    if(!button_map) std::cout << "could not open: button_map.txt" << std::endl;
    while (row <= id) {
        std::getline(button_map, line);
    }
    // Load first character to ID 
    if (stoi(line.substr(0, 1)) == id) {
        ID = stoi(line.substr(0, 1));
    } else {
        std::cout << "Mismaching id:s - " << id << std::endl;
    }
    // Erase ID and first delimeter
    line.erase(0, 2);
    // Load button configuration separated by delimeter 
    size_t pos = 0;
    while (pos = line.find(FILE_DELIMETER) != std::string::npos) {
        configuration.push_back(line.substr(0, pos));
        line.erase(0, pos + 1);
    }
}

std::vector<std::string> Button::GetConfiguration() {
    return configuration;
}

void Button::incrementMode() {
    if (mode < MODES) {
        mode++;
    } else {
        mode = 0;
    }
}

int Button::GetMode() {
    return mode;
}

int Button::GetID() {
    return ID;
}