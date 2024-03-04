//playerStruct.h
#ifndef PLAYERSTRUCT_H
#define PLAYERSTRUCT_H

// Macros
#define MAX_INVENTORY 10
#define MAX_STRING_LENGTH 30
#define MAX_DESCRIPTION_LENGTH 64
#define MAP_HEIGHT 7
#define MAP_WIDTH 21

// Structures
// Player
struct item {
	char name[MAX_STRING_LENGTH];
	char description[MAX_DESCRIPTION_LENGTH];
};

struct statBlock {
	int willpower;
	int luck;
	int education;
	int craftmanship;
};

struct playerStruct {
	int xp;
	struct statBlock stats;
	struct item inventory[MAX_INVENTORY];
	char name[MAX_STRING_LENGTH];
};

// Journal
struct mapStruct {
	char playerMap[MAP_HEIGHT][MAP_WIDTH];
	char fullMap[MAP_HEIGHT][MAP_WIDTH];
	int campX;
	int campY;
};

struct journalStruct {
	struct mapStruct map;
	int biome;
};

// Functions
int biomeCtoI(char);
void biomeItoS(int, char[MAX_STRING_LENGTH]);
void mapInit(const int, char[MAP_HEIGHT][MAP_WIDTH]);
void mapReveal(struct journalStruct*);

#endif