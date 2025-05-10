#ifndef DICEROLLER_H
#define DICEROLLER_H
#include <vector>

using namespace std;

class DiceRoller {
public:
    static int random_int(int min, int max);

    static vector<int> roll_stats();
    static void confirm_stat_rolls(vector<int> &rolls_);
    static void display_stat_rolls(const vector<int> &rolls_);

private:
    static int stat_roll_4d6();
};

#endif //DICEROLLER_H
