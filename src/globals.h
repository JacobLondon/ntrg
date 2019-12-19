#ifndef NTRG_GLOBALS_H
#define NTRG_GLOBALS_H

#include <jlib.h>
#include <nce.h>

enum Constants {
    NumRooms = 16,
    RoomSize = 16,
    CharWall = '#',
    CharFloor = '.',
};

extern int px;
extern int py;
extern bool redraw;
extern struct room *Rooms[NumRooms];

#endif // NTRG_GLOBALS_H