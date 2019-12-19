#include "globals.h"

#include "player.h"
#include "room.h"

struct player Player = PLAYER_NEW(0, 0);
struct room *Rooms[NUM_ROOMS] = {0};
