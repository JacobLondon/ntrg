#include "room.h"

struct room *room_new(int x, int y, int w, int h)
{
    if (w > RoomSize || h > RoomSize) {
        fprintf(stderr, "Room width=%d and height=%d but max dimension=%d\n", w, h, RoomSize);
        exit(-1);
    }

    struct room *self;
    try_malloc(self, sizeof(struct room), "Could not allocate 'struct room'");
    self->x = x;
    self->y = y;
    self->w = w;
    self->h = h;

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            self->buf[i][j] = 0;
            if (i == 0 || j == 0 || i == w - 1 || j == h - 1)
                self->buf[i][j] = CharWall;
            else
                self->buf[i][j] = CharFloor;
        }
    }

    return self;
}

void room_draw(struct room *self)
{
    for (int i = 0; i < self->w; i++) {
        nce_write(self->buf[i], self->x, self->y + i);
    }
}