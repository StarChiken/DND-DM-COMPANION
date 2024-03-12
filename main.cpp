#include <iostream>
#include "diceroller.h"
using namespace std;

int main() {
    int D4num_of_rolls, D6num_of_rolls, D8num_of_rolls, D10num_of_rolls,
    D12num_of_rolls, D20num_of_rolls, D100num_of_rolls; // declares number of rolls variable for each dice
    int D4total = 0, D6total = 0, D8total = 0, D10total = 0, D12total = 0, D20total = 0, 
    D100total = 0, final_total = 0; // sets all totals to 0

    // asks the user to enter number of rolls for each dice
    cout << "\nEnter the number of rolls for a D4 dice: ";
    cin >> D4num_of_rolls;

    if (D4num_of_rolls < 0) {
    cout << "Invalid number. Please enter a positive number of rolls." << endl;
    return -1;
    }

    cout << "Enter the number of rolls for a D6 dice: ";
    cin >> D6num_of_rolls;

    if (D6num_of_rolls < 0) {
    cout << "Invalid number. Please enter a positive number of rolls." << endl;
    return -1;
    }

    cout << "Enter the number of rolls for a D8 dice: ";
    cin >> D8num_of_rolls;

    if (D8num_of_rolls < 0) {
    cout << "Invalid number. Please enter a positive number of rolls." << endl;
    return -1;
    }

    cout << "Enter the number of rolls for a D10 dice: ";
    cin >> D10num_of_rolls;

    if (D10num_of_rolls < 0) {
    cout << "Invalid number. Please enter a positive number of rolls." << endl;
    return -1;
    }

    cout << "Enter the number of rolls for a D12 dice: ";
    cin >> D12num_of_rolls;

    if (D12num_of_rolls < 0) {
    cout << "Invalid number. Please enter a positive number of rolls." << endl;
    return -1;
    }

    cout << "Enter the number of rolls for a D20 dice: ";
    cin >> D20num_of_rolls;

    if (D20num_of_rolls < 0) {
    cout << "Invalid number. Please enter a positive number of rolls." << endl;
    return -1;
    }

    cout << "Enter the number of rolls for a D100 dice: ";
    cin >> D100num_of_rolls;
    cout << "\n";

    if (D20num_of_rolls < 0) {
    cout << "Invalid number. Please enter a positive number of rolls." << endl;
    return -1;
    }

    // calls each function in diceroller.cpp and outputs the dice type total
    D4Roll(D4num_of_rolls, D4total, final_total);
    cout << "D4 Total: " << D4total << endl << "\n";

    D6Roll(D6num_of_rolls, D6total, final_total);
    cout << "D6 Total: " << D6total << endl << "\n";

    D8Roll(D8num_of_rolls, D8total, final_total);
    cout << "D8 Total: " << D8total << endl << "\n";
    
    D10Roll(D10num_of_rolls, D10total, final_total);
    cout << "D10 Total: " << D10total << endl << "\n";

    D12Roll(D12num_of_rolls, D12total, final_total);
    cout << "D12 Total: " << D12total << endl << "\n";

    D20Roll(D20num_of_rolls, D20total, final_total);
    cout << "D20 Total: " << D20total << endl << "\n";

    D100Roll(D100num_of_rolls, D100total, final_total);
    cout << "D100 Total: " << D100total << endl << "\n";

    // outputs the total of all roll results
    cout << "Final Total: " << final_total << endl << "\n";

    return 0;
}