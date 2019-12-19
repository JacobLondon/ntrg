#include <nce.h>
#include <jlib.h>

int px = 0, py = 0;

struct room {
    int x, y, w, h;
};

struct room *room_new(int x, int y, int w, int h);
struct room *room_new(int x, int y, int w, int h)
{
    struct room *self;
    try_malloc(self, sizeof(struct room), "Could not allocate 'struct room'");
    self->x = x;
    self->y = y;
    self->w = w;
    self->h = h;
    return self;
}

void nce_resize(int sig)
{

}

void nce_startup()
{

}

void nce_update()
{
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
