#include <iostream>
#include <sys/stat.h>

#include "npc.h"
#include "logger.h"
#include "diceroller.h"

using namespace std;

void MainMenuInterface();
void DiceRollerInterface();
void NPCInterface();
int GetOption(int, int);

int main()
{
    InitializeLogger();
    InitializeNPCVectors();
    
    struct stat sb;
    if (stat("resources", &sb) != 0)
    {
        PrintToLog("resources folder needed, please refer to README file", true);
        return 1;
    }

    MainMenuInterface();

    CloseLogger();
    return 0;
}

void MainMenuInterface()
{
    cout << "\n====DND DM COMPANION====" << endl;
    cout << "    1. Dice Roller" << endl;
    cout << "    2. NPC Helper" << endl;
    cout << "    3. Exit Program" << endl;

    int option = GetOption(1, 3);

    if (option == 1) DiceRollerInterface();
    else if (option == 2) NPCInterface();
    else if (option == 3) exit(0);
}

void DiceRollerInterface()
{
    int totalOfRolls = 0;
    cout << "\n====DICE ROLLER====" << endl;
    while (true)
    {
        cout << "    1. D4" << endl;
        cout << "    2. D6" << endl;
        cout << "    3. D8" << endl;
        cout << "    4. D10" << endl;
        cout << "    5. D12" << endl;
        cout << "    6. D20" << endl;
        cout << "    7. D100" << endl;
        cout << "    8. Back To Menu" << endl;

        int option = GetOption(1, 8);

        int numberOfRolls;
        cout << "Enter Number of Rolls: ";
        cin >> numberOfRolls;
        while (numberOfRolls < 1)
        {
            cout << "Number of rolls must be 1 or more" << endl;
            cout << "Enter Number of Rolls: ";
            cin >> numberOfRolls;
        }

        int rolledValue;
        if (option == 1) rolledValue = RollDice(D4, numberOfRolls);
        else if (option == 2) rolledValue = RollDice(D6, numberOfRolls);
        else if (option == 3) rolledValue = RollDice(D8, numberOfRolls);
        else if (option == 4) rolledValue = RollDice(D10, numberOfRolls);
        else if (option == 5) rolledValue = RollDice(D12, numberOfRolls);
        else if (option == 6) rolledValue = RollDice(D20, numberOfRolls);
        else if (option == 7) rolledValue = RollDice(D100, numberOfRolls);
        else if (option == 8) break;

        totalOfRolls += rolledValue;

        cout << "\nSum of Dice Rolled: " << rolledValue << endl;
        cout << "Total of All Rolls: " << totalOfRolls << '\n' << endl;

        char continueChar;
        cout << "Roll Again? (y / n): ";
        cin >> continueChar;

        while (continueChar != 'y' && continueChar != 'n')
        {
            cout << "Invalid Input" << endl;
            cout << "Roll Again? (y / n): ";
            cin >> continueChar;
        }

        if (continueChar == 'n')
        {
            break;
        }

        cout << endl;
    }

    MainMenuInterface();
}

void NPCInterface()
{
    NPC selectedNPC;
    while (true)
    {
        cout << "\n====NPC HELPER====" << endl;
        cout << "    1. Generate Random NPC" << endl;
        cout << "    2. Create New NPC" << endl;
        cout << "    3. Load NPC" << endl;
        cout << "    4. Back To Menu" << endl;

        int helperOption = GetOption(1, 4);

        bool isLoaded = false;

        if (helperOption == 1)
        {
            selectedNPC.GenerateRandomNPC();
            isLoaded = true;
            cout << "\nGenerated Random NPC\n" << endl;
        }
        else if (helperOption == 2)
        {
            cout << "NPC CREATOR:" << endl;

            cout << "\nEnter NPC Name: ";
            cin.ignore();
            getline(cin, selectedNPC.name);

            cout << "\nChoose NPC Age:\n    1. Young\n    2. Middle-Aged\n    3. Old" << endl;
            int age = GetOption(1, 3) - 1;
            selectedNPC.age = (Ages)age;

            cout << "\nChoose NPC Race:\n    1. Dragonborn\n    2. Dwarf\n    3. Elf\n    4. Gnome\n    5. Half-Elf\n    6. Halfling\n    7. Half-Orc\n    8. Human\n    9. Tiefling\n    10. Orc" << endl;
            int race = GetOption(1, 10) - 1;
            selectedNPC.race = (Races)race;

            cout << "\nChoose NPC Alignment:" << endl;
            cout << "  Choose Inclination:\n      1. Lawful\n      2. Neutral\n      3. Chaotic" << endl;
            int inclination = GetOption(1, 3) - 1;
            selectedNPC.alignment.inclination = (Inclination)inclination;
            cout << "  Choose Moral:\n      1. Good\n      2. Neutral\n      3. Evil" << endl;
            int moral = GetOption(1, 3) - 1;
            selectedNPC.alignment.moral = (Moral)moral;

            cout << "\nEnter NPC Stats:" << endl;
            cout << "  Enter Strength: ";
            cin >> selectedNPC.stats[0];
            while (selectedNPC.stats[0] < 1)
            {
                cout << "  All stats must be greater than 0" << endl;
                cout << "  Enter Strength: ";
                cin >> selectedNPC.stats[0];
            }

            cout << "  Enter Dexterity: ";
            cin >> selectedNPC.stats[1];
            while (selectedNPC.stats[1] < 1)
            {
                cout << "  All stats must be greater than 0" << endl;
                cout << "  Enter Dexterity: ";
                cin >> selectedNPC.stats[1];
            }

            cout << "  Enter Constitution: ";
            cin >> selectedNPC.stats[2];
            while (selectedNPC.stats[2] < 1)
            {
                cout << "  All stats must be greater than 0" << endl;
                cout << "  Enter Constitution: ";
                cin >> selectedNPC.stats[2];
            }

            cout << "  Enter Intelligence: ";
            cin >> selectedNPC.stats[3];
            while (selectedNPC.stats[3] < 1)
            {
                cout << "  All stats must be greater than 0" << endl;
                cout << "  Enter Intelligence: ";
                cin >> selectedNPC.stats[3];
            }

            cout << "  Enter Wisdom: ";
            cin >> selectedNPC.stats[4];
            while (selectedNPC.stats[4] < 1)
            {
                cout << "  All stats must be greater than 0" << endl;
                cout << "  Enter Wisdom: ";
                cin >> selectedNPC.stats[4];
            }

            cout << "  Enter Charisma: ";
            cin >> selectedNPC.stats[5];
            while (selectedNPC.stats[5] < 1)
            {
                cout << "  All stats must be greater than 0" << endl;
                cout << "  Enter Charisma: ";
                cin >> selectedNPC.stats[5];
            }

            cout << "\nEnter NPC Physical Feature: ";
            cin.ignore();
            getline(cin, selectedNPC.physicalFeature);

            cout << "\nEnter NPC Talent: ";
            getline(cin, selectedNPC.talent);

            cout << "\nEnter NPC Mannerism: ";
            getline(cin, selectedNPC.mannerism);

            cout << "\nEnter NPC Interaction Trait: ";
            getline(cin, selectedNPC.interactionTrait);

            cout << "\nEnter NPC Ideal: ";
            getline(cin, selectedNPC.ideal);

            cout << "\nEnter NPC Bond: ";
            getline(cin, selectedNPC.bond);

            cout << "\nEnter NPC Flaw: ";
            getline(cin, selectedNPC.flaw);

            cout << "\nNPC Creation Finished" << endl;

            isLoaded = true;
        }
        else if (helperOption == 3)
        {
            cout << "Enter NPC Name: ";
            string npcName;
            getline(cin, npcName);

            isLoaded = selectedNPC.LoadNPC(npcName);

            while (!isLoaded)
            {
                cout << "NPC file does not exist (Enter \"Back\" to return to NPC Helper menu)" << endl;
                cout << "Enter NPC Name: ";
                string npcName;
                getline(cin, npcName);

                if (npcName == "Back") break;
                isLoaded = selectedNPC.LoadNPC(npcName);
            }
        }
        else if (helperOption == 4) break;

        string upperName = "";
        for (int i = 0; i < selectedNPC.name.length(); i++) upperName += toupper(selectedNPC.name[i]);

        while (true)
        {
            cout << "\n==" << upperName << " NPC OPTIONS==" << endl;
            cout << "    1. Print NPC Info" << endl;
            cout << "    2. Edit NPC Info" << endl;
            cout << "    3. Save NPC To File" << endl;
            cout << "    4. Back" << endl;

            int option = GetOption(1, 4);

            if (option == 1)
            {
                selectedNPC.PrintNPCSheet();
            }
            else if (option == 2)
            {
                cout << "Select Info To Edit:\n    1. Name\n    2. Age\n    3. Race\n    4. Alignment\n    5. Stats\n    6. Physical Feature\n    7. Talent\n    8. Mannerism\n    9. Interaction Trait\n    10. Ideal\n    11. Bond\n    12. Flaw" << endl;

                int editOption = GetOption(1, 12);

                if (editOption == 1)
                {
                    cout << "\nEnter NPC Name: ";
                    cin.ignore();
                    getline(cin, selectedNPC.name);
                }
                else if (editOption == 2)
                {
                    cout << "\nChoose NPC Age:\n    1. Young\n    2. Middle-Aged\n    3. Old" << endl;
                    int age = GetOption(1, 3) - 1;
                    selectedNPC.age = (Ages)age;
                }
                else if (editOption == 3)
                {
                    cout << "\nChoose NPC Race:\n    1. Dragonborn\n    2. Dwarf\n    3. Elf\n    4. Gnome\n    5. Half-Elf\n    6. Halfling\n    7. Half-Orc\n    8. Human\n    9. Tiefling\n    10. Orc" << endl;
                    int race = GetOption(1, 10) - 1;
                    selectedNPC.race = (Races)race;
                }
                else if (editOption == 4)
                {
                    cout << "\nChoose NPC Alignment:" << endl;
                    cout << "  Choose Inclination:\n      1. Lawful\n      2. Neutral\n      3. Chaotic" << endl;
                    int inclination = GetOption(1, 3) - 1;
                    selectedNPC.alignment.inclination = (Inclination)inclination;
                    cout << "  Choose Moral:\n      1. Good\n      2. Neutral\n      3. Evil" << endl;
                    int moral = GetOption(1, 3) - 1;
                    selectedNPC.alignment.moral = (Moral)moral;
                }
                else if (editOption == 5)
                {
                    cout << "\nEnter NPC Stats:" << endl;
                    cout << "  Enter Strength: ";
                    cin >> selectedNPC.stats[0];
                    while (selectedNPC.stats[0] < 1)
                    {
                        cout << "  All stats must be greater than 0" << endl;
                        cout << "  Enter Strength: ";
                        cin >> selectedNPC.stats[0];
                    }

                    cout << "  Enter Dexterity: ";
                    cin >> selectedNPC.stats[1];
                    while (selectedNPC.stats[1] < 1)
                    {
                        cout << "  All stats must be greater than 0" << endl;
                        cout << "  Enter Dexterity: ";
                        cin >> selectedNPC.stats[1];
                    }

                    cout << "  Enter Constitution: ";
                    cin >> selectedNPC.stats[2];
                    while (selectedNPC.stats[2] < 1)
                    {
                        cout << "  All stats must be greater than 0" << endl;
                        cout << "  Enter Constitution: ";
                        cin >> selectedNPC.stats[2];
                    }

                    cout << "  Enter Intelligence: ";
                    cin >> selectedNPC.stats[3];
                    while (selectedNPC.stats[3] < 1)
                    {
                        cout << "  All stats must be greater than 0" << endl;
                        cout << "  Enter Intelligence: ";
                        cin >> selectedNPC.stats[3];
                    }

                    cout << "  Enter Wisdom: ";
                    cin >> selectedNPC.stats[4];
                    while (selectedNPC.stats[4] < 1)
                    {
                        cout << "  All stats must be greater than 0" << endl;
                        cout << "  Enter Wisdom: ";
                        cin >> selectedNPC.stats[4];
                    }

                    cout << "  Enter Charisma: ";
                    cin >> selectedNPC.stats[5];
                    while (selectedNPC.stats[5] < 1)
                    {
                        cout << "  All stats must be greater than 0" << endl;
                        cout << "  Enter Charisma: ";
                        cin >> selectedNPC.stats[5];
                    }
                }
                else if (editOption == 6)
                {
                    cout << "\nEnter NPC Physical Feature: ";
                    cin.ignore();
                    getline(cin, selectedNPC.physicalFeature);
                }
                else if (editOption == 7)
                {
                    cout << "\nEnter NPC Talent: ";
                    cin.ignore();
                    getline(cin, selectedNPC.talent);
                }
                else if (editOption == 8)
                {
                    cout << "\nEnter NPC Mannerism: ";
                    getline(cin, selectedNPC.mannerism);
                }
                else if (editOption == 9)
                {
                    cout << "\nEnter NPC Interaction Trait: ";
                    getline(cin, selectedNPC.interactionTrait);
                }
                else if (editOption == 10)
                {
                    cout << "\nEnter NPC Ideal: ";
                    getline(cin, selectedNPC.ideal);
                }
                else if (editOption == 11)
                {
                    cout << "\nEnter NPC Bond: ";
                    getline(cin, selectedNPC.bond);
                }
                else if (editOption == 12)
                {
                    cout << "\nEnter NPC Flaw: ";
                    getline(cin, selectedNPC.flaw);
                }
            }
            else if (option == 3)
            {
                bool wasSaved = selectedNPC.SaveNPC();
                if (wasSaved) cout << "Success Saved: " << selectedNPC.name << endl;
            }
            else if (option == 4) break;

            cout << endl;
        }
    }

    MainMenuInterface();
}

int GetOption(int min, int max)
{
    int option;
    cout << "\nEnter Option (" << min << " - " << max << "): ";
    cin >> option;
    while (option > max || option < min)
    {
        cout << "Invlaid Choice" << endl;
        cout << "\nEnter Option (" << min << " - " << max << "): ";
        cin >> option;
    }

    return option;
}