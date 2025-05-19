#include "splashkit.h"
#include "khunglong.h"
#include "Obstacle.h"
#include "constants.h"
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    open_window("Dino Dash DX", SCREEN_WIDTH, SCREEN_HEIGHT);
    bitmap dino_bmp = load_bitmap("dino", "dinoo.png");
    bitmap_set_cell_details(dino_bmp, 64, 64, 2, 1, 2);
    load_bitmap("cactus", "cactus3.png");
    dino_data dino = new_dino();
    vector<Obstacle_Data> obstacles;

    float spawn_timer = 100;
    float speed = 5;
    float speed_timer = 0;
    float game_time = 0;
    bool game_over = false;
    bool game_started = false;
    while (!window_close_requested("Dino Dash DX"))
    {
        process_events();
        if(!game_started){
            clear_screen(COLOR_WHITE);
            draw_text("Press SPACE to restart", COLOR_BLACK, SCREEN_WIDTH/2 - 120, SCREEN_HEIGHT/2);
            if(key_typed(SPACE_KEY)){
                game_started = true;
            }
            draw_line(COLOR_BLACK, 0, GROUND_Y, SCREEN_WIDTH, GROUND_Y);
            draw_dino(dino);
            refresh_screen(60);
            continue;
        }
        if (!game_over) {
            game_time += 1.0/60.0;
            dino.score += 1 + (int)(game_time / 10);
            spawn_timer += 1;
            speed_timer += 1;

            if (spawn_timer > 100)
            {
                obstacles.push_back(create_Obstacle());
                spawn_timer = 0;
            }

            if (speed_timer > 300)
            {
                speed += 0.5;
                speed_timer = 0;
            }

            for (auto &obs : obstacles)
            {
                update_Obstacle(obs);
                game_logic(dino, obs);
                if (check_collision(dino, obs)) {
                    game_over = true;
                }
            }

            // Clean up off-screen obstacles
            obstacles.erase(remove_if(obstacles.begin(), obstacles.end(),
                                    [](const Obstacle_Data &obs)
                                    {
                                        return sprite_x(obs.cactus) + sprite_width(obs.cactus) < 0;
                                    }),
                            obstacles.end());
        }

        clear_screen(COLOR_WHITE);
        draw_text("Score: " + to_string(dino.score), COLOR_BLACK, 10, 10);
        draw_line(COLOR_BLACK, 0, GROUND_Y, SCREEN_WIDTH, GROUND_Y);
        draw_dino(dino);
        for (auto &obs : obstacles)
        {
            draw_Obstacle(obs);
        }

        if (game_over) {
            draw_text("GAME OVER", COLOR_RED, SCREEN_WIDTH/2 - 100, SCREEN_HEIGHT/2 - 50);
            draw_text("Press SPACE to restart", COLOR_BLACK, SCREEN_WIDTH/2 - 120, SCREEN_HEIGHT/2);
            
            if (key_typed(SPACE_KEY)) {
                dino = new_dino();
                obstacles.clear();
                game_time = 0;
                speed = 5;
                spawn_timer = 0;
                speed_timer = 0;
                game_over = false;
            }
        }

        refresh_screen(60);
    }

    return 0;
}

