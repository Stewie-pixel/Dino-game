#include "splashkit.h"
#include <Dinosaur.h>
#include <Obstacle.h>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 300;
const int GROUND_Y = 250;

load_bitmap("A", "Dinoo.png");

int main() {

    Dinosaur dino;
    vector <Obstacles> obstacle;

    while(!window_close_requested("Dino Dash DX")) {
        open_window("Dino Dash DX", SCREEN_WIDTH, SCREEN_HEIGHT);
        load_font("arial", "arial.ttf");

        while (!window_close_requested("Dino Dash DX")) {
            process_events();
            clear_screen(COLOR_WHITE);

            dino.update();

            draw_line(COLOR_DARK_GREEN, 0, GROUND_Y, SCREEN_WIDTH, GROUND_Y);
            dino.draw();
        }
    }


}
