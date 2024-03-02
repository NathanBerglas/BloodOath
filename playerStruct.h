//playerStruct.h
#ifndef PLAYERSTRUCT_H
#define PLAYERSTRUCT_H

struct item {
	char name[30]; // when you're better at c replaced with maxTextLength and others
	char description[];
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
	struct item inventory[10]; // here
	char name[30]; // here as well
};
#endif