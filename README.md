# Calculator

The physical calculator has buttons for user input and LCD display for displaying output. ATMega328P is used as microcontroller (Arduino Nano)
- Buttons are represented in software with Button class.
- The whole button interface is represented in software with ButtonInterface class. 
- User input is interpreted with InputManager class.
- Calculator class is used for calculating required mathematical operations and storing relevant data for calculations (e.g. input and result)
- Output to LCD display is conducted by OutputManager class

Calculator.ccp
// Inputs from 0 to 9. Mode: operator, number representation etc.  Sel: subcategory for mode (i.e. select correct operator from +,-,*,/ or select number representation from bin, hex, dec)

inputs: num0,num1,num2,num3,num4,num5,num6,num7,num8,num9,mode,sel

logic:
1. sequence of inputs is inserted (i.e. num1 -> + -> num2)
2. execute calculation
3. output as float 

**Programming practise guidelines**
- Keep main branch clean
    - Develop new features in branches
    - Use Pull requests if code is not peer reviewed
    - Merge only working code
- Comment notations
    - TODO: Used when improvements are required
    - DEBUG: Used for code that is used only for debugging purposes
    - ERROR: Used for code that is used for error management
    - Summarize function logic and relevant parts of code with comments
- Use object oriented c++
- Use smart pointers instead of normal pointers
- Create unit tests along new features
- Use "constants.hpp" for constant variables. Avoid hard coding
- Aim for scalability and efficiency in program structure
- Use debugger and valgrind for finding errors and memory leaks
- Use consistent file structure: one .hpp introduces a class and corresponding .cpp defines the functionality
- Use consistent naming practises
    - Name classes starting with capital letter
    - Name functions starting with lowercase with capital separator (camelCase)
    - Name variables mainly lowercase
