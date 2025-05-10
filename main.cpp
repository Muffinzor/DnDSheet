#include <iostream>

#include "Console.h"
#include "DiceRoller.h"

int main() {
    Character character = Character();

    auto stats = DiceRoller::roll_stats();
    DiceRoller::confirm_stat_rolls(stats);
    character.assign_stats(stats);


    return 0;
}
