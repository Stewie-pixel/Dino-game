#ifndef khunglong
#define khunglong
#include "splashkit.h"

struct dino_data
{
    sprite  dino_sprite;
    int score;
};
dino_data new_dino();
void draw_dino(dino_data &dino);
void update_dino(dino_data &dino);
#endif
