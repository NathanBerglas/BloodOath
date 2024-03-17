// Blood Oath - source.cpp
// Houses main function

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Headers
#include "charecterCreation.h"
#include "playerStruct.h"
#include "gameLoop.h"

// Constants
const int campStartX = 10;
const int campStartY = 4;
const int startingChunk = 10;

// main(void)
int main(void) {
	// Variables
	struct journalStruct journal;

	// Set up and intialization
	srand(time(NULL)); // Initialize a seed
	mapInit(1, journal.map.fullMap);
	mapInit(2, journal.map.playerMap);
	mapInitChunk(journal.map.chunks);
	journal.map.campY = campStartY;
	journal.map.campX = campStartX;
	chunkReveal(&journal, startingChunk);
	journal.map.playerMap[campStartY][campStartX] = 'C';
    journal.biome = journal.map.fullMap[campStartY][campStartX];

	// Intro
	printf("BLOOD OATH - Made by Nate Berglas\n");
	struct playerStruct player = charecterCreation();
	printf("This story starts during the first year of your exile. You, %s, were found to be practicing dark magic", player.name);
	printf(", and due to your heresy was excommunicated. You may rejoin society when you have proved your faith,");
    printf(" by slaying the vampire lord named Jezebel that preys on the land. You hear rumours that he lives in a castle in the forest, ");
    printf("but before taking him on, you need to power up. Collect your gear, and prepare for the adventure of your life!\n");
	if (gameLoop(&player, &journal, 0)) {
		printf("GAME OVER. Thus was the tale of %s\n", player.name);
	} else {
		printf("See you next time!\n");
	}
	return 0;
}
