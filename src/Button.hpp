#pragma once
#include <string>
#include <vector>

class Button {
    public:
        Button(int);
        ~Button() = default;

        std::vector<std::string> GetConfiguration();
        void incrementMode();
        int GetMode();
        int GetID();
    
    private:
        std::vector<std::string> configuration;
        int mode;
        int ID;
};