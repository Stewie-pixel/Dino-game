#include "splashkit.h"
#include "khunglong.h"
dino_data new_dino()
{
    load_bitmap("dino","dino.png");
    dino_data ans;
    ans.dino_sprite= create_sprite(bitmap_named("dino"));
    sprite_set_scale(ans.dino_sprite, 0.2);
    sprite_set_position(ans.dino_sprite,{-344+50,-180+200});
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
    // Áp dụng trọng lực
    dino.velocity_y += 0.5; // tăng dần để tạo cảm giác rơi

    // Cập nhật vị trí theo vận tốc Y
    float new_y = sprite_y(dino.dino_sprite) + dino.velocity_y;
    sprite_set_y(dino.dino_sprite, new_y);

    // Kiểm tra nếu chạm đất
    if (new_y >= 20) // giả sử mặt đất tại y = 20
    {
        sprite_set_y(dino.dino_sprite, 20);
        dino.velocity_y = 0;
        dino.is_jumping = false;
    }

    update_sprite(dino.dino_sprite);
}
void handle_input(dino_data &dino)
{
    if ((key_typed(SPACE_KEY) || key_typed(UP_KEY)) && !dino.is_jumping)
    {
        dino.velocity_y = -10; // giá trị âm để nhảy lên
        dino.is_jumping = true;
    }
}