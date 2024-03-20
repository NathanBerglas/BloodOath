//charecterCreation.h

// Headers
#include "playerStruct.h"

// Functions
struct playerStruct *createCharecter(void);
void destroyCharecter(struct playerStruct*);
struct journalStruct *createJournal(int, int, int);
void destroyJournal(struct journalStruct*);
