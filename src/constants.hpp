#pragma once
#include <string>
#include <vector>

static const int BUTTONS = 12;
static const int MODES = 3;
static const char DEFAULT_MODE = 0;
static const std::vector<char> BASES = {'b', 'd', 'h'};  // BIN (Base-2), DEC (Base-10), HEX (Base-16)
static const int DEFAULT_BASE = 'd';
static const std::string FILE_DELIMETER = "\t";
static const std::string FILE_PATH = "../config/button_map.txt";
static const int LCD_COLUMNS = 16;
static const int LCD_ROWS = 2;