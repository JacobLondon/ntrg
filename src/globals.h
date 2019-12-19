#ifndef NTRG_GLOBALS_H
#define NTRG_GLOBALS_H

#include <jlib.h>
#include <nce.h>

enum Constants {
    NUM_ROOMS = 16,
    ROOM_SIZE = 16,
    C_WALL = '#',
    C_FLOOR = '.',
};

extern struct player Player;
extern struct room *Rooms[NUM_ROOMS];

#endif // NTRG_GLOBALS_H