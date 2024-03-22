//playerStruct.h
#ifndef PLAYERSTRUCT_H
#define PLAYERSTRUCT_H

// Libraries
#include <stdbool.h>

// Headers
#include "playerStruct.h"

// Macros
#define MAX_INVENTORY 10
#define BACKPACK_SIZE 10
#define MAX_STRING_LENGTH 30
#define MAX_DESCRIPTION_LENGTH 64
#define ITEM_CLASS_SIZE 12
#define ITEM_BIOME_SIZE 8
#define ITEM_SPECIAL_SIZE 3
#define MAP_HEIGHT 9
#define MAP_WIDTH 21
#define CHUNK_COUNT 21
#define CHUNK_SIZE 3

// Constants
extern const struct item emptyItem;
extern const int maxVitality;
extern const int maxSanity;
extern const int maxHunger;

// Structures

struct playerStruct; // For item
struct journalStruct; // For item

// Player
struct item {
	char *name;
	char *description;
	int id;
	bool (*use)(struct playerStruct*, struct journalStruct*);
};

struct statBlock {
	int willpower;
	int luck;
	int education;
	int survival;
};

struct playerStruct {
	int vitality;
	int sanity;
	int hunger;
	int xp;
	struct statBlock stats;
	struct item inventory[MAX_INVENTORY + BACKPACK_SIZE];
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
	char biome;
};

// Functions
char* biomeCtoS(char);
void mapInit(int, char[MAP_HEIGHT][MAP_WIDTH]);
void mapInitChunk(char[CHUNK_COUNT]);
void printMap(struct journalStruct*);
void chunkReveal(struct journalStruct*, int);
void moveCamp(struct journalStruct*, int, int);
bool appendItem(struct item, struct playerStruct*);
bool deleteItem(int, struct playerStruct*);
struct item randomItem(int, int, char);

#endif