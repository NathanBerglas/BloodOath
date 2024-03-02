//charecterCreation.c

// Libraries
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Headers
#include "charecterCreation.h"

//charecterCreation(void) Creates the charecter, returning the player that was made
// Effects: 	Reads input
//  		Returns player struct
struct playerStruct charecterCreation(void) {
	// Variables
	struct playerStruct player;
	char inputc[] = "";
	int inputi;
	int statScores[4];

	// Charecter Creation
	printf("What is your name? $: ");
	scanf("%s", &inputc);
	strcpy(player.name, inputc);
	printf("\n");
	printf("Next we will determine the ability scores of  %s. Here are your available stats, chosen randomly.", inputc);
	srand(time(NULL)); // Initialize a seed
	printf("\n");
	for(int i = 0; i < 4; i++) {
		statScores[i] = rand();
		printf("%d: %d\n", i, statScores[i]);
	}
	char *skills[] = {"willpower", "luck", "education", "craftmanship"};
	for(int i = 0; i < 4; i++) {	
		printf("Your available stats are willpower, luck, education and craftmanship. Enter the number you wish for %s $: ", skills[i]);
		scanf("%d", &inputi);
		printf("\n");
		switch (i) {
		case 0:
			player.stats.willpower = statScores[inputi-1];
			break;
		case 1:
			player.stats.luck = statScores[inputi-1];
			break;
		case 2:
			player.stats.education = statScores[inputi-1];
			break;
		case 3:
			player.stats.craftmanship = statScores[inputi-1];
			break;
		default:
			printf("SOMETHING BROKE, stat creation switch statement : %d\n", i);
			break;
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
