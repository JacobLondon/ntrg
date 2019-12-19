#ifndef NTRG_PLAYER_H
#define NTRG_PLAYER_H

#include "types.h"

struct player {
    struct position pos;
};

#define PLAYER_NEW(X, Y) (struct player) { \
    POSITION_NEW(X, Y),                    \
}
void player_move(struct player *self, struct position new);

#endif // NTRG_PLAYER_H