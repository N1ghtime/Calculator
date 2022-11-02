
// For testing ButtonInterface and Button 
#include <array>

bool TestButtonInterface () {
    // initialize
    std::array<std::string, 6> reference = {"8", "backspace", "NULL", "9", "backspace", "NULL"}; // expected results
    std::array<std::string, 6> output {};
    bool result = false;
    ButtonInterface buttonInterface;
    // test
    for(int i = 0; i < (MODES * 2); i++) {
        output[i] = (*buttonInterface.GetButton(2)).GetConfiguration()[(*buttonInterface.GetButton(2)).GetMode()];
        // std::cout << output[i] << std::endl; // DEBUG
        (*buttonInterface.GetButton(2)).IncrementMode();
    }
    // check results
    if (reference == output)
        result = true;

    return result;
}