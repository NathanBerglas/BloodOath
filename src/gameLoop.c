//gameLoop.c

// Libraries
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Headers
#include "charecterCreation.h"
#include "playerStruct.h"
#include "camp.h"
#include "actions.h"

// Constants
const int actionCount = 3;
const int maxDays = 15;
const int hungerLossMin = 7;
const int hungerLossMax = 18;

void dayEvents(int);

bool gameLoop(struct playerStruct *player, struct journalStruct *journal, int day) {
    // Variables
    int inputi;

    // Check if game is over (lost)
    if (day > maxDays) {
        printf("As the sun sets on your fiteenth day, a chill runs down your spine...\n");
        printf("During the night in the realm where terror reigns, the Vampire Lord Jezebel destorys the forest, your town and all that lives within.\n");
        printf("In natures complete destruction, Jezebel reigns supreme, and marks his new tyranny with your death...\n");
        return false;
    }
    // Pre day events
    dayEvents(day);
    if (day != 0) {
        int randHunger = rand();
        randHunger %= (hungerLossMax - hungerLossMin);
        randHunger += hungerLossMin;
        player->hunger -= randHunger;
    }

    if (player->hunger < 0) {
        printf("Your ribs are showing through your chest, your energy is sapped. You fall to the ground and can't muster enough strength to stand...\n");
        printf("You have starved to death.\n");
        return true;
    }

    // Day loop
    printf("DAY: %d\n", day);
    int actions = actionCount;
    while(actions > 0) {
        printf("Remaining actions: %d\n", actions);
        printf("(1) See camp (0 Actions)\n"); // Done!
        printf("(2) Train 2 skills\n"); // Done!
        printf("(3) Scavenge supplies\n"); // Done! (-encounters)
        printf("(4) Explore\n"); // Done! (-encounters)
        printf("(5) Move Camp\n"); // Done!
        printf("(6) Recover and heal (1 day)\n");
        printf("(7) Quit\n");
        scanf("%d", &inputi);
        switch (inputi) {     
        case 1:
            camp(player, journal);
            break;
        case 2:
            if (train(player)) {
                actions--;
            }
            break;
        case 3:
            if (scavenge(player, journal)) {
                actions--;
            }
            break;
        case 4:
            if (explore(journal)) {
                actions--;
            }
            break;
        case 5:
            if (move(journal)) {
                actions--;
            }
            break;
        case 6:
            if (recover(player)) {
                actions = 0;
            }
            break;
        case 7:
            return false;
            break;
        default:
            printf("Not a correct action.\n");
            actions--;
            break;
        }
    }
    return gameLoop(player, journal, day+1);
}

void dayEvents(int day) {
    // nothin'
}