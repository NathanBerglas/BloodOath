//charecterCreation.c

// Libraries
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Headers
#include "charecterCreation.h"
#include "playerStruct.h"

//skillAssign(skill, input);
void skillAssign(int skill, int input, struct playerStruct* player, int statScores[]);

//charecterCreation(void) Creates the charecter, returning the player that was made
// Effects: 	Reads input
//  		Returns player struct
struct playerStruct charecterCreation(void) {
	// Variables
	struct playerStruct player;
	char inputc[20];
	int inputi;
	int statScores[4];

	// Charecter Creation
	printf("What is your name? $: ");
	scanf("%s", inputc);
	strcpy(player.name, inputc);
	printf("\n");
	printf("Next we will determine the ability scores of  %s. Here are your available stats, chosen randomly.", inputc);
	srand(time(NULL)); // Initialize a seed
	printf("\n");
	char *skills[] = {"willpower", "luck", "education", "craftmanship"};
	for(int j = 0; j < 4; j++) {
		statScores[j] = rand();
		statScores[j] %= 2000;
		statScores[j] += 500;
		printf("%d: %d\n", j+1, statScores[j]);
	}
	for (int i = 0; i < 4; i++) {
		printf("Your available stats are willpower, luck, education and craftmaship. Enter the number you want for %s $: ",skills[i]);
		scanf("%d", &inputi);
		skillAssign(i,inputi,&player,statScores);
		printf("Available scores:\n");
		for (int j = 0; j < 4-i-1; j++) {
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
	return player;
}

void skillAssign(int skill, int input, struct playerStruct* player, int statScores[]) {
	if (skill == 0) {
		// Willpower
		player->stats.willpower = *(statScores+input-1);
	} else if (skill == 1) {
		// Luck
		player->stats.luck = *(statScores+input-1);
	} else if (skill == 2) {
		// Education
		player->stats.education = *(statScores+input-1); 
	} else if (skill == 3) {
		// Craftmanship
		player->stats.craftmanship = *(statScores+input-1);
	}
}