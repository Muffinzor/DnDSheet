#ifndef DICEROLL_H
#define DICEROLL_H
#include <array>

using namespace std;

class DiceRoll {
public:
    array<int, 6> stats_results;
    array<int, 6> roll_stats();

private:
    int stat_roll_4d6();
};

#endif //DICEROLL_H
