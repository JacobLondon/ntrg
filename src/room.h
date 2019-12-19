#ifndef NTRG_ROOM_H
#define NTRG_ROOM_H

#include "globals.h"

struct room {
    int x, y, w, h;
    char buf[ROOM_SIZE][ROOM_SIZE];
};

struct room *room_new(int x, int y, int w, int h);
void room_draw(struct room *self);

#endif // NTRG_ROOM_H