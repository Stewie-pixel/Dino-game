#include "splashkit.h"

int main()
{
    open_window("dino",800,300);
    load_bitmap("dino","dino.png");
    while(!quit_requested())
    {
        process_events();
        clear_screen(COLOR_WHITE);
        draw_bitmap("dino",-344+20,-180+200,option_scale_bmp(0.2,0.2));
        refresh_screen(60);
    }
}