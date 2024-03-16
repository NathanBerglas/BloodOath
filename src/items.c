//items.c

// Libraries
#include <stdio.h>

// Headers
#include "playerStruct.h"
#include "items.h"

// Item Definitions

// Empty
const struct item emptyItem = {"Empty", "No description", EMPTY, &emptyIF};

// Novice
const struct item noviceItems[ITEM_CLASS_SIZE] = {
{"Pokey Stick", "A long stick that is slightly pokey.", POKEY_STICK, &pokeyStickIF}, // Weapons
{"Fiber Whip", "A weapon made from loose fiber.", FIBER_WHIP, &fiberWhipIF},
{"Rock", "SMASH!", ROCK, &rockIF},
{"Magic Wand", "Requires a strong will to cast, but powerful.", MAGIC_WAND, &magicWandIF},
{"Bandaid", "Minorly heals you", BANDAID, &bandaidIF}, // Healing
{"Ball of Mud", "A ball of mud.", BALL_OF_MUD, &ballOfMudIF},
{"Raw Meat", "Can be eaten, at a cost.", RAW_MEAT, &rawMeatIF},
{"Strange Mushroom", "Can be eaten. Your choice.", STRANGE_MUSHROOM, &strangeMushroomIF},
{"Puzzle", "Can be studied.", PUZZLE, &puzzleIF}, // Training
{"Dice", "Can play a game to increase luck.", DICE, &diceIF},
{"Spell Book", "Can be used to train your magic and willpower.", SPELL_BOOK, &spellBookIF},
{"Unsigned Document", "You cannot read the text, yet you may still sign it.", UNSIGNED_DOCUMENT, &unsignedDocumentIF} }; // Misc.

// Adept
const struct item adeptItems[ITEM_CLASS_SIZE] = {
{"Sword", "A sword. What do you expect?", SWORD, &swordIF}, // Weapons
{"Leather whip", "A whip made from leather, quite effective.", LEATHER_WHIP, &leatherWhipIF},
{"Mace", "BIG SMASH!", MACE},
{"Wizard Hat", "Not for sorting, but for destruction.", WIZARD_HAT, &wizardHatIF},
{"First Aid Kit", "Good in a pinch to heal.", FIRST_AID_KIT, &firstAidKitIF}, // Healing
{"Leaf", "A leaf.", LEAF},
{"Cooked meat", "Can be eaten, filling!", COOKED_MEAT, &cookedMeatIF},
{"Potion", "Red coloured. Must be healing!?", POTION, &potionIF},
{"Book", "Can be read to increase education.", BOOK, &bookIF}, // Training
{"Deck of Cards", "Can be used to play a game and train luck.", DECK_OF_CARDS, &deckOfCardsIF},
{"ORB", "PONDER THE ORB...", ORB, &orbIF},
{"Scroll", "A spell scroll in a strange language. You could try casting it.", SCROLL, &scrollIF} }; // Misc

// Expert
const struct item expertItems[ITEM_CLASS_SIZE] = {
{"Katana", "Rumoured to be able to kill a demon by decapitation.", KATANA, &katanaIF}, // Weapons
{"Morningstar Whip", "Tried and tested against Vampires for generations.", MORNINGSTAR_WHIP, &morningstarIF},
{"War Hammer", "SMASH, SMASH, SMASH, SMASH!!!", WAR_HAMMER, &warHammerIF},
{"Wizard Staff", "I cast fireball!", WIZARD_HAT, &wizardHatIF},
{"Potion of Healing", "Don't worry, the glass is edible as well!", POTION_OF_HEALING, &potionOfHealingIF}, // Healing
{"Branch", "If combined, rumoured to be incredibly powerful...", BRANCH, &branchIF},
{"Steak", "Yes. A fully cooked steak... just found... Just take it.", STEAK, &steakIF},
{"Scroll of Rejuvination", "Once casted, is able to heal you incredibly.", SCROLL_OF_REJUVINATION, &scrollOfRejuvinationIF},
{"Personal Journal", "The personal journal of an adventurer. Many things to learn!", PERSONAL_JOURNAL, &personalJournalIF}, // Training
{"Rabbit Foot", "Rumoured to give incredible luck to all owners.", RABBIT_FOOT, &rabbitFootIF},
{"Demon Soul in a Jar", "A demon's soul trapt in a jar. You may bend its willpower.", DEMON_SOUL_IN_A_JAR, &demonSoulInAJarIF},
{"Knife and Pot", "It has a strange language on it. Do you dare spill your blood?", KNIFE_AND_POT, &knifeAndPotIF} };

// Biome Items
const struct item forestItems[ITEM_BIOME_SIZE] = {
{"Cloak (F)", "Good for all sorts of things, like being sneaky", CLOAK, &cloakIF},
{"Spring Water (F)", "Tastes good, helps calm and heal you", SPRING_WATER, &springWaterIF},
{"Elven Sword (F)", "Possibly glows when close to vampires?", ELVEN_SWORD, &elvenSwordIF},
{"Lantern (F)", "Helps keeps the dark away", LANTERN, &lanternIF},
{"Ivy Whip (F)", "Wait, why should it be called the Snapthorn again?", IVY_WHIP, &ivyWhipIF},
{"Nightshade Berries (F)", "They look tasty...", NIGHTSHADE_BERRIES, &nightshadeBerriesIF},
{"Tree sap (F)", "Good for healing wounds", TREE_SAP, &treeSapIF},
{"Tattered Map (F)", "Reveals the location of a secret stash!", TATTERED_MAP, &tatteredMapIF} };

const struct item mountainItems[ITEM_BIOME_SIZE] = {
{"Climbing Pick (M)", "Not only good for rock", CLIMBING_PICK, &climbingPickIF},
{"Insulated Cloak (M)", "Keep out the cold", INSULATED_CLOAK, &insulatedCloakIF},
{"Grappling Hook (M)", "I'm batman", GRAPPLING_HOOK, &grapplingHookIF},
{"Ram (M)", "The animal. Can show you the way to its home", RAM, &ramIF},
{"Bed Roll (M)", "Makes your nights more comfortable", BED_ROLL, &bedRollIF},
{"Eagle Egg (M)", "Yummy! Beware Eagles", EAGLE_EGG, &eagleEggIF},
{"Dried Meat (M)", "Chewy, but good", DRIED_MEAT, &driedMeatIF},
{"Snow (M)", "Do you want to build a snowman?", SNOW, &snowIF} };

const struct item desertItems[ITEM_BIOME_SIZE] = {
{"Sandstone Amulet (D)", "Makes you look good", SANDSTONE_AMULET, &sandstoneAmuletIF},
{"Ancient Manuscript (D)", "Has some interesting lore", ANCIENT_MANUSCRIPT, &ancientManuscriptIF},
{"Serpent Scale (D)", "Can be used to improve an item", SERPENT_SCALE, &springWaterIF},
{"Waterskin (D)", "Good to keep water in", WATERSKIN, &waterskinIF},
{"Vulture Bone (D)", "Creepy", VULTURE_BONE, &vultureBoneIF},
{"Sunstone Compass (D)", "Can guide you to your destination", SUNSTONE_COMPASS, &sunstoneCompassIF},
{"Dust goggles (D)", "Helps you see better in the sand", DUST_GOGGLES, &dustGogglesIF},
{"Scorpion Venom (D)", "You do not want this in your bloodstream", SCORPION_VENOM, &scorpionVenomIF} };

// Special Items: 1 of each per game
const struct item villageItems[ITEM_SPECIAL_SIZE] = {
{"Backpack", "Allows you to carry more items", BACKPACK, &backpackIF},
{"Blessing of Christ", "You are immune to the mind altering affects of revenants", BLESSING_OF_CHRIST, &blessingOfChristIF},
{"Map of surrounding area", "Unveils your map in entirety", MAP_OF_SURROUNDING_AREA, &mapOfSurroundingAreaIF} };

const struct item pyramidItems[ITEM_SPECIAL_SIZE] = {
{"Watch of the Chronomaster", "Allows you to take an extra action per day", WATCH_OF_THE_CHRONOMASTER, &watchOfTheChronomasterIF},
{"Desert Spirit's Sundial","Magically transports you back slightly in time", DESERT_SPIRITS_SUNDIAL, &desertSpiritsSundialIF},
{"The soul of a Pharaoh", "An ancient spellcaster, you will always suceed in spells", THE_SOUL_OF_A_PHAROAH, &theSoulOfAPharoahIF} };

const struct item caveItems[ITEM_SPECIAL_SIZE] = {
{"Jezebel's Key", "A key that can open a locked door...", JEZEBELS_KEY, &jezebelsKeyIF},
{"Jezebel's Coin", "Offers you a second chance", JEZEBELS_COIN, &jezebelsCoinIF},
{"Jezebel's Grimoire", "Allows you to summon any single item", JEZEBELS_GRIMOIRE, &jezebelsGrimoireIF} }; 

// Item Functions
bool emptyIF(struct playerStruct *player, struct journalStruct *journal) { return false; }

// Novice Items
bool pokeyStickIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool fiberWhipIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool rockIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool magicWandIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool bandaidIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool ballOfMudIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool rawMeatIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool strangeMushroomIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool puzzleIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool diceIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool spellBookIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool unsignedDocumentIF(struct playerStruct *player, struct journalStruct *journal) { return false; }

// Adept Items
bool swordIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool leatherWhipIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool maceIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool wizardHatIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool firstAidKitIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool leafIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool cookedMeatIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool potionIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool bookIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool deckOfCardsIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool orbIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool scrollIF(struct playerStruct *player, struct journalStruct *journal) { return false; }

// Expert Items
bool katanaIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool morningstarIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool warHammerIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool wizardStaffIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool potionOfHealingIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool branchIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool steakIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool scrollOfRejuvinationIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool personalJournalIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool rabbitFootIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool demonSoulInAJarIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool knifeAndPotIF(struct playerStruct *player, struct journalStruct *journal) { return false; }

// Forest Items
bool cloakIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool springWaterIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool elvenSwordIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool lanternIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool ivyWhipIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool nightshadeBerriesIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool treeSapIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool tatteredMapIF(struct playerStruct *player, struct journalStruct *journal) { return false; }

// Mountain Items
bool climbingPickIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool insulatedCloakIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool grapplingHookIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool ramIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool bedRollIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool eagleEggIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool driedMeatIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool snowIF(struct playerStruct *player, struct journalStruct *journal) { return false; }

// Desert Items
bool sandstoneAmuletIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool ancientManuscriptIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool serpentScaleIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool waterskinIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool vultureBoneIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool sunstoneCompassIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool dustGogglesIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool scorpionVenomIF(struct playerStruct *player, struct journalStruct *journal) { return false; }

// Village Items
bool backpackIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool blessingOfChristIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool mapOfSurroundingAreaIF(struct playerStruct *player, struct journalStruct *journal) { return false; }

// Pyramid Items
bool watchOfTheChronomasterIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool desertSpiritsSundialIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool theSoulOfAPharoahIF(struct playerStruct *player, struct journalStruct *journal) { return false; }

// Cave Items
bool jezebelsKeyIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool jezebelsCoinIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool jezebelsGrimoireIF(struct playerStruct *player, struct journalStruct *journal) { return false; }