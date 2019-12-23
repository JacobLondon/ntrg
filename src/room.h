#ifndef NTRG_ROOM_H
#define NTRG_ROOM_H

#include "globals.h"

struct room {
    int x, y, w, h;
    char buf[ROOM_SIZE][ROOM_SIZE];
    unsigned doors[4], door_dir[4], door_count;
};

enum direction {
    NORTH,
    EAST,
    SOUTH,
    WEST,
    DIRECTION_COUNT,
};

struct room *room_new(int x, int y, int w, int h);
void room_draw(struct room *self);

void room_gen_door(struct room *self);

#endif // NTRG_ROOM_H
