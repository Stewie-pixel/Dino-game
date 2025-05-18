#include "splashkit.h"
#include "khunglong.h"
#include "Obstacle.h"

int main()
{
    open_window("Dino Game", 800, 450);
    load_resource_bundle("game_bundle", "game.txt");

    Player_Data player;
    Obstacle_Data obstacle;

    create_player(player);
    create_Obstacle(obstacle);

    while (!window_close_requested("Dino Game"))
    {
        process_events();

        clear_screen(COLOR_WHITE);

        update_player(player);
        update_Obstacle(obstacle);

        draw_player(player);
        draw_Obstacle(obstacle);

        refresh_screen(60);
    }

    return 0;
}


