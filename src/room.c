#include "room.h"

struct room *room_new(int x, int y, int w, int h)
{
    if (w > ROOM_SIZE || h > ROOM_SIZE) {
        fprintf(stderr, "Room width=%d and height=%d but max dimension=%d\n", w, h, ROOM_SIZE);
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
                self->buf[i][j] = C_WALL;
            else
                self->buf[i][j] = C_FLOOR;
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

static int rand_choice(int min, int max)
{
    int choice = rand() % (max - min) + min;
    return choice;
}

void room_gen_door(struct room *self)
{
    // choose wall
    int wallx, wally, choice = rand_choice(0, 3);
    switch (choice) {
    case 0: wallx = 0;       wally = rand_choice(0, self->h); // left wall
    case 1: wallx = self->w; wally = rand_choice(0, self->h); // right wall
    case 2: wallx = rand_choice(0, self->w); wally = 0;       // top wall
    case 3: wallx = rand_choice(0, self->w); wally = self->h; // bottom wall
    default:
        fprintf(stderr, "Invalid random choice %d\n", choice);
        exit(-1);
    }
    
    

}
