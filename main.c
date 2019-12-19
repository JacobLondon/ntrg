#include <nce.h>

int px = 0, py = 0;

void nce_resize(int sig)
{

}

void nce_startup()
{

}

void nce_update()
{



    if      (Keys['w']) swrite(" ", px,   py - 1 >= 0 ? py-- : py);
    else if (Keys['a']) swrite(" ", px - 1 >= 0 ? px-- : px,   py);
    else if (Keys['s']) swrite(" ", px,   py + 1 < SHeight ? py++ : py);
    else if (Keys['d']) swrite(" ", px + 1 < SWidth ? px++ : px, py);
    swrite("@", px, py);

    for (int i = 0; i < 1e6; i++);
}

int main()
{
    nce_init();

    return 0;
}
