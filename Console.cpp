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

void Console::display_race_choices() {
    for (int i = 1; i <= static_cast<int>(DnD::Race::Dragonborn); ++i) {
        const auto character_race = static_cast<DnD::Race>(i);
        printf("%3d. %s\n", i, DnD::race_to_string(character_race).c_str());
    }
    cout << "\nYour choice:\n>";
}


