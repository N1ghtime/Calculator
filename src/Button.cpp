#include "Button.hpp"
#include "constants.hpp"
#include <fstream>
#include <iostream> // ERROR, DEBUG

// Constructor:
// 1. Initializes button mode to default
// 2. Loads button ID and button configuration
Button::Button(int id) {
    // Set mode to default
    mode = DEFAULT_MODE;
    
    std::string line;
    std::ifstream button_map (FILE_PATH);
    if(!button_map) std::cout << "could not open: " << FILE_PATH << std::endl; // ERROR
    
    // Search desired row by ID to "line". Parse first row to "headers". 
    // TODO Is there more efficient way?
    int row = 0;
    std::vector<std::string> headers;
    while (row <= id + 1) {
        std::getline(button_map, line);
        if (row == 0) {
            // Parse first row into vector "headers"
            size_t pos = 0;
            while ((pos = line.find(FILE_DELIMETER)) != std::string::npos) {
                headers.push_back(line.substr(0, pos));
                line.erase(0, pos + FILE_DELIMETER.size());
            }
            headers.push_back(line);
        }
        row++;  
    }
 
    // TODO search row according to id instead of row index. Currently this is not working correctly 
    /*
    bool row_found = false;
    while (!row_found) {
        std::getline(button_map, line);
        size_t pos = line.find(FILE_DELIMETER);
        if (stoi(line.substr(0, pos)) == id) {
            row_found = true;
        }
    }
    */
    // Load ID and configuration to vector "configuration"
    // TODO Is this more efficient than opening stringstream and using getline?
    // TODO Error management for id. Function isInteger?
    // TODO Use "headers" vector in error handling. NOTE: headers[0] = "INPUT_ID", headers[1] = "MODE_1" etc.
    size_t pos = 0;
    int column = 0;
    while ((pos = line.find(FILE_DELIMETER)) != std::string::npos) {
        configuration.push_back(line.substr(0, pos));
        line.erase(0, pos + FILE_DELIMETER.size());
        column++;
    }
    configuration.push_back(line);

    // Load ID to "ID"
    if (id != stoi(configuration[0])) {
        std::cout << "Mismaching id:s - " << id << std::endl; // ERROR
    } else {
        ID = id;
    }
    // Erase ID from "configuration"
    configuration.erase(configuration.begin());

    button_map.close();
}

std::vector<std::string> Button::getConfiguration() {
    return configuration;
}

// Increment mode. If mode tries to increment over max mode, reset mode to 0.
void Button::incrementMode() {
    if (mode < MODES - 1) {
        mode++;
    } else {
        mode = 0;
    }
}

int Button::getMode() {
    return mode;
}

int Button::getID() {
    return ID;
}