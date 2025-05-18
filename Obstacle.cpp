#include "Obstacle.h"
#include "splashkit.h"

using namespace std;

void create_Obstacle(Obstacle_Data &obstacle)
{
    // Load bitmaps if not already loaded
    load_bitmap("cactus", "cactus1.png");

    // Create cactus sprite
    obstacle.cactus = create_sprite(bitmap_named("cactus"));
    obstacle.x = 800; // start off-screen to the right
    obstacle.y = 320; // y-position on the ground
    sprite_set_x(obstacle.cactus, obstacle.x);
    sprite_set_y(obstacle.cactus, obstacle.y);

    // Set speed
    obstacle.speed = 5;
}

void draw_Obstacle(const Obstacle_Data &obstacle)
{
    draw_sprite(obstacle.cactus);

}

void update_Obstacle(Obstacle_Data &obstacle)
{
    // Move both obstacles left
    obstacle.x -= obstacle.speed;

    sprite_set_x(obstacle.cactus, obstacle.x);
}
