#include "Character.h"

#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include "DiceRoller.h"
#include "Console.h"

Character::Character() {
    this->character_class = DnD::Class::None;
    this->character_race = DnD::Race::None;
}

void Character::set_name(const string &name) {
    this->name = name;
}

void Character::set_level(const int lvl) {
    this->lvl = lvl;
}

void Character::set_class(const DnD::Class class_) {
    this->character_class = class_;
}

void Character::set_race(const DnD::Race race_) {
    this->character_race = race_;
}

void Character::set_initial_hp() {
    int initial_value = 0;
    switch (this->character_class) {
        case DnD::Class::Barbarian:
            initial_value = 12;
            break;
        case DnD::Class::Fighter:
        case DnD::Class::Paladin:
        case DnD::Class::Ranger:
            initial_value = 10;
            break;
        case DnD::Class::Cleric:
        case DnD::Class::Druid:
        case DnD::Class::Bard:
        case DnD::Class::Rogue:
        case DnD::Class::Monk:
        case DnD::Class::Warlock:
            initial_value = 8;
            break;
        case DnD::Class::Wizard:
        case DnD::Class::Sorcerer:
            initial_value = 6;
            break;
        case DnD::Class::None:
            initial_value = 2;
    }
    this->hp = initial_value + get_stat_modifier(2);
}

void Character::set_lvl_hp() {
    int base_hp = hp - get_stat_modifier(2);
    for (int i = 1; i < lvl; i++) {
        hp += DiceRoller::random_int(1, base_hp) + get_stat_modifier(2);
    }
}


void Character::apply_race_bonus() {
    for (unsigned int i = 0; i < this->race_bonus.size(); i++) {
        this->stats[i] += this->race_bonus[i];
    }
}
void Character::assign_stats(vector<int> &rolls_) {
    for (int i = 0; i < 5; i++) {
        assign_individual_stats(rolls_, i);
    }
    this->stats[5] = rolls_[0];
    Console::clearScreen();
}

void Character::assign_individual_stats(vector<int> &rolls_, const int stat) {
    Console::clearScreen();
    printf("Here are your remaining rolls:\n");
    DiceRoller::display_stat_rolls(rolls_);
    string stat_string;
    switch (stat) {
        case 0: stat_string = "Strength"; break;
        case 1: stat_string = "Dexterity"; break;
        case 2: stat_string = "Constitution"; break;
        case 3: stat_string = "Intelligence"; break;
        case 4: stat_string = "Wisdom"; break;
    }
    printf("%s %s\n>", "Assign your", stat_string.c_str());
    unsigned int choice;
    cin >> choice;
    while (!(choice > 0 && choice <= rolls_.size())) {
        std::cout << "Invalid choice, please pick again:\n> ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> choice;
    }
    this->stats[stat] = rolls_[choice-1];
    rolls_.erase(rolls_.begin() + (choice-1));
}

void Character::display_stats(std::ostream& out) const {
    out << "Name: " << this->name << '\n';
    out << "Level " << this->lvl << ' ' << DnD::class_to_string(this->character_class) << '\n';

    for (int i = 0; i < 6; i++) {
        std::string stat_string;
        std::string stat_modifier;
        switch (i) {
            case 0: stat_string = "STR"; break;
            case 1: stat_string = "DEX"; break;
            case 2: stat_string = "CON"; break;
            case 3: stat_string = "INT"; break;
            case 4: stat_string = "WIS"; break;
            case 5: stat_string = "CHA"; break;
        }
        int stat_mod = get_stat_modifier(i);
        if (stat_mod >= 0) {
            stat_modifier = "+" + std::to_string(stat_mod);
        } else {
            stat_modifier = std::to_string(stat_mod);
        }
        out << stat_string << ": " << std::setw(3) << this->stats[i] << " [" << stat_modifier << "]\n";
    }
    out << "Hit points: " << this->hp << '\n';
}


int Character::get_stat_modifier(const int stat) const {
    const int value = this->stats[stat];
    const int modifier = (value/2) - 5;
    return modifier;
}





