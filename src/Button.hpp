#pragma once
#include <string>
#include <vector>

class Button {
    public:
        Button(int);
        ~Button() = default;

        std::vector<std::string> getConfiguration();
        void incrementMode();
        int getMode();
        int getID();
    
    private:
        std::vector<std::string> configuration;
        int mode;
        int ID;
};

/* mode and increment mode to parent class? */