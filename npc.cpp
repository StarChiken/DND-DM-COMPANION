#include <time.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <random>

#include "libraries/magic_enum.hpp"
#include "npc.h"

using namespace std;

//This creates a seed for the GetRandomNumberByRange function
random_device randomDevice;
mt19937 generator(randomDevice());

bool hasInitializedVectors = false;

vector<string> physicalFeatures;
vector<string> talents;
vector<string> mannerisms;
vector<string> interactionTraits;
vector<string> bonds;
vector<string> flaws;

vector<string> goodIdeals;
vector<string> evilIdeals;
vector<string> neutralIdeals;
vector<string> lawfulIdeals;
vector<string> chaoticIdeals;
vector<string> otherIdeals;
//This is a 2 dimensional vector
vector<vector<string>> raceNames;

void InitializeNPCVectors();
void SetVectorToFileContents(vector<string>&, string);
int GetRandomIndex(int);
int RollStat(int bonus = 0);
string GetRandomIdeal(Moral);
string GetRandomIdeal(Inclination);
int GetRandomNumberByRange(int, int);

//TODO REMOVE LATER (This is for debugging)
int main()
{
    srand(time(0));
    NPC testNPC("");
    cout << "Name: " << testNPC.GetName() << endl;
    cout << "Race: " << magic_enum::enum_name(testNPC.GetRace()) << endl;
    cout << "Ideal: " << testNPC.GetIdeal() << endl;
    return 0;
}

NPC::NPC(string npcName)
{
    if (!hasInitializedVectors)
    {
        InitializeNPCVectors();
        hasInitializedVectors = true;
    }

    if (npcName == "")
    {
        cout << "Creating NPC" << endl;
        //Creates new randomized NPC
        age = (Ages)GetRandomNumberByRange(0, 2);
        race = (Races)GetRandomNumberByRange(0, (int)RacesItemNumber);
        alignment.moral = (Moral)GetRandomNumberByRange(0, 2);
        alignment.inclination = (Inclination)GetRandomNumberByRange(0, 2);

        physicalFeature = physicalFeatures[GetRandomIndex(physicalFeatures.size())];
        talent = talents[GetRandomIndex(talents.size())];
        mannerism = mannerisms[GetRandomIndex(mannerisms.size())];
        interactionTrait = interactionTraits[GetRandomIndex(interactionTraits.size())];
        flaw = flaws[GetRandomIndex(flaws.size())];

        name = raceNames[(int)race][GetRandomIndex(raceNames[(int)race].size())];

        //Sets ideal based on alignment
        bool moralIdeal = GetRandomNumberByRange(0, 1);

        if (moralIdeal)
        {
            ideal = GetRandomIdeal(alignment.moral);
        }
        else
        {
            ideal = GetRandomIdeal(alignment.inclination);
        }

        //Populates stats array
        int highStat = GetRandomNumberByRange(0, 5);
        int lowStat = GetRandomNumberByRange(0, 5);

        if (highStat == lowStat)
        {
            if (highStat == 0)
            {
                lowStat++;
            }
            else
            {
                lowStat--;
            }
        }

        for (int i = 0; i < 6; i++)
        {
            if (i == highStat)
            {
                stats[i] = RollStat(1);
            }
            else if (i == lowStat)
            {
                stats[i] = RollStat(-1);
            }
            else
            {
                stats[i] = RollStat(0);
            }
        }

        cout << "NPC Created\n" << endl;
    }
    else
    {
        //Finds and reads NPC file by name
        //For NPC archive (Will Do Later)
    }
}

void InitializeNPCVectors()
{
    SetVectorToFileContents(physicalFeatures, "resources/physicalFeatures.txt");
    SetVectorToFileContents(talents, "resources/talents.txt");
    SetVectorToFileContents(mannerisms, "resources/mannerisms.txt");
    SetVectorToFileContents(interactionTraits, "resources/interactionTraits.txt");
    SetVectorToFileContents(bonds, "resources/bonds.txt");
    SetVectorToFileContents(flaws, "resources/flaws.txt");

    //Ideals
    SetVectorToFileContents(goodIdeals, "resources/ideals/goodIdeals.txt");
    SetVectorToFileContents(evilIdeals, "resources/ideals/evilIdeals.txt");
    SetVectorToFileContents(lawfulIdeals, "resources/ideals/lawfulIdeals.txt");
    SetVectorToFileContents(chaoticIdeals, "resources/ideals/chaoticIdeals.txt");
    SetVectorToFileContents(neutralIdeals, "resources/ideals/neutralIdeals.txt");
    SetVectorToFileContents(otherIdeals, "resources/ideals/otherIdeals.txt");

    //Names
    for (int i = 0; i < (int)RacesItemNumber; i++)
    {
        /*
        This is a cursed programming techinque
        You cannot cast a string_view to a string for weird memory reasons
        But you can append a string_view to a string (only like this but you can't do it in other ways for some god awful reason)
        * Creating correct filePath
        */
        string_view enumName = magic_enum::enum_name(Races(i));
        string filePath = "resources/names/";
        filePath += enumName;
        filePath[16] = tolower(filePath[16]);
        filePath += "Names";

        vector<string> nameVect;
        SetVectorToFileContents(nameVect, filePath);
        raceNames.push_back(nameVect);
    }
}

void SetVectorToFileContents(vector<string>& inputVect, string filePath)
{
    ifstream inputFile(filePath, ios::in);
    string currentInput;

    if (!inputFile.good()) //Checks if the file exists
    {
        cout << "File Path: \"" << filePath << "\" Does Not Exist" << endl;
        return;
    }
    
    if (inputFile.peek() == ifstream::traits_type::eof()) //Checks if the file is empty
    {
        cout << "File: \"" << filePath << "\" Is Empty" << endl;
        return;
    }

    while (getline(inputFile, currentInput)) // * Loops until each line of the input file has been read
    {
        inputVect.push_back(currentInput);
    }

    inputFile.close();
}

int GetRandomIndex(int sizeOfArray)
{
    return GetRandomNumberByRange(0, sizeOfArray - 1);
}

int RollStat(int bonus)
{
    int total = 0;
    int lowestRoll = 10;
    int currentRoll;
    for (int i = 0; i < 4; i++)
    {
        currentRoll = GetRandomNumberByRange(0, 5);
        total += currentRoll;
        if (currentRoll < lowestRoll)
        {
            lowestRoll = currentRoll;
        }
    }
    total -= lowestRoll;
    return total;
}

string GetRandomIdeal(Moral moral)
{
    string ideal = "";

    switch (moral)
    {
        case Good:
            ideal = goodIdeals[GetRandomIndex(goodIdeals.size())];
            break;
        case Neutral:
            ideal = neutralIdeals[GetRandomIndex(neutralIdeals.size())];
            break;
        case Evil:
            ideal = evilIdeals[GetRandomIndex(evilIdeals.size())];
            break;
    }

    return ideal;
}

string GetRandomIdeal(Inclination inclination)
{
    string ideal = "";

    switch (inclination)
    {
        case Lawful:
            ideal = lawfulIdeals[GetRandomIndex(lawfulIdeals.size())];
            break;
        case Neither:
            ideal = otherIdeals[GetRandomIndex(otherIdeals.size())];
            break;
        case Chaotic:
            ideal = chaoticIdeals[GetRandomIndex(chaoticIdeals.size())];
            break;
    }

    return ideal;
}

int GetRandomNumberByRange(int minNum, int maxNum)
{
    //Gets a random number in the given range (inclusive)
    uniform_int_distribution<int> distribution(minNum, maxNum);
    return distribution(generator);
}

#pragma region Getters

int NPC::GetAge()
{
    return age;
}

Races NPC::GetRace()
{
    return race;
}

int NPC::GetStat(StatTypes statType)
{
    return stats[statType];
}

Alignment NPC::GetAlignment()
{
    return alignment;
}

Moral NPC::GetMoral()
{
    return alignment.moral;
}

Inclination NPC::GetInclination()
{
    return alignment.inclination;
}

string NPC::GetName()
{
    return name;
}

string NPC::GetPhysicalFeature()
{
    return physicalFeature;
}

string NPC::GetTalent()
{
    return talent;
}

string NPC::GetMannerism()
{
    return mannerism;
}

string NPC::GetInteractionTrait()
{
    return interactionTrait;
}

string NPC::GetIdeal()
{
    return ideal;
}

string NPC::GetBond()
{
    return bond;
}

string NPC::GetFlaw()
{
    return flaw;
}

#pragma endregion