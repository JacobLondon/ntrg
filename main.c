#include <nce.h>
#include <jlib.h>

/**
 * Game requirements
 */

enum Constants {
    NumRooms = 16,
    RoomSize = 16,
};

struct room {
    int x, y, w, h;
    char buf[RoomSize + 1][RoomSize + 1];
};

// Globals
int px = 0, py = 0;
bool redraw = true;
char CharWall = '#';
char CharFloor = '.';
struct room *Rooms[NumRooms] = {0};

struct room *room_new(int x, int y, int w, int h);
void room_draw(struct room *self);

struct room *room_new(int x, int y, int w, int h)
{
    struct room *self;
    try_malloc(self, sizeof(struct room), "Could not allocate 'struct room'");
    self->x = x;
    self->y = y;
    self->w = w;
    self->h = h;

    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= h; j++) {
            self->buf[i][j] = 0;
            if (i == w)
                continue;
            if (i == 0 || j == 0 || i == w - 1 || j == h)
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

/**
 * NCE Required functions
 */

void nce_resize(int sig)
{

}

void nce_startup()
{
    Rooms[0] = room_new(5, 5, 10, 10);

}

void nce_update()
{
    // draw rooms
    for (int i = 0; i < NumRooms; i++) {
        if (Rooms[i]) room_draw(Rooms[i]);
    }

    // move with bounds check
    if      (nce_keypressed(Keys, 'w')) nce_write(" ", px,   py - 1 >= 0 ? py-- : py);
    else if (nce_keypressed(Keys, 'a')) nce_write(" ", px - 1 >= 0 ? px-- : px,   py);
    else if (nce_keypressed(Keys, 's')) nce_write(" ", px,   py + 1 < SHeight ? py++ : py);
    else if (nce_keypressed(Keys, 'd')) nce_write(" ", px + 1 < SWidth ? px++ : px, py);
    nce_write("@", px, py);
}

int main()
{
    nce_init();

    return 0;
}
