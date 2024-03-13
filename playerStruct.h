//playerStruct.h
#ifndef PLAYERSTRUCT_H
#define PLAYERSTRUCT_H

// Libraries
#include <stdbool.h>

// Macros
#define MAX_INVENTORY 10
#define MAX_STRING_LENGTH 30
#define MAX_DESCRIPTION_LENGTH 64
#define ITEM_CLASS_SIZE 12
#define MAP_HEIGHT 9
#define MAP_WIDTH 21
#define CHUNK_COUNT 21
#define CHUNK_SIZE 3

// Constants
extern const struct item emptyItem;

// Structures
// Player
struct item {
	char name[MAX_STRING_LENGTH];
	char description[MAX_DESCRIPTION_LENGTH];
	bool occupied;
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
	char chunks[CHUNK_COUNT];
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
void mapInitChunk(char[CHUNK_COUNT]);
void printMap(struct journalStruct*);
void chunkReveal(struct journalStruct*, int);
void moveCamp(struct journalStruct*, int, int);
bool appendItem(struct item, struct playerStruct*);
bool deleteItem(int, struct playerStruct*);
struct item randomItem(int, int);

#endif