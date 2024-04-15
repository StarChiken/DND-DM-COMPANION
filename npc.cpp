#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sys/stat.h>

#include "libraries/magic_enum.hpp"
#include "randomnumbers.h"
#include "logger.h"
#include "npc.h"

using namespace std;

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

void SetVectorToFileContents(vector<string>&, string);
int GetRandomIndex(int);
int RollStat(int bonus = 0);
string GetRandomIdeal(Moral);
string GetRandomIdeal(Inclination);

void NPC::GenerateRandomNPC()
{
    PrintToLog("creating randomized npc");
    
    //Creates new randomized NPC
    age = (Ages)GetRandomNumberByRange(0, 2);
    string agePrint = "set age to: ";
    agePrint += magic_enum::enum_name(age);
    PrintToLog(agePrint);
    
    race = (Races)GetRandomNumberByRange(0, (int)RacesItemNumber - 1);
    string racePrint = "set race to: ";
    racePrint += magic_enum::enum_name(race);
    PrintToLog(racePrint);
    
    alignment.moral = (Moral)GetRandomNumberByRange(0, 2);
    alignment.inclination = (Inclination)GetRandomNumberByRange(0, 2);
    string alignmentPrint = "set alignment to: ";
    alignmentPrint += magic_enum::enum_name(alignment.inclination);
    alignmentPrint += ' ';
    alignmentPrint += magic_enum::enum_name(alignment.moral);
    PrintToLog(alignmentPrint);
    
    physicalFeature = physicalFeatures[GetRandomIndex(physicalFeatures.size())];
    PrintToLog("set physicalFeature to: " + physicalFeature);
    
    talent = talents[GetRandomIndex(talents.size())];
    PrintToLog("set talent to: " + talent);
    
    mannerism = mannerisms[GetRandomIndex(mannerisms.size())];   
    PrintToLog("set mannerism to: " + mannerism);

    interactionTrait = interactionTraits[GetRandomIndex(interactionTraits.size())];
    PrintToLog("set interactionTrait to: " + interactionTrait);
    
    flaw = flaws[GetRandomIndex(flaws.size())];
    PrintToLog("set flaw to: " + flaw);
    
    bond = bonds[GetRandomIndex(bonds.size())];
    PrintToLog("set bond to: " + bond);
    
    name = raceNames[(int)race][GetRandomIndex(raceNames[(int)race].size())];
    PrintToLog("set name to: " + name);

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

    PrintToLog("set ideal to: " + ideal);
    
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
            stats[i] = RollStat(2);
        }
        else if (i == lowStat)
        {
            stats[i] = RollStat(-2);
        }
        else
        {
            stats[i] = RollStat();
        }
        PrintToLog("set stat[" + to_string(i) + "] to: " + to_string(stats[i]));
    }

    PrintToLog("npc created");
}

void InitializeNPCVectors()
{
    PrintToLog("initializing vectors");

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
        filePath += "Names.txt";

        vector<string> nameVect;
        SetVectorToFileContents(nameVect, filePath);
        raceNames.push_back(nameVect);
    }

    PrintToLog("finished initializing vectors");
}

void SetVectorToFileContents(vector<string>& inputVect, string filePath)
{
    ifstream inputFile(filePath, ios::in);
    string currentInput;

    if (!inputFile.good()) //Checks if the file exists
    {
        PrintToLog("file path: \"" + filePath + "\" does not exist", true);
        return;
    }
    
    if (inputFile.peek() == ifstream::traits_type::eof()) //Checks if the file is empty
    {
        PrintToLog("file: \"" + filePath + "\" is empty", true);
        return;
    }

    while (getline(inputFile, currentInput)) // * Loops until each line of the input file has been read
    {
        inputVect.push_back(currentInput);
    }

    inputFile.close();
    PrintToLog("filled vector with path contents: " + filePath);
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
        currentRoll = GetRandomNumberByRange(1, 6);
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

bool NPC::LoadNPC(string npcName)
{
    PrintToLog("Started loading NPC: " + npcName);

    ifstream npcFile("npcs/" + npcName + ".npc");
    if (!npcFile.good())
    {
        PrintToLog("npcs/" + npcName + ".npc does not exist");
        return false;
    }

    name = npcName;

    int iterations = 0;
    while(true)
    {
        string type = "";
        while (true)
        {
            char c;
            npcFile >> c;
            if (c == ':') break;
            else type += c;
        }

        if (type == "age")
        {
            int value;
            npcFile >> value;
            age = (Ages)value;
        }
        else if (type == "race")
        {
            int value;
            npcFile >> value;
            race = (Races)value;
        }
        else if (type == "alignment")
        {
            int value;
            npcFile >> value;
            alignment.inclination = (Inclination)value;
            
            npcFile >> value;
            alignment.moral = (Moral)value;
        }
        else if (type == "stats")
        {
            for (int i = 0; i < 6; i++)
            {
                npcFile >> stats[i];
            }
        }
        else if (type == "physicalFeature")
        {
            getline(npcFile, physicalFeature);
        }
        else if (type == "talent")
        {
            getline(npcFile, talent);
        }
        else if (type == "mannerism")
        {
            getline(npcFile, mannerism);
        }
        else if (type == "interactionTrait")
        {
            getline(npcFile, interactionTrait);
        }
        else if (type == "ideal")
        {
            getline(npcFile, ideal);
        }
        else if (type == "bond")
        {
            getline(npcFile, bond);
        }
        else if (type == "flaw")
        {
            getline(npcFile, flaw);
        }

        if(npcFile.eof())
        {
            break;
        }

        PrintToLog("Loaded: " + type);

        iterations++;
        if (iterations > 300)
        {
            PrintToLog("Infinite loop while loading npc", true);
            break;
        }
    }

    npcFile.close();
    PrintToLog("Finised loading NPC: " + name);
    return true;
}

bool NPC::SaveNPC()
{
    PrintToLog("Started saving NPC: " + name);

    ofstream npcFile("npcs/" + name + ".npc");

    if (!npcFile.good())
    {
        PrintToLog("Unable to save " + name + "(bad file)", true);
        return false;
    }

    npcFile << "age:" << age << '\n';
    npcFile << "race:" << race << '\n';
    npcFile << "alignment:" << alignment.inclination << ' ' << alignment.moral << '\n';
    npcFile << "stats:" << stats[0] << ' ' << stats[1] << ' ' << stats[2] << ' ' << stats[3] << ' ' << stats[4] << ' ' << stats[5] << '\n';
    npcFile << "physicalFeature:" << physicalFeature << '\n';
    npcFile << "talent:" << talent << '\n';
    npcFile << "mannerism:" << mannerism << '\n';
    npcFile << "interactionTrait:" << interactionTrait << '\n';
    npcFile << "ideal:" << ideal << '\n';
    npcFile << "bond:" << bond << '\n';
    npcFile << "flaw:" << flaw << '\n';

    npcFile.close();
    PrintToLog("Finished saving npc to: npcs/" + name + ".npc");
    return true;
}

void NPC::PrintNPCSheet()
{
    string upperName = "";
    for (int i = 0; i < name.length(); i++) upperName += toupper(name[i]);
    cout << "\n==" << upperName << "==" << endl;
    cout << "Age: " << magic_enum::enum_name(age) << endl;
    cout << "Race: " << magic_enum::enum_name(race) << endl;
    cout << "Alignment" << magic_enum::enum_name(alignment.inclination) << ' ' << magic_enum::enum_name(alignment.moral) << endl;
    cout << "Stats:" << "\n  STR: " << stats[0] << "\n  DEX: " << stats[1] << "\n  CON: " << stats[2] << "\n  INT: " << stats[3] << "\n  WIS: " << stats[4] << "\n  CHA: " << stats[5] << endl;
    cout << "Physical Feature: " << physicalFeature << endl;
    cout << "Talent: " << talent << endl;
    cout << "Mannerism: " << mannerism << endl;
    cout << "Interaction Trait: " << interactionTrait << endl;
    cout << "Ideal: " << ideal << endl;
    cout << "Bond: " << bond << endl;
}