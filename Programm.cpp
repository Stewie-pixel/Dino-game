#include "splashkit.h"
#include "khunglong.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 300;
const int GROUND_Y = 250;

int main() {
    open_window("Dino Dash DX", SCREEN_WIDTH, SCREEN_HEIGHT);
    dino_data player=new_dino();
    while(!window_close_requested("Dino Dash DX")) {
        load_font("arial", "arial.ttf");

        while (!window_close_requested("Dino Dash DX")) {
            process_events();
            handle_input(player);
            update_dino(player);
            clear_screen(COLOR_WHITE);
            draw_dino(player);
            draw_line(COLOR_DARK_GREEN, 0, GROUND_Y, SCREEN_WIDTH, GROUND_Y);
            refresh_screen(60);
        }
    }


}

