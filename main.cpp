#include <iostream>

#include "Console.h"
#include "DiceRoller.h"

int main() {
    Character character = Character();
    Console::get_name(character);
    Console::get_class(character);
    Console::get_race(character);
    Console::get_lvl(character);

    auto stats = DiceRoller::roll_stats();
    DiceRoller::confirm_stat_rolls(stats);
    character.assign_stats(stats);
    character.apply_race_bonus();
    character.set_initial_hp();
    character.set_lvl_hp();
    character.display_stats(std::cout);
    Console::ask_to_print(character);


    return 0;
}
