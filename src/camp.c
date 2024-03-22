//camp.c

// Libraries
#include <stdio.h>
#include <string.h>

// Headers
#include "camp.h"
#include "playerStruct.h"

// camp(player,journal) Displays the camp and allows the player to see many of their stats, items, and mainly map
void camp(struct playerStruct *player, struct journalStruct *journal) {
    printf("CAMP: \n");
    printf("Player: %s\n", player->name);
    printf("Vitality: %d / %d\n", player->vitality, maxVitality);
    printf("Sanity: %d / %d\n", player->sanity, maxSanity);
    printf("Hunger (0 is dead) %d / %d\n", player->hunger, maxHunger);
    printf("XP: %d\n",player->xp);
    printf("Willpower: %d\n", player->stats.willpower);
    printf("Luck: %d\n", player->stats.luck);
    printf("Education: %d\n", player->stats.education);
    printf("Craftmanship: %d\n", player->stats.survival);
    printf("Equipment Slots: \n");
    for(int i = 0; i < MAX_INVENTORY; i++) {
        printf("%d: %s \\ %s\n",i+1,player->inventory[i].name, player->inventory[i].description);
    }
    char biomeString[MAX_STRING_LENGTH];
    strcpy(biomeString, biomeCtoS(journal->biome));
    printf("Camp Biome: %s\n", biomeString);
    printf("Map: \n");
    printf("(_/-: Forest, M: Mountain, r: River, L: Lake, D: Desert, V: Village, P: Pyramid, C: Cave, J: Jezebel's Castle)\n");
    printf("Uppercase is un-scavenged, lower case is scavenged\n");
    printMap(journal);
    printf("Camp actions:\n");
    printf("(1) Manage Inventory\n");
    printf("(2) Exit\n");
    int inputi = 0;
    scanf("%d",&inputi);
    switch (inputi) {
    case 1:
        // Manage Inventory
        printf("Select what item you wish you to use?\n");
        int inputi;
        scanf("%d", &inputi);
        if (player->inventory[inputi - 1].use == NULL) {
            printf("You may not use this item.\n");
        } else {
            if(!player->inventory[inputi - 1].use(player, journal)) {
                printf("You may not use this item at this time.\n");
            }
        }
        break;
    default:
        break; // Exit
    }
}
