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
    int hp = 0;

    Character();
    void set_name(const string &name);
    void set_class(DnD::Class class_);
    void set_race(DnD::Race race_);
    void set_initial_hp();

    void apply_race_bonus();

    void assign_stats(vector<int> &rolls_);
    void assign_individual_stats(vector<int> &rolls_, int stat);

    void display_stats() const;
    int get_stat_modifier(int stat) const;
};

#endif //CHARACTER_H
