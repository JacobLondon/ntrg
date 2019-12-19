#ifndef NTRG_TYPES_H
#define NTRG_TYPES_H

struct position {
    int x, y;
};

#define POSITION_NEW(X, Y) (struct position) { X, Y }

struct player;
struct room;

#endif // NTRG_TYPES_H