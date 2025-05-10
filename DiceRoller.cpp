#include "DiceRoller.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <random>

int random_int(const int min, const int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dist(min, max);
    return dist(gen);
}

vector<int> DiceRoller::roll_stats() {
    vector<int> rolls{};
    for (int i = 0; i < 6; i++) {
        rolls.push_back(stat_roll_4d6());
    }
    return rolls;
}

void DiceRoller::confirm_stat_rolls(vector<int> &rolls_) {
    printf("Here are your rolled stats:\n");
    display_stat_rolls(rolls_);
    printf("You can mulligan once, do you want to keep these rolls? y/n\n>");
    char choice;
    cin >> choice;
    while (!(choice == 'y' || choice == 'n')) {
        std::cout << "Invalid choice, please type 'y' or 'n':\n>";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> choice;
    }
    if (choice == 'n') {
        rolls_ = roll_stats();
    }
}

void DiceRoller::display_stat_rolls(const vector<int> &rolls_) {
    for (int i = 0; i < rolls_.size(); i++) {
        printf("%d: %d\n", i + 1, rolls_[i]);
    }
}

int DiceRoller::stat_roll_4d6() {
    array<int, 4> dices{};
    for (int i = 0; i < 4; i++) {
        dices[i] = random_int(1, 6);
    }
    ranges::sort(dices);
    return dices[1] + dices[2] + dices[3];

}

