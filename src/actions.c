//actions.c

// Libraries
#include <stdio.h>
#include <stdlib.h>

// Headers
#include "actions.h"
#include "playerStruct.h"
#include "items.h"

// Constants
const int TRAINING_MAX = 400;
const int TRAINING_MIN = 200;
const int vitRegainMin = 10;
const int vitRegainMax = 15;
const int sanityRegainMin = 60;
const int sanityRegainMax = 80;

// Action Functions
bool train(struct playerStruct *player) {
    // Variables 
    int inputi;

    printf("What skills would you like to train? Enter the first, then enter the second. You can train the same skill twice. \n");
    printf("(1) Willpower\n");
    printf("(2) Luck\n");
    printf("(3) Education\n");
    for (int i = 0; i < 2; i++) {
        int trainAmount = rand(); // 800-1200
        trainAmount  %= (TRAINING_MAX-TRAINING_MIN);
        trainAmount += TRAINING_MIN;
        scanf("%d", &inputi);
        switch (inputi) {
        case 1:
            player->stats.willpower += trainAmount;
            printf("You train willpower by: %d\n", trainAmount);
            break;
        case 2:
            player->stats.luck += trainAmount;
            printf("You train luck by: %d\n", trainAmount);
            break;
        case 3:
            player->stats.education += trainAmount;
            printf("You train education by: %d\n", trainAmount);
            break;
        /*case 4:
           player->stats.survival += trainAmount;
            printf("You train survival by: %d\n", trainAmount);
           break; */
        default:
            printf("Not a correct skill. Training forfeit.\n");
            player->xp -= trainAmount;
            return false;
            break;
        }
        player->xp += trainAmount;
    }
    return true;
}

bool scavenge(struct playerStruct *player, struct journalStruct *journal) {
    printf("You leave camp to scavenge for supplies.\n");
    if (player->inventory[MAX_INVENTORY - 1].id != EMPTY) {
        printf("Warning! Your hands are full. If you do not have a backpack, you will not be able to pick up any more items.\n");
        printf("Do you wish to continue? (1): Yes, (2), No\n");
        int inputi;
        scanf("%d",&inputi);
        if (inputi != 1) {
            printf("You head home.\n");
            return false;
        }
    }
    if (('a' < journal->biome && journal->biome < 'z') || journal->biome == '-') { // Checking if explored
        printf("This area has already been scavenged. You return to camp.\n");
        return false;
    } else {
        struct item foundItem = randomItem(player->stats.luck, player->xp, journal->biome);
        printf("You found: %s!\n", foundItem.name);
        if (appendItem(foundItem, player)) {
            printf("You have taken the item.\n");
        } else {
            printf("Your inventory is full, you unfortunatly discard it.");
        }
        // Adjusts full map. Since playermap holds 'C', when you move the camp it adjusts for you, no extra stuff needed.
        if (journal->map.fullMap[journal->map.campY][journal->map.campX] != '_') { // Check if forest, because unique behavior
            journal->map.fullMap[journal->map.campY][journal->map.campX] += ('a' - 'A'); // Changes to lowercase;
        } else {
            journal->map.fullMap[journal->map.campY][journal->map.campX] = '-';
        } 
        journal->biome = journal->map.fullMap[journal->map.campY][journal->map.campX];
    }
    return false;
}

// Helper function for explore
char printChunk(const struct journalStruct *journal, const int index) {
    if (journal->map.campX < (index%7 +1) * 3 && journal->map.campX >= (index%7) * 3 && // 12
        journal->map.campY < (index/7 + 1) * 3 && journal->map.campY >= (index/7) * 3) {
        return 'C';
    } else if (journal->map.chunks[index] == 'E') {
        return 'E';
    } else {
        return '?';
    }
}

bool explore(struct journalStruct *journal) {
    // Variables
    int inputi = 0;

    printf("Explore: Exploring reveals more map, but may cause encounters which could hurt you. You must be prepared!\n");
    printf("Explored and Unexplored sections:\n");
    for(int i = 0; i < CHUNK_COUNT; i++) {
        if (i%7 == 0) {
            printf("\n%c", printChunk(journal, i));
        } else {
            printf(" %c", printChunk(journal, i));
        }
    }
    printf("\nWould you like to explore: Only enter a direction you may go from C (Camp)\n");
    printf("(1) North\n");
    printf("(2) East\n");
    printf("(3) South\n");
    printf("(4) West\n");
    scanf("%d", &inputi);
    switch (inputi)
    {
    case 1:
        chunkReveal(journal, (journal->map.campY / CHUNK_SIZE) * (CHUNK_COUNT / CHUNK_SIZE) + (journal->map.campX / CHUNK_SIZE) - (MAP_WIDTH / CHUNK_SIZE));
        break;
    case 2:
        chunkReveal(journal, (journal->map.campY / CHUNK_SIZE) * (CHUNK_COUNT / CHUNK_SIZE) + (journal->map.campX / CHUNK_SIZE) + 1);
        break;
    case 3:
        chunkReveal(journal, (journal->map.campY / CHUNK_SIZE) * (CHUNK_COUNT / CHUNK_SIZE) + (journal->map.campX / CHUNK_SIZE) + (MAP_WIDTH / CHUNK_SIZE));
        break;
    case 4:
        chunkReveal(journal, (journal->map.campY / CHUNK_SIZE) * (CHUNK_COUNT / CHUNK_SIZE) + (journal->map.campX / CHUNK_SIZE) - 1);
        break;
    default:
        printf("Incorrect direction. You just stayed home.\n");
        return false;
        break;
    }
    return true;
}

bool move(struct journalStruct *journal) {
    // Variables
    int inputiX = 0;
    int inputiY = 0;

    printf("What explored tile do you wish to move your camp? Please enter the column then row / X, then Y.\n");
    printf("You start at (11,5). Top right would be (21, 1). Bottom left would be (1, 9) \n");
    printf("Note: You may only move your camp to explore solid tiles. No rivers (r) or Lakes (L): \n");
    printMap(journal);
    printf("\n");
    scanf("%d", &inputiX);
    scanf("%d", &inputiY);
    //printf("\nx:, %d, y: %d->%c<-\n",inputiX-1, inputiY-1, journal->map.playerMap[inputiY - 1][inputiX - 1]);
    if (inputiX > 1 && inputiX <= MAP_WIDTH && inputiY  > 1 && inputiY <= MAP_HEIGHT &&
        journal->map.playerMap[inputiY - 1][inputiX - 1] != '?' &&
        journal->map.playerMap[inputiY - 1][inputiX - 1] != 'r' &&
        journal->map.playerMap[inputiY - 1][inputiX - 1] != 'L') {
        moveCamp(journal, inputiX, inputiY);
    } else {
        printf("Invalid camp position. Either unexplored or water.\n");
        return false;
    }
    return true;
}

// For recover
int min(int a, int b) {
    return (a < b) ? a : b;
}

bool recover(struct playerStruct *player) {
    int randVit = rand();
    randVit %= (vitRegainMax - vitRegainMin);
    randVit += vitRegainMin;

    int randSan = rand();
    randSan %= (sanityRegainMax - sanityRegainMin);
    randSan += sanityRegainMin;

    printf("You take the day easy and rest and recover.\n");
    printf("You gain %d vitality, and %d sanity.\n", min(randVit, (maxVitality - player->vitality)), min(randSan, (maxSanity - player->sanity)));
    player->vitality += min(randVit, (maxVitality - player->vitality));
    player->sanity += min(randSan, (maxSanity - player->sanity));
    return true;
}