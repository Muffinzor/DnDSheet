#ifndef CONSOLE_H
#define CONSOLE_H
#include "Character.h"

class Console {
public:
    static void get_name(Character &character);
    static void get_lvl(Character &character);
    static void display_class_choices();
    static void get_class(Character &character);
    static void display_race_choices();
    static void get_race(Character &character);
    static void clearScreen();
};

#endif //CONSOLE_H
