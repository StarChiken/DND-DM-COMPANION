#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to generate a random number within a range
int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a random encounter based on desired challenge rating and enemy count
void generateEncounter(int desiredCR, int enemyCount, const map<string, int>& enemies) {
    // Output the encounter details
    cout << "\nGenerated Encounter" << endl;
    cout << "Desired Challenge Rating: " << desiredCR << endl;

    // Determine the maximum challenge rating for enemies
    int maxCR = min(desiredCR, 10); // Maximum CR is 10

    // Creates a list of enemies based on the desired challenge rating
    vector<string> selectedEnemies;
    map<string, int>::const_iterator it;
    for (it = enemies.begin(); it != enemies.end(); ++it) {
        if (it->second <= maxCR) {
            selectedEnemies.push_back(it->first);
        }
    }

    // Outputs the encounter
    if (enemyCount == 1) { // If only one enemy is generated
        int index = random(0, selectedEnemies.size() - 1); 
        cout << "There is a " << selectedEnemies[index] << "." << endl;
    } 
    else { // If multiple enemies are generated
        cout << "There are " << enemyCount << " enemies: ";
        for (int i = 0; i < enemyCount; ++i) { // Lists the name for each enemy generated
            int index = random(0, selectedEnemies.size() - 1);
            cout << selectedEnemies[index];
            if (i != enemyCount - 1) {
                cout << ", ";
            }
        }
        cout << "." << endl;
    }
}

int main() {
    // Seeding the random number generator
    srand(time(nullptr));

    // Map of the enemies in alphabetical order (somewhat) and their challenge ratings (called CR)
    map<string, int> enemies;
    // CR 1
    enemies["animated armor"] = 1;
    enemies["brass dragon wyrmling"] = 1;
    enemies["copper dragon wyrmling"] = 1;
    enemies["goblin boss"] = 1;
    // CR 2
    enemies["ankheg"] = 2;
    enemies["azer"] = 2;
    enemies["bronze dragon wyrmling"] = 2;
    enemies["centaur"] = 2;
    // CR 3
    enemies["ankylosaurus"] = 3;
    enemies["basilisk"] = 3;
    enemies["doppelganger"] = 3;
    enemies["githyanki warrior"] = 3;
    // CR 4
    enemies["banshee"] = 4;
    enemies["bone naga"] = 4;
    enemies["chuul"] = 4;
    enemies["ghost"] = 4;
    // CR 5
    enemies["cambion"] = 5;
    enemies["hill giant"] = 5;
    enemies["night hag"] = 5;
    // CR 6
    enemies["drider"] = 6;
    enemies["hobgoblin warlord"] = 6;
    enemies["kuo-toa archpriest"] = 6;
    enemies["vrock"] = 6;
    // CR 7
    enemies["grick alpha"] = 7;
    enemies["mind flayer"] = 7;
    enemies["stone giant"] = 7;
    // CR 8
    enemies["hydra"] = 8;
    enemies["tyrannosaurus rex"] = 8;
    enemies["young bronze dragon"] = 8;
    // CR 9
    enemies["abominable yeti"] = 9;
    enemies["bone devil"] = 9;
    enemies["young silver dragon"] = 9;
    // CR 10
    enemies["aboleth"] = 10;
    enemies["guardian naga"] = 10;
    enemies["stone golem"] = 10;

    // Gets user inputs
    int desiredCR, enemyCount;
    cout << "Enter the desired challenge rating for the enemies (1-10): ";
    cin >> desiredCR;
    cout << "Enter the desired enemy count: ";
    cin >> enemyCount;

    // Generate the encounter
    generateEncounter(desiredCR, enemyCount, enemies);

    return 0;
}
