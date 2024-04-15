#include <iostream>

#include "diceroller.h"
#include "randomnumbers.h"
#include "libraries/magic_enum.hpp"

using namespace std;

int RollDice(Dice diceType, int numberOfRolls)
{
    int totalOfRolls = 0;

    for (int i = 0; i < numberOfRolls; i++)
    {
        int currentRoll = GetRandomNumberByRange(1, (int)diceType);
        totalOfRolls += GetRandomNumberByRange(1, (int)diceType);
        cout << 'D' << (int)diceType << " Roll #" << i + 1 << ": " << currentRoll << endl;
    }
    return totalOfRolls;
}