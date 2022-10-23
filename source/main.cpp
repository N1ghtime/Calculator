#include <stdio.h>
#include "input.hpp"
#include <iostream>

int main () 
{
    std::cout << pi;
    char Operator;
    float num1, num2, result = 0;
    printf("Enter any one operator like +, -, *, / :");
    scanf("%c", &Operator);
    printf("Enter values of num1 and num2:");
    scanf("%f%f", &num1, &num2);
    switch(Operator){
        case '+': result = num1 + num2;
            break;
        case '-': result = num1 - num2;
            break;
        case '*': result = num1 * num2;
            break;
        case '/': result = num1 / num2;
            break;
        default: printf("Invalid Operator");
    }
    printf("The value = %f", result);
    return 0;
}