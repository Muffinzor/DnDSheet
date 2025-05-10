//
// Created by leoin on 2025-05-10.
//

#include "Console.h"
#include <limits>
#include <algorithm>
#include <iostream>
#include <fstream>

void Console::clearScreen() {
    std::cout << "\033[2J\033[H" << std::flush;
}

void Console::get_name(Character &character) {
    clearScreen();
    std::cout << "Enter your name:\n>";
    std::cout.flush();
    std::getline(std::cin, character.name);
}

void Console::get_lvl(Character &character) {
    clearScreen();
    int lvl;
    std::cout << "What's your character's level:\n>";
    cin >> lvl;
    while (!(lvl > 0 && lvl <= 20)) {
        std::cout << "Pick a value between 1 and 20\n>";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> lvl;
    }
    character.lvl = lvl;
}

void Console::get_class(Character &character) {
    clearScreen();
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
    clearScreen();
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
        case 1: character.race_bonus = {1, 0, 0, 0, 0, 1}; break;
        case 2: character.race_bonus = {0, 2, 0, 0, 0, 0}; break;
        case 3: character.race_bonus = {0, 1, 0, 0, 0, 1}; break;
        case 4: character.race_bonus = {2, 0, 0, 0, 0, 0}; break;
        case 5: character.race_bonus = {0, 0, 2, 0, 0, 0}; break;
        case 6: character.race_bonus = {0, 1, 1, 0, 0, 0}; break;
        case 7: character.race_bonus = {0, 0, 1, 1, 0, 0}; break;
        case 8: character.race_bonus = {0, 0, 0, 1, 0, 1}; break;
        case 9: character.race_bonus = {0, 1, 0, 1, 0, 0}; break;
        case 10: character.race_bonus = {1, 0, 0, 0, 0, 1}; break;
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

void Console::ask_to_print(Character &character) {
    printf("\nDo you want to save this character sheet as a text file? y/n\n>");
    char choice;
    cin >> choice;
    while (!(choice == 'y' || choice == 'n')) {
        std::cout << "Invalid choice, please type 'y' or 'n':\n> ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> choice;
    }
    if(choice == 'y') {
        save_textfile(character);
    } else {
        printf("Very well, see you next time!\n");
    }
}

void Console::save_textfile(Character &character) {
    string filename = character.name;
    std::replace(filename.begin(), filename.end(), ' ', '_');
    filename += ".txt";
    std::ofstream file(filename.c_str());
    if (file.is_open()) {
        character.display_stats(file);
        file.close();
        printf("It's done!\n");
    }
}


