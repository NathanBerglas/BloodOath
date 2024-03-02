// Blood Oath - source.cpp
// Houses main function

// Libraries
#include <stdio.h>
#include <stdlib.h>

// Headers
#include "charecterCreation.h"
#include "playerStruct.h"
#include "gameLoop.h"

// main(void)
int main(void) {
	int input;
	printf("BLOOD OATH - Made by Nate Berglas\n");
	struct playerStruct player = charecterCreation();
	printf("This story starts during the first year of your exile. You, %s, were found to be practicing dark magic", player.name);
	printf(", and due to your heresy was excommunicated. You may rejoin society when you have proved your faith,");
    printf(" by slaying the vampire lord that preys on the land. You hear rumours that he lives in a cave in the forest, ");
    printf("but before then you need to power up. Collect your gear, and prepare for the adventure of your life!\n");
	gameLoop(player);
	return 0;
}
