#include "ErrorHandler.hpp"

// This function checks if input string is an integer
bool isInteger(std::string str)
{
    return  (str ==  "0") ||
            (str ==  "1") ||
            (str ==  "2") ||
            (str ==  "3") ||
            (str ==  "4") ||
            (str ==  "5") ||
            (str ==  "6") ||
            (str ==  "7") ||
            (str ==  "8") ||
            (str ==  "9") ;
/*     char* p;
    strtol(str.c_str(), &p, 10);
    return *p == 0; */
}

bool isOperator(std::string str) {
    return  (str ==  "+") ||
            (str ==  "-") ||
            (str ==  "*") ||
            (str ==  "/") ||
            (str ==  "%") ||
            (str ==  "exp") ||
            (str ==  "sqrt") ||
            (str ==  "=");
}

bool isHexChar(std::string str) {
    return  (str ==  "A") ||
            (str ==  "B") ||
            (str ==  "C") ||
            (str ==  "D") ||
            (str ==  "E") ||
            (str ==  "F");
}

bool isUniversal(std::string str) {
    return  (str ==  "backspace") ||
            (str ==  "clear") ||
            (str ==  "base") ||
            (str ==  "mode") ||
            (str ==  "NULL");
}

bool isBin(std::string str) {
    return  isOperator(str) |
            (str ==  "0") ||
            (str ==  "1");
}

bool isDec(std::string str) {
    return  isOperator(str) ||
            isInteger(str) ||
            (str ==  ".") ;
}

bool isHex(std::string str) {
    return  isOperator(str) ||
            isInteger(str) ||
            isHexChar(str);
}