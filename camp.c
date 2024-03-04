//camp.c

// Libraries
#include <stdio.h>

// Headers
#include "camp.h"
#include "playerStruct.h"

// camp(player,journal) Displays the camp and allows the player to see many of their stats, items, and mainly map
void camp(struct playerStruct *player, struct journalStruct *journal) {
    printf("CAMP: \n");
    printf("Player: %s", player->name);
    printf("XP: %d",player->xp);
    char biomeString[MAX_STRING_LENGTH];
    biomeItoS(journal->biome, biomeString);
    printf("Camp Biome: %s\n", biomeString);
    printf("Equipment Slots: \n");
    for(int i = 0; i < MAX_INVENTORY; i++) {
        printf("%d: %s\n",i+1,player->inventory[i].name);
    }
    printf("Map: \n");
    for (int y = 0; y < MAP_HEIGHT; y++) {
        printf("%c",journal->map.playerMap[0][y]);
        for (int x = 1; x < MAP_WIDTH; x++) {
            printf(" %c",journal->map.playerMap[y][x]);
        }
        printf("\n");
    }
}
