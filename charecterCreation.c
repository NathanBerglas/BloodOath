//charecterCreation.c

// Libraries
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Headers
#include "charecterCreation.h"
#include "playerStruct.h"

// Macros
#define SKILL_COUNT 4

// Constants
const int minSkill = 1500;
const int maxSkill = 2500;

// Functions
void skillAssign(int skill, int input, struct playerStruct* player, int statScores[]);

//charecterCreation(void) Creates the charecter, returning the player that was made
// Effects: 	Reads input
//  		Returns player struct
struct playerStruct charecterCreation(void) {
	// Variables
	struct playerStruct player;
	char inputc[MAX_STRING_LENGTH];
	int inputi;
	int statScores[SKILL_COUNT];

	// Inventory Set up
	for (int i = 0; i < MAX_INVENTORY; i++) {
		strcpy(player.inventory[i].name, "Empty");
		strcpy(player.inventory[i].description, "No description");
	}
	#ifndef SKIP
	// Charecter Creation I/O & stats
	printf("What is your name? $: ");
	scanf("%s", inputc);
	strcpy(player.name, inputc);
	printf("\n");
	printf("Next we will determine the ability scores of  %s. Here are your available stats, chosen randomly.", inputc);
	srand(time(NULL)); // Initialize a seed
	printf("\n");
	char *skills[] = {"willpower", "luck", "education", "craftmanship"};
	for(int j = 0; j < SKILL_COUNT; j++) {
		statScores[j] = rand();
		statScores[j] %= maxSkill-minSkill;
		statScores[j] += minSkill;
		printf("%d: %d\n", j+1, statScores[j]);
	}
	for (int i = 0; i < SKILL_COUNT; i++) {
		printf("Your available stats are willpower, luck, education and craftmaship. Enter the number you want for %s $: ",skills[i]);
		scanf("%d", &inputi);
		skillAssign(i,inputi,&player,statScores);
		printf("Available scores:\n");
		for (int j = 0; j < SKILL_COUNT-i-1; j++) {
			if (j == inputi-1) {
				for (int k = 0; k < 4-i-j; k++) {
					statScores[k] = statScores[k+1];
				}
			}
			printf("%d: %d\n", j+1, statScores[j]);
		}
	}
	printf("Thus concludes charecter creation. This is your charecter:\n");
	printf("Name: %s\n", player.name);
	printf("Willpower: %d\n", player.stats.willpower);
	printf("Luck: %d\n", player.stats.luck);
	printf("Education: %d\n", player.stats.education);
	printf("Craftmanship: %d\n", player.stats.craftmanship);
	#else
	player.name[0] = 'P';
	player.stats.willpower = 1800;
	player.stats.luck = 1800;
	player.stats.education = 1800;
	player.stats.craftmanship = 1800;
	#endif
	// Xp set up
	player.xp = player.stats.willpower+player.stats.luck+player.stats.education+player.stats.craftmanship;
	
	return player;
}

void skillAssign(int skill, int input, struct playerStruct* player, int statScores[]) {
	switch(skill) {
	case 0:
		// Willpower
		player->stats.willpower = *(statScores+input-1);
		break;
	case 1:
		// Luck
		player->stats.luck = *(statScores+input-1);
		break;
	case 2:
		// Education
		player->stats.education = *(statScores+input-1);
		break; 
	case 3:
		// Craftmanship
		player->stats.craftmanship = *(statScores+input-1);
		break;
	default:
		// Other
		printf("INCORRECT SKILL!!\n");
		break;
	}
}