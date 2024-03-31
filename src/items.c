//items.c

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Headers
#include "playerStruct.h"
#include "items.h"

// Constants for type
const int SWORD_T = 3000;
const int WHIP_T = 3100;
const int BLUDGEON_T = 3200;
const int SPELL_T = 3300;
const int FSPECIAL_T = 3400;
const int MSPECIAL_T = 3410;
const int DSPECIAL_T = 3420;

const int WILLPOWER = 6000;
const int LUCK = 6100;
const int EDUCATION = 6200;
const int SURVIVABILITY = 6300; 

// Item Definitions

// Empty
const struct item emptyItem = {"Empty", "No description", EMPTY, NULL};

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
{"General Store", "Allows you to purchase any single item", GENERAL_STORE, &generalStoreIF},
{"Map of surrounding area", "Unveils your map in entirety", MAP_OF_SURROUNDING_AREA, &mapOfSurroundingAreaIF} };

const struct item pyramidItems[ITEM_SPECIAL_SIZE] = {
{"Watch of the Chronomaster", "Allows you to take an extra action per day", WATCH_OF_THE_CHRONOMASTER, &watchOfTheChronomasterIF},
{"Desert Spirit's Sundial","Magically transports you back slightly in time", DESERT_SPIRITS_SUNDIAL, &desertSpiritsSundialIF},
{"The soul of a Pharaoh", "An ancient spellcaster, you will always succeed in spells", THE_SOUL_OF_A_PHAROAH, &theSoulOfAPharoahIF} };

const struct item caveItems[ITEM_SPECIAL_SIZE] = {
{"Jezebel's Key", "A key that can open a locked door...", JEZEBELS_KEY, &jezebelsKeyIF},
{"Jezebel's Coin", "Offers you a second chance", JEZEBELS_COIN, &jezebelsCoinIF},
{"Blessing of Jezebel", "You are immune to the mind altering affects of revenants", BLESSING_OF_JEZEBEL, &blessingOfJezebelIF},
 }; 

 const struct item specialItems[1] = {
    {"Hoggle's Talisman", "You may call for the power of Hoggle.", DRUID_TALISMAN, &druidTalismanIF}
 };

// Abstract Item Functions

bool trainSkill(int trainAmnt, int skill, struct playerStruct *player) {
    switch(skill) {
        case WILLPOWER:
            player->stats.willpower += trainAmnt;
            break;
        case EDUCATION:
            player->stats.education += trainAmnt;
            break;
        case LUCK:
            player->stats.luck += trainAmnt;
            break;
        case SURVIVABILITY:
            player->stats.survival += trainAmnt;
            break;
        default:
            return false;
    }
    return true;
}

bool weapon(int damage, int type, struct playerStruct *player, struct item item) {
    if (appendItem(player->equipedWeapon, player) && player->equipedWeapon.id != emptyItem.id) {
        printf("You unequip %s and put it back in your inventory.\n", player->equipedWeapon.name);
    } else {
        printf("You unequip %s and cannot fit it in your inventory.\n", player->equipedWeapon.name);
    }
    struct weaponStruct weapon;
    weapon.damage = damage;
    weapon.scale = 0;
    weapon.willpower = 0;
    weapon.type = type;
    player->weapon = weapon;
    player->equipedWeapon = item;
    printf("You equip this weapon. Damage: %d\n", damage);
    return true;
}

bool spell(int willpower, int scale, int type, struct playerStruct *player, struct item item) {
    if (appendItem(player->equipedWeapon, player) && player->equipedWeapon.id != emptyItem.id) {
        printf("You unequip %s and put it back in your inventory.\n", player->equipedWeapon.name);
    } else {
        printf("You unequip %s and cannot fit it in your inventory.\n", player->equipedWeapon.name);
    }
    struct weaponStruct weapon;
    weapon.scale = scale;
    weapon.damage = 0;
    weapon.willpower = willpower;
    weapon.type = type;
    player->weapon = weapon;
    player->equipedWeapon = item;
    printf("You equip this spell. Scale: %d, Willpower: %d\n", scale, willpower);
    return true;
}

// For heal
int minHeal(int a, int b) {
    return (a < b) ? a : b;
}

bool heal(int healing, int food, struct playerStruct *player) {
    int healAmount = minHeal(healing, (maxVitality - player->vitality));
    int hungerAmount = minHeal(food, (maxHunger - player->hunger));
    player->vitality += healAmount;
    player->hunger += hungerAmount;
    printf("You heal for %d, and restore %d hunger.\n", healAmount, hungerAmount);
    return true;
}

// Specific Item Functions

// 4 damage, sword type
bool pokeyStickIF(struct playerStruct *player, struct journalStruct *journal) { 
    const int damage = 4;
    const int type = SWORD_T;
    return weapon(damage, type, player, noviceItems[0]);
 }

// 3 damage, whip type
bool fiberWhipIF(struct playerStruct *player, struct journalStruct *journal) { 
    const int damage = 3;
    const int type = WHIP_T;
    return weapon(damage, type, player, noviceItems[1]);
}

// 5 damage, bludgeon type
bool rockIF(struct playerStruct *player, struct journalStruct *journal) { 
    const int damage = 5;
    const int type = BLUDGEON_T;
    return weapon(damage, type, player, noviceItems[2]);
}

bool magicWandIF(struct playerStruct *player, struct journalStruct *journal) { 
    const int willpower = 2000;
    const int scale = 900; // idk figure it out
    const int type = SPELL_T;
    return spell(willpower, scale, type, player, noviceItems[3]);
}

bool bandaidIF(struct playerStruct *player, struct journalStruct *journal) { 
    const int healing = 5;
    const int food = 0;
    return heal(healing, food, player);
}

bool ballOfMudIF(struct playerStruct *player, struct journalStruct *journal) { 
    bool hasLeaf = false;
    bool hasBranch = false;
    bool hasMud = false;
    for (int i = 0; i < MAX_INVENTORY + BACKPACK_SIZE; i++) {
        hasMud = (player->inventory[i].id == BALL_OF_MUD) || hasMud;
        hasLeaf = (player->inventory[i].id == LEAF) || hasLeaf;
        hasBranch = (player->inventory[i].id == BRANCH) || hasBranch;
    }
    if (hasBranch && hasLeaf) {
        printf("YOU COMBINE THE MIGHTY POWERS, AND GAIN THE DRUIDIC TALISMAN OF ARCH DRUID HOGGLE\n");
        if (!appendItem(specialItems[0], player)) {
            printf("You reject Hoggle's gift :(\n");
        }
        return true;
    }
    return false;
}

bool rawMeatIF(struct playerStruct *player, struct journalStruct *journal) { 
    const int healing = 1;
    const int food = 10;
    return heal(healing, food, player);
}

bool strangeMushroomIF(struct playerStruct *player, struct journalStruct *journal) { 
    int healing = rand() % 10;
    healing -= 10;
    return heal(healing, 10, player);  
}

bool puzzleIF(struct playerStruct *player, struct journalStruct *journal) {
    const int trainAmnt = 500;
    return trainSkill(trainAmnt, WILLPOWER, player);
}

bool diceIF(struct playerStruct *player, struct journalStruct *journal) { 
    const int trainAmnt = 500;
    return trainSkill(trainAmnt, LUCK, player);
}

bool spellBookIF(struct playerStruct *player, struct journalStruct *journal) { 
    const int trainAmnt = 500;
    return trainSkill(trainAmnt, WILLPOWER, player);
}

bool unsignedDocumentIF(struct playerStruct *player, struct journalStruct *journal) { 
    printf("You look at the unsigned document. It's written in a script you do not understand.\n");
    printf("There is lots of numbered lines of text, it looks like some sign of agreement.\n");
    printf("At the bottom, instead of a signature there is a rune, and a symbol... a J.\n");
    printf("Do you wish to sign the document? (1): Yes, (2): No\n");
    int inputi;
    scanf("%d",&inputi);
    if (inputi == 1) {
        player->stats.willpower = -99999;
        player->vitality = 1000;
        player->hunger = 1000;
        char *newName = "J. THRALL";
        strcpy(player->name, newName);
    } else {
        printf("Wise move. The document self-immolates.\n");
    }
    return true;
}

// Adept Items
bool swordIF(struct playerStruct *player, struct journalStruct *journal) { 
    const int damage = 8;
    const int type = SWORD_T;
    return weapon(damage, type, player, adeptItems[0]);
}

bool leatherWhipIF(struct playerStruct *player, struct journalStruct *journal) {
    const int damage = 7;
    const int type = WHIP_T;
    return weapon(damage, type, player, adeptItems[1]);
}

bool maceIF(struct playerStruct *player, struct journalStruct *journal) {
    const int damage = 10;
    const int type = BLUDGEON_T;
    return weapon(damage, type, player, adeptItems[2]);
}

bool wizardHatIF(struct playerStruct *player, struct journalStruct *journal) {
    const int willpower = 4000;
    const int scale = 600; // idk figure it out
    const int type = SPELL_T;
    return spell(willpower, scale, type, player, adeptItems[3]);
}

bool firstAidKitIF(struct playerStruct *player, struct journalStruct *journal) {
    const int healing = 9;
    const int food = 0;
    return heal(healing, food, player);
}

bool leafIF(struct playerStruct *player, struct journalStruct *journal) { 
    return ballOfMudIF(player, journal);
}

bool cookedMeatIF(struct playerStruct *player, struct journalStruct *journal) {
    const int healing = 3;
    const int food = 30;
    return heal(healing, food, player);
}

bool potionIF(struct playerStruct *player, struct journalStruct *journal) {
    player->hunger *= 3;
    if (player->hunger > maxHunger) {
        player->hunger = 100;
    }
    player->vitality *= 2;
    if (player->vitality > maxVitality) {
        player->vitality = maxVitality;
    }
    player->sanity /= 3;
    printf("You begin to feel full, healthy, but a little queasy.\n");
    return true;
}

bool bookIF(struct playerStruct *player, struct journalStruct *journal) {
    const int trainAmnt = 800;
    return trainSkill(trainAmnt, WILLPOWER, player);
}

bool deckOfCardsIF(struct playerStruct *player, struct journalStruct *journal) {
    const int trainAmnt = 800;
    return trainSkill(trainAmnt, LUCK, player);
}

bool orbIF(struct playerStruct *player, struct journalStruct *journal) {
    const int trainAmnt = 800;
    return trainSkill(trainAmnt, WILLPOWER, player);
}

bool scrollIF(struct playerStruct *player, struct journalStruct *journal) {
    printf("You examine the scroll. It's a mysterious language, but you can make out the pictures.\n");
    printf("The first picture has a pair of identical babies and a mother.\n");
    printf("The next image is the two babies as children. One is seperated from the rest.\n");
    printf("The seperated child meets a stranger in the next panel. The stranger is pale and thin.\n");
    printf("The child shakes his hand, and the child becomes like the stranger.\n");
    printf("The final image shows the child returning to their family...\nand kills..., then eats their mother.\n");
    printf("The scroll immolates and falls to ash.\n");
    return true;
}

// Expert Items
bool katanaIF(struct playerStruct *player, struct journalStruct *journal) { 
    const int damage = 15;
    const int type = SWORD_T;
    return weapon(damage, type, player, expertItems[0]);
}

bool morningstarIF(struct playerStruct *player, struct journalStruct *journal) {
    const int damage = 13;
    const int type = WHIP_T;
    return weapon(damage, type, player, expertItems[1]);
}

bool warHammerIF(struct playerStruct *player, struct journalStruct *journal) {
    const int damage = 17;
    const int type = BLUDGEON_T;
    return weapon(damage, type, player, expertItems[2]);
}

bool wizardStaffIF(struct playerStruct *player, struct journalStruct *journal) { 
    const int willpower = 6000;
    const int scale = 400; // idk figure it out
    const int type = SPELL_T;
    return spell(willpower, scale, type, player, expertItems[3]);
}

bool potionOfHealingIF(struct playerStruct *player, struct journalStruct *journal) {
    const int healing = 15;
    const int food = 0;
    return heal(healing, food, player);
}

bool branchIF(struct playerStruct *player, struct journalStruct *journal) {
    return ballOfMudIF(player, journal);
}

bool steakIF(struct playerStruct *player, struct journalStruct *journal) {
    const int healing = 5;
    const int food = 60;
    return heal(healing, food, player);
}

bool scrollOfRejuvinationIF(struct playerStruct *player, struct journalStruct *journal) {
    printf("You feel all your lost vitality get restored!\n");
    return heal(maxVitality, 0, player);
}

bool personalJournalIF(struct playerStruct *player, struct journalStruct *journal) {
    printf("You read journal. It's written by an adventurer, not too many years past.\n");
    printf("In his stories, he details two places of power. In the desert there is a pyramid hiding treausres unkown.\n");
    printf("The second place is a cave. The final journal entry is the morning before he entered.\n");
    const int trainAmnt = 1000;
    return trainSkill(trainAmnt, WILLPOWER, player);
}

bool rabbitFootIF(struct playerStruct *player, struct journalStruct *journal) {
    const int trainAmnt = 500;
    return trainSkill(trainAmnt, LUCK, player);
}

bool demonSoulInAJarIF(struct playerStruct *player, struct journalStruct *journal) {
    const int trainAmnt = 1000;
    return trainSkill(trainAmnt, WILLPOWER, player);
}

bool knifeAndPotIF(struct playerStruct *player, struct journalStruct *journal) {
    printf("You examine the pot and knife. The bottom of the pot and the edge of the knife are blood stained.\n");
    printf("Do you wish to cut yourself and drop your blood into the pot? (1) Yes, (2) No\n");
    int inputi = 0;
    scanf("%d", &inputi);
    if (inputi == 1) {
        printf("As you watch your blood drip into the pot, you feel a chill run down your spine.\n");
        printf("Appearing infront of you is a very tall and very beatiful woman.\n");
        printf("She does not look vampiric to you, but there is no mistaking her lack of humanity.\n");
        printf("She say's \"You have summoned an agent of Jezebel. What do you want?\n");
        printf("(1): Who are you?\n");
        printf("(2): I wish to kill you.\n");
        printf("(3): I wish to know more about Jezebel.\n");
        printf("(4): I wish to become a vampire.\n");
        scanf("%d", &inputi);
        switch(inputi) {
            case 1:
                printf("She replies, \"I am my masters's Thrall. I do not have a name. I am a simple demon here to do my masters's blessing.\"\n");
                break;
            case 2:
                printf("She replies, \"A foolish goal. Do not tempt me mortal, for I could kill you a hundred ways each time you blink.\"\n");
                break;
            case 3:
                printf("She does not reply. She simply smiles.\n");
                break;
            case 4:
                printf("She smiles, and replies, \"Oh? You do? Be my guest.\" ");
                if (appendItem(noviceItems[11], player)) {
                    printf("She hands you a scroll.\n");
                } else {
                    printf("She says, \"Unfortunatly you cannot hold anything more. How disapointing\"\n");
                }
                printf("In a puff of smoke, she disapears just as she appeared.\n");
                return true;
                break;
            }
            printf("The demon says, \"Either way, my buisness with you is done. My master will deal with you when the time is right.\"\n");
            printf("She steps away from you, but turns back. \"I will leave you to play, young adventurer.\" And with that, she disapears in a puff of smoke.\n");
        } else {
        printf("You decide to not risk it and discard the knife and pot.\n");
    }
    return true;
}

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
bool generalStoreIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool mapOfSurroundingAreaIF(struct playerStruct *player, struct journalStruct *journal) { return false; }

// Pyramid Items
bool watchOfTheChronomasterIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool desertSpiritsSundialIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool theSoulOfAPharoahIF(struct playerStruct *player, struct journalStruct *journal) { return false; }

// Cave Items
bool jezebelsKeyIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool jezebelsCoinIF(struct playerStruct *player, struct journalStruct *journal) { return false; }
bool blessingOfJezebelIF(struct playerStruct *player, struct journalStruct *journal) { return false; }

// Special Items
bool druidTalismanIF(struct playerStruct *player, struct journalStruct *journal) { return false; }