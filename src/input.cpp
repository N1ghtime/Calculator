#include "input.hpp"

#define BUTTONS 12
#define MODES   3

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
        // loop file, expect first line is header
        string line;
        vector<Button> button(BUTTONS);
        int i;
        for (i=0;i<=BUTTONS;++i)
        {
            // TODO: how to use headers to map data?
            if (i==0) //skip headers
            {
                getline(myfile, line);
            }
            else
            {
            getline(myfile, line);
            // TODO: check if no data on line?
            istringstream ss(line);
            // debug: cout << "Line:" << line << i <<'\n';
            string substr;
            vector<string> substr_val(MODES+1);
                // loop tab delimited columns. expect: id, mode1, mode2, mode3
                int j;
                for (j=0;j<=MODES;++j)
                {
                    getline(ss,substr,'\t');
                    substr_val[j] = substr;
                    // TODO: check if no data found?
                    // debug: cout << "Val:" << substr << j << '\n';
                }
            button[i-1].set_values(substr_val[0],substr_val[1],substr_val[2],substr_val[3]);
            }
        }
        myfile.close();
    }
}