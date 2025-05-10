//
// Created by leoin on 2025-05-10.
//

#include "Console.h"
#include <limits>
#include <iostream>

void Console::get_name(Character &character) {
    std::cout << "Enter your name:\n>";
    std::cout.flush();
    std::getline(std::cin, character.name);
}

void Console::get_class(Character &character) {
    int choice;
    std::cout << "Pick your class:\n";
    display_class_choices();
    cin >> choice;
    while (!(choice > 0 && choice <= 12)) {
        std::cout << "Invalid choice, please pick again:\n>";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> choice;
    }
    character.character_class = static_cast<DnD::Class>(choice);
}

void Console::display_class_choices() {
    for (int i = 1; i <= static_cast<int>(DnD::Class::Warlock); ++i) {
        const auto character_class = static_cast<DnD::Class>(i);
        printf("%3d. %s\n", i, DnD::class_to_string(character_class).c_str());
    }
    cout << "\nYour choice:\n>";
}

void Console::get_race(Character &character) {
    int choice;
    std::cout << "Pick your race:\n";
    printf("%-17s %-10s\n", "  Race", "Stats Bonus");
    display_race_choices();
    cin >> choice;
    while (!(choice > 0 && choice <= 10)) {
        std::cout << "Invalid choice, please pick again:\n>";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> choice;
    }
    character.character_race = static_cast<DnD::Race>(choice);
    switch (choice) {
        case 1: character.race_bonus = {1, 0, 0, 0, 0, 1};
        case 2: character.race_bonus = {0, 2, 0, 0, 0, 0};
        case 3: character.race_bonus = {0, 1, 0, 0, 0, 1};
        case 4: character.race_bonus = {2, 0, 0, 0, 0, 0};
        case 5: character.race_bonus = {0, 0, 2, 0, 0, 0};
        case 6: character.race_bonus = {0, 1, 1, 0, 0, 0};
        case 7: character.race_bonus = {0, 0, 1, 1, 0, 0};
        case 8: character.race_bonus = {0, 0, 0, 1, 0, 1};
        case 9: character.race_bonus = {0, 1, 0, 1, 0, 0};
        case 10: character.race_bonus = {1, 0, 0, 0, 0, 1};
    }
}

void Console::display_race_choices() {
    for (int i = 1; i <= static_cast<int>(DnD::Race::Dragonborn); ++i) {
        const auto character_race = static_cast<DnD::Race>(i);
        printf("%3d. %-12s", i, DnD::race_to_string(character_race).c_str());
        printf("%s\n", DnD::race_bonuses(character_race).c_str());
    }
    cout << "\nYour choice:\n>";
}


