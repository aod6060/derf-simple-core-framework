#include "../sys.h"
#include "../../thirdparty/imgui/imgui.h"



namespace config {
    Config _config;

    bool showSystemConfig = false;

    std::map<std::string, input::Keyboard> keys = {
    {"KEYS_UNKNOWN", input::Keyboard::KEYS_UNKNOWN},
    {"KEYS_A", input::Keyboard::KEYS_A},
    {"KEYS_B", input::Keyboard::KEYS_B},
    {"KEYS_C", input::Keyboard::KEYS_C},
    {"KEYS_D", input::Keyboard::KEYS_D},
    {"KEYS_E", input::Keyboard::KEYS_E},
    {"KEYS_F", input::Keyboard::KEYS_F},
    {"KEYS_G", input::Keyboard::KEYS_G},
    {"KEYS_H", input::Keyboard::KEYS_H},
    {"KEYS_I", input::Keyboard::KEYS_I},
    {"KEYS_J", input::Keyboard::KEYS_J},
    {"KEYS_K", input::Keyboard::KEYS_K},
    {"KEYS_L", input::Keyboard::KEYS_L},
    {"KEYS_M", input::Keyboard::KEYS_M},
    {"KEYS_N", input::Keyboard::KEYS_N},
    {"KEYS_O", input::Keyboard::KEYS_O},
    {"KEYS_P", input::Keyboard::KEYS_P},
    {"KEYS_Q", input::Keyboard::KEYS_Q},
    {"KEYS_R", input::Keyboard::KEYS_R},
    {"KEYS_S", input::Keyboard::KEYS_S},
    {"KEYS_T", input::Keyboard::KEYS_T},
    {"KEYS_U", input::Keyboard::KEYS_U},
    {"KEYS_V", input::Keyboard::KEYS_V},
    {"KEYS_W", input::Keyboard::KEYS_W},
    {"KEYS_X", input::Keyboard::KEYS_X},
    {"KEYS_Y", input::Keyboard::KEYS_Y},
    {"KEYS_Z", input::Keyboard::KEYS_Z},
    {"KEYS_1", input::Keyboard::KEYS_1},
    {"KEYS_2", input::Keyboard::KEYS_2},
    {"KEYS_3", input::Keyboard::KEYS_3},
    {"KEYS_4", input::Keyboard::KEYS_4},
    {"KEYS_5", input::Keyboard::KEYS_5},
    {"KEYS_6", input::Keyboard::KEYS_6},
    {"KEYS_7", input::Keyboard::KEYS_7},
    {"KEYS_8", input::Keyboard::KEYS_8},
    {"KEYS_9", input::Keyboard::KEYS_9},
    {"KEYS_0", input::Keyboard::KEYS_0},
    {"KEYS_RETURN", input::Keyboard::KEYS_RETURN},
    {"KEYS_ESCAPE", input::Keyboard::KEYS_ESCAPE},
    {"KEYS_BACKSPACE", input::Keyboard::KEYS_BACKSPACE},
    {"KEYS_TAB", input::Keyboard::KEYS_TAB},
    {"KEYS_SPACE", input::Keyboard::KEYS_SPACE},
    {"KEYS_MINUS", input::Keyboard::KEYS_MINUS},
    {"KEYS_EQUALS", input::Keyboard::KEYS_EQUALS},
    {"KEYS_LEFTBRACKET", input::Keyboard::KEYS_LEFTBRACKET},
    {"KEYS_RIGHTBRACKET", input::Keyboard::KEYS_RIGHTBRACKET},
    {"KEYS_BACKSLASH", input::Keyboard::KEYS_BACKSLASH},
    {"KEYS_NONUSHASH", input::Keyboard::KEYS_NONUSHASH},
    {"KEYS_SEMICOLON", input::Keyboard::KEYS_SEMICOLON},
    {"KEYS_APOSTROPHE", input::Keyboard::KEYS_APOSTROPHE},
    {"KEYS_GRAVE", input::Keyboard::KEYS_GRAVE},
    {"KEYS_COMMA", input::Keyboard::KEYS_COMMA},
    {"KEYS_PERIOD", input::Keyboard::KEYS_PERIOD},
    {"KEYS_SLASH", input::Keyboard::KEYS_SLASH},
    {"KEYS_CAPSLOCK", input::Keyboard::KEYS_CAPSLOCK},
    {"KEYS_F1", input::Keyboard::KEYS_F1},
    {"KEYS_F2", input::Keyboard::KEYS_F2},
    {"KEYS_F3", input::Keyboard::KEYS_F3},
    {"KEYS_F4", input::Keyboard::KEYS_F4},
    {"KEYS_F5", input::Keyboard::KEYS_F5},
    {"KEYS_F6", input::Keyboard::KEYS_F6},
    {"KEYS_F7", input::Keyboard::KEYS_F7},
    {"KEYS_F8", input::Keyboard::KEYS_F8},
    {"KEYS_F9", input::Keyboard::KEYS_F9},
    {"KEYS_F10", input::Keyboard::KEYS_F10},
    {"KEYS_F11", input::Keyboard::KEYS_F11},
    {"KEYS_F12", input::Keyboard::KEYS_F12},
    {"KEYS_PRINTSCREEN", input::Keyboard::KEYS_PRINTSCREEN},
    {"KEYS_SCROLLLOCK", input::Keyboard::KEYS_SCROLLLOCK},
    {"KEYS_PAUSE", input::Keyboard::KEYS_PAUSE},
    {"KEYS_INSERT", input::Keyboard::KEYS_INSERT},
    {"KEYS_HOME", input::Keyboard::KEYS_HOME},
    {"KEYS_PAGEUP", input::Keyboard::KEYS_PAGEUP},
    {"KEYS_DELETE", input::Keyboard::KEYS_DELETE},
    {"KEYS_END", input::Keyboard::KEYS_END},
    {"KEYS_PAGEDOWN", input::Keyboard::KEYS_PAGEDOWN},
    {"KEYS_RIGHT", input::Keyboard::KEYS_RIGHT},
    {"KEYS_LEFT", input::Keyboard::KEYS_LEFT},
    {"KEYS_DOWN", input::Keyboard::KEYS_DOWN},
    {"KEYS_UP", input::Keyboard::KEYS_UP},
    {"KEYS_NUMLOCKCLEAR", input::Keyboard::KEYS_NUMLOCKCLEAR},
    {"KEYS_KP_DIVIDE", input::Keyboard::KEYS_KP_DIVIDE},
    {"KEYS_KP_MULTIPLY", input::Keyboard::KEYS_KP_MULTIPLY},
    {"KEYS_KP_MINUS", input::Keyboard::KEYS_KP_MINUS},
    {"KEYS_KP_PLUS", input::Keyboard::KEYS_KP_PLUS},
    {"KEYS_KP_ENTER", input::Keyboard::KEYS_KP_ENTER},
    {"KEYS_KP_1", input::Keyboard::KEYS_KP_1},
    {"KEYS_KP_2", input::Keyboard::KEYS_KP_2},
    {"KEYS_KP_3", input::Keyboard::KEYS_KP_3},
    {"KEYS_KP_4", input::Keyboard::KEYS_KP_4},
    {"KEYS_KP_5", input::Keyboard::KEYS_KP_5},
    {"KEYS_KP_6", input::Keyboard::KEYS_KP_6},
    {"KEYS_KP_7", input::Keyboard::KEYS_KP_7},
    {"KEYS_KP_8", input::Keyboard::KEYS_KP_8},
    {"KEYS_KP_9", input::Keyboard::KEYS_KP_9},
    {"KEYS_KP_0", input::Keyboard::KEYS_KP_0},
    {"KEYS_KP_PERIOD", input::Keyboard::KEYS_KP_PERIOD},
    {"KEYS_NONUSBACKSLASH", input::Keyboard::KEYS_NONUSBACKSLASH},
    {"KEYS_APPLICATION", input::Keyboard::KEYS_APPLICATION},
    {"KEYS_POWER", input::Keyboard::KEYS_POWER},
    {"KEYS_KP_EQUALS", input::Keyboard::KEYS_KP_EQUALS},
    {"KEYS_F13", input::Keyboard::KEYS_F13},
    {"KEYS_F14", input::Keyboard::KEYS_F14},
    {"KEYS_F15", input::Keyboard::KEYS_F15},
    {"KEYS_F16", input::Keyboard::KEYS_F16},
    {"KEYS_F17", input::Keyboard::KEYS_F17},
    {"KEYS_F18", input::Keyboard::KEYS_F18},
    {"KEYS_F19", input::Keyboard::KEYS_F19},
    {"KEYS_F20", input::Keyboard::KEYS_F20},
    {"KEYS_F21", input::Keyboard::KEYS_F21},
    {"KEYS_F22", input::Keyboard::KEYS_F22},
    {"KEYS_F23", input::Keyboard::KEYS_F23},
    {"KEYS_F24", input::Keyboard::KEYS_F24},
    {"KEYS_EXECUTE", input::Keyboard::KEYS_EXECUTE},
    {"KEYS_HELP", input::Keyboard::KEYS_HELP},
    {"KEYS_MENU", input::Keyboard::KEYS_MENU},
    {"KEYS_SELECT", input::Keyboard::KEYS_SELECT},
    {"KEYS_STOP", input::Keyboard::KEYS_STOP},
    {"KEYS_AGAIN", input::Keyboard::KEYS_AGAIN},
    {"KEYS_UNDO", input::Keyboard::KEYS_UNDO},
    {"KEYS_CUT", input::Keyboard::KEYS_CUT},
    {"KEYS_COPY", input::Keyboard::KEYS_COPY},
    {"KEYS_PASTE", input::Keyboard::KEYS_PASTE},
    {"KEYS_FIND", input::Keyboard::KEYS_FIND},
    {"KEYS_MUTE", input::Keyboard::KEYS_MUTE},
    {"KEYS_VOLUMEUP", input::Keyboard::KEYS_VOLUMEUP},
    {"KEYS_VOLUMEDOWN", input::Keyboard::KEYS_VOLUMEDOWN},
    {"KEYS_KP_COMMA", input::Keyboard::KEYS_KP_COMMA},
    {"KEYS_KP_EQUALSAS400", input::Keyboard::KEYS_KP_EQUALSAS400},
    {"KEYS_INTERNATIONAL1", input::Keyboard::KEYS_INTERNATIONAL1},
    {"KEYS_INTERNATIONAL2", input::Keyboard::KEYS_INTERNATIONAL2},
    {"KEYS_INTERNATIONAL3", input::Keyboard::KEYS_INTERNATIONAL3},
    {"KEYS_INTERNATIONAL4", input::Keyboard::KEYS_INTERNATIONAL4},
    {"KEYS_INTERNATIONAL5", input::Keyboard::KEYS_INTERNATIONAL5},
    {"KEYS_INTERNATIONAL6", input::Keyboard::KEYS_INTERNATIONAL6},
    {"KEYS_INTERNATIONAL7", input::Keyboard::KEYS_INTERNATIONAL7},
    {"KEYS_INTERNATIONAL8", input::Keyboard::KEYS_INTERNATIONAL8},
    {"KEYS_INTERNATIONAL9", input::Keyboard::KEYS_INTERNATIONAL9},
    {"KEYS_LANG1", input::Keyboard::KEYS_LANG1},
    {"KEYS_LANG2", input::Keyboard::KEYS_LANG2},
    {"KEYS_LANG3", input::Keyboard::KEYS_LANG3},
    {"KEYS_LANG4", input::Keyboard::KEYS_LANG4},
    {"KEYS_LANG5", input::Keyboard::KEYS_LANG5},
    {"KEYS_LANG6", input::Keyboard::KEYS_LANG6},
    {"KEYS_LANG7", input::Keyboard::KEYS_LANG7},
    {"KEYS_LANG8", input::Keyboard::KEYS_LANG8},
    {"KEYS_LANG9", input::Keyboard::KEYS_LANG9},
    {"KEYS_ALTERASE", input::Keyboard::KEYS_ALTERASE},
    {"KEYS_SYSREQ", input::Keyboard::KEYS_SYSREQ},
    {"KEYS_CANCEL", input::Keyboard::KEYS_CANCEL},
    {"KEYS_CLEAR", input::Keyboard::KEYS_CLEAR},
    {"KEYS_PRIOR", input::Keyboard::KEYS_PRIOR},
    {"KEYS_RETURN2", input::Keyboard::KEYS_RETURN2},
    {"KEYS_SEPARATOR", input::Keyboard::KEYS_SEPARATOR},
    {"KEYS_OUT", input::Keyboard::KEYS_OUT},
    {"KEYS_OPER", input::Keyboard::KEYS_OPER},
    {"KEYS_CLEARAGAIN", input::Keyboard::KEYS_CLEARAGAIN},
    {"KEYS_CRSEL", input::Keyboard::KEYS_CRSEL},
    {"KEYS_EXSEL", input::Keyboard::KEYS_EXSEL},
    {"KEYS_KP_00", input::Keyboard::KEYS_KP_00},
    {"KEYS_KP_000", input::Keyboard::KEYS_KP_000},
    {"KEYS_THOUSANDSSEPARATOR", input::Keyboard::KEYS_THOUSANDSSEPARATOR},
    {"KEYS_DECIMALSEPARATOR", input::Keyboard::KEYS_DECIMALSEPARATOR},
    {"KEYS_CURRENCYUNIT", input::Keyboard::KEYS_CURRENCYUNIT},
    {"KEYS_CURRENCYSUBUNIT", input::Keyboard::KEYS_CURRENCYSUBUNIT},
    {"KEYS_KP_LEFTPAREN", input::Keyboard::KEYS_KP_LEFTPAREN},
    {"KEYS_KP_RIGHTPAREN", input::Keyboard::KEYS_KP_RIGHTPAREN},
    {"KEYS_KP_LEFTBRACE", input::Keyboard::KEYS_KP_LEFTBRACE},
    {"KEYS_KP_RIGHTBRACE", input::Keyboard::KEYS_KP_RIGHTBRACE},
    {"KEYS_KP_TAB", input::Keyboard::KEYS_KP_TAB},
    {"KEYS_KP_BACKSPACE", input::Keyboard::KEYS_KP_BACKSPACE},
    {"KEYS_KP_A", input::Keyboard::KEYS_KP_A},
    {"KEYS_KP_B", input::Keyboard::KEYS_KP_B},
    {"KEYS_KP_C", input::Keyboard::KEYS_KP_C},
    {"KEYS_KP_D", input::Keyboard::KEYS_KP_D},
    {"KEYS_KP_E", input::Keyboard::KEYS_KP_E},
    {"KEYS_KP_F", input::Keyboard::KEYS_KP_F},
    {"KEYS_KP_XOR", input::Keyboard::KEYS_KP_XOR},
    {"KEYS_KP_POWER", input::Keyboard::KEYS_KP_POWER},
    {"KEYS_KP_PERCENT", input::Keyboard::KEYS_KP_PERCENT},
    {"KEYS_KP_LESS", input::Keyboard::KEYS_KP_LESS},
    {"KEYS_KP_GREATER", input::Keyboard::KEYS_KP_GREATER},
    {"KEYS_KP_AMPERSAND", input::Keyboard::KEYS_KP_AMPERSAND},
    {"KEYS_KP_DBLAMPERSAND", input::Keyboard::KEYS_KP_DBLAMPERSAND},
    {"KEYS_KP_VERTICALBAR", input::Keyboard::KEYS_KP_VERTICALBAR},
    {"KEYS_KP_DBLVERTICALBAR", input::Keyboard::KEYS_KP_DBLVERTICALBAR},
    {"KEYS_KP_COLON", input::Keyboard::KEYS_KP_COLON},
    {"KEYS_KP_HASH", input::Keyboard::KEYS_KP_HASH},
    {"KEYS_KP_SPACE", input::Keyboard::KEYS_KP_SPACE},
    {"KEYS_KP_AT", input::Keyboard::KEYS_KP_AT},
    {"KEYS_KP_EXCLAM", input::Keyboard::KEYS_KP_EXCLAM},
    {"KEYS_KP_MEMSTORE", input::Keyboard::KEYS_KP_MEMSTORE},
    {"KEYS_KP_MEMRECALL", input::Keyboard::KEYS_KP_MEMRECALL},
    {"KEYS_KP_MEMCLEAR", input::Keyboard::KEYS_KP_MEMCLEAR},
    {"KEYS_KP_MEMADD", input::Keyboard::KEYS_KP_MEMADD},
    {"KEYS_KP_MEMSUBTRACT", input::Keyboard::KEYS_KP_MEMSUBTRACT},
    {"KEYS_KP_MEMMULTIPLY", input::Keyboard::KEYS_KP_MEMMULTIPLY},
    {"KEYS_KP_MEMDIVIDE", input::Keyboard::KEYS_KP_MEMDIVIDE},
    {"KEYS_KP_PLUSMINUS", input::Keyboard::KEYS_KP_PLUSMINUS},
    {"KEYS_KP_CLEAR", input::Keyboard::KEYS_KP_CLEAR},
    {"KEYS_KP_CLEARENTRY", input::Keyboard::KEYS_KP_CLEARENTRY},
    {"KEYS_KP_BINARY", input::Keyboard::KEYS_KP_BINARY},
    {"KEYS_KP_OCTAL", input::Keyboard::KEYS_KP_OCTAL},
    {"KEYS_KP_DECIMAL", input::Keyboard::KEYS_KP_DECIMAL},
    {"KEYS_KP_HEXADECIMAL", input::Keyboard::KEYS_KP_HEXADECIMAL},
    {"KEYS_LCTRL", input::Keyboard::KEYS_LCTRL},
    {"KEYS_LSHIFT", input::Keyboard::KEYS_LSHIFT},
    {"KEYS_LALT", input::Keyboard::KEYS_LALT},
    {"KEYS_LGUI", input::Keyboard::KEYS_LGUI},
    {"KEYS_RCTRL", input::Keyboard::KEYS_RCTRL},
    {"KEYS_RSHIFT", input::Keyboard::KEYS_RSHIFT},
    {"KEYS_RALT", input::Keyboard::KEYS_RALT},
    {"KEYS_RGUI", input::Keyboard::KEYS_RGUI},
    {"KEYS_MODE", input::Keyboard::KEYS_MODE},
    {"KEYS_AUDIONEXT", input::Keyboard::KEYS_AUDIONEXT},
    {"KEYS_AUDIOPREV", input::Keyboard::KEYS_AUDIOPREV},
    {"KEYS_AUDIOSTOP", input::Keyboard::KEYS_AUDIOSTOP},
    {"KEYS_AUDIOPLAY", input::Keyboard::KEYS_AUDIOPLAY},
    {"KEYS_AUDIOMUTE", input::Keyboard::KEYS_AUDIOMUTE},
    {"KEYS_MEDIASELECT", input::Keyboard::KEYS_MEDIASELECT},
    {"KEYS_WWW", input::Keyboard::KEYS_WWW},
    {"KEYS_MAIL", input::Keyboard::KEYS_MAIL},
    {"KEYS_CALCULATOR", input::Keyboard::KEYS_CALCULATOR},
    {"KEYS_COMPUTER", input::Keyboard::KEYS_COMPUTER},
    {"KEYS_AC_SEARCH", input::Keyboard::KEYS_AC_SEARCH},
    {"KEYS_AC_HOME", input::Keyboard::KEYS_AC_HOME},
    {"KEYS_AC_BACK", input::Keyboard::KEYS_AC_BACK},
    {"KEYS_AC_FORWARD", input::Keyboard::KEYS_AC_FORWARD},
    {"KEYS_AC_STOP", input::Keyboard::KEYS_AC_STOP},
    {"KEYS_AC_REFRESH", input::Keyboard::KEYS_AC_REFRESH},
    {"KEYS_AC_BOOKMARKS", input::Keyboard::KEYS_AC_BOOKMARKS},
    {"KEYS_BRIGHTNESSDOWN", input::Keyboard::KEYS_BRIGHTNESSDOWN},
    {"KEYS_BRIGHTNESSUP", input::Keyboard::KEYS_BRIGHTNESSUP},
    {"KEYS_DISPLAYSWITCH", input::Keyboard::KEYS_DISPLAYSWITCH},
    {"KEYS_KBDILLUMTOGGLE", input::Keyboard::KEYS_KBDILLUMTOGGLE},
    {"KEYS_KBDILLUMDOWN", input::Keyboard::KEYS_KBDILLUMDOWN},
    {"KEYS_KBDILLUMUP", input::Keyboard::KEYS_KBDILLUMUP},
    {"KEYS_EJECT", input::Keyboard::KEYS_EJECT},
    {"KEYS_SLEEP", input::Keyboard::KEYS_SLEEP},
    {"KEYS_APP1", input::Keyboard::KEYS_APP1},
    {"KEYS_APP2", input::Keyboard::KEYS_APP2},
    {"KEYS_AUDIOREWIND", input::Keyboard::KEYS_AUDIOREWIND},
    {"KEYS_AUDIOFASTFORWARD", input::Keyboard::KEYS_AUDIOFASTFORWARD},
    {"KEYS_SOFTLEFT", input::Keyboard::KEYS_SOFTLEFT},
    {"KEYS_SOFTRIGHT", input::Keyboard::KEYS_SOFTRIGHT},
    {"KEYS_ENDCALL", input::Keyboard::KEYS_ENDCALL}
    };
    
    std::map<input::Keyboard, std::string> keys_rev = {
    {input::Keyboard::KEYS_UNKNOWN, "KEYS_UNKNOWN"},
    {input::Keyboard::KEYS_A, "KEYS_A"},
    {input::Keyboard::KEYS_B, "KEYS_B"},
    {input::Keyboard::KEYS_C, "KEYS_C"},
    {input::Keyboard::KEYS_D, "KEYS_D"},
    {input::Keyboard::KEYS_E, "KEYS_E"},
    {input::Keyboard::KEYS_F, "KEYS_F"},
    {input::Keyboard::KEYS_G, "KEYS_G"},
    {input::Keyboard::KEYS_H, "KEYS_H"},
    {input::Keyboard::KEYS_I, "KEYS_I"},
    {input::Keyboard::KEYS_J, "KEYS_J"},
    {input::Keyboard::KEYS_K, "KEYS_K"},
    {input::Keyboard::KEYS_L, "KEYS_L"},
    {input::Keyboard::KEYS_M, "KEYS_M"},
    {input::Keyboard::KEYS_N, "KEYS_N"},
    {input::Keyboard::KEYS_O, "KEYS_O"},
    {input::Keyboard::KEYS_P, "KEYS_P"},
    {input::Keyboard::KEYS_Q, "KEYS_Q"},
    {input::Keyboard::KEYS_R, "KEYS_R"},
    {input::Keyboard::KEYS_S, "KEYS_S"},
    {input::Keyboard::KEYS_T, "KEYS_T"},
    {input::Keyboard::KEYS_U, "KEYS_U"},
    {input::Keyboard::KEYS_V, "KEYS_V"},
    {input::Keyboard::KEYS_W, "KEYS_W"},
    {input::Keyboard::KEYS_X, "KEYS_X"},
    {input::Keyboard::KEYS_Y, "KEYS_Y"},
    {input::Keyboard::KEYS_Z, "KEYS_Z"},
    {input::Keyboard::KEYS_1, "KEYS_1"},
    {input::Keyboard::KEYS_2, "KEYS_2"},
    {input::Keyboard::KEYS_3, "KEYS_3"},
    {input::Keyboard::KEYS_4, "KEYS_4"},
    {input::Keyboard::KEYS_5, "KEYS_5"},
    {input::Keyboard::KEYS_6, "KEYS_6"},
    {input::Keyboard::KEYS_7, "KEYS_7"},
    {input::Keyboard::KEYS_8, "KEYS_8"},
    {input::Keyboard::KEYS_9, "KEYS_9"},
    {input::Keyboard::KEYS_0, "KEYS_0"},
    {input::Keyboard::KEYS_RETURN, "KEYS_RETURN"},
    {input::Keyboard::KEYS_ESCAPE, "KEYS_ESCAPE"},
    {input::Keyboard::KEYS_BACKSPACE, "KEYS_BACKSPACE"},
    {input::Keyboard::KEYS_TAB, "KEYS_TAB"},
    {input::Keyboard::KEYS_SPACE, "KEYS_SPACE"},
    {input::Keyboard::KEYS_MINUS, "KEYS_MINUS"},
    {input::Keyboard::KEYS_EQUALS, "KEYS_EQUALS"},
    {input::Keyboard::KEYS_LEFTBRACKET, "KEYS_LEFTBRACKET"},
    {input::Keyboard::KEYS_RIGHTBRACKET, "KEYS_RIGHTBRACKET"},
    {input::Keyboard::KEYS_BACKSLASH, "KEYS_BACKSLASH"},
    {input::Keyboard::KEYS_NONUSHASH, "KEYS_NONUSHASH"},
    {input::Keyboard::KEYS_SEMICOLON, "KEYS_SEMICOLON"},
    {input::Keyboard::KEYS_APOSTROPHE, "KEYS_APOSTROPHE"},
    {input::Keyboard::KEYS_GRAVE, "KEYS_GRAVE"},
    {input::Keyboard::KEYS_COMMA, "KEYS_COMMA"},
    {input::Keyboard::KEYS_PERIOD, "KEYS_PERIOD"},
    {input::Keyboard::KEYS_SLASH, "KEYS_SLASH"},
    {input::Keyboard::KEYS_CAPSLOCK, "KEYS_CAPSLOCK"},
    {input::Keyboard::KEYS_F1, "KEYS_F1"},
    {input::Keyboard::KEYS_F2, "KEYS_F2"},
    {input::Keyboard::KEYS_F3, "KEYS_F3"},
    {input::Keyboard::KEYS_F4, "KEYS_F4"},
    {input::Keyboard::KEYS_F5, "KEYS_F5"},
    {input::Keyboard::KEYS_F6, "KEYS_F6"},
    {input::Keyboard::KEYS_F7, "KEYS_F7"},
    {input::Keyboard::KEYS_F8, "KEYS_F8"},
    {input::Keyboard::KEYS_F9, "KEYS_F9"},
    {input::Keyboard::KEYS_F10, "KEYS_F10"},
    {input::Keyboard::KEYS_F11, "KEYS_F11"},
    {input::Keyboard::KEYS_F12, "KEYS_F12"},
    {input::Keyboard::KEYS_PRINTSCREEN, "KEYS_PRINTSCREEN"},
    {input::Keyboard::KEYS_SCROLLLOCK, "KEYS_SCROLLLOCK"},
    {input::Keyboard::KEYS_PAUSE, "KEYS_PAUSE"},
    {input::Keyboard::KEYS_INSERT, "KEYS_INSERT"},
    {input::Keyboard::KEYS_HOME, "KEYS_HOME"},
    {input::Keyboard::KEYS_PAGEUP, "KEYS_PAGEUP"},
    {input::Keyboard::KEYS_DELETE, "KEYS_DELETE"},
    {input::Keyboard::KEYS_END, "KEYS_END"},
    {input::Keyboard::KEYS_PAGEDOWN, "KEYS_PAGEDOWN"},
    {input::Keyboard::KEYS_RIGHT, "KEYS_RIGHT"},
    {input::Keyboard::KEYS_LEFT, "KEYS_LEFT"},
    {input::Keyboard::KEYS_DOWN, "KEYS_DOWN"},
    {input::Keyboard::KEYS_UP, "KEYS_UP"},
    {input::Keyboard::KEYS_NUMLOCKCLEAR, "KEYS_NUMLOCKCLEAR"},
    {input::Keyboard::KEYS_KP_DIVIDE, "KEYS_KP_DIVIDE"},
    {input::Keyboard::KEYS_KP_MULTIPLY, "KEYS_KP_MULTIPLY"},
    {input::Keyboard::KEYS_KP_MINUS, "KEYS_KP_MINUS"},
    {input::Keyboard::KEYS_KP_PLUS, "KEYS_KP_PLUS"},
    {input::Keyboard::KEYS_KP_ENTER, "KEYS_KP_ENTER"},
    {input::Keyboard::KEYS_KP_1, "KEYS_KP_1"},
    {input::Keyboard::KEYS_KP_2, "KEYS_KP_2"},
    {input::Keyboard::KEYS_KP_3, "KEYS_KP_3"},
    {input::Keyboard::KEYS_KP_4, "KEYS_KP_4"},
    {input::Keyboard::KEYS_KP_5, "KEYS_KP_5"},
    {input::Keyboard::KEYS_KP_6, "KEYS_KP_6"},
    {input::Keyboard::KEYS_KP_7, "KEYS_KP_7"},
    {input::Keyboard::KEYS_KP_8, "KEYS_KP_8"},
    {input::Keyboard::KEYS_KP_9, "KEYS_KP_9"},
    {input::Keyboard::KEYS_KP_0, "KEYS_KP_0"},
    {input::Keyboard::KEYS_KP_PERIOD, "KEYS_KP_PERIOD"},
    {input::Keyboard::KEYS_NONUSBACKSLASH, "KEYS_NONUSBACKSLASH"},
    {input::Keyboard::KEYS_APPLICATION, "KEYS_APPLICATION"},
    {input::Keyboard::KEYS_POWER, "KEYS_POWER"},
    {input::Keyboard::KEYS_KP_EQUALS, "KEYS_KP_EQUALS"},
    {input::Keyboard::KEYS_F13, "KEYS_F13"},
    {input::Keyboard::KEYS_F14, "KEYS_F14"},
    {input::Keyboard::KEYS_F15, "KEYS_F15"},
    {input::Keyboard::KEYS_F16, "KEYS_F16"},
    {input::Keyboard::KEYS_F17, "KEYS_F17"},
    {input::Keyboard::KEYS_F18, "KEYS_F18"},
    {input::Keyboard::KEYS_F19, "KEYS_F19"},
    {input::Keyboard::KEYS_F20, "KEYS_F20"},
    {input::Keyboard::KEYS_F21, "KEYS_F21"},
    {input::Keyboard::KEYS_F22, "KEYS_F22"},
    {input::Keyboard::KEYS_F23, "KEYS_F23"},
    {input::Keyboard::KEYS_F24, "KEYS_F24"},
    {input::Keyboard::KEYS_EXECUTE, "KEYS_EXECUTE"},
    {input::Keyboard::KEYS_HELP, "KEYS_HELP"},
    {input::Keyboard::KEYS_MENU, "KEYS_MENU"},
    {input::Keyboard::KEYS_SELECT, "KEYS_SELECT"},
    {input::Keyboard::KEYS_STOP, "KEYS_STOP"},
    {input::Keyboard::KEYS_AGAIN, "KEYS_AGAIN"},
    {input::Keyboard::KEYS_UNDO, "KEYS_UNDO"},
    {input::Keyboard::KEYS_CUT, "KEYS_CUT"},
    {input::Keyboard::KEYS_COPY, "KEYS_COPY"},
    {input::Keyboard::KEYS_PASTE, "KEYS_PASTE"},
    {input::Keyboard::KEYS_FIND, "KEYS_FIND"},
    {input::Keyboard::KEYS_MUTE, "KEYS_MUTE"},
    {input::Keyboard::KEYS_VOLUMEUP, "KEYS_VOLUMEUP"},
    {input::Keyboard::KEYS_VOLUMEDOWN, "KEYS_VOLUMEDOWN"},
    {input::Keyboard::KEYS_KP_COMMA, "KEYS_KP_COMMA"},
    {input::Keyboard::KEYS_KP_EQUALSAS400, "KEYS_KP_EQUALSAS400"},
    {input::Keyboard::KEYS_INTERNATIONAL1, "KEYS_INTERNATIONAL1"},
    {input::Keyboard::KEYS_INTERNATIONAL2, "KEYS_INTERNATIONAL2"},
    {input::Keyboard::KEYS_INTERNATIONAL3, "KEYS_INTERNATIONAL3"},
    {input::Keyboard::KEYS_INTERNATIONAL4, "KEYS_INTERNATIONAL4"},
    {input::Keyboard::KEYS_INTERNATIONAL5, "KEYS_INTERNATIONAL5"},
    {input::Keyboard::KEYS_INTERNATIONAL6, "KEYS_INTERNATIONAL6"},
    {input::Keyboard::KEYS_INTERNATIONAL7, "KEYS_INTERNATIONAL7"},
    {input::Keyboard::KEYS_INTERNATIONAL8, "KEYS_INTERNATIONAL8"},
    {input::Keyboard::KEYS_INTERNATIONAL9, "KEYS_INTERNATIONAL9"},
    {input::Keyboard::KEYS_LANG1, "KEYS_LANG1"},
    {input::Keyboard::KEYS_LANG2, "KEYS_LANG2"},
    {input::Keyboard::KEYS_LANG3, "KEYS_LANG3"},
    {input::Keyboard::KEYS_LANG4, "KEYS_LANG4"},
    {input::Keyboard::KEYS_LANG5, "KEYS_LANG5"},
    {input::Keyboard::KEYS_LANG6, "KEYS_LANG6"},
    {input::Keyboard::KEYS_LANG7, "KEYS_LANG7"},
    {input::Keyboard::KEYS_LANG8, "KEYS_LANG8"},
    {input::Keyboard::KEYS_LANG9, "KEYS_LANG9"},
    {input::Keyboard::KEYS_ALTERASE, "KEYS_ALTERASE"},
    {input::Keyboard::KEYS_SYSREQ, "KEYS_SYSREQ"},
    {input::Keyboard::KEYS_CANCEL, "KEYS_CANCEL"},
    {input::Keyboard::KEYS_CLEAR, "KEYS_CLEAR"},
    {input::Keyboard::KEYS_PRIOR, "KEYS_PRIOR"},
    {input::Keyboard::KEYS_RETURN2, "KEYS_RETURN2"},
    {input::Keyboard::KEYS_SEPARATOR, "KEYS_SEPARATOR"},
    {input::Keyboard::KEYS_OUT, "KEYS_OUT"},
    {input::Keyboard::KEYS_OPER, "KEYS_OPER"},
    {input::Keyboard::KEYS_CLEARAGAIN, "KEYS_CLEARAGAIN"},
    {input::Keyboard::KEYS_CRSEL, "KEYS_CRSEL"},
    {input::Keyboard::KEYS_EXSEL, "KEYS_EXSEL"},
    {input::Keyboard::KEYS_KP_00, "KEYS_KP_00"},
    {input::Keyboard::KEYS_KP_000, "KEYS_KP_000"},
    {input::Keyboard::KEYS_THOUSANDSSEPARATOR, "KEYS_THOUSANDSSEPARATOR"},
    {input::Keyboard::KEYS_DECIMALSEPARATOR, "KEYS_DECIMALSEPARATOR"},
    {input::Keyboard::KEYS_CURRENCYUNIT, "KEYS_CURRENCYUNIT"},
    {input::Keyboard::KEYS_CURRENCYSUBUNIT, "KEYS_CURRENCYSUBUNIT"},
    {input::Keyboard::KEYS_KP_LEFTPAREN, "KEYS_KP_LEFTPAREN"},
    {input::Keyboard::KEYS_KP_RIGHTPAREN, "KEYS_KP_RIGHTPAREN"},
    {input::Keyboard::KEYS_KP_LEFTBRACE, "KEYS_KP_LEFTBRACE"},
    {input::Keyboard::KEYS_KP_RIGHTBRACE, "KEYS_KP_RIGHTBRACE"},
    {input::Keyboard::KEYS_KP_TAB, "KEYS_KP_TAB"},
    {input::Keyboard::KEYS_KP_BACKSPACE, "KEYS_KP_BACKSPACE"},
    {input::Keyboard::KEYS_KP_A, "KEYS_KP_A"},
    {input::Keyboard::KEYS_KP_B, "KEYS_KP_B"},
    {input::Keyboard::KEYS_KP_C, "KEYS_KP_C"},
    {input::Keyboard::KEYS_KP_D, "KEYS_KP_D"},
    {input::Keyboard::KEYS_KP_E, "KEYS_KP_E"},
    {input::Keyboard::KEYS_KP_F, "KEYS_KP_F"},
    {input::Keyboard::KEYS_KP_XOR, "KEYS_KP_XOR"},
    {input::Keyboard::KEYS_KP_POWER, "KEYS_KP_POWER"},
    {input::Keyboard::KEYS_KP_PERCENT, "KEYS_KP_PERCENT"},
    {input::Keyboard::KEYS_KP_LESS, "KEYS_KP_LESS"},
    {input::Keyboard::KEYS_KP_GREATER, "KEYS_KP_GREATER"},
    {input::Keyboard::KEYS_KP_AMPERSAND, "KEYS_KP_AMPERSAND"},
    {input::Keyboard::KEYS_KP_DBLAMPERSAND, "KEYS_KP_DBLAMPERSAND"},
    {input::Keyboard::KEYS_KP_VERTICALBAR, "KEYS_KP_VERTICALBAR"},
    {input::Keyboard::KEYS_KP_DBLVERTICALBAR, "KEYS_KP_DBLVERTICALBAR"},
    {input::Keyboard::KEYS_KP_COLON, "KEYS_KP_COLON"},
    {input::Keyboard::KEYS_KP_HASH, "KEYS_KP_HASH"},
    {input::Keyboard::KEYS_KP_SPACE, "KEYS_KP_SPACE"},
    {input::Keyboard::KEYS_KP_AT, "KEYS_KP_AT"},
    {input::Keyboard::KEYS_KP_EXCLAM, "KEYS_KP_EXCLAM"},
    {input::Keyboard::KEYS_KP_MEMSTORE, "KEYS_KP_MEMSTORE"},
    {input::Keyboard::KEYS_KP_MEMRECALL, "KEYS_KP_MEMRECALL"},
    {input::Keyboard::KEYS_KP_MEMCLEAR, "KEYS_KP_MEMCLEAR"},
    {input::Keyboard::KEYS_KP_MEMADD, "KEYS_KP_MEMADD"},
    {input::Keyboard::KEYS_KP_MEMSUBTRACT, "KEYS_KP_MEMSUBTRACT"},
    {input::Keyboard::KEYS_KP_MEMMULTIPLY, "KEYS_KP_MEMMULTIPLY"},
    {input::Keyboard::KEYS_KP_MEMDIVIDE, "KEYS_KP_MEMDIVIDE"},
    {input::Keyboard::KEYS_KP_PLUSMINUS, "KEYS_KP_PLUSMINUS"},
    {input::Keyboard::KEYS_KP_CLEAR, "KEYS_KP_CLEAR"},
    {input::Keyboard::KEYS_KP_CLEARENTRY, "KEYS_KP_CLEARENTRY"},
    {input::Keyboard::KEYS_KP_BINARY, "KEYS_KP_BINARY"},
    {input::Keyboard::KEYS_KP_OCTAL, "KEYS_KP_OCTAL"},
    {input::Keyboard::KEYS_KP_DECIMAL, "KEYS_KP_DECIMAL"},
    {input::Keyboard::KEYS_KP_HEXADECIMAL, "KEYS_KP_HEXADECIMAL"},
    {input::Keyboard::KEYS_LCTRL, "KEYS_LCTRL"},
    {input::Keyboard::KEYS_LSHIFT, "KEYS_LSHIFT"},
    {input::Keyboard::KEYS_LALT, "KEYS_LALT"},
    {input::Keyboard::KEYS_LGUI, "KEYS_LGUI"},
    {input::Keyboard::KEYS_RCTRL, "KEYS_RCTRL"},
    {input::Keyboard::KEYS_RSHIFT, "KEYS_RSHIFT"},
    {input::Keyboard::KEYS_RALT, "KEYS_RALT"},
    {input::Keyboard::KEYS_RGUI, "KEYS_RGUI"},
    {input::Keyboard::KEYS_MODE, "KEYS_MODE"},
    {input::Keyboard::KEYS_AUDIONEXT, "KEYS_AUDIONEXT"},
    {input::Keyboard::KEYS_AUDIOPREV, "KEYS_AUDIOPREV"},
    {input::Keyboard::KEYS_AUDIOSTOP, "KEYS_AUDIOSTOP"},
    {input::Keyboard::KEYS_AUDIOPLAY, "KEYS_AUDIOPLAY"},
    {input::Keyboard::KEYS_AUDIOMUTE, "KEYS_AUDIOMUTE"},
    {input::Keyboard::KEYS_MEDIASELECT, "KEYS_MEDIASELECT"},
    {input::Keyboard::KEYS_WWW, "KEYS_WWW"},
    {input::Keyboard::KEYS_MAIL, "KEYS_MAIL"},
    {input::Keyboard::KEYS_CALCULATOR, "KEYS_CALCULATOR"},
    {input::Keyboard::KEYS_COMPUTER, "KEYS_COMPUTER"},
    {input::Keyboard::KEYS_AC_SEARCH, "KEYS_AC_SEARCH"},
    {input::Keyboard::KEYS_AC_HOME, "KEYS_AC_HOME"},
    {input::Keyboard::KEYS_AC_BACK, "KEYS_AC_BACK"},
    {input::Keyboard::KEYS_AC_FORWARD, "KEYS_AC_FORWARD"},
    {input::Keyboard::KEYS_AC_STOP, "KEYS_AC_STOP"},
    {input::Keyboard::KEYS_AC_REFRESH, "KEYS_AC_REFRESH"},
    {input::Keyboard::KEYS_AC_BOOKMARKS, "KEYS_AC_BOOKMARKS"},
    {input::Keyboard::KEYS_BRIGHTNESSDOWN, "KEYS_BRIGHTNESSDOWN"},
    {input::Keyboard::KEYS_BRIGHTNESSUP, "KEYS_BRIGHTNESSUP"},
    {input::Keyboard::KEYS_DISPLAYSWITCH, "KEYS_DISPLAYSWITCH"},
    {input::Keyboard::KEYS_KBDILLUMTOGGLE, "KEYS_KBDILLUMTOGGLE"},
    {input::Keyboard::KEYS_KBDILLUMDOWN, "KEYS_KBDILLUMDOWN"},
    {input::Keyboard::KEYS_KBDILLUMUP, "KEYS_KBDILLUMUP"},
    {input::Keyboard::KEYS_EJECT, "KEYS_EJECT"},
    {input::Keyboard::KEYS_SLEEP, "KEYS_SLEEP"},
    {input::Keyboard::KEYS_APP1, "KEYS_APP1"},
    {input::Keyboard::KEYS_APP2, "KEYS_APP2"},
    {input::Keyboard::KEYS_AUDIOREWIND, "KEYS_AUDIOREWIND"},
    {input::Keyboard::KEYS_AUDIOFASTFORWARD, "KEYS_AUDIOFASTFORWARD"},
    {input::Keyboard::KEYS_SOFTLEFT, "KEYS_SOFTLEFT"},
    {input::Keyboard::KEYS_SOFTRIGHT, "KEYS_SOFTRIGHT"},
    {input::Keyboard::KEYS_ENDCALL, "KEYS_ENDCALL"}
    };

    std::map<std::string, input::MouseButtons> mouseButtons = {
    {"MBS_LEFT", input::MouseButtons::MBS_LEFT},
    {"MBS_CENTER", input::MouseButtons::MBS_CENTER},
    {"MBS_RIGHT", input::MouseButtons::MBS_RIGHT}
    };

    std::map<input::MouseButtons, std::string> mouseButtons_rev = {
    {input::MouseButtons::MBS_LEFT, "MBS_LEFT"},
    {input::MouseButtons::MBS_CENTER, "MBS_CENTER"},
    {input::MouseButtons::MBS_RIGHT, "MBS_RIGHT"}
    };

    std::map<std::string, input::gamepad::PlayerControllerName> playerNames = {
    {"PCN_PLAYER_1", input::gamepad::PlayerControllerName::PCN_PLAYER_1},
    {"PCN_PLAYER_2", input::gamepad::PlayerControllerName::PCN_PLAYER_2},
    {"PCN_PLAYER_3", input::gamepad::PlayerControllerName::PCN_PLAYER_3},
    {"PCN_PLAYER_4", input::gamepad::PlayerControllerName::PCN_PLAYER_4}
    };

    std::map<input::gamepad::PlayerControllerName, std::string> playerNames_rev = {
    {input::gamepad::PlayerControllerName::PCN_PLAYER_1, "PCN_PLAYER_1"},
    {input::gamepad::PlayerControllerName::PCN_PLAYER_2, "PCN_PLAYER_2"},
    {input::gamepad::PlayerControllerName::PCN_PLAYER_3, "PCN_PLAYER_3"},
    {input::gamepad::PlayerControllerName::PCN_PLAYER_4, "PCN_PLAYER_4"}
    };

    std::map<std::string, input::gamepad::ControllerButton> controllerButtons = {
    {"CB_INVALID", input::gamepad::ControllerButton::CB_INVALID},
    {"CB_A", input::gamepad::ControllerButton::CB_A},
    {"CB_B", input::gamepad::ControllerButton::CB_B},
    {"CB_X", input::gamepad::ControllerButton::CB_X},
    {"CB_Y", input::gamepad::ControllerButton::CB_Y},
    {"CB_BACK", input::gamepad::ControllerButton::CB_BACK},
    {"CB_GUIDE", input::gamepad::ControllerButton::CB_GUIDE},
    {"CB_START", input::gamepad::ControllerButton::CB_START},
    {"CB_LEFTSTICK", input::gamepad::ControllerButton::CB_LEFTSTICK},
    {"CB_RIGHTSTICK", input::gamepad::ControllerButton::CB_RIGHTSTICK},
    {"CB_LEFTSHOULDER", input::gamepad::ControllerButton::CB_LEFTSHOULDER},
    {"CB_RIGHTSHOULDER", input::gamepad::ControllerButton::CB_RIGHTSHOULDER},
    {"CB_DPAD_UP", input::gamepad::ControllerButton::CB_DPAD_UP},
    {"CB_DPAD_DOWN", input::gamepad::ControllerButton::CB_DPAD_DOWN},
    {"CB_DPAD_LEFT", input::gamepad::ControllerButton::CB_DPAD_LEFT},
    {"CB_DPAD_RIGHT", input::gamepad::ControllerButton::CB_DPAD_RIGHT},
    {"CB_MISC1", input::gamepad::ControllerButton::CB_MISC1},
    {"CB_PADDLE1", input::gamepad::ControllerButton::CB_PADDLE1},
    {"CB_PADDLE2", input::gamepad::ControllerButton::CB_PADDLE2},
    {"CB_PADDLE3", input::gamepad::ControllerButton::CB_PADDLE3},
    {"CB_PADDLE4", input::gamepad::ControllerButton::CB_PADDLE4},
    {"CB_TOUCHPAD", input::gamepad::ControllerButton::CB_TOUCHPAD}
    };

    std::map<input::gamepad::ControllerButton, std::string> controllerButtons_rev = {
    {input::gamepad::ControllerButton::CB_INVALID, "CB_INVALID"},
    {input::gamepad::ControllerButton::CB_A, "CB_A"},
    {input::gamepad::ControllerButton::CB_B, "CB_B"},
    {input::gamepad::ControllerButton::CB_X, "CB_X"},
    {input::gamepad::ControllerButton::CB_Y, "CB_Y"},
    {input::gamepad::ControllerButton::CB_BACK, "CB_BACK"},
    {input::gamepad::ControllerButton::CB_GUIDE, "CB_GUIDE"},
    {input::gamepad::ControllerButton::CB_START, "CB_START"},
    {input::gamepad::ControllerButton::CB_LEFTSTICK, "CB_LEFTSTICK"},
    {input::gamepad::ControllerButton::CB_RIGHTSTICK, "CB_RIGHTSTICK"},
    {input::gamepad::ControllerButton::CB_LEFTSHOULDER, "CB_LEFTSHOULDER"},
    {input::gamepad::ControllerButton::CB_RIGHTSHOULDER, "CB_RIGHTSHOULDER"},
    {input::gamepad::ControllerButton::CB_DPAD_UP, "CB_DPAD_UP"},
    {input::gamepad::ControllerButton::CB_DPAD_DOWN, "CB_DPAD_DOWN"},
    {input::gamepad::ControllerButton::CB_DPAD_LEFT, "CB_DPAD_LEFT"},
    {input::gamepad::ControllerButton::CB_DPAD_RIGHT, "CB_DPAD_RIGHT"},
    {input::gamepad::ControllerButton::CB_MISC1, "CB_MISC1"},
    {input::gamepad::ControllerButton::CB_PADDLE1, "CB_PADDLE1"},
    {input::gamepad::ControllerButton::CB_PADDLE2, "CB_PADDLE2"},
    {input::gamepad::ControllerButton::CB_PADDLE3, "CB_PADDLE3"},
    {input::gamepad::ControllerButton::CB_PADDLE4, "CB_PADDLE4"},
    {input::gamepad::ControllerButton::CB_TOUCHPAD, "CB_TOUCHPAD"}
    };

    std::vector<std::string> keyList = {
    "KEYS_UNKNOWN",
    "KEYS_A",
    "KEYS_B",
    "KEYS_C",
    "KEYS_D",
    "KEYS_E",
    "KEYS_F",
    "KEYS_G",
    "KEYS_H",
    "KEYS_I",
    "KEYS_J",
    "KEYS_K",
    "KEYS_L",
    "KEYS_M",
    "KEYS_N",
    "KEYS_O",
    "KEYS_P",
    "KEYS_Q",
    "KEYS_R",
    "KEYS_S",
    "KEYS_T",
    "KEYS_U",
    "KEYS_V",
    "KEYS_W",
    "KEYS_X",
    "KEYS_Y",
    "KEYS_Z",
    "KEYS_1",
    "KEYS_2",
    "KEYS_3",
    "KEYS_4",
    "KEYS_5",
    "KEYS_6",
    "KEYS_7",
    "KEYS_8",
    "KEYS_9",
    "KEYS_0",
    "KEYS_RETURN",
    "KEYS_ESCAPE",
    "KEYS_BACKSPACE",
    "KEYS_TAB",
    "KEYS_SPACE",
    "KEYS_MINUS",
    "KEYS_EQUALS",
    "KEYS_LEFTBRACKET",
    "KEYS_RIGHTBRACKET",
    "KEYS_BACKSLASH",
    "KEYS_NONUSHASH",
    "KEYS_SEMICOLON",
    "KEYS_APOSTROPHE",
    "KEYS_GRAVE",
    "KEYS_COMMA",
    "KEYS_PERIOD",
    "KEYS_SLASH",
    "KEYS_CAPSLOCK",
    "KEYS_F1",
    "KEYS_F2",
    "KEYS_F3",
    "KEYS_F4",
    "KEYS_F5",
    "KEYS_F6",
    "KEYS_F7",
    "KEYS_F8",
    "KEYS_F9",
    "KEYS_F10",
    "KEYS_F11",
    "KEYS_F12",
    "KEYS_PRINTSCREEN",
    "KEYS_SCROLLLOCK",
    "KEYS_PAUSE",
    "KEYS_INSERT",
    "KEYS_HOME",
    "KEYS_PAGEUP",
    "KEYS_DELETE",
    "KEYS_END",
    "KEYS_PAGEDOWN",
    "KEYS_RIGHT",
    "KEYS_LEFT",
    "KEYS_DOWN",
    "KEYS_UP",
    "KEYS_NUMLOCKCLEAR",
    "KEYS_KP_DIVIDE",
    "KEYS_KP_MULTIPLY",
    "KEYS_KP_MINUS",
    "KEYS_KP_PLUS",
    "KEYS_KP_ENTER",
    "KEYS_KP_1",
    "KEYS_KP_2",
    "KEYS_KP_3",
    "KEYS_KP_4",
    "KEYS_KP_5",
    "KEYS_KP_6",
    "KEYS_KP_7",
    "KEYS_KP_8",
    "KEYS_KP_9",
    "KEYS_KP_0",
    "KEYS_KP_PERIOD",
    "KEYS_NONUSBACKSLASH",
    "KEYS_APPLICATION",
    "KEYS_POWER",
    "KEYS_KP_EQUALS",
    "KEYS_F13",
    "KEYS_F14",
    "KEYS_F15",
    "KEYS_F16",
    "KEYS_F17",
    "KEYS_F18",
    "KEYS_F19",
    "KEYS_F20",
    "KEYS_F21",
    "KEYS_F22",
    "KEYS_F23",
    "KEYS_F24",
    "KEYS_EXECUTE",
    "KEYS_HELP",
    "KEYS_MENU",
    "KEYS_SELECT",
    "KEYS_STOP",
    "KEYS_AGAIN",
    "KEYS_UNDO",
    "KEYS_CUT",
    "KEYS_COPY",
    "KEYS_PASTE",
    "KEYS_FIND",
    "KEYS_MUTE",
    "KEYS_VOLUMEUP",
    "KEYS_VOLUMEDOWN",
    "KEYS_KP_COMMA",
    "KEYS_KP_EQUALSAS400",
    "KEYS_INTERNATIONAL1",
    "KEYS_INTERNATIONAL2",
    "KEYS_INTERNATIONAL3",
    "KEYS_INTERNATIONAL4",
    "KEYS_INTERNATIONAL5",
    "KEYS_INTERNATIONAL6",
    "KEYS_INTERNATIONAL7",
    "KEYS_INTERNATIONAL8",
    "KEYS_INTERNATIONAL9",
    "KEYS_LANG1",
    "KEYS_LANG2",
    "KEYS_LANG3",
    "KEYS_LANG4",
    "KEYS_LANG5",
    "KEYS_LANG6",
    "KEYS_LANG7",
    "KEYS_LANG8",
    "KEYS_LANG9",
    "KEYS_ALTERASE",
    "KEYS_SYSREQ",
    "KEYS_CANCEL",
    "KEYS_CLEAR",
    "KEYS_PRIOR",
    "KEYS_RETURN2",
    "KEYS_SEPARATOR",
    "KEYS_OUT",
    "KEYS_OPER",
    "KEYS_CLEARAGAIN",
    "KEYS_CRSEL",
    "KEYS_EXSEL",
    "KEYS_KP_00",
    "KEYS_KP_000",
    "KEYS_THOUSANDSSEPARATOR",
    "KEYS_DECIMALSEPARATOR",
    "KEYS_CURRENCYUNIT",
    "KEYS_CURRENCYSUBUNIT",
    "KEYS_KP_LEFTPAREN",
    "KEYS_KP_RIGHTPAREN",
    "KEYS_KP_LEFTBRACE",
    "KEYS_KP_RIGHTBRACE",
    "KEYS_KP_TAB",
    "KEYS_KP_BACKSPACE",
    "KEYS_KP_A",
    "KEYS_KP_B",
    "KEYS_KP_C",
    "KEYS_KP_D",
    "KEYS_KP_E",
    "KEYS_KP_F",
    "KEYS_KP_XOR",
    "KEYS_KP_POWER",
    "KEYS_KP_PERCENT",
    "KEYS_KP_LESS",
    "KEYS_KP_GREATER",
    "KEYS_KP_AMPERSAND",
    "KEYS_KP_DBLAMPERSAND",
    "KEYS_KP_VERTICALBAR",
    "KEYS_KP_DBLVERTICALBAR",
    "KEYS_KP_COLON",
    "KEYS_KP_HASH",
    "KEYS_KP_SPACE",
    "KEYS_KP_AT",
    "KEYS_KP_EXCLAM",
    "KEYS_KP_MEMSTORE",
    "KEYS_KP_MEMRECALL",
    "KEYS_KP_MEMCLEAR",
    "KEYS_KP_MEMADD",
    "KEYS_KP_MEMSUBTRACT",
    "KEYS_KP_MEMMULTIPLY",
    "KEYS_KP_MEMDIVIDE",
    "KEYS_KP_PLUSMINUS",
    "KEYS_KP_CLEAR",
    "KEYS_KP_CLEARENTRY",
    "KEYS_KP_BINARY",
    "KEYS_KP_OCTAL",
    "KEYS_KP_DECIMAL",
    "KEYS_KP_HEXADECIMAL",
    "KEYS_LCTRL",
    "KEYS_LSHIFT",
    "KEYS_LALT",
    "KEYS_LGUI",
    "KEYS_RCTRL",
    "KEYS_RSHIFT",
    "KEYS_RALT",
    "KEYS_RGUI",
    "KEYS_MODE",
    "KEYS_AUDIONEXT",
    "KEYS_AUDIOPREV",
    "KEYS_AUDIOSTOP",
    "KEYS_AUDIOPLAY",
    "KEYS_AUDIOMUTE",
    "KEYS_MEDIASELECT",
    "KEYS_WWW",
    "KEYS_MAIL",
    "KEYS_CALCULATOR",
    "KEYS_COMPUTER",
    "KEYS_AC_SEARCH",
    "KEYS_AC_HOME",
    "KEYS_AC_BACK",
    "KEYS_AC_FORWARD",
    "KEYS_AC_STOP",
    "KEYS_AC_REFRESH",
    "KEYS_AC_BOOKMARKS",
    "KEYS_BRIGHTNESSDOWN",
    "KEYS_BRIGHTNESSUP",
    "KEYS_DISPLAYSWITCH",
    "KEYS_KBDILLUMTOGGLE",
    "KEYS_KBDILLUMDOWN",
    "KEYS_KBDILLUMUP",
    "KEYS_EJECT",
    "KEYS_SLEEP",
    "KEYS_APP1",
    "KEYS_APP2",
    "KEYS_AUDIOREWIND",
    "KEYS_AUDIOFASTFORWARD",
    "KEYS_SOFTLEFT",
    "KEYS_SOFTRIGHT",
    "KEYS_ENDCALL"
    };

    std::vector<std::string> mouseButtonsList = {
    "MBS_LEFT",
    "MBS_CENTER",
    "MBS_RIGHT"
    };

    std::vector<std::string> playerNameList = {
    "PCN_PLAYER_1",
    "PCN_PLAYER_2",
    "PCN_PLAYER_3",
    "PCN_PLAYER_4",
    };

    std::vector<std::string> controllerButtonsList = {
    "CB_INVALID",
    "CB_A",
    "CB_B",
    "CB_X",
    "CB_Y",
    "CB_BACK",
    "CB_GUIDE",
    "CB_START",
    "CB_LEFTSTICK",
    "CB_RIGHTSTICK",
    "CB_LEFTSHOULDER",
    "CB_RIGHTSHOULDER",
    "CB_DPAD_UP",
    "CB_DPAD_DOWN",
    "CB_DPAD_LEFT",
    "CB_DPAD_RIGHT",
    "CB_MISC1",
    "CB_PADDLE1",
    "CB_PADDLE2",
    "CB_PADDLE3",
    "CB_PADDLE4",
    "CB_TOUCHPAD",
    };

    std::vector<std::string> displayList;
    std::string currentDisplay;

    std::vector<std::vector<std::string>> resList;
    std::string currentRes;

    std::string currentKey = keyList[0];
    std::string currentMouse = mouseButtonsList[0];

    void _reload() {
        std::ifstream in("config.json");
        Json::Value root;
        in >> root;
        in.close();

        Json::Value app = root["app"];
        _config.application.caption = app["caption"].asString();
        _config.application.fullscreen = app["fullscreen"].asBool();
        _config.application.display = app["display"].asInt();
        _config.application.resolution = app["resolution"].asInt();

        Json::Value input = root["input"];
        Json::Value im = input["mapping"];

        // Grabbing stuff for InputMapping
        for(int i = 0; i < im.size(); i++) {
            Json::Value item = im[i];

            std::string name = item["name"].asString();
            bool isMouse = item["is-mouse"].asBool();

            _config.input.mapping[name].name = name;
            //_config.input.mapping[name].currentValue = item["input"].asString();

            if(isMouse) {
                _config.input.mapping[name].currentMouseButton = item["input"].asString();

                input::MouseButtons mb = mouseButtons.at(item["input"].asString());
                input::initInputMapping(&_config.input.mapping[name].mapping, mb, isMouse);
            } else {
                _config.input.mapping[name].currentKey = item["input"].asString();

                input::Keyboard key = keys.at(item["input"].asString());
                input::initInputMapping(&_config.input.mapping[name].mapping, key);
            }
        }

        // Gamepad Mapping
        Json::Value gamepad = input["gamepad"];
        Json::Value players = gamepad["players"];

        std::cout << "Player Size: " << players.size() << "\n";

        _config.input.gamepad.players.clear();
        
        for(int i = 0; i < players.size(); i++) {
            Json::Value item = players[i];

            Json::Value mapping = item["mapping"];

            Player player;

            player.name = (input::gamepad::PlayerControllerName)i;

            for(int j = 0; j < mapping.size(); j++) {
                Json::Value item2 = mapping[j];

                std::string name2 = item2["name"].asString();

                player.mapping[name2].name = name2;

                player.mapping[name2].currentButton = item2["controller-button"].asString();

                std::cout << player.mapping[name2].name << ": " << player.mapping[name2].currentButton << "\n";

                input::gamepad::initInputMapping(&player.mapping[name2].mapping, player.name, controllerButtons[player.mapping[name2].currentButton]);
            }

            _config.input.gamepad.players.push_back(player);
        }

        /*
        for(int i = 0; i < im.size(); i++) {
            Json::Value item = im[i];

            std::string name = item["name"].asString();
            input::gamepad::PlayerControllerName playerName = playerNames[item["player-name"].asString()];
            input::gamepad::ControllerButton cb = controllerButtons[item["controller-button"].asString()];
            //input::gamepad::initInputMapping(&_config.input.gamepad.mapping[name], playerName, cb);
        }
        */

        Json::Value render = root["render"];
        // Will add stuff here later

        Json::Value physics = root["physics"];
        // Will add stuff here later

        Json::Value sound = root["sound"];
        _config.sound.masterVolume = sound["master-volume"].asFloat();
        _config.sound.musicVolume = sound["music-volume"].asFloat();
        _config.sound.soundFXVolume = sound["sound-fx-volume"].asFloat(); 
    }

    void init() {
        // Grabbing
        for(int i = 0; i < SDL_GetNumVideoDisplays(); i++) {
            std::stringstream ss;

            ss << "Display " << i;

            displayList.push_back(ss.str());
        }

        currentDisplay = displayList[_config.application.display];

        resList.resize(displayList.size());

        for(int i = 0; i < SDL_GetNumVideoDisplays(); i++) {

            for(int j = 0; j < SDL_GetNumDisplayModes(i); j++) {
                SDL_DisplayMode mode;

                SDL_GetDisplayMode(i, j, &mode);

                std::stringstream ss;

                ss << mode.w << "x" << mode.h << " @" << mode.refresh_rate << " format: " << SDL_GetPixelFormatName(mode.format);

                resList[i].push_back(ss.str());
            }

        }

        currentRes = resList[_config.application.display][_config.application.resolution];


        _reload();
    }

    void release() {
        // Not real sure what to do here
    }

    Config* getConfig() {
        return &_config;
    }

    void reload() {
        save();
        _config.input.mapping.clear();
        //_config.input.gamepad.mapping.clear();
        _reload();

        app::reloadRelease();
        app::reloadInit();
    }

    void save() {
        Json::Value root;

        Json::Value app;

        // App
        app["caption"] = _config.application.caption;
        app["fullscreen"] = _config.application.fullscreen;
        app["display"] = _config.application.display;
        app["resolution"] = _config.application.resolution;

        root["app"] = app;

        // Input
        Json::Value input;

        Json::Value im;

        for(std::map<std::string, KeyboardMouseInputMap>::iterator it = _config.input.mapping.begin(); it != _config.input.mapping.end(); it++) {
            Json::Value item;

            item["name"] = it->first;
            //item["input"] = 
            item["is-mouse"] = it->second.mapping.isMouse;

            if(it->second.mapping.isMouse) {
                item["input"] = mouseButtons_rev[(input::MouseButtons)it->second.mapping.input];
            } else {
                item["input"] = keys_rev[(input::Keyboard)it->second.mapping.input];
            }

            im.append(item);
        }

        input["mapping"] = im;

        Json::Value gamepad;

        Json::Value players;

        for(std::vector<Player>::iterator it = _config.input.gamepad.players.begin(); it != _config.input.gamepad.players.end(); it++) {
            Json::Value player;
            Json::Value mapping;
            //players.append(mapping);

            for(std::map<std::string, GamepadInputMapping>::iterator it2 = it->mapping.begin(); it2 != it->mapping.end(); it2++) {
                Json::Value item;

                std::cout << it2->second.name << ": " << it2->second.currentButton << "\n";

                item["name"] = it2->second.name;
                item["controller-button"] = it2->second.currentButton;

                mapping.append(item);
            }

            player["mapping"] = mapping;
            players.append(player);
        }
        
        gamepad["players"] = players;

        //Json::Value gim;

        /*
        for(std::map<std::string, input::gamepad::InputMapping>::iterator it = _config.input.gamepad.mapping.begin(); it != _config.input.gamepad.mapping.end(); it++) {
            Json::Value item;

            item["name"] = it->first;

            item["player-name"] = playerNames_rev[it->second.name];

            item["controller-button"] = controllerButtons_rev[it->second.button];

            gim.append(item);
        }
        */
        
        //gamepad["mapping"] = gim;

        input["gamepad"] = gamepad;

        root["input"] = input;

        // Render (TODO: Add stuff the render configuration)
        root["render"] = Json::Value(Json::objectValue);

        // Physics (TODO: Add stuff to physics configuration)
        root["physics"] = Json::Value(Json::objectValue);
        // Sound
        Json::Value sound;
        sound["master-volume"] = _config.sound.masterVolume;
        sound["music-volume"] = _config.sound.musicVolume;
        sound["sound-fx-volume"] = _config.sound.soundFXVolume;

        root["sound"] = sound;

        std::ofstream out("config.json");

        out << root;

        out.close();
    }

    void getKeysList(std::vector<std::string>& list) {
        std::for_each(keyList.begin(), keyList.end(), [&](std::string item) {
            list.push_back(item);
        });
    }

    void getMouseButtonList(std::vector<std::string>& list) {
        std::for_each(mouseButtonsList.begin(), mouseButtonsList.end(), [&](std::string item) {
            list.push_back(item);
        });
    }

    void getPlayerNameList(std::vector<std::string>& list) {
        std::for_each(playerNameList.begin(), playerNameList.end(), [&](std::string item) {
            list.push_back(item);
        });
    }

    void getGamePadButtonList(std::vector<std::string>& list) {
        std::for_each(controllerButtonsList.begin(), controllerButtonsList.end(), [&](std::string item) {
            list.push_back(item);
        });
    }


    // Menu Systems
    static bool needsReload = false;

    void appTab() {
        ImGui::Text("Application Config");

        ImGui::Text("Caption: %s", _config.application.caption.c_str());

        if(ImGui::Checkbox("Is Fullscreen?", &_config.application.fullscreen)) {
            needsReload = true;
        }

        if(ImGui::BeginCombo("Display", currentDisplay.data())) {
            for(int i = 0; i < displayList.size(); i++) {
                bool is_selected = (currentDisplay == displayList[i]);

                if(ImGui::Selectable(displayList[i].data(), is_selected)) {
                    currentDisplay = displayList[i];
                    _config.application.display = i;
                    needsReload = true;
                }

                if(is_selected) {
                    ImGui::SetItemDefaultFocus();
                }
            }

            ImGui::EndCombo();
        }

        if(ImGui::BeginCombo("Resolution", currentRes.data())) {
            for(int i = 0; i < resList[_config.application.display].size(); i++) {
                bool is_selected = (currentRes == resList[_config.application.display][i]);

                if(ImGui::Selectable(resList[_config.application.display][i].data(), is_selected)) {
                    currentRes = resList[_config.application.display][i];
                    _config.application.resolution = i;
                    needsReload = true;
                }
                
                if(is_selected) {
                    ImGui::SetItemDefaultFocus();
                }
            }

            ImGui::EndCombo();
        }
    }

    #define SIZE_OF_BUFFER 128
    char im_name_buf[SIZE_OF_BUFFER];

    bool im_is_mouse = false;
    std::string im_current_key = "KEYS_UNKNOWN";
    std::string im_current_mouse = "MBS_LEFT";
    
    void inputTab() {
        ImGui::Text("Input Config");

        ImGui::Separator();

        ImGui::Text("Keyboard/Mouse");

        // Add in input mapping
        ImGui::PushID("Add IM");

        ImGui::InputText("IM Name", im_name_buf, SIZE_OF_BUFFER);
        ImGui::Checkbox("Is Mouse?", &im_is_mouse);

        if(im_is_mouse) {
            if(ImGui::BeginCombo("Mouse Buttons", im_current_mouse.data())) {

                for(int i = 0; i < mouseButtonsList.size(); i++) {
                    bool is_selected = (im_current_mouse == mouseButtonsList[i]);

                    if(ImGui::Selectable(mouseButtonsList[i].data(), is_selected)) {
                        im_current_mouse = mouseButtonsList[i];
                        //input::initInputMapping(&it->second.mapping, mouseButtons[it->second.currentMouseButton], it->second.mapping.isMouse);
                    }

                    if(is_selected) {
                        ImGui::SetItemDefaultFocus();
                    }
                }

                ImGui::EndCombo();
            }
        } else {
            if(ImGui::BeginCombo("Keys", im_current_key.data())) {

                for(int i = 0; i < keyList.size(); i++) {
                    bool is_selected = (im_current_key == keyList[i]);

                    if(ImGui::Selectable(keyList[i].data(), is_selected)) {
                        im_current_key = keyList[i];
                        //input::initInputMapping(&it->second.mapping, keys[it->second.currentKey], it->second.mapping.isMouse);
                    }

                    if(is_selected) {
                        ImGui::SetItemDefaultFocus();
                    }
                }

                ImGui::EndCombo();
            }
        }

        if(ImGui::Button("Add Keyboard/MouseButton Mapping")) {
            _config.input.mapping[im_name_buf].name = im_name_buf;
            _config.input.mapping[im_name_buf].currentMouseButton = "KEYS_UNKNOWN";
            _config.input.mapping[im_name_buf].currentKey = "MBS_LEFT";
            if(im_is_mouse) {
                _config.input.mapping[im_name_buf].currentMouseButton = im_current_mouse;
                input::initInputMapping(&_config.input.mapping[im_name_buf].mapping, mouseButtons.at(im_current_mouse), true);
            } else {
                _config.input.mapping[im_name_buf].currentMouseButton = im_current_key;
                input::initInputMapping(&_config.input.mapping[im_name_buf].mapping, keys.at(im_current_key), false);
            }
        }

        ImGui::PopID();

        ImGui::Separator();

        std::vector<std::map<std::string, KeyboardMouseInputMap>::iterator> dels;

        for(std::map<std::string, KeyboardMouseInputMap>::iterator it = _config.input.mapping.begin(); it != _config.input.mapping.end(); it++) {

            std::stringstream id;

            id << "mapping_" << it->first.c_str();

            ImGui::PushID(id.str().c_str());

            ImGui::Text("Name: %s", it->first.c_str());

            ImGui::SameLine();

            ImGui::Checkbox("Is Mouse? ", &it->second.mapping.isMouse);

            ImGui::SameLine();

            if(it->second.mapping.isMouse) {
                if(ImGui::BeginCombo("Mouse Buttons", it->second.currentMouseButton.data())) {

                    for(int i = 0; i < mouseButtonsList.size(); i++) {
                        bool is_selected = (it->second.currentMouseButton == mouseButtonsList[i]);

                        if(ImGui::Selectable(mouseButtonsList[i].data(), is_selected)) {
                            it->second.currentMouseButton = mouseButtonsList[i];
                            input::initInputMapping(&it->second.mapping, mouseButtons[it->second.currentMouseButton], it->second.mapping.isMouse);
                        }

                        if(is_selected) {
                            ImGui::SetItemDefaultFocus();
                        }
                    }

                    ImGui::EndCombo();
                }
            } else {
                if(ImGui::BeginCombo("Keys", it->second.currentKey.data())) {

                    for(int i = 0; i < keyList.size(); i++) {
                        bool is_selected = (it->second.currentKey == keyList[i]);

                        if(ImGui::Selectable(keyList[i].data(), is_selected)) {
                            it->second.currentKey = keyList[i];
                            input::initInputMapping(&it->second.mapping, keys[it->second.currentKey], it->second.mapping.isMouse);
                        }

                        if(is_selected) {
                            ImGui::SetItemDefaultFocus();
                        }
                    }

                    ImGui::EndCombo();
                }
            }

            if(ImGui::Button("Remove")) {
                dels.push_back(it);
            }

            ImGui::PopID();
        }

        // Remove
        for(int i =0; i < dels.size(); i++) {
            _config.input.mapping.erase(dels[i]);
        }

        dels.clear();
        
        ImGui::Separator();

        ImGui::Text("Gamepads");

        ImGui::BeginTabBar("Gamepads Tabs");

        for(int i = 0; i < config::getConfig()->input.gamepad.players.size(); i++) {
            std::stringstream ss;

            ss << "Player " << (i+1);

            if(ImGui::BeginTabItem(ss.str().c_str())) {

                ImGui::PushID(ss.str().c_str());

                for(std::map<std::string, GamepadInputMapping>::iterator it = config::getConfig()->input.gamepad.players[i].mapping.begin(); it != config::getConfig()->input.gamepad.players[i].mapping.end(); it++) {
                    ImGui::Text("Name: %s", it->second.name.c_str());

                    if(ImGui::BeginCombo("Buttons", it->second.currentButton.data())) {

                        for(int j = 0; j < controllerButtonsList.size(); j++) {
                            bool is_selected = (it->second.currentButton == controllerButtonsList[j]);

                            if(ImGui::Selectable(controllerButtonsList[j].data(), is_selected)) {
                                it->second.currentButton = controllerButtonsList[j];
                                input::gamepad::initInputMapping(&it->second.mapping, config::getConfig()->input.gamepad.players[i].name, controllerButtons[it->second.currentButton]);
                            }

                            if(is_selected) {
                                ImGui::SetItemDefaultFocus();
                            }
                        }

                        ImGui::EndCombo();

                    }
                }

                ImGui::PopID();

                ImGui::EndTabItem();
            }
        }

        ImGui::EndTabBar();
    }

    void renderTab() {
        ImGui::Text("Render Tab");
    }

    bool drawConfigSystem() {

        if(input::isKeyPressedOnce(input::Keyboard::KEYS_F1)) {
            showSystemConfig = !showSystemConfig;
        }


        if(showSystemConfig) {
            ImGui::Begin("System Config");

            ImGui::BeginTabBar("System Config TabBar");

            if(ImGui::BeginTabItem("Application")) {
                appTab();
                ImGui::EndTabItem();
            }

            if(ImGui::BeginTabItem("Input")) {
                inputTab();
                ImGui::EndTabItem();
            }

            if(ImGui::BeginTabItem("Render")) {
                renderTab();
                ImGui::EndTabItem();
            }

            ImGui::EndTabBar();
            ImGui::Separator();

            if(needsReload) {
                if(ImGui::Button("Reload/Save")) {
                    reload();
                    needsReload = false;
                    return true;
                }
            } else {
                if(ImGui::Button("Save")) {
                    save();
                }
            }

            ImGui::SameLine();

            if(ImGui::Button("Close")) {
                showSystemConfig = false;
            }

            ImGui::End();
        }

        return false;
    }

}