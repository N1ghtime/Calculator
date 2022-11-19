#include <string>
#include <array>

#include "UnitTests.hpp"

#define ITERATIONS 6

bool TestButtonInterfaceMode () {
    // initialize
    std::array<std::string, ITERATIONS> reference = {"9", "backspace", "NULL", "9", "backspace", "NULL"}; // expected results
    std::array<std::string, ITERATIONS> output {};
    bool result = false;
    ButtonInterface buttonInterface;
    // test
    for(int i = 0; i < ITERATIONS; i++) {
        output[i] = buttonInterface.getButtonConfiguration(2);
        // std::cout << output[i] << std::endl; // DEBUG
        buttonInterface.incrementMode();
    }
    // check results
    if (reference == output)
        result = true;

    return result;
}

bool TestButtonInterfaceBase () {
    // initialize
    std::array<char, ITERATIONS> reference = {'d', 'h', 'b', 'd', 'h', 'b'}; // expected results
    std::array<char, ITERATIONS> output {};
    bool result = false;
    ButtonInterface buttonInterface;
    // test
    for(int i = 0; i < ITERATIONS; i++) {
        output[i] = buttonInterface.getBase();
        std::cout << output[i] << std::endl; // DEBUG
        buttonInterface.incrementBase();
    }
    // check results
    if (reference == output)
        result = true;

    return result;
}