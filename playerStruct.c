//playerStruct.h

// Libraries
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Headers
#include "playerStruct.h"
#include "itemAndEncounters.h"

// Biome Macros
#define FOREST 990
#define CAMP 999
#define LAKE 991
#define RIVER 992
#define MOUNTAIN 993
#define DESERT 994
#define SMALL_CAVE 995
#define BIG_CAVE 996
#define VILLAGE 997
#define JEZEBEL_CASTLE 998

// item constants
const struct item emptyItem = {"Empty", "No description", false};
const int luckScale = 1;
const int stage1 = 15000;
const int stage2 = 30000;



int biomeCtoI(char biomeChar) {
    switch (biomeChar)
    {
    case '_':
        return FOREST;
        break;
    case 'L':
        return LAKE;
        break;
    case 'r':
        return RIVER;
        break;
    case 'M':
        return MOUNTAIN;
        break;
    case 'D':
        return DESERT;
        break;
    case 'c':
        return SMALL_CAVE;
        break;
    case 'C':
        return BIG_CAVE;
        break;
    case 'V':
        return VILLAGE;
        break;
    case 'J':
        return JEZEBEL_CASTLE;
    default:
        return -1;
        break;
    }
}

void biomeItoS(int biomeInt, char biomeString[MAX_STRING_LENGTH]) {
    switch (biomeInt) {
    case FOREST:
        char Forest[MAX_STRING_LENGTH] = "Forest";
        strcpy(biomeString, Forest);
        break;
    case LAKE:
        char Lake[MAX_STRING_LENGTH] = "Lake";
        strcpy(biomeString, Lake);
        break;
    case RIVER:
        char River[MAX_STRING_LENGTH] = "River";
        strcpy(biomeString, River);
        break;
    case MOUNTAIN:
        char Mountain[MAX_STRING_LENGTH] = "Mountain";
        strcpy(biomeString, Mountain);
        break;
    case DESERT:
        char Desert[MAX_STRING_LENGTH] = "Desert";
        strcpy(biomeString, Desert);
        break;
    case SMALL_CAVE:
        char Small_Cave[MAX_STRING_LENGTH] = "Small Cave";
        strcpy(biomeString, Small_Cave);
        break;
    case BIG_CAVE:
        char Big_Cave[MAX_STRING_LENGTH] = "Big Cave";
        strcpy(biomeString, Big_Cave);
        break;
    case VILLAGE:
        char Village[MAX_STRING_LENGTH] = "Village";
        strcpy(biomeString, Village);
        break;
    case JEZEBEL_CASTLE:
        char Jezebels_Castle[MAX_STRING_LENGTH] = "Jezebel's Castle";
        strcpy(biomeString, Jezebels_Castle);
        break;
    }
}

void mapInit(const int type, char mapInit[MAP_HEIGHT][MAP_WIDTH]) {
    // Full map
    if (type == 1) {
		    char map[MAP_HEIGHT][MAP_WIDTH] = { // C for camp, _ for forest, L for lake, r for river M for mountain, D for desert, c for small cave, C for big cave, and V for village
            "rrrLLLLLLLLLrrrrrrrrM",
            "MMrM_LLLLLL______CMMr",
            "DDM_r_L_LLL__MM___MMr",
            "DDD__L____r_____MMMM_",
            "DDVD___M___r_M_MM__MM",
            "DDDDD__MM_r___MM_JJMm",
            "DcDDDD_____r_____JJMM",
            "DLLDDD__rVrr_______MM",
            "DDDDDDDr_____________"
	    };
        for (int x = 0; x <= MAP_WIDTH; x++) {
            for (int y = 0; y <= MAP_HEIGHT; y++) {
                mapInit[y][x] = map[y][x];
            }
        }
	} else if (type == 2) {
        // Player map
	    char map[MAP_HEIGHT][MAP_WIDTH] = {
           "?????????????????????",
           "?????????????????????",
           "?????????????????????",
           "?????????????????????",
           "?????????????????????",
           "?????????????????????",
           "?????????????????????",
           "?????????????????????",
           "?????????????????????"
        };
        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                mapInit[y][x] = map[y][x];
            }
        }
    }
}

// Initializes a chunk
void mapInitChunk(char mapInit[CHUNK_COUNT]) {
    char map[CHUNK_COUNT]= {
        '?','?','?','?','?','?','?',
        '?','?','?','?','?','?','?',
        '?','?','?','?','?','?','?'
    };
    for (int chunk = 0; chunk < CHUNK_COUNT; chunk++) {
            mapInit[chunk] = map[chunk];
    }
}

void printMap(struct journalStruct* journal) {
    printf("0   1 ");
    for (int i = 2; i <= MAP_WIDTH; i++) {
        printf("%d ", (i%10));
    }
    printf("\n");
    for (int y = 0; y < MAP_HEIGHT; y++) {
        printf("%d | ", y+1);
        printf("%c",journal->map.playerMap[y][0]);
        for (int x = 1; x < MAP_WIDTH; x++) {
            printf(" %c",journal->map.playerMap[y][x]);
        }
        printf("\n");
    }
}

// Reveals a chosen chunk
void chunkReveal(struct journalStruct* journal, int chunk) { // Takes index
    int offsetY[9] = {0, 0, 0, 1, 0, 0, 1, 0, 0};
    int offsetX[9] = {0, 1, 1, -2, 1, 1, -2, 1, 1};
    int indexY = chunk / (MAP_WIDTH / CHUNK_SIZE);
    int indexX = chunk % (MAP_WIDTH / CHUNK_SIZE);
    // Now indexY and inedxX are at the correct chunk, but not coords
    indexY = indexY * CHUNK_SIZE;
    indexX = indexX * CHUNK_SIZE;
    for (int i = 0; i < 9; i++) {
        indexY += offsetY[i];
        indexX += offsetX[i];
        if (indexX >= 0 && indexX < MAP_WIDTH && indexY >= 0 && indexY < MAP_HEIGHT) { // Should not be neccesary if given chunk is good
            journal->map.playerMap[indexY][indexX] =
            journal->map.fullMap[indexY][indexX];
        }
    }
    journal->map.chunks[chunk] = 'E';
    journal->map.playerMap[journal->map.campY][journal->map.campX] = 'C';
}

// Moves camp
void moveCamp(struct journalStruct* journal, int x, int y) {
    //printf("\nplayer x : %d,y: %d -> %c\n\n",journal->map.campX, journal->map.campY, journal->map.playerMap[journal->map.campY][journal->map.campX]);
    journal->map.playerMap[journal->map.campY][journal->map.campX] = 
    journal->map.fullMap[journal->map.campY][journal->map.campX];
    journal->map.campX = x - 1;
    journal->map.campY = y - 1;
    //printf("\nplayer x : %d,y: %d -> %c\n\n",journal->map.campX, journal->map.campY, journal->map.playerMap[journal->map.campY][journal->map.campX]);
    journal->map.playerMap[journal->map.campY][journal->map.campX] = 'C';
    //printf("\nplayer x : %d,y: %d -> %c\n\n",journal->map.campX, journal->map.campY, journal->map.playerMap[journal->map.campY][journal->map.campX]);
}

// True if it appends an item, false if inventory is full
bool appendItem(const struct item item, struct playerStruct *player) {
    int index = 0;
    for(int i = 0; player->inventory[i].occupied; i++) {
        index++;
        if (i == MAX_INVENTORY - 1 && player->inventory[i].occupied) {
            printf("Inventory is full, cannot add new item.\n");
            return false;
        }
    }
    player->inventory[index] = item;
    return true;
}

// index, and player
bool deleteItem(const int index, struct playerStruct *player) {
    printf("Here is inventory: \n");
    for (int i = 0; i < MAX_INVENTORY; i++) {
        printf("Name: %s, occupied: %d\n", player->inventory[i].name, player->inventory[i].occupied);
    }
    if (!player->inventory[index].occupied) {
        printf("You cannot discard a non existent item.\n");
        return false;
    } else {
        for (int i = index; i + 1 < MAX_INVENTORY; i++) {
            printf("Moving index %d, item was %s", i, player->inventory[i].name);
            player->inventory[i] = player->inventory[i+1];
            printf(", now is %s.\n",player->inventory[i].name);
        }
        player->inventory[MAX_INVENTORY - 1] = emptyItem;
        printf("replacing with empty item called %s\n", player->inventory[MAX_INVENTORY - 1].name);
    }
}

// randomItem(luck, xp) Gives random item
struct item randomItem(const int luck, const int xp) {
    // Pick random item from a class
    int randIndex = rand();
    randIndex %= ITEM_CLASS_SIZE;

    // Pick class based on xp mostly, and up to an entire luck bonus
    int class = rand();
    class %= (luck * luckScale);
    class += xp;
    
    // Returns item
    if (class < stage1) {
        return noviceItems[randIndex];
    } else if (class < stage2) {
        return adeptItems[randIndex];
    } else {
        return expertItems[randIndex];
    }
}


/*
// Reveals surrounding area around camp
void mapReveal(struct journalStruct* journal) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        //printf("%c",journal->map.playerMap[0][y]);
        for (int x = 1; x < MAP_WIDTH; x++) {
            //printf(" %c",journal->map.playerMap[y][x]);
            if (y == journal->map.campY && x == journal->map.campX) {
                if (y+1 < MAP_HEIGHT) {
                    revealCamp(journal, x, y);
                }
            }
        }
    }
*/
/*
// Helper function to mapReveal, reveals around point (x,y)
void revealCamp(struct journalStruct* journal, int x, int y) {
    int dx[] = {-1, -1, -1,  0, 0, 0,  1, 1, 1};
    int dy[] = {-1,  0,  1, -1, 0, 1, -1, 0, 1};
    for (int i = 0; i < 9; i++) {
        int updateX = x + dx[i];
        int updateY = y + dy[i];

        // Check if out of bounds
        if (updateX >= 0 && updateX < MAP_WIDTH && updateY >= 0 && updateY < MAP_HEIGHT) {
            // Update cell
            journal->map.playerMap[updateY][updateX] = journal->map.fullMap[updateY][updateX];
        }
    }
} */
