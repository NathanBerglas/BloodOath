//gameLoop.c

// Libraries
#include<stdio.h>
#include <stdbool.h>

// Headers
#include "charecterCreation.h"
#include "playerStruct.h"
#include "camp.h"

// Constants
const int actionCount = 3;

bool gameLoop(struct playerStruct player, struct journalStruct journal, int day) {
    // Variables
    int inputi;

    // Check if game is over (lost)
    if (day > 15) {
        printf("As the sun sets on your fiteenth day, a chill runs down your spine...\n");
        printf("During the night in the realm where terror reigns, the Vampire Lord Jezebel destorys the forest, your town and all that lives within.\n");
        printf("In natures complete destruction, Jezebel reigns supreme, and marks his new tyranny with your death...\n");
        return false;
    }

    // Day loop
    printf("DAY: %d\n", day);
    for (int actions = actionCount; actions > 0; actions--) {
        printf("Remaining actions: %d\n", actions);
        printf("(1) See camp (0 Actions)\n");
        printf("(2) Train 3 skills (1 Actions)\n");
        printf("(3) Scavenge supplies (1 Action)\n");
        printf("(4) Explore (2 Actions)\n");
        printf("(5) Recover and heal (1 day)\n");
        scanf("%d", &inputi);
        switch (inputi) {     
        case 1:
            camp(player, journal);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("Not a correct action. You just chill the whole day.\n");
            break;
        }
    }
    gameLoop(player, journal, day+1);
}
