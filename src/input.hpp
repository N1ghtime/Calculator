#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Button;

// returns Button class pointer
Button * ReturnButtonPointer();

// loads button data from input file
vector<Button *> load_button_data(string file_name);

// get pressed button value from Button class memory
string get_pressed_button(int button_id, vector<Button *> button);

// checks if input string is an integer
bool isInteger(string line);