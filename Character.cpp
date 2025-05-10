#include "Character.h"

#include <iostream>
#include <limits>
#include <vector>
#include "DiceRoller.h"

Character::Character() {
    this->character_class = DnD::Class::None;
    this->character_race = DnD::Race::None;
}

void Character::set_name(const string &name) {
    this->name = name;
}

void Character::set_class(const DnD::Class class_) {
    this->character_class = class_;
}

void Character::set_race(const DnD::Race race_) {
    this->character_race = race_;
}

void Character::apply_race_bonus() {
    for (int i = 0; i < this->race_bonus.size(); i++) {
        this->stats[i] += this->race_bonus[i];
    }
}
void Character::assign_stats(vector<int> &rolls_) {
    for (int i = 0; i < 5; i++) {
        assign_individual_stats(rolls_, i);
    }
    this->stats[5] = rolls_[0];
}

void Character::assign_individual_stats(vector<int> &rolls_, const int stat) {
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
    int choice;
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




