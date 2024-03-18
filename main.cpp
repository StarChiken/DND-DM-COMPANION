#include <iostream>
#include "diceroller.h"
using namespace std;

int main() {
    int numberOfRolls;
    unsigned seed = time(0);
    srand(seed);

    // asks the user to enter number of rolls for each dice
    cout << "\nEnter the number of rolls for a D4 dice: ";
    cin >> numberOfRolls;

    if (numberOfRolls < 0) {
    cout << "Invalid number. Please enter a positive number of rolls." << endl;
    return -1;
    }

    cout << "Enter the number of rolls for a D6 dice: ";
    cin >> numberOfRolls;

    if (numberOfRolls < 0) {
    cout << "Invalid number. Please enter a positive number of rolls." << endl;
    return -1;
    }

    cout << "Enter the number of rolls for a D8 dice: ";
    cin >> numberOfRolls;

    if (numberOfRolls < 0) {
    cout << "Invalid number. Please enter a positive number of rolls." << endl;
    return -1;
    }

    cout << "Enter the number of rolls for a D10 dice: ";
    cin >> numberOfRolls;

    if (numberOfRolls < 0) {
    cout << "Invalid number. Please enter a positive number of rolls." << endl;
    return -1;
    }

    cout << "Enter the number of rolls for a D12 dice: ";
    cin >> numberOfRolls;

    if (numberOfRolls < 0) {
    cout << "Invalid number. Please enter a positive number of rolls." << endl;
    return -1;
    }

    cout << "Enter the number of rolls for a D20 dice: ";
    cin >> numberOfRolls;

    if (numberOfRolls < 0) {
    cout << "Invalid number. Please enter a positive number of rolls." << endl;
    return -1;
    }

    cout << "Enter the number of rolls for a D100 dice: ";
    cin >> numberOfRolls;
    cout << "\n";

    if (numberOfRolls < 0) {
    cout << "Invalid number. Please enter a positive number of rolls." << endl;
    return -1;
    }

    // calls each function in diceroller.cpp and outputs the dice type total
    cout << "D4 Total: " << D4Roll(numberOfRolls) << endl << "\n";

    cout << "D6 Total: " << D6Roll(numberOfRolls) << endl << "\n";

    cout << "D8 Total: " << D8Roll(numberOfRolls) << endl << "\n";
    
    cout << "D10 Total: " << D10Roll(numberOfRolls) << endl << "\n";

    cout << "D12 Total: " << D12Roll(numberOfRolls) << endl << "\n";

    cout << "D20 Total: " << D20Roll(numberOfRolls) << endl << "\n";

    cout << "D100 Total: " << D100Roll(numberOfRolls) << endl << "\n";

    return 0;
}