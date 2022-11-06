# Calculator

The physical calculator has buttons for user input and LCD display for displaying output. ATMega328P is used as microcontroller (Arduino Nano)
- Buttons are represented in software with Button class.
- The whole button interface is represented in software with ButtonInterface class. 
- User input and output is managed with IOManager class.
- Calculator class is used for calculating required mathematical operations.
- ErrorHandler is used for errors. UnitTests are used for testing features.

Calculator has n buttons (ID 0 ... n-1). Default n = 12.
Buttons have n modes (0 ... n-1). Default n = 3
Each mode may have up to n configurations
Button configuration is loaded from a .txt file

logic:
1. sequence of inputs is inserted using physical buttons (i.e. num1 -> + -> num2)
2. software interprets input and executes calculation accordingly
3. LCD display is used to display result, current input, current mode and active number base 

## Programming practise guidelines
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
