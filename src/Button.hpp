#pragma once
#include <string>
#include <vector>

class Button {
    public:
        Button(int);
        ~Button() = default;

        std::vector<std::string> getConfiguration();
    
    private:
        std::vector<std::string> configuration;
        int buttonid;
};