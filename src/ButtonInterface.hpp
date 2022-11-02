#pragma once
#include "Button.hpp"

class ButtonInterface {
    public:
        ButtonInterface();
        ~ButtonInterface();
        
        Button* GetButton(int);
        void incrementModes();
    
    private:
        std::vector<Button*> interface;
};