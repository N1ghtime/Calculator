# Calculator

Calculator takes inputs from buttons. Input is handled by function input.cpp
Calculator.ccp will handle logic from input to output.
Output is produced to LED screen and its handled by function output.cpp.

Calculator.ccp
// Inputs from 0 to 9. Mode: operator, number representation etc.  Sel: subcategory for mode (i.e. select correct operator from +,-,*,/ or select number representation from bin, hex, dec)

inputs: num0,num1,num2,num3,num4,num5,num6,num7,num8,num9,mode,sel

logic:
1. sequence of inputs is inserted (i.e. num1 -> + -> num2)
2. execute calculation
3. output as float 
