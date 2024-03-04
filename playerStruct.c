//playerStruct.h

// Libraries
#include <string.h>

// Headers
#include "playerStruct.h"

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
            "MMMrM_LLLLLL______CM",
            "DDM_r_L_LLL__MM___MM",
            "DDD__L____r_____MMMM",
            "DDVD___M__rr_M_MM__M",
            "DDDDD__MM__r__MM_JJM",
            "DcDDDD_____r_____JJM",
            "DDDDDD__rVrr_______M"
	    };
        for (int x = 0; x <= MAP_WIDTH; x++) {
            for (int y = 0; y <= MAP_HEIGHT; y++) {
                mapInit[y][x] = map[y][x];
            }
        }
	} else {
        // Player map
	    char map[MAP_HEIGHT][MAP_WIDTH] = {
           "???????????????????",
           "???????????????????",
           "???????????????????",
           "???????????????????",
           "???????????????????",
           "???????????????????",
           "???????????????????",
        };
        for (int x = 0; x <= 21; x++) {
            for (int y = 0; y <= 7; y++) {
                mapInit[y][x] = map[y][x];
            }
        }
    }
}

// Helper function to mapReveal, reveals around camp
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
}

// Reveals surrounding area around camp
void mapReveal(struct journalStruct* journal) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        //printf("%c",journal->map.playerMap[0][y]);
        for (int x = 1; x < MAP_WIDTH; x++) {
            //printf(" %c",journal->map.playerMap[y][x]);
            if (y == journal->map.campY && x == journal->map.campX) {
                if (y+1 < MAP_HEIGHT) {
                    revealCamp(journal, x, y);
                    journal->map.playerMap[y][x] = 'C';
                    journal->biome = biomeCtoI(journal->map.fullMap[y][x]);
                }
            }
        }
    }
}