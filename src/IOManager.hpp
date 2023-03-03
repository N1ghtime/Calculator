// TODO
/* Pseudocode
input
- Able to receive button input data as one button press at the time, data is stored in a "button_pressed" variable. Find Button's active configuration
- Keeps in store a "print_row1" and "print_row2" variables which are printed to LCD row 1 and 2 correspondingly 
- Class stores received buttons active configuration's data into temporary vector<std::string> "input_data_vector", update vector with every added input
    - if button's active configuration is "NULL"
        - do nothing
    - if button's active configuration is "backspace"
        - remove last element from "input_data vector" std::vector::pop_back
    - if button's active configuration is "clear"
        - empty whole "input_data_vector" = {""}
    - if button's active configuration is "base"
        - increment numeral base
    - if button's active configuration is an operator
        - try to add corresponding operator to "input_data_vector"
    - if button's active configuration is a number
        - try to add corresponding number to "input_data_vector"
    - if button's active configuration is "."
        try to add "." to "input_data_vector"
    - if button's active configuration is "="
        - pass first number, operator and second number to Calculator
    - if button's active configuration is "mode"
        - increment mode
- When "input_data_vector" has updated with valid data, store it to "print_row2" 
    - "input_data_vector" is displayed in the bottom part of the screen as current input "print_row1"
    - Display refreshes after every input
- When operator is inputed, "input_data_vector" with data for the first number is combined and stored to separate string variable in corresponding number base.
    - "input_data_vector" is cleared
    - if multiple operators are inputed in a row, stored operator is overwrited
- If a number has been previously stored, an non number input must follow (otherwise no action is performed)
- When a number is inputed after an operator, the operator in "input_data_vector" is stored to separate string variable
- if the operator is "sqrt" or "exp", use Calculator class to perform sqrt or exp
    - "input_data_vector" is cleared
- Receive result data from Calculator and store it to "print_row2"

DEC (base-10)
- e.g. vector [2, 2, 3] is stored as string 223 (Base-10)
- Able to receive only numbers 0-9, ".", "e" and operators
    - Does not update vector if multiple "." are inputed in a row
    - Can not input "." as a first input item

HEX (base-16) //TODO add A-F configurations to button_map.txt
- e.g. vector [2, A, A, F] is stored as string 2AAF (Base-16)
- Able to receive only 0-9, A-F and operators

BIN (base-2)
- e.g. vector [0, 1, 1] is stored as string 011 (Base-2)
- Able to receive only 0, 1 and operators

Output
- Use e.g. LiquidCrystal library to operate LCD
- Print "print_row1" and "print_row2" after every input
    - row 1: result
    - row 2: current input
        - Print currently active base and mode to lower right corner e.g. (D1 = base-10, mode 1)
 */
#include <string>
#include "constants.hpp"
#include "ButtonInterface.hpp"
class IOManager {
    public:
        IOManager();
        ~IOManager();
        void write();
        void clear();
        void clearAll();
        void initiate();
        void incrementCursor();

    private:
         // 2D array (rows and columns/cells) simulates LCD display.
         // display[LCD_ROWS-1] (last rowindex) indicates input row
         // display[LCD_ROWS-2] (second last rowindex) indicates result row: stores number which indicates calculation result or recently added input
        char display[LCD_ROWS][LCD_COLUMNS];
        int cursor; // indicates location of next available index in display input row 
        ButtonInterface buttoninterface; // buttoninterface constructor is called with IOManager constructor
        // when operation is activated
        // if input row is empty, store result row to num1
        // else store input row to num2 and result row to num1
        double num1; // stores first number used in calculations
        double num2; // stores second number used in calculations 
        bool operationactive; // is operation (+, -, etc..) active
        double result; // store result
        std::string operation;
};