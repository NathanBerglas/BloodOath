//items.h

// Headers
#include "playerStruct.h"

// Items
extern const struct item noviceItems[ITEM_CLASS_SIZE];
extern const struct item adeptItems[ITEM_CLASS_SIZE];
extern const struct item expertItems[ITEM_CLASS_SIZE];

extern const struct item forestItems[ITEM_BIOME_SIZE];
extern const struct item mountainItems[ITEM_BIOME_SIZE];
extern const struct item desertItems[ITEM_BIOME_SIZE];

extern const struct item villageItems[ITEM_SPECIAL_SIZE];
extern const struct item pyramidItems[ITEM_SPECIAL_SIZE];
extern const struct item caveItems[ITEM_SPECIAL_SIZE];

// Empty Item
#define EMPTY 0
 
// Novice Items
#define POKEY_STICK 10
#define FIBER_WHIP 11
#define ROCK 12
#define MAGIC_WAND 13
#define BANDAID 14
#define BALL_OF_MUD 15
#define RAW_MEAT 16
#define STRANGE_MUSHROOM 17
#define PUZZLE 18
#define DICE 19
#define SPELL_BOOK 20
#define UNSIGNED_DOCUMENT 21

// Adept Items
#define SWORD 30
#define LEATHER_WHIP 31
#define MACE 32
#define WIZARD_HAT 33
#define FIRST_AID_KIT 34
#define LEAF 35
#define COOKED_MEAT 36
#define POTION 37
#define BOOK 38
#define DECK_OF_CARDS 39
#define ORB 40
#define SCROLL 41

// Expert Items
#define KATANA 50
#define MORNINGSTAR_WHIP 51
#define WAR_HAMMER 52
#define WIZARD_STAFF 53
#define POTION_OF_HEALING 54
#define BRANCH 55
#define STEAK 56
#define SCROLL_OF_REJUVINATION 57
#define PERSONAL_JOURNAL 58
#define RABBIT_FOOT 59
#define DEMON_SOUL_IN_A_JAR 60
#define KNIFE_AND_POT 61

// Forest Items
#define CLOAK 110
#define SPRING_WATER 111
#define ELVEN_SWORD 112
#define LANTERN 113
#define IVY_WHIP 114
#define NIGHTSHADE_BERRIES 115
#define TREE_SAP 116
#define TATTERED_MAP 117

// Mountain Items
#define CLIMBING_PICK 120
#define INSULATED_CLOAK 121
#define GRAPPLING_HOOK 122
#define RAM 123
#define BED_ROLL 124
#define EAGLE_EGG 125
#define DRIED_MEAT 126
#define SNOW 127

// Desert Items
#define SANDSTONE_AMULET 130
#define ANCIENT_MANUSCRIPT 131
#define SERPENT_SCALE 132
#define WATERSKIN 133
#define VULTURE_BONE 134
#define SUNSTONE_COMPASS 135
#define DUST_GOGGLES 136
#define SCORPION_VENOM 137

// Village Items
#define BACKPACK 200
#define GENERAL_STORE 201
#define MAP_OF_SURROUNDING_AREA 202

// Pyramid Items
#define WATCH_OF_THE_CHRONOMASTER 210
#define DESERT_SPIRITS_SUNDIAL 211
#define THE_SOUL_OF_A_PHAROAH 212

// Cave Items
#define JEZEBELS_KEY 220
#define JEZEBELS_COIN 221
#define BLESSING_OF_JEZEBEL 222

// Item Functions (IF)

// Empty
bool emptyIF(struct playerStruct*, struct journalStruct*);

// Novice Items
bool pokeyStickIF(struct playerStruct*, struct journalStruct*);
bool fiberWhipIF(struct playerStruct*, struct journalStruct*);
bool rockIF(struct playerStruct*, struct journalStruct*);
bool magicWandIF(struct playerStruct*, struct journalStruct*);
bool bandaidIF(struct playerStruct*, struct journalStruct*);
bool ballOfMudIF(struct playerStruct*, struct journalStruct*);
bool rawMeatIF(struct playerStruct*, struct journalStruct*);
bool strangeMushroomIF(struct playerStruct*, struct journalStruct*);
bool puzzleIF(struct playerStruct*, struct journalStruct*);
bool diceIF(struct playerStruct*, struct journalStruct*);
bool spellBookIF(struct playerStruct*, struct journalStruct*);
bool unsignedDocumentIF(struct playerStruct*, struct journalStruct*);

// Adept Items
bool swordIF(struct playerStruct*, struct journalStruct*);
bool leatherWhipIF(struct playerStruct*, struct journalStruct*);
bool maceIF(struct playerStruct*, struct journalStruct*);
bool wizardHatIF(struct playerStruct*, struct journalStruct*);
bool firstAidKitIF(struct playerStruct*, struct journalStruct*);
bool leafIF(struct playerStruct*, struct journalStruct*);
bool cookedMeatIF(struct playerStruct*, struct journalStruct*);
bool potionIF(struct playerStruct*, struct journalStruct*);
bool bookIF(struct playerStruct*, struct journalStruct*);
bool deckOfCardsIF(struct playerStruct*, struct journalStruct*);
bool orbIF(struct playerStruct*, struct journalStruct*);
bool scrollIF(struct playerStruct*, struct journalStruct*);

// Expert Items
bool katanaIF(struct playerStruct*, struct journalStruct*);
bool morningstarIF(struct playerStruct*, struct journalStruct*);
bool warHammerIF(struct playerStruct*, struct journalStruct*);
bool wizardStaffIF(struct playerStruct*, struct journalStruct*);
bool potionOfHealingIF(struct playerStruct*, struct journalStruct*);
bool branchIF(struct playerStruct*, struct journalStruct*);
bool steakIF(struct playerStruct*, struct journalStruct*);
bool scrollOfRejuvinationIF(struct playerStruct*, struct journalStruct*);
bool personalJournalIF(struct playerStruct*, struct journalStruct*);
bool rabbitFootIF(struct playerStruct*, struct journalStruct*);
bool demonSoulInAJarIF(struct playerStruct*, struct journalStruct*);
bool knifeAndPotIF(struct playerStruct*, struct journalStruct*);

// Forest Items
bool cloakIF(struct playerStruct*, struct journalStruct*);
bool springWaterIF(struct playerStruct*, struct journalStruct*);
bool elvenSwordIF(struct playerStruct*, struct journalStruct*);
bool lanternIF(struct playerStruct*, struct journalStruct*);
bool ivyWhipIF(struct playerStruct*, struct journalStruct*);
bool nightshadeBerriesIF(struct playerStruct*, struct journalStruct*);
bool treeSapIF(struct playerStruct*, struct journalStruct*);
bool tatteredMapIF(struct playerStruct*, struct journalStruct*);

// Mountain Items
bool climbingPickIF(struct playerStruct*, struct journalStruct*);
bool insulatedCloakIF(struct playerStruct*, struct journalStruct*);
bool grapplingHookIF(struct playerStruct*, struct journalStruct*);
bool ramIF(struct playerStruct*, struct journalStruct*);
bool bedRollIF(struct playerStruct*, struct journalStruct*);
bool eagleEggIF(struct playerStruct*, struct journalStruct*);
bool driedMeatIF(struct playerStruct*, struct journalStruct*);
bool snowIF(struct playerStruct*, struct journalStruct*);

// Desert Items
bool sandstoneAmuletIF(struct playerStruct*, struct journalStruct*);
bool ancientManuscriptIF(struct playerStruct*, struct journalStruct*);
bool serpentScaleIF(struct playerStruct*, struct journalStruct*);
bool waterskinIF(struct playerStruct*, struct journalStruct*);
bool vultureBoneIF(struct playerStruct*, struct journalStruct*);
bool sunstoneCompassIF(struct playerStruct*, struct journalStruct*);
bool dustGogglesIF(struct playerStruct*, struct journalStruct*);
bool scorpionVenomIF(struct playerStruct*, struct journalStruct*);

// Village Items
bool backpackIF(struct playerStruct*, struct journalStruct*);
bool generalStoreIF(struct playerStruct*, struct journalStruct*);
bool mapOfSurroundingAreaIF(struct playerStruct*, struct journalStruct*);

// Pyramid Items
bool watchOfTheChronomasterIF(struct playerStruct*, struct journalStruct*);
bool desertSpiritsSundialIF(struct playerStruct*, struct journalStruct*);
bool theSoulOfAPharoahIF(struct playerStruct*, struct journalStruct*);

// Cave Items
bool jezebelsKeyIF(struct playerStruct*, struct journalStruct*);
bool jezebelsCoinIF(struct playerStruct*, struct journalStruct*);
bool blessingOfJezebelIF(struct playerStruct*, struct journalStruct*);