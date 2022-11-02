#pragma once
#include "Button.hpp"

class ButtonInterface {
    public:
        ButtonInterface();
        ~ButtonInterface();
        
        Button* GetButton(int);
    
    private:
        std::vector<Button*> interface;
};