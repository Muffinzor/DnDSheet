#include <iostream>

#include "Console.h"
#include "DiceRoller.h"

int main() {
    Character character = Character();
    Console::get_class(character);
    Console::get_race(character);

    auto stats = DiceRoller::roll_stats();
    DiceRoller::confirm_stat_rolls(stats);
    character.assign_stats(stats);
    character.apply_race_bonus();
    character.set_initial_hp();
    character.display_stats();


    return 0;
}
