#pragma once

#include <string>

using namespace std;

/*
#NOTES#
I am using a class because the alternative are a lot of parellel arrays.

* All variables are private and I am using getter methods so that the variables cannot be changed outside the class.
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
    private: // * These are not accessable outside the class
        //I always order my variables from least memory to most
        //I have no idea why I do this but I have for 9 years ¯\_(ツ)_/¯
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

        void GenerateNPC();


    public: // * These are accessable outside the class
        NPC(string npcName = ""); //Class constructor
        bool SaveNPC();
        //Getter Functions (There are *a lot* of getter functions [erm actually methods bc they are in a class])
        Ages GetAge();
        Races GetRace();
        int GetStat(StatTypes statType = Strength);
        Alignment GetAlignment();
        Moral GetMoral();
        Inclination GetInclination();
        string GetName();
        string GetPhysicalFeature();
        string GetTalent();
        string GetMannerism();
        string GetInteractionTrait();
        string GetIdeal();
        string GetBond();
        string GetFlaw();
};