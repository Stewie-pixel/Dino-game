#include "splashkit.h"
#include "khunglong.h"
#include "Obstacle.h"
#include "constants.h"
#include <cmath>

dino_data new_dino()
{
    load_bitmap("dino","dinoo.png");
    dino_data ans;
    ans.dino_sprite= create_sprite(bitmap_named("dino"));
    sprite_set_scale(ans.dino_sprite, 0.2);
    sprite_set_x(ans.dino_sprite, -290);
    sprite_set_y(ans.dino_sprite, 20);
    ans.score=0;
    ans.velocity_y = 0;
    ans.is_jumping = false;
    return ans;
}

void draw_dino(dino_data &dino)
{
    draw_sprite(dino.dino_sprite);
}

void update_dino(dino_data &dino)
{
    dino.velocity_y += GRAVITY;
    sprite_set_y(dino.dino_sprite, sprite_y(dino.dino_sprite) + dino.velocity_y);

    // Clamp to ground
    if (sprite_y(dino.dino_sprite) >= 20)
    {
        sprite_set_y(dino.dino_sprite, 20);
        dino.velocity_y = 0;
        dino.is_jumping = false;
    }

    update_sprite(dino.dino_sprite); // <-- necessary for animation!
}
double point_distance(point_2d a, point_2d b)
{
 return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

// Hàm kiểm tra va chạm giữa hai hình chữ nhật
bool check_rect_collision(double x1, double y1, double w1, double h1,
                         double x2, double y2, double w2, double h2) {
    return (x1 < x2 + w2 &&
            x1 + w1 > x2 &&
            y1 < y2 + h2 &&
            y1 + h1 > y2);
}

bool check_collision(dino_data &dino, Obstacle_Data &obstacle)
{
    double dino_x = sprite_x(dino.dino_sprite);
    double dino_y = sprite_y(dino.dino_sprite);
    double dino_w = sprite_width(dino.dino_sprite);
    double dino_h = sprite_height(dino.dino_sprite);
    

    dino_x += 340;
    dino_w -= 35;
    dino_y += 180;
    dino_h -= 35;
    //write_line(dino_x);
    //write_line(dino_y);
    //write_line(dino_w);
    //write_line(dino_h);
    //write_line();

    double cactus_x = sprite_x(obstacle.cactus);
    double cactus_y = sprite_y(obstacle.cactus);
    double cactus_w = sprite_width(obstacle.cactus);
    double cactus_h = sprite_height(obstacle.cactus);
    

    cactus_x += 190;
    cactus_w -= 545;
    cactus_y += 112;
    cactus_h -= 260;
    //write_line(cactus_x);
    //write_line(cactus_y);
    //write_line(cactus_w);
    //write_line(cactus_h);
    //write_line("ditme");
    // Kiểm tra va chạm
    return check_rect_collision(dino_x, dino_y, dino_w, dino_h,
                               cactus_x, cactus_y, cactus_w, cactus_h);
}

void game_logic(dino_data &dino, Obstacle_Data &obstacle)
{
    update_dino(dino);
    handle_input(dino);
    check_collision(dino, obstacle);

    if (!obstacle.scored &&
        sprite_x(obstacle.cactus) + sprite_width(obstacle.cactus) < sprite_x(dino.dino_sprite) &&
        dino.is_jumping)
    {
        dino.score += 10;
        obstacle.scored = true;
    }
}

void handle_input(dino_data &dino)
{
    if ((key_typed(SPACE_KEY) || key_typed(UP_KEY)) && !dino.is_jumping)
    {
        dino.velocity_y = JUMP_VELOCITY; // giá trị âm để nhảy lên
        dino.is_jumping = true;
    }
}
