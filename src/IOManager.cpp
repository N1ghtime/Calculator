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
    cursor = 0;
}

void IOManager::clearAll() {
    for(int i = 0; i < LCD_ROWS-1; i++) {
        for (int j = 0; j < LCD_COLUMNS; j++) {
            display[i][j] = ' ';
        }
        clear();
    }
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
        // if 'q' is given, quit program.
        if(strid == "q") {
            programstatus = false;
            break;
        }
        int id = std::stoi(strid);
        std::string config = buttoninterface.getButtonConfiguration(id);
        
        if(isUniversal(config)) {
            if(config == "backspace") {
                if(cursor != 0) {
                    display[LCD_ROWS-1][cursor-1] = ' ';
                    cursor--;
                }
            } else if (config == "clear") {
                clear();
            } else if (config == "base") {
                buttoninterface.incrementBase();
                clearAll();
            } else if (config == "mode") {
                buttoninterface.incrementMode();
                display[LCD_ROWS-1][LCD_COLUMNS-1] = '0' + buttoninterface.getMode();
            } else if (config == "NULL") {
                // Do nothing
            }
        }

        switch (buttoninterface.getBase())
        {   // BIN
            case 'b':
                if (!isBin(config)) break; // check if pressed button's configuration is viable in BIN mode
                if (((config == "0") | (config == "1")) && (cursor < LCD_COLUMNS-2)) {
                    display[LCD_ROWS-1][cursor] = config.c_str()[0];
                    incrementCursor();
                    break;
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
                }
                    break;
            // DEC
            case 'd':
                if (!isDec(config)) break; // check if pressed button's configuration is viable in DEC mode
                if(isInteger(config) && cursor < LCD_COLUMNS-2){
                    // add inputed number to the display
                    display[LCD_ROWS-1][cursor] = config.c_str()[0];
                    incrementCursor();
                    break;
                } else if(isOperator(config)) { // TODO
                    if(config == "+") {
                        
                    } else if(config == "-") {
                        
                    } else if(config == "*") {
                        
                    } else if(config == "/") {
                        
                    } else if(config == "%") {
                        
                    } else if(config == "exp") {
                        
                    } else if(config == "sqrt") {
                        
                    } else if(config == "=") {
                        
                    }
                    break;
                } else if(config == ".") {
                    // Check if '.' is already in input. More than one '.' is not allowed
                    bool dotalready = false;
                    for(int i = 0; i < LCD_COLUMNS-2; i++) {
                        if(display[LCD_ROWS-1][i] == '.') dotalready = true;
                    }
                    if((cursor < LCD_COLUMNS-2) && (cursor > 0) && !dotalready) {
                        display[LCD_ROWS-1][cursor] = '.';
                        incrementCursor();
                    }
                }
                break;
            // HEX
            case 'h':
                if (!isHex(config)) break; // check if pressed button's configuration is viable in HEX mode
                if(isInteger(config) && cursor < LCD_COLUMNS-2){
                    // add inputed number to the display
                    display[LCD_ROWS-1][cursor] = config.c_str()[0];
                    incrementCursor();
                    break;
                } else if(isHexChar(config) && cursor < LCD_COLUMNS-2){
                    // add inputed hexchar to the display
                    display[LCD_ROWS-1][cursor] = config.c_str()[0];
                    incrementCursor();
                    break;
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
                }
                break;
            
            default:
                // ERROR
                break;
        }
        // Update display
        write();
        }
}