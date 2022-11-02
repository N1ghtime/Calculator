#include <iostream>

//#include "Calculator.hpp"
#include "constants.hpp"
#include "ButtonInterface.hpp"
#include "Button.hpp"

#include "UnitTests.cpp"

#define TESTING_MODE // use for running unit tests, otherwise comment out

int main () 
{
    #ifndef TESTING_MODE // run if TESTING_MODE is not defined
    // TODO memory debugging

    // Initiate ButtonInterface
    ButtonInterface buttonInterface;
    
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
    // For testing ButtonInterface and Button
    bool result1 = TestButtonInterface();
    std::cout << "TestButtonInterface result: " << result1 << std::endl;
    #endif
    return 0;
}
