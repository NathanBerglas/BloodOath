//actions.c

// Libraries
#include <stdio.h>
#include <stdlib.h>

// Headers
#include "actions.h"
#include "playerStruct.h"

// Constants
const int TRAINING_MAX = 400;
const int TRAINING_MIN = 200;

// Action Functions
bool train(struct playerStruct *player) {
    // Variables 
    int inputi;

    printf("What skills would you like to train? Enter the first, then enter the second. You can train the same skill twice. \n");
    printf("(1) Willpower\n");
    printf("(2) Luck\n");
    printf("(3) Education\n");
    printf("(4) Craftmanship\n");
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
        case 4:
           player->stats.craftmanship += trainAmount;
            printf("You train craftmanship by: %d\n", trainAmount);
           break;
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

bool scavenge(struct playerStruct *player) {
    // int inputi = 0;
    // printf("Press 1: add item, 2: delete item\n");
    // scanf("%d", &inputi);
    // if (inputi == 1) {
    //     appendItem(randomItem(player->stats.luck, player->xp), player);
    // } else {
    //     printf("Give item you wish to destroy from 1 to %d", MAX_INVENTORY);
    //     scanf("%d", &inputi);
    //     printf("inventory slot 2 name: %s",player->inventory[1].name);
    //     deleteItem(inputi - 1, player);
    // }
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

bool recover(struct playerStruct *player) {
    return false;
}