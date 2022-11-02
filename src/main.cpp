#include <iostream>

//#include "Calculator.hpp"
#include "constants.hpp"
#include "ButtonInterface.hpp"
#include "Button.hpp"

int main () 
{
    // TODO memory debugging

    // Initiate ButtonInterface
    ButtonInterface buttonInterface;
    
    // For testing ButtonInterface and Button 
    for(int i = 0; i < MODES * 2; i++) {
        std::cout <<(*buttonInterface.GetButton(2)).GetConfiguration()[(*buttonInterface.GetButton(2)).GetMode()] << std::endl;
        buttonInterface.incrementModes();
    }
    
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

    return 0;
}
