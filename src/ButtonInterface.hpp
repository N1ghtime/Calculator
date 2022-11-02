#pragma once
#include "Button.hpp"

class ButtonInterface {
    public:
        ButtonInterface();
        ~ButtonInterface() = default;
        
        Button GetButton(int);
    
    private:
        std::vector<Button> interface;
};