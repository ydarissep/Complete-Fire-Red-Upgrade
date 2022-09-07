#pragma once

#include "../global.h"
#include "../pokemon.h"

/**
 * \file exp.h
 * \brief Contains functions relating to Pokemon gaining experience in battle.
 *		  Also contains the function repsonsible for assigning Pokemon Effort
 *		  Values after battle.
 */

extern const u16 LevelCap[];

//Exported Functions
bool8 AddEVs(struct Pokemon* mon, u8 statId, u16 numToAdd);
u32 GetSpeciesExpToLevel(u16 species, u8 toLevel);

//Functions Hooked In
u8 GetCurrentLevelCap(void);
void atk23_getexp(void);
void PlayerHandleExpBarUpdate(void);
u8 GetBadgeCount();
