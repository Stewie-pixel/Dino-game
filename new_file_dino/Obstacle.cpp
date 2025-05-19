#include "Obstacle.h"
#include "constants.h"
#include "splashkit.h"

using namespace std;

Obstacle_Data create_Obstacle()
{
    // Load bitmaps if not already loaded
    load_bitmap("cactus", "cactus3.png");

    Obstacle_Data obstacle;
    // Create cactus sprite
    obstacle.cactus = create_sprite(bitmap_named("cactus"));
    sprite_set_scale(obstacle.cactus, 0.5);
    sprite_set_x(obstacle.cactus, 600);
    sprite_set_y(obstacle.cactus, GROUND_Y - sprite_height(obstacle.cactus) / 1.75); // start off-screen to the right

    // Set initial speed
    obstacle.speed = 5;  // Tốc độ ban đầu thấp hơn
    obstacle.scored = false;
    return obstacle;
}

void draw_Obstacle(const Obstacle_Data &obstacle)
{
    draw_sprite(obstacle.cactus);
}

void update_Obstacle(Obstacle_Data &obstacle)
{
    // Tăng tốc độ dần dần
    if(obstacle.speed < 20)
    obstacle.speed += 0.001;  // Tăng tốc độ mỗi frame
    sprite_set_x(obstacle.cactus, sprite_x(obstacle.cactus) - obstacle.speed);
}