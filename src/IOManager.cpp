/*  Maybe usable?
// get pressed button value from Button class memory
string get_pressed_button(int button_id, vector<Button> buttons_data) {
    int mode = mode_state.get_mode();
    string button_value = buttons_data[button_id].get_value(mode);
    return button_value;
}
*/

#include <iostream>
#include "IOManager.hpp"
#include "ErrorHandler.hpp"

// Constructor
IOManager::IOManager() {
    clearAll();
}

IOManager::~IOManager() { }

void IOManager::write() {
    std::cout   << "+----------------+\n" << "|" ;
    for(int i = 0; i < LCD_COLUMNS; i++) {
    std::cout << display[0][i];
    }
    std::cout << "|\n|";
    for(int i = 0; i < LCD_COLUMNS; i++) {
    std::cout << display[1][i];
    }
    std::cout << "|\n+----------------+" << std::endl;
}

void IOManager::clear() {
    for (int i = 0; i < LCD_COLUMNS-2; i++) {
        display[LCD_ROWS-1][i] = ' ';
    }
    display[LCD_ROWS-1][LCD_COLUMNS-2] = buttoninterface.getBase();
    display[LCD_ROWS-1][LCD_COLUMNS-1] = '0' + buttoninterface.getMode();
}

void IOManager::clearAll() {
    for(int i = 0; i < LCD_ROWS-1; i++) {
        for (int j = 0; j < LCD_COLUMNS; j++) {
            display[i][j] = ' ';
        }
        clear();
    }
    cursor = 0;
}

void IOManager::incrementCursor() {
    if (cursor < LCD_COLUMNS - 2) {
        cursor++;
    }
}

void IOManager::initiate() {
    bool programstatus = true;
    while(programstatus) {
        std::cout << "Enter button ID: 0-" << BUTTONS-1 << std::endl;
        std::string strid;
        std::cin >> strid;
        int id = std::stoi(strid);
        std::string config = buttoninterface.getButtonConfiguration(id);
        std::string previousconfig;
        
        if(isUniversal(config)) {
            if(config == "backspace") {
                for(int i = 0; i < LCD_COLUMNS-1; i++) {
                    if(i = 0) {
                        break;
                    } else if(i = LCD_COLUMNS-2) {
                        display[LCD_ROWS-1][i] == ' ';
                        cursor--;
                        break;
                    } else if(display[LCD_ROWS-1][i] == ' ') {
                        display[LCD_ROWS-1][i-1] = ' ';
                        cursor--;
                        break;
                    }
                }
            } else if (config == "clear") {
                clear();
            } else if (config == "base") {
                buttoninterface.incrementBase();
                clear();
            } else if (config == "mode") {
                buttoninterface.incrementMode();
                 display[LCD_ROWS-1][LCD_COLUMNS-1] = '0' + buttoninterface.getMode();
            } else if (config == "NULL") {
                // Do nothing
            }
            previousconfig = config;
        }

        switch (buttoninterface.getBase())
        {   // BIN
            case 'b':
                if (!isBin(config)) break; // check if pressed button's configuration is viable in BIN mode
                else {
                    
                    break;
                }
            // DEC
            case 'd':
                if (!isDec(config)) break; // check if pressed button's configuration is viable in DEC mode
                if(isInteger(config) && cursor < LCD_COLUMNS-2){
                    // add inputed number to the display
                    display[LCD_ROWS-1][cursor] = config.c_str()[0];
                    incrementCursor();
                } else if(isOperator(config)) {
                    if(config == "+") {
                        
                    } else if(config == "-") {
                        
                    } else if(config == "*") {
                        
                    } else if(config == "/") {
                        
                    } else if(config == "%") {
                        
                    } else if(config == "exp") {
                        
                    } else if(config == "sqrt") {
                        
                    } else if(config == "=") {
                        
                    }
                } else if(config == ".") {

                }
                    break;
            // HEX
            case 'h':
                if (!isHex(config)) break; // check if pressed button's configuration is viable in HEX mode
                else {
                    
                    break;
                }
            
            default:
                // ERROR
                break;
        }
        write();
    }
}