//gameLoop.h
#pragma once
#ifndef GAMELOOP_H
#define GAMELOOP_H

// Libraries
#include <stdbool.h>

// Header
#include "playerStruct.h"

// Functions
bool gameLoop(struct playerStruct*, struct journalStruct*, int);
#endif