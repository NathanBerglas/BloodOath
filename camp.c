//camp.c

// Libraries
#include <stdio.h>

// Headers
#include "camp.h"
#include "playerStruct.h"

// camp(player,journal) Displays the camp and allows the player to see many of their stats, items, and mainly map
void camp(struct playerStruct *player, struct journalStruct *journal) {
    printf("CAMP: \n");
    printf("Player: %s\n", player->name);
    printf("XP: %d\n",player->xp);
    printf("Willpower: %d\n", player->stats.willpower);
    printf("Luck: %d\n", player->stats.luck);
    printf("Education: %d\n", player->stats.education);
    printf("Craftmanship: %d\n", player->stats.craftmanship);
    printf("Equipment Slots: \n");
    for(int i = 0; i < MAX_INVENTORY; i++) {
        printf("%d: %s \\ %s\n",i+1,player->inventory[i].name, player->inventory[i].description);
    }
    char biomeString[MAX_STRING_LENGTH];
    biomeItoS(journal->biome, biomeString);
    printf("Camp Biome: %s\n", biomeString);
    printf("Map: \n");
    printf("(_: Forest, M: Mountain, r: River, L: Lake, D: Desert, V: Village, c: Small Cave, C: Big Cave, J: Jezebel's Castle)\n");
    printMap(journal);
    printf("Camp actions:\n");
    printf("(1) Manage Inventory\n");
    printf("(2) Exit\n");
    int inputi = 0;
    scanf("%d",&inputi);
    switch (inputi) {
    case 1:
        // Manage Inventory
        break;
    default:
        break; // Exit
    }
}
