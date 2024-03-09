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
void train(struct playerStruct *player) {
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
            break;
        }
        player->xp += trainAmount;
    }
}

void scavenge(struct playerStruct *player) {
    
}

// Helper function for explore
char printChunk(const struct journalStruct *journal, const int index) {
    if (journal->map.campX <= (index%7 +1) * 3 && journal->map.campX >= (index%7) * 3 &&
        journal->map.campY <= (index/7 + 1) * 3 && journal->map.campY >= (index/7) * 3) {
        return 'C';
    } else if (journal->map.chunks[index] == 'E') {
        return 'E';
    } else {
        return '?';
    }
}

void explore(struct journalStruct *journal) {
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
        break;
    }
}

void move(struct playerStruct *player) {

}

void recover(struct playerStruct *player) {

}
