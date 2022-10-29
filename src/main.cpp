#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "calculator.hpp"
#include "input.cpp"
#include "output.hpp"

using namespace std;
int main () 
{
    //load configs
    load_input_map("input_map.txt");
    char Operator;
    float num1, num2, result;

    cout << "Enter a number for calculation:\n";
    cin >> num1;

    cout << "Enter calculation operator like +, -, *, / :\n";
    cin >> Operator;

    cout <<"Enter a number for calculation:\n";
    cin >> num2;

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
    std::cout << "The value = " << result << endl;
    return 0;
}
