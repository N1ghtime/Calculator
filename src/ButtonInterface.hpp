#pragma once
#include "Button.hpp"
#include <memory>

class ButtonInterface {
    public:
        ButtonInterface();
        ~ButtonInterface();
        
        Button& getButton(int);
        void incrementModes();
    
    private:
        std::vector<std::unique_ptr<Button>> interface;
};