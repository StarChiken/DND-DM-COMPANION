#pragma once

#include <string>
#include <vector>

using namespace std;

/*
#NOTES#
I am using a class because the alternative are a lot of parellel arrays.
*/

#pragma region Data Types
//I used a lot of enums because they can be easily compared and are stupidly memory efficient (I mean they're just ints)
//Also C++ is just weird, I had to wrangle the ordering of these to stop compiler errors
enum Ages
{
    Young,
    MiddleAged,
    Old
};

enum Races
{
    Dragonborn,
    Dwarf,
    Elf,
    Gnome,
    HalfElf,
    Halfling,
    HalfOrc,
    Human,
    Tiefling,
    Orc,
    RacesItemNumber
};

enum StatTypes
{
    Strength,
    Dexterity,
    Consitution,
    Intelligence,
    Wisdom,
    Charisma
};

enum Moral
{
    Good,
    Neutral,
    Evil
};

enum Inclination
{
    Lawful,
    Neither,
    Chaotic
};

//I technically could have used 1 enum with all 9 possibilties but it would lead to more comparisons in if statements so here we are
struct Alignment
{
    Moral moral;
    Inclination inclination;
};
#pragma endregion

class NPC
{
    public: // * These are accessable outside the class
        Ages age;
        Races race;
        Alignment alignment;
        int stats[6];
        string name;
        string physicalFeature;
        string talent;
        string mannerism;
        string interactionTrait;
        string ideal;
        string bond;
        string flaw;

        void GenerateRandomNPC();
        bool SaveNPC();
        bool LoadNPC(string npcName);
        void PrintNPCSheet();
};

void InitializeNPCVectors();