#include <iostream>
#include <cstdlib>
#include <time.h>
#include "diceroller.h" // header file
using namespace std;

// function definition for D4 dice
int D4Roll(int D4num_of_rolls, int& D4total, int& final_total) {
    int dice_roll;

    unsigned seed = time(0);
    srand(seed);

    // loop interating the amount of rolls a user wants
    for (int i = 0; i < D4num_of_rolls; i++) {
        dice_roll = rand() % 4 + 1; // random number between 1 and 4
        D4total += dice_roll; // adds each D4 dice roll to D4 total
        cout << "D4 Roll #" << i + 1 << ": " << dice_roll << endl;
    }
    final_total = final_total + D4total; // adds total D4 rolls to final total
    return 0;
    
}

// function definition for D6 dice
int D6Roll(int D6num_of_rolls, int& D6total, int& final_total) {
    int dice_roll;

    unsigned seed = time(0);
    srand(seed);

    // loop interating the amount of rolls a user wants
    for (int i = 0; i < D6num_of_rolls; i++) {
        dice_roll = rand() % 6 + 1; // random number between 1 and 6
        D6total += dice_roll; // adds each D6 dice roll to D6 total
        cout << "D6 Roll #" << i + 1 << ": " << dice_roll << endl;
    }
    final_total = final_total + D6total; // adds total D6 rolls to final total
    return 0;
    
}

// function definition for D8 dice
int D8Roll(int D8num_of_rolls, int& D8total, int& final_total) {
    int dice_roll;

    unsigned seed = time(0);
    srand(seed);

    // loop interating the amount of rolls a user wants
    for (int i = 0; i < D8num_of_rolls; i++) {
        dice_roll = rand() % 8 + 1; // random number between 1 and 8
        D8total += dice_roll; // adds each D8 dice roll to D8 total
        cout << "D8 Roll #" << i + 1 << ": " << dice_roll << endl;
    }
    final_total = final_total + D8total; // adds total D8 rolls to final total
    return 0;
    
}

// function definition for D10 dice
int D10Roll(int D10num_of_rolls, int& D10total, int& final_total) {
    int dice_roll;

    unsigned seed = time(0);
    srand(seed);

    // loop interating the amount of rolls a user wants
    for (int i = 0; i < D10num_of_rolls; i++) {
        dice_roll = rand() % 10 + 1; // random number between 1 and 10
        D10total += dice_roll; // adds each D10 dice roll to D10 total
        cout << "D10 Roll #" << i + 1 << ": " << dice_roll << endl;
    }
    final_total = final_total + D10total; // adds total D10 rolls to final total
    return 0;
    
}

// function definition for D12 dice
int D12Roll(int D12num_of_rolls, int& D12total, int& final_total) {
    int dice_roll;

    unsigned seed = time(0);
    srand(seed);

    // loop interating the amount of rolls a user wants
    for (int i = 0; i < D12num_of_rolls; i++) {
        dice_roll = rand() % 12 + 1; // random number between 1 and 12
        D12total += dice_roll;// adds each D12 dice roll to D12 total
        cout << "D12 Roll #" << i + 1 << ": " << dice_roll << endl;
    }
    final_total = final_total + D12total; // adds total D12 rolls to final total
    return 0;
    
}

// function definition for D20 dice
int D20Roll(int D20num_of_rolls, int& D20total, int& final_total) {
    int dice_roll;

    unsigned seed = time(0);
    srand(seed);

    // loop interating the amount of rolls a user wants
    for (int i = 0; i < D20num_of_rolls; i++) {
        dice_roll = rand() % 20 + 1; // random number between 1 and 20
        D20total += dice_roll; // adds each D20 dice roll to D20 total
        cout << "D20 Roll #" << i + 1 << ": " << dice_roll << endl;
    }
    final_total = final_total + D20total; // adds total D20 rolls to final total
    return 0;
    
}

// function definition for D100 dice
int D100Roll(int D100num_of_rolls, int& D100total, int& final_total) {
    int dice_roll;

    unsigned seed = time(0);
    srand(seed);

    // loop interating the amount of rolls a user wants
    for (int i = 0; i < D100num_of_rolls; i++) {
        dice_roll = rand() % 100 + 1; // random number between 1 and 100
        D100total += dice_roll; // adds each D100 dice roll to D100 total
        cout << "D100 Roll #" << i + 1 << ": " << dice_roll << endl;
    }
    final_total = final_total + D100total; // adds total D100 rolls to final total
    return 0;
    
}