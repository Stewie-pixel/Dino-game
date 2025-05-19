#ifndef khunglong
#define khunglong
#include "splashkit.h"
#include "Obstacle.h"

using namespace std;

struct dino_data
{
    sprite dino_sprite;
    int score;
    float velocity_y;  
    bool is_jumping;  
};

dino_data new_dino();
void draw_dino(dino_data &dino);
void update_dino(dino_data &dino);
void handle_input(dino_data &dino);
void game_logic(dino_data &dino, Obstacle_Data &obstacle);
bool check_collision(dino_data &dino, Obstacle_Data &obstacle);

#endif
