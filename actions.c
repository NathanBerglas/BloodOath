//actions.c

// Headers
#include "actions.h"
#include "playerStruct.h"

// Action Functions
void train(struct playerStruct *player) {
    // Variables 
    int inputi1;
    int inputi2;
    int trainAmount = rand(); // 1000-2500
    trainAmount  %= 1000;
    trainAmount += 1500;

    printf("What skills would you like to train? Enter the first, then enter the second. You can train the same skill twice. \n");
    printf("(1) Willpower\n");
    printf("(2) Luck\n");
    printf("(3) Education\n");
    printf("(4) Craftmanship\n");
    scanf("%d", &inputi1);
    scanf("%d", &inputi2);
    switch (inputi1) {
    case 1:
        player->stats.willpower += trainAmount;
        break;
    case 2:
        player->stats.luck += trainAmount;
        break;
    case 3:
        player->stats.education += trainAmount;
        break;
    case 4:
        player->stats.craftmanship += trainAmount;
        break;
    default:
        printf("Not a correct skill. Training forfeit.\n");
        break;
    }
    switch (inputi2) {
    case 1:
        player->stats.willpower += trainAmount;
        break;
    case 2:
        player->stats.luck += trainAmount;
        break;
    case 3:
        player->stats.education += trainAmount;
        break;
    case 4:
        player->stats.craftmanship += trainAmount;
        break;
    default:
        printf("Not a correct skill. Training forfeit.\n");
        break;
    }
}

void scavenge(struct playerStruct *player) {
    
}

void explore(struct playerStruct *player) {

}

void move(struct playerStruct *player) {

}

void recover(struct playerStruct *player) {

}
