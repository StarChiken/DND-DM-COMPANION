**LINK TO GITHUB:** https://github.com/StarChiken/DND-DM-COMPANION

# **DND-DM-COMPANION README**
**DISCLAIMER: This project has a lot of removed code. My partner for the project cheated and I was forced to remove all of their work.**
All code written by: Ethan Brandt

## Functionality:
### Diceroller
Allows user to roll all common dice types: D4, D6, D8, D10, D12, D20, & D100
Allows the user to specify the number of rolls

### NPC Helper
#### NPC Information
Name, Age, Race, Alignment, Stats (STR, DEX, CON, INT, WIS, & CHA), Physical Feature, Talent, Interaction Trait, Ideal, Bond, Flaw

#### Generate Random NPC
Generates a completely randomized NPC

#### Create New NPC
Prompts the user for all NPC information and then creates an NPC with the given information

#### Load NPC
Loads an NPC given the NPC name

### NPC Options
#### Print NPC Info
Outputs all NPC info into the terminal

#### Edit NPC Info
Prompts the user to choose which info to edit and then prompts them again to input the new info

#### Save NPC To File
Saves the NPC to a .npc file which it can be read and edited from

## .cpp files
### Logger
Allows printing to a log file
A new log file is created each time the program is run

### NPC
Holds all NPC data and functionality
Allows saving and loading of .npc files

### Dice Roller
Simple dice rolling script

### Random Numbers
Simple implementation of a popular version of the Mersenne Twister

## Attributions / Libraries Used
**MAGIC_ENUM:** https://github.com/Neargye/magic_enum
