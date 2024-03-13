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
{"Pokey Stick", "A long stick that is slightly pokey.", true}, // Weapons
{"Fiber Whip", "A weapon made from loose fiber.", true},
{"Rock", "SMASH!", true},
{"Magic Wand", "Requires a strong will to cast, but powerful.", true},
{"Water Skin", "A leather pouch that can hold water.", true}, // Healing
{"Ball of Mud", "A ball of mud.", true},
{"Raw Meat", "Can be eaten, at a cost.", true},
{"Strange Mushroom", "Can be eaten. Your choice.", true},
{"Puzzle", "Can be studied.", true}, // Training
{"Dice", "Can play a game to increase luck.", true},
{"Spell Book", "Can be used to train your magic and willpower.", true},
{"Unsigned Document", "You cannot read the text, yet you may still sign it.", true} }; // Misc.

// Adept
const struct item adeptItems[ITEM_CLASS_SIZE] = {
{"Sword", "A sword. What do you expect?", true}, // Weapons
{"Leather whip", "A whip made from leather, quite effective.", true},
{"Mace", "BIG SMASH!", true},
{"Wizard Hat", "Not for sorting, but for destruction.", true},
{"First Aid Kit", "Good in a pinch to heal.", true}, // Healing
{"Leaf", "A leaf.", true},
{"Cooked meat", "Can be eaten, filling!", true},
{"Potion", "Red coloured. Must be healing!?", true},
{"Book", "Can be read to increase education.", true}, // Training
{"Deck of Cards", "Can be used to play a game and train luck.", true},
{"ORB", "PONDER THE ORB...", true},
{"Scroll", "A spell scroll in a strange language. You could try casting it.", true} }; // Misc

// Expert
const struct item expertItems[ITEM_CLASS_SIZE] = {
{"Katana", "Rumoured to be able to kill a demon by decapitation.", true}, // Weapons
{"Morningstar Whip", "Tried and tested against Vampires for generations.", true},
{"War Hammer", "SMASH, SMASH, SMASH, SMASH!!!", true},
{"Wizard Staff", "I cast fireball!", true},
{"Potion of Healing", "Don't worry, the glass is edible as well!", true}, // Healing
{"Branch", "If combined, rumoured to be incredibly powerful...", true},
{"Steak", "Yes. A fully cooked steak... just found... Just take it.", true},
{"Scroll of Rejuvination", "Once casted, is able to heal you incredibly.", true},
{"Personal Journal", "The personal journal of an adventurer. Many things to learn!", true}, // Training
{"Rabbit Foot", "Rumoured to give incredible luck to all owners.", true},
{"Demon Soul in a Jar", "A demon's soul trapt in a jar. You may bend its willpower.", true},
{"Knife and Pot", "It has a strange language on it. Do you dare spill your blood?", true} };