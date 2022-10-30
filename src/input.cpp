#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Button {
        string id;
        string mode1;
        string mode2;
        string mode3;
    public:
        void set_values (string,string,string,string);
};

void Button::set_values (string arg1,string arg2,string arg3,string arg4) {id=arg1; mode1=arg2; mode2=arg3; mode3=arg4;}

void load_button_data(string file_name) {
    ifstream myfile (file_name);
    if (!myfile.is_open())
    {
        cout << "Error, could not open file: " << file_name << endl;
    }
    else
    {
        // loop file, expect 13 lines (first one is headers)
        string line;
        vector<Button> button(12);
        int i;
        for (i=0;i<13;i++)
        {
            // TODO: how to use headers to map data?
            if (i!=0)
            {
                //skip headers
            }
            else
            {
            getline(myfile, line);
            // TODO: check if no data on line?
            istringstream ss(line);
            string substr;
            vector<string> substr_val(4);
                // loop tab delimited columns. expect: id, mode1, mode2, mode3
                int j;
                for (j=0;j<4;j++)
                {
                    getline(ss,substr,'\t');
                    substr_val[j] = substr;
                    // TODO: check if no data found?
                    cout << substr << '\n';
                }
                button[i].set_values(substr_val[0],substr_val[1],substr_val[2],substr_val[3]);
            }
        }
        myfile.close();
    }
}