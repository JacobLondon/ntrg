#include "player.h"
#include "globals.h"

void player_move(struct player *self, struct position new)
{
    // clear old pos, get new character the player is on top of, draw new pos
    switch (mvinch(new.x, new.y)) {
    case C_WALL:
        break;
    case C_FLOOR:
        self->pos.x = new.x;
        self->pos.y = new.y;
        break;
    default:
        break;
    }
}
