#ifndef CHARACTER_H
#define CHARACTER_H
#include <array>
#include <string>
#include <vector>

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
    static void set_stats(vector<int> &rolls_);

    static void display_stat_rolls(const vector<int> &rolls_);
};

#endif //CHARACTER_H
