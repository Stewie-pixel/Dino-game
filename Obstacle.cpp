#include "Obstacle.h"
#include "splashkit.h"

using namespace std;

void create_Obstacle(Obstacle_Data &obstacle)
{
    // Load bitmaps if not already loaded
    load_bitmap("cactus", "cactus1.png");
    load_bitmap("bird", "bird.png");

    // Create cactus sprite
    obstacle.cactus = create_sprite(bitmap_named("cactus"));
    obstacle.x = 800; // start off-screen to the right
    obstacle.y = 320; // y-position on the ground
    sprite_set_x(obstacle.cactus, obstacle.x);
    sprite_set_y(obstacle.cactus, obstacle.y);

    // Create bird sprite
    obstacle.bird = create_sprite(bitmap_named("bird"));
    sprite_set_x(obstacle.bird, obstacle.x + 300); // bird starts further right
    sprite_set_y(obstacle.bird, 250);              // flying height

    // Set speed
    obstacle.speed = 5;
}

void draw_Obstacle(const Obstacle_Data &obstacle)
{
    draw_sprite(obstacle.cactus);
    draw_sprite(obstacle.bird);
}

void update_Obstacle(Obstacle_Data &obstacle)
{
    // Move both obstacles left
    obstacle.x -= obstacle.speed;

    sprite_set_x(obstacle.cactus, obstacle.x);
    sprite_set_x(obstacle.bird, obstacle.x + 300); // bird always ahead of cactus
}