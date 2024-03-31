//charecterCreation.h
#pragma once
#ifndef CHARECTERCREATIONS_H
#define CHARECTERCREATIONS_H

// Headers
#include "playerStruct.h"

// Functions
struct playerStruct *createCharecter(void);
void destroyCharecter(struct playerStruct*);
struct journalStruct *createJournal(int, int, int);
void destroyJournal(struct journalStruct*);
#endif
