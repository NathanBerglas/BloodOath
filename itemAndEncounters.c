//itemAndEncounters.c

// Headers
#include "playerStruct.h"

// Items

// Crafting
const struct item tools[3] = {
{"Hammer", "A tool to build things."},
{"Tape", "A tool to build things. Not sure if it's historically accurate."},
{"String", "A tool to build things."} };

// Novice
const struct item noviceItems[ITEM_CLASS_SIZE] = {
{"Pokey Stick", "A long stick that is slightly pokey."}, // Weapons
{"Fiber Whip", "A weapon made from loose fiber."},
{"Rock", "SMASH!"},
{"Magic Wand", "Requires a strong will to cast, but powerful."},
{"Water Skin", "A leather pouch that can hold water."}, // Healing
{"Ball of Mud", "A ball of mud."},
{"Raw Meat", "Can be eaten, at a cost."},
{"Strange Mushroom", "Can be eaten. Your choice."},
{"Puzzle", "Can be studied."}, // Training
{"Dice", "Can play a game to increase luck."},
{"Spell Book", "Can be used to train your magic and willpower."},
{"Unsigned Document", "You cannot read the text, yet you may still sign it."} }; // Misc.

// Adept
const struct item adeptItems[ITEM_CLASS_SIZE] = {
{"Sword", "A sword. What do you expect?"}, // Weapons
{"Leather whip", "A whipe made from leather, quite effective."},
{"Mace", "BIG SMASH!"},
{"Wizard Hat", "Not for sorting, but for destruction."},
{"First Aid Kit", "Good in a pinch to heal."}, // Healing
{"Leaf", "A leaf."},
{"Cooked meat", "Can be eaten, filling!"},
{"Potion", "Red coloured. Must be healing!?"},
{"Book", "Can be read to increase education."}, // Training
{"Deck of Cards", "Can be used to play a game and train luck."},
{"ORB", "PONDER THE ORB..."},
{"Scroll", "A spell scroll in a strange language. You could try casting it."} }; // Misc

// Expert
const struct item expertItems[ITEM_CLASS_SIZE] = {
{"Katana", "Rumoured to be able to kill a demon by decapitation."}, // Weapons
{"Morningstar Whip", "Tried and tested against Vampires for generations."},
{"War Hammer", "SMASH, SMASH, SMASH, SMASH!!!"},
{"Wizard Staff", "I cast fireball!"},
{"Potion of Healing", "Don't worry, the glass is edible as well!"}, // Healing
{"Branch", "If combined, rumoured to be incredibly powerful..."},
{"Steak", "Yes. A fully cooked steak... just found... Just take it."},
{"Scroll of Rejuvination", "Once casted, is able to heal you incredibly."},
{"Personal Journal", "The personal journal of an adventurer. Many things to learn!"}, // Training
{"Rabbit Foot", "Rumoured to give incredible luck to all owners."},
{"Demon Soul in a Jar", "A demon's soul trapt in a jar. You may bend its willpower."},
{"Knife and Pot", "It has a strange language on it. Do you dare spill your blood?"} };