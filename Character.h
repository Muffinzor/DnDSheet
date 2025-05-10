#ifndef CHARACTER_H
#define CHARACTER_H
#include <array>
#include <string>
#include "DnD.h"

using namespace std;

class Character {
public:
    string name;
    DnD::Class character_class;
    DnD::Race character_race;
    array<int, 6> stats{};
    array<int, 6> race_bonus{};

    Character();
    void set_name(const string &name);
    void set_class(DnD::Class class_);
    void set_race(DnD::Race race_);
    void set_stats(const array<int, 6> &stats_);
};

#endif //CHARACTER_H
