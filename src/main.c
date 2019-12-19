#include "room.h"

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
