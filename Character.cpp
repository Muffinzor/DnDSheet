#include "Character.h"

#include <iostream>
#include <vector>

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

void Character::set_stats(vector<int> &stats_) {

}




