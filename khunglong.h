#ifndef khunglong
#define khunglong
#include "splashkit.h"

struct dino_data
{
    sprite dino_sprite;
    int score;
    float velocity_y;  // thêm vận tốc theo trục Y
    bool is_jumping;   // để tránh nhảy khi đang ở trên không
};
dino_data new_dino();
void draw_dino(dino_data &dino);
void update_dino(dino_data &dino);
void handle_input(dino_data &dino);
#endif
