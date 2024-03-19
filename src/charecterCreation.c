//charecterCreation.c

// Libraries
#include <stdio.h>
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
const int minStartVit = 3;
const int maxStartVit = 6;
const int maxStartHunger = 40;
const int minStartHunger = 30;

// Functions

// Helper for charecterCreation
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
		player->stats.survival = *(statScores+input-1);
		break;
	default:
		// Other
		printf("INCORRECT SKILL!!\n");
		break;
	}
}

//charecterCreation(void) Creates the charecter, returning the player that was made
// Effects: 	Reads input
//  		Returns player struct
struct playerStruct *charecterCreation(void) {
	// Variables
	struct playerStruct *player = malloc(sizeof(struct playerStruct));
	char inputc[MAX_STRING_LENGTH];
	int inputi;
	int statScores[SKILL_COUNT];

	// Vitality, Sanity, and Hunger	
	int randVit = rand();
	randVit %= (maxStartVit - minStartVit);
	randVit +=  minStartVit;
	player->vitality = randVit;
	player->sanity = 100; // Out of 100
	int randHun = rand();
	randHun %= (maxStartHunger - minStartHunger);
	randHun +=  minStartHunger;
	player->hunger = randHun;

	// Inventory Set up

	for (int i = 0; i < MAX_INVENTORY; i++) {
		player->inventory[i] = emptyItem;
	}
	#ifndef SKIP
	// Charecter Creation I/O & stats
	printf("What is your name? $: ");
	scanf("%s", inputc);
	strcpy(player->name, inputc);
	printf("\n");
	printf("Next we will determine the ability scores of  %s. Here are your available stats, chosen randomly.", inputc);
	printf("\n");
	char *skills[] = {"willpower", "luck", "education", "survival"};
	for(int j = 0; j < SKILL_COUNT; j++) {
		statScores[j] = rand();
		statScores[j] %= maxSkill-minSkill;
		statScores[j] += minSkill;
		printf("%d: %d\n", j + 1, statScores[j]);
	}
	for (int i = 0; i < SKILL_COUNT; i++) {
		printf("Your available stats are willpower, luck, education and craftmaship. Enter the number you want for %s $: ",skills[i]);
		scanf("%d", &inputi);
		skillAssign(i, inputi, player, statScores);
		printf("Available scores:\n");
		for (int j = 0; j < SKILL_COUNT - i - 1; j++) {
			if (j == inputi - 1) {
				for (int k = 0; k < 4 - i - j; k++) {
					statScores[k] = statScores[k+1];
				}
			}
			printf("%d: %d\n", j + 1, statScores[j]);
		}
	}

	// Xp set up
	player->xp = player->stats.willpower + player->stats.luck + player->stats.education + player->stats.survival;

	printf("Before you flee your village, you have the chance to grab a single item, choose carefully. Enter the number of the item you choose:\n");
	struct item randItem1 = randomItem(player->stats.luck, player->xp, ' ');	
	struct item randItem2 = randomItem(player->stats.luck, player->xp, ' ');
	printf("(1): %s / %s\n", randItem1.name, randItem1.description);
	printf("(2): %s / %s\n", randItem2.name, randItem2.description);
	scanf("%d",&inputi);
	switch (inputi) {
		case 1:
			appendItem(randItem1, player);
		break;
		case 2:
			appendItem(randItem2, player);
		break;
		default:
			printf("Item forfeit, you decide you'll be fine without.\n");
		break;
	}

	printf("Thus concludes charecter creation. This is your charecter:\n");
	printf("Name: %s\n", player->name);
	printf("Willpower: %d\n", player->stats.willpower);
	printf("Luck: %d\n", player->stats.luck);
	printf("Education: %d\n", player->stats.education);
	printf("Craftmanship: %d\n", player->stats.survival);
	
	#else
	player->name[0] = 'P';
	player->stats.willpower = 1800;
	player->stats.luck = 1800;
	player->stats.education = 1800;
	player->stats.survival = 1800;
	player->xp = player->stats.willpower + player->stats.luck + player->stats.education + player->stats.survival;
	#endif
	
	return player;
}

void charecterDestruction(struct playerStruct* player) {
	free(player);
}