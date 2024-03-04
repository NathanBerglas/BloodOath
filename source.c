// Blood Oath - source.cpp
// Houses main function

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Headers
#include "charecterCreation.h"
#include "playerStruct.h"
#include "gameLoop.h"

// Constants
const int campStartX = 9;
const int campStartY = 3;

// main(void)
int main(void) {
	// Variables
	int input;
	struct journalStruct journal;

	// Set up and intialization
	mapInit(1, journal.map.fullMap);
	mapInit(2, journal.map.playerMap);
	journal.map.campY = campStartY;
	journal.map.campX = campStartX;
	mapReveal(&journal);

	// Intro
	printf("BLOOD OATH - Made by Nate Berglas\n");
	struct playerStruct player = charecterCreation();
	printf("This story starts during the first year of your exile. You, %s, were found to be practicing dark magic", player.name);
	printf(", and due to your heresy was excommunicated. You may rejoin society when you have proved your faith,");
    printf(" by slaying the vampire lord named Jezebel that preys on the land. You hear rumours that he lives in a castle in the forest, ");
    printf("but before taking him on, you need to power up. Collect your gear, and prepare for the adventure of your life!\n");
	if (gameLoop(&player, &journal, 0)) {
		printf("You win! You have defeated the vampire lord and are reinstated to your village as a hero!\n");
	} else {
		printf("You lose :0 \n");
	}
	printf("GAME OVER\n");
	return 0;
}
