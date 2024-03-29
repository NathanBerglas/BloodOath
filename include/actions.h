//actions.h

// Headers
#include "playerStruct.h"
#include <stdbool.h>

// Functions
bool train(struct playerStruct*);
bool scavenge(struct playerStruct*, struct journalStruct*);
bool explore(struct journalStruct*);
bool move(struct journalStruct*);
bool recover(struct playerStruct*);