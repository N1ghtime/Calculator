/*  Maybe usable?
// get pressed button value from Button class memory
string get_pressed_button(int button_id, vector<Button> buttons_data) {
    int mode = mode_state.get_mode();
    string button_value = buttons_data[button_id].get_value(mode);
    return button_value;
}
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <cmath>
#include <bitset>
#include "IOManager.hpp"
#include "ErrorHandler.hpp"

// Constructor
IOManager::IOManager() {
    clearAll();
}

IOManager::~IOManager() { }

// Simulates 16x2 display in terminal
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

// Clear input row and reset cursor. Does not reset base or mode.
void IOManager::clear() {
    for (int i = 0; i < LCD_COLUMNS-2; i++) {
        display[LCD_ROWS-1][i] = ' ';
    }
    display[LCD_ROWS-1][LCD_COLUMNS-2] = buttoninterface.getBase();
    display[LCD_ROWS-1][LCD_COLUMNS-1] = '0' + buttoninterface.getMode();
    cursor = 0;
    operationactive = false;
}

// Clear display and calculator memory
void IOManager::clearAll() {
    for(int i = 0; i < LCD_ROWS-1; i++) {
        for (int j = 0; j < LCD_COLUMNS; j++) {
            display[i][j] = ' ';
        }
        num1 = NAN;
        num2 = NAN;
        operationactive = false;
        result = NAN;
        clear();
    }
}

// Increment cursor. Does not increment to space reserved for base and mode
void IOManager::incrementCursor() {
    if (cursor < LCD_COLUMNS - 2) {
        cursor++;
    }
}

// Calculator program loop
void IOManager::initiate() {
    write();
    bool programstatus = true;
    while(programstatus) {
        // Ask button id and find the active configuration
        std::cout << "Enter button ID: 0-" << BUTTONS-1 << " ('q' = quit)" << std::endl;
        std::string strid;
        std::cin >> strid;
        // if 'q' is given, quit program.
        if(strid == "q") {
            programstatus = false;
            break;
        }
        int id = std::stoi(strid); //TODO ERROR, Catch stoi exception. Allow only id: 0...BUTTONS-1
        std::string config = buttoninterface.getButtonConfiguration(id);
        
        // Act accordnigly with universal configurations (available always)
        if(isUniversal(config)) {
            if(config == "backspace") {
                if(cursor != 0) {
                    display[LCD_ROWS-1][cursor-1] = ' ';
                    cursor--;
                }
                if(operationactive) operationactive = false;
            } else if (config == "clear") {
                clearAll();
            } else if (config == "base") {
                buttoninterface.incrementBase();
                clearAll(); // TODO clear only input row, change result to new base
            } else if (config == "mode") {
                buttoninterface.incrementMode();
                display[LCD_ROWS-1][LCD_COLUMNS-1] = '0' + buttoninterface.getMode();
            } else if(config == ".") {
                // Check if '.' is already in input. More than one '.' is not allowed
                bool dot_already = false;
                for(int i = 0; i < LCD_COLUMNS-2; i++) {
                    if(display[LCD_ROWS-1][i] == '.') dot_already = true;
                }
                // add '.' to cursor. '.' can't start a number.
                if((cursor < LCD_COLUMNS-2) && (cursor > 0) && !dot_already) { // TODO allow to start number with "."
                    display[LCD_ROWS-1][cursor] = '.';
                    incrementCursor();
                }
            } else if (config == "NULL") { // TODO efficiency
                // Do nothing
            }
        }

        // Act according to configuration. Active base is considered
        switch (buttoninterface.getBase())
        {   // Binary base
            case 'b':
                if (!isBin(config)) break; // check if pressed button's configuration is viable in BIN mode
                if (((config == "0") | (config == "1")) && (cursor < LCD_COLUMNS-2)) {
                    // Add binary number to display according to cursor location
                    display[LCD_ROWS-1][cursor] = config.c_str()[0];
                    incrementCursor();
                }
                if((isOperator(config) || operationactive) && ((display[LCD_ROWS-1][0] != ' ') || (display[LCD_ROWS-2][0] != ' '))) {
                    if(!operationactive) {
                        // if result row is empty, store input row to result row and num1
                        if(display[LCD_ROWS-2][0] == ' ') {
                            
                            char tempinput[LCD_COLUMNS-2];
                            std::copy(display[LCD_ROWS-1], display[LCD_ROWS-1] + LCD_COLUMNS-2, tempinput);
                            num1 = 0b0 + atof(tempinput);
                            result = num1;

                        // else if result row is not empty store input row to num2 and result row to num1
                        } else if (display[LCD_ROWS-2][0] != ' ') {
                            char tempinput[LCD_COLUMNS-2];
                            std::copy(display[LCD_ROWS-1], display[LCD_ROWS-1] + LCD_COLUMNS-2, tempinput);
                            num2 = 0b0 + atof(tempinput);

                            char displaycopy[LCD_ROWS-1][LCD_COLUMNS];
                            std::copy(display[LCD_ROWS-2], display[LCD_ROWS-2] + LCD_COLUMNS, displaycopy[LCD_ROWS-2]);
                            num1 = 0b0 + atof(displaycopy[LCD_ROWS-1]);
                            result = num1;
                        }
                    } else {
                        if(isnan(num2)){
                            // store input row to num2
                            char tempinput[LCD_COLUMNS-2];
                            std::copy(display[LCD_ROWS-1], display[LCD_ROWS-1] + LCD_COLUMNS-2, tempinput);
                            num2 = 0b0 + atof(tempinput);
                        }
                    }
                    if(isOperator(config)) operation = config; 
                    // display operator
                    clear();
                    for (int i = 0; i < operation.size(); i++) {
                        display[LCD_ROWS-1][i] = operation.c_str()[i];
                    }
                    write();
                    clear();
                    operationactive = true;

                if((operation == "+") && (!isnan(num1) && !isnan(num2))) {
                    // TODO fix
                    // sum num1 and num2. reset num1 and num2. store sum to result
                    int  n1 = 0b0 + int(num1);
                    int n2 = 0b0 + int(num2);
                    while(n1 != 0) {
                        int temp = n1 & n2;
                        n2 = n1 ^ n2;
                        temp = temp << 1;
                        n1 = temp;
                    }
                    result = n2;
                    num1 = NAN;
                    num2 = NAN;
                    operationactive = false;

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
                } 
            
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
        // Format result to char array and write it to result row (for display purposes)
        if(!isnan(result)){
            std::string res = std::to_string(result);
            for (int i = 0; i < res.size(); i++) {
                display[LCD_ROWS-2][i] = res.c_str()[i];
            }
        }
        
        // Update display
        write();

    }
}