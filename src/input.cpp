#include "input.hpp"

#define BUTTONS 12
#define MODES   3

//Button class keeps track of button config
class Button {
        int id;
        vector<string> modes;
    public:
        Button(){}
        ~Button(){}
        void set_values (int,vector<string>);
        string get_value(int);
};

typedef vector<Button> buttons_data;

void Button::set_values (int arg1,vector<string> arg2) {id=arg1; modes=arg2;}

string Button::get_value(int arg)
{
    string button_value;
    if (arg == 0)
        button_value = id;
    else if (arg == 1)
        button_value = modes[0];
    else if (arg == 2)
        button_value = modes[1];
    else if (arg == 3)
        button_value = modes[2];
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
    int mode = 1;
    public:
        void increment_mode ();
        int get_mode();
} mode_state;

int Mode::get_mode() {
    return mode;
}
// increments to next mode (same as pressing mode would do)
void Mode::increment_mode () {
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
vector<Button> load_button_data(string file_name) {
    ifstream myfile (file_name);
    vector<Button> buttons_data(BUTTONS);
    if (!myfile.is_open())
    {
        cout << "Error, could not open file: " << file_name << endl;
    }
    else
    {
        // loop file, expect first line is header
        string line;
        for (int i=0; i <= BUTTONS; i++)
        {
            getline(myfile, line,'\n');
            // TODO: check if no data on line?
            istringstream ss(line);
            // debug: cout << "Line:" << line << i <<'\n';
            string substr;
            vector<string> headers(MODES+1);
            vector<string> button_values(MODES);
            int idx;
            if (i > 0) //skip headers
            {
                // loop tab delimited columns. expect: id, mode1, mode2, mode3
                for (int j=0; j <= MODES; j++)
                {
                    getline(ss,substr,'\t');
                    if (j > 0) // button values
                    {
                        button_values[j-1] = substr;
                        // TODO: check if no data found?
                        // debug: cout << "Val:" << substr << j << '\n';
                    }
                    else // j==0, button id
                    {
                        if (isInteger(substr) == true)
                            int idx = stoi(substr);
                        else
                            cout << "Error in " << file_name << ". " << substr << " under header " << headers[j] << " is not an integer." << endl;
                    }
                }
            buttons_data[i-1].set_values(idx,button_values);
            }
            else
            {
                // save headers: loop tab delimited columns for header row: id, mode1, mode2, mode3
                for (int k=0; k <= MODES; k++)
                {
                    getline(ss,substr,'\t');
                    headers[k] = substr;
                }
            }
        }
        myfile.close();
    }
    return buttons_data;
}

// get pressed button value from Button class memory
string get_pressed_button(int button_id, vector<Button> buttons_data) {
    int mode = mode_state.get_mode();
    string button_value = buttons_data[button_id].get_value(mode);
    return button_value;
}