#pragma once
#include <memory>
#include "Button.hpp"

class ButtonInterface {
    public:
        ButtonInterface();
        ~ButtonInterface();
        
        
        std::string getButtonConfiguration(char);
        int getMode();
        char getBase();
        void incrementMode();
        void incrementBase();
    
    private:
        Button& getButton(int);
        std::vector<std::unique_ptr<Button>> interface;
        int mode;
        char base;
};