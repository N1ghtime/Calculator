#include "input.hpp"

#define BUTTONS 12
#define MODES   3

//Button class keeps track of button config
class Button {
        string id;
        string mode1;
        string mode2;
        string mode3;
    public:
        void set_values (string,string,string,string);
        string get_value(int);
};

void Button::set_values (string arg1,string arg2,string arg3,string arg4) {id=arg1; mode1=arg2; mode2=arg3; mode3=arg4;}

string Button::get_value(int arg)
{
    string button_value;
    if (arg == 0)
        button_value = id;
    else if (arg == 1)
        button_value = mode1;
    else if (arg == 2)
        button_value = mode2;
    else if (arg == 3)
        button_value = mode3;
    else
        cout << "Error:  " << arg << " is not member of Button class.";
    return button_value;
}

Button * ReturnButtonPointer()
{
    Button * pButton = new Button();
    return pButton;
}

//Mode class keeps track of mode state
class Mode {
    int mode;
    public:
        void set_mode (int);
        int get_mode();
} mode_state;

int Mode::get_mode() {
    return mode;
}

void Mode::set_mode (int mode) {
    if (get_mode() < MODES)
    {
        mode=get_mode()+1;
    }
    else
    {
        mode=1;
    }
}

// This function checks if input string is an integer
bool isInteger(string line)
{
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

// This function loads button data from file to Button class
vector<Button *> load_button_data(string file_name) {
    ifstream myfile (file_name);
    if (!myfile.is_open())
    {
        cout << "Error, could not open file: " << file_name << endl;
    }
    else
    {
        // loop file, expect first line is header
        string line;
        vector<Button *> button(BUTTONS);
        for (int i=0;i<=BUTTONS;++i)
        {
            getline(myfile, line);
            // TODO: check if no data on line?
            istringstream ss(line);
            // debug: cout << "Line:" << line << i <<'\n';
            string substr;
            vector<string> headers(MODES+1);
            vector<string> substr_val(MODES+1);
            if (i>0) //skip headers
            {
                // loop tab delimited columns. expect: id, mode1, mode2, mode3
                for (int j=0;j<=MODES;++j)
                {
                    getline(ss,substr,'\t');
                    if (j>0)
                    {
                        substr_val[j] = substr;
                        // TODO: check if no data found?
                        // debug: cout << "Val:" << substr << j << '\n';
                    }
                    else
                    {
                        if (isInteger(substr)==true)
                            int idx = stoi(substr);
                        else
                            cout << "Error in " << file_name << ". " << substr << " under header " << headers[j] << " is not an integer." << endl;
                    }
                }
            button[i-1]->set_values(substr_val[0],substr_val[1],substr_val[2],substr_val[3]);
            }
            else
            {
                // save headers: loop tab delimited columns for header row: id, mode1, mode2, mode3
                for (int k=0;k<=MODES;++k)
                {
                    getline(ss,substr,'\t');
                    headers[k] = substr;
                }
            }
        }
        myfile.close();
        // Set initial mode to 1
        mode_state.set_mode(1);
        return button;
    }
}

// get pressed button value from Button class memory
string get_pressed_button(int button_id, vector<Button *> button) {
    int mode = mode_state.get_mode();
    string button_value = button[button_id]->get_value(mode);
    return button_value;
}