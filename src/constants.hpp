#pragma once
#include <string>
#include <vector>

static const int BUTTONS = 12;
static const int MODES = 3;
static const int DEFAULT_MODE = 0;
static const std::vector<int> BASES = {2, 10, 16};  // BIN (Base-2), DEC (Base-10), HEX (Base-16)
static const int DEFAULT_BASE = 10;
static const std::string FILE_DELIMETER = "\t";
static const std::string FILE_PATH = "../config/button_map.txt";