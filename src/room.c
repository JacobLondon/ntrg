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
    if (self->door_count > DIRECTION_COUNT) {
        fprintf(stderr, "Too many doors: %d", self->door_count);
        exit(-1);
    }
    // choose wall, 4
    int wallx, wally, choice = rand_choice(0, DIRECTION_COUNT - 1);
    switch (choice) {
    case NORTH: wallx = rand_choice(0, self->w); wally = 0;       // top wall
    case EAST: wallx = self->w; wally = rand_choice(0, self->h); // right wall
    case SOUTH: wallx = rand_choice(0, self->w); wally = self->h; // bottom wall
    case WEST: wallx = 0;       wally = rand_choice(0, self->h); // left wall
    default:
        fprintf(stderr, "Invalid random choice %d\n", choice);
        exit(-1);
    }

}
