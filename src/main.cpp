#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

//#include "calculator.hpp"
//#include "input.hpp"
//#include "output.hpp"
#include "constants.hpp"
#include "ButtonInterface.hpp"
#include "Button.hpp"

using namespace std;
int main () 
{
/*     //load button configs
    vector<Button> button_data = load_button_data("button_map.txt");

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
    std::cout << "The value = " << result << endl; */
    ButtonInterface buttonInterface;
    
    for(int i = 0; i < 6; i++) {
        std::cout << "a" <<buttonInterface.GetButton(2).GetConfiguration()[buttonInterface.GetButton(2).GetMode() - 1] << std::endl;
        buttonInterface.GetButton(2).incrementMode();
    }
    
    return 0;
}
