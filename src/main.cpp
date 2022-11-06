#include <iostream>

//#include "Calculator.hpp"
#include "constants.hpp"
#include "ButtonInterface.hpp"
#include "Button.hpp"

#include "UnitTests.cpp"

// #define TESTING_MODE // use for running unit tests, otherwise comment out

int main () 
{
    #ifndef TESTING_MODE // run if TESTING_MODE is not defined
    // TODO memory debugging

    // Initiate ButtonInterface
    ButtonInterface buttonInterface;
    
    // Initiate Calculator
    // Calculator calculator;

    // Initiate IOManager
    // InputManager ioManager;
    
    /* Pseudocode/draft for the loop 
    loop{
        button_voltage = analogRead(pin_with_button_circuit);
        if (button_voltage >= b1 && button_voltage <= b1) {             // b1 = voltage range for button 1
            // Pass BUTTON1 to ioManager 
        } else if (button_voltage >= b2 && button_voltage <= b2) {      // b2 = voltage range for button 2
            // Pass BUTTON2 to ioManager
        }
            ...
            ...                                                         // b3...b11
            ...
        
        } else if (button_voltage >= b12 && button_voltage <= b12) {     //b12 = voltage range for button 12
            // Pass BUTTON12 to ioManager
        } else {
            // No button pressed, do nothing
        }
    }
    
     */

    /*  
    // TODO implement working "Calculator" class and move/redo calculator logic there  
    char Operator;
    float num1, num2, result;

    std::cout << "Enter a number for calculation:\n";
    std::cin >> num1;

    std::cout << "Enter calculation operator like + (add), - (substract), * (multiply), / (divide), % (modulo):\n";
    std::cin >> Operator;

    std::cout <<"Enter a number for calculation:\n";
    std::cin >> num2;

    switch(Operator){
        case '+': result = calculate_add(num1, num2);
            break;
        case '-': result = calculate_substract(num1, num2);
            break;
        case '*': result = calculate_multiply(num1, num2);
            break;
        case '/': result = calculate_divide(num1, num2);
            break;
        case '%': result = calculate_modulo(num1, num2);
            break;
        default: std::cout << "Invalid Operator";
    }
    std::cout << "The value = " << result << std::endl;
    */
    #else
    // For testing ButtonInterface: incrementMode
    bool result1 = TestButtonInterfaceMode();
    std::cout << "TestButtonInterfaceMode result: " << result1 << std::endl;

    // For testing ButtonInterface: incrementBase
    bool result2 = TestButtonInterfaceBase();
    std::cout << "TestButtonInterfaceBase result: " << result2 << std::endl;
    #endif
    return 0;
}