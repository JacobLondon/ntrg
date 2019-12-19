#include "types.h"
#include "globals.h"
#include "player.h"
#include "room.h"

void nce_resize(int sig)
{

}

void nce_startup()
{
    Player.pos.x = 7;
    Player.pos.y = 7;
    Rooms[0] = room_new(5, 5, 10, 10);
    Rooms[1] = room_new(30, 30, 10, 12);
}

void nce_update()
{
    // draw rooms
    for (int i = 0; i < NUM_ROOMS; i++) {
        if (Rooms[i]) room_draw(Rooms[i]);
    }

    // move with bounds check
    nce_write(" ", Player.pos.x, Player.pos.y);
    if      (nce_keypressed(Keys, 'w')) player_move(&Player, POSITION_NEW(Player.pos.x, Player.pos.y - 1));
    else if (nce_keypressed(Keys, 'a')) player_move(&Player, POSITION_NEW(Player.pos.x - 1, Player.pos.y));
    else if (nce_keypressed(Keys, 's')) player_move(&Player, POSITION_NEW(Player.pos.x, Player.pos.y + 1));
    else if (nce_keypressed(Keys, 'd')) player_move(&Player, POSITION_NEW(Player.pos.x + 1, Player.pos.y));
    nce_write("@", Player.pos.x, Player.pos.y);
}

int main()
{
    nce_init();

    return 0;
}
