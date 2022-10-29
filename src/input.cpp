#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct input_map_data {
        string id;
        string mode_1;
        string mode_2;
        string mode_3;
    };

int load_input_map(string file_name) {

    streampos file_size;
    char * memblock;
    string line;
    //set position to end of file
    ifstream myfile (file_name);
    if (!myfile.is_open())
    {
        cout << "Error, could not open file: " << file_name << endl;
        return -1;
    }
    file_size = myfile.tellg();
    memblock = new char [file_size];
    myfile.seekg(0,ios::beg);
        while (getline(myfile, line))
        {
            cout << line << '\n';
        }
        myfile.close();
        return 1;
}