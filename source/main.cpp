#include <iostream>
#include <stdio.h>
#include "calculator.hpp"
#include "input.hpp"

int main () 
{
    char Operator;
    float num1, num2, result = 0;

    std::cout << "Enter a number for calculation:\n";
    std::cin >> num1;

    std::cout << "Enter calculation operator like +, -, *, / :\n";
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
        default: std::cout << "Invalid Operator";
    }
    std::cout << "The value = " << result;
    return 0;
}