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

int px = 0, py = 0;
bool redraw = true;
struct room *Rooms[NumRooms] = {0};

#endif // NTRG_GLOBALS_H