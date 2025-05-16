#include "splashkit.h"
#include "khunglong.h"
dino_data new_dino()
{
    load_bitmap("dino","dino.png");
    dino_data ans;
    ans.dino_sprite= create_sprite(bitmap_named("dino"));
    sprite_set_position(ans.dino_sprite,{-344+20,-180+200});
    ans.score=0;
    return ans;
}
void draw_dino(dino_data &dino)
{
    draw_sprite(dino.dino_sprite);
}
void update_dino(dino_data &dino)
{
    update_sprite(dino.dino_sprite);
    point_2d sprite_center =center_point(dino.dino_sprite);
}