#include <iostream>
#include <cstdlib>
#include <time.h>
#include "diceroller.h" // header file
using namespace std;

// function definition for D4 dice
int D4Roll(int numberOfRolls) {
    int total = 0;
    int diceRoll;

    // loop iterating the amount of rolls a user wants
    for (int i = 0; i < numberOfRolls; i++) {
        diceRoll = 1 + (rand() % 4);
        total += diceRoll;
        cout << "D4 Roll #" << i + 1 << ": " << diceRoll << endl;
    }
    return total;
}

// function definition for D6 dice
int D6Roll(int numberOfRolls) {
    int total = 0;
    int diceRoll;

    // loop iterating the amount of rolls a user wants
    for (int i = 0; i < numberOfRolls; i++) {
        diceRoll = 1 + (rand() % 6);
        total += diceRoll;
        cout << "D6 Roll #" << i + 1 << ": " << diceRoll << endl;
    }
    return total;
}

// function definition for D8 dice
int D8Roll(int numberOfRolls) {
    int total = 0;
    int diceRoll;

    // loop iterating the amount of rolls a user wants
    for (int i = 0; i < numberOfRolls; i++) {
        diceRoll = 1 + (rand() % 8);
        total += diceRoll;
        cout << "D8 Roll #" << i + 1 << ": " << diceRoll << endl;
    }
    return total;
}

// function definition for D10 dice
int D10Roll(int numberOfRolls) {
    int total = 0;
    int diceRoll;

    // loop iterating the amount of rolls a user wants
    for (int i = 0; i < numberOfRolls; i++) {
        diceRoll = 1 + (rand() % 10);
        total += diceRoll;
        cout << "D10 Roll #" << i + 1 << ": " << diceRoll << endl;
    }
    return total;
}

// function definition for D12 dice
int D12Roll(int numberOfRolls) {
    int total = 0;
    int diceRoll;

    // loop iterating the amount of rolls a user wants
    for (int i = 0; i < numberOfRolls; i++) {
        diceRoll = 1 + (rand() % 12);
        total += diceRoll;
        cout << "D12 Roll #" << i + 1 << ": " << diceRoll << endl;
    }
    return total;
}

// function definition for D20 dice
int D20Roll(int numberOfRolls) {
    int total = 0;
    int diceRoll;

    // loop iterating the amount of rolls a user wants
    for (int i = 0; i < numberOfRolls; i++) {
        diceRoll = 1 + (rand() % 20);
        total += diceRoll;
        cout << "D20 Roll #" << i + 1 << ": " << diceRoll << endl;
    }
    return total;
}

// function definition for D100 dice
int D100Roll(int numberOfRolls) {
    int total = 0;
    int diceRoll;

    // loop iterating the amount of rolls a user wants
    for (int i = 0; i < numberOfRolls; i++) {
        diceRoll = 1 + (rand() % 100);
        total += diceRoll;
        cout << "D100 Roll #" << i + 1 << ": " << diceRoll << endl;
    }
    return total;
}