#include <nce.h>
#include <jlib.h>

/**
 * Game requirements
 */

enum Constants {
    NumRooms = 16,
    RoomSize = 16,
    CharWall = '#',
    CharFloor = '.',
};

struct room {
    int x, y, w, h;
    char buf[RoomSize][RoomSize];
};

// Globals
int px = 0, py = 0;
bool redraw = true;
struct room *Rooms[NumRooms] = {0};

struct room *room_new(int x, int y, int w, int h);
void room_draw(struct room *self);

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

/**
 * NCE Required functions
 */

void nce_resize(int sig)
{

}

void nce_startup()
{
    px = 7;
    py = 7;
    Rooms[0] = room_new(5, 5, 10, 10);
}

void player_move(int xnew, int ynew);
void player_move(int xnew, int ynew)
{
    // clear old pos, get new, draw new pos
    switch (mvinch(xnew, ynew)) {
    case CharWall:
        break;
    case CharFloor:
        px = xnew;
        py = ynew;
        break;
    default:
        break;
    }
}

void nce_update()
{
    // draw rooms
    for (int i = 0; i < NumRooms; i++) {
        if (Rooms[i]) room_draw(Rooms[i]);
    }

    // move with bounds check
    nce_write(" ", px, py);
    if      (nce_keypressed(Keys, 'w')) player_move(px, py - 1);
    else if (nce_keypressed(Keys, 'a')) player_move(px - 1, py);
    else if (nce_keypressed(Keys, 's')) player_move(px, py + 1);
    else if (nce_keypressed(Keys, 'd')) player_move(px + 1, py);
    nce_write("@", px, py);
}

int main()
{
    nce_init();

    return 0;
}
