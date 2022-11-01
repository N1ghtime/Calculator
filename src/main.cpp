#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "calculator.hpp"
#include "input.hpp"
#include "output.hpp"

using namespace std;
int main () 
{
    //load button configs
    Button *pButton = ReturnButtonPointer();
    vector<Button *> pButton = load_button_data("button_map.txt");

    char Operator;
    float num1, num2, result;

    cout << "Enter a number for calculation:\n";
    cin >> num1;

    cout << "Enter calculation operator like + (add), - (substract), * (multiply), / (divide), % (modulo):\n";
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
    delete pButton;
    return 0;
}
