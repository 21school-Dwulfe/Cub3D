#include "../render.h"

void    set_start_ammunition(t_data *d)
{
    // int i;

    // i = 0;
    d->act_weapon = &d->weapon[0];
    // while (i < WEAPON_COUNT)
    // {
    //     d->available_weapon[i] = 0;
    //     i++;
    // }
    d->available_weapon[0] = 1;
}
