#include <string>
#include <array>

#include "UnitTests.hpp"

#define ITERATIONS 6

bool TestButtonInterface () {
    // initialize
    std::array<std::string, ITERATIONS> reference = {"9", "backspace", "NULL", "9", "backspace", "NULL"}; // expected results
    std::array<std::string, ITERATIONS> output {};
    bool result = false;
    ButtonInterface buttonInterface;
    // test
    for(int i = 0; i < ITERATIONS; i++) {
        output[i] = (*buttonInterface.GetButton(2)).GetConfiguration()[(*buttonInterface.GetButton(2)).GetMode()];
        // std::cout << output[i] << std::endl; // DEBUG
        (*buttonInterface.GetButton(2)).IncrementMode();
    }
    // check results
    if (reference == output)
        result = true;

    return result;
}