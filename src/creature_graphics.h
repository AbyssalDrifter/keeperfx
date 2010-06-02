/******************************************************************************/
// Free implementation of Bullfrog's Dungeon Keeper strategy game.
/******************************************************************************/
/** @file creature_graphics.h
 *     Header file for creature_graphics.c.
 * @par Purpose:
 *     Creature graphics support functions.
 * @par Comment:
 *     Just a header file - #defines, typedefs, function prototypes etc.
 * @author   Tomasz Lis
 * @date     11 Mar 2010 - 23 May 2010
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#ifndef DK_CRTRGRAPHICS_H
#define DK_CRTRGRAPHICS_H

#include "globals.h"
#include "bflib_basics.h"

#ifdef __cplusplus
extern "C" {
#endif

// note - this is temporary value; not correct
#define CREATURE_FRAMELIST_LENGTH     982

enum CreatureGraphicsInstances {
    CGI_TopViewSymbol = 20,
};
/******************************************************************************/
#pragma pack(1)

struct CreaturePickedUpOffset // sizeof = 8
{
  short delta_x;
  short delta_y;
  short field_4;
  short field_6;
};

struct KeeperSprite { // sizeof = 16
  unsigned char field_0[9];
  unsigned char field_9;
  unsigned char field_A[4];
  unsigned char field_E[2];
};

#pragma pack()
/******************************************************************************/
//extern unsigned short creature_graphics[][22];
/******************************************************************************/
struct CreaturePickedUpOffset *get_creature_picked_up_offset(struct Thing *thing);

unsigned char keepersprite_frames(unsigned short n);
long get_lifespan_of_animation(long ani, long frameskip);
unsigned long get_creature_anim(struct Thing *thing, unsigned short frame);
unsigned long get_creature_breed_graphics(long breed, unsigned short frame);
void set_creature_breed_graphics(long breed, unsigned short frame, unsigned long val);
void set_creature_graphic(struct Thing *thing);

/******************************************************************************/
#ifdef __cplusplus
}
#endif
#endif
