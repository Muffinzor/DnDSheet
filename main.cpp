#include <iostream>

#include "Console.h"
#include "DiceRoller.h"

int main() {
    Character character = Character();
    auto stats = DiceRoller::roll_stats();
    DiceRoller::confirm_rolls(stats);


    return 0;
}
