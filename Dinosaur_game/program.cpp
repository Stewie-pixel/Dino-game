#include "splashkit.h"
#include <vector>
#include <string>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 300;
const int GROUND_Y = 250;

class Player {
private:
    rectangle bounds;
    float velocityY;
    bool is_jumping;

public:
    Player() {
        bounds = rectangle_from(50, GROUND_Y - 40, 30, 40);
        velocityY = 0;
        is_jumping = false;
    }

    void update() {
        if (key_typed(SPACE_KEY) && !is_jumping) {
            velocityY = -12;
            is_jumping = true;
        }

        velocityY += 0.6f;
        bounds.y += velocityY;

        if (bounds.y >= GROUND_Y - bounds.height) {
            bounds.y = GROUND_Y - bounds.height;
            velocityY = 0;
            is_jumping = false;
        }
    }

    void draw() const {
        fill_rectangle(COLOR_WHITE, bounds);
    }

    bool is_colliding(const rectangle &other) const {
        return rectangles_intersect(bounds, other);
    }
};

class Obstacle {
private:
    rectangle bounds;
    
public:
    Obstacle(float x) {
        bounds = rectangle_from(x, GROUND_Y - 30, 20, 30);
    }

    void update(float speed) {
        bounds.x -= speed;
    }

    void draw() const {
        fill_rectangle(COLOR_RED, bounds);
    }

    float x() const {
        return bounds.x;
    }

    rectangle get_bounds() const {
        return bounds;
    }
};

class Game {
private:
    Player player;
    vector<Obstacle> obstacles;
    int score;
    float speed;

    float calculate_speed(int score, float base_speed) {
        float speed_increase = (score / 100) * 0.5f;
        float max_speed = 12.0f;
        float new_speed = base_speed + speed_increase;
        return (new_speed > max_speed) ? max_speed : new_speed;
    }

    float calculate_obstacle_spacing(float speed) {
        float base_spacing = 200.0f;
        return base_spacing + (speed * 30.0f);  // Spacing increases with speed
    }

public:
    Game() {
        score = 0;
        speed = 5.0f;
    }

    void run() {
        open_window("Dino Dash DX", SCREEN_WIDTH, SCREEN_HEIGHT);
        load_font("arial", "arial.ttf");
        load_bitmap("A", "Dinoo.png");
        
        
        while (!window_close_requested("Dino Dash DX")) {
            restart();

            bool game_over = false;

            while (!game_over && !window_close_requested("Dino Dash DX")) {
                process_events();
                clear_screen(COLOR_WHITE);

                player.update();

                for (auto &obs : obstacles) obs.update(speed);
                if (!obstacles.empty() && obstacles.front().x() < -20)
                    obstacles.erase(obstacles.begin());

                // Use dynamic spacing instead of hardcoded 500
                if (obstacles.empty() || obstacles.back().x() < SCREEN_WIDTH - calculate_obstacle_spacing(speed)) {
                    if (rnd() < 0.02) obstacles.emplace_back(SCREEN_WIDTH);
                }

                for (auto &obs : obstacles) {
                    if (player.is_colliding(obs.get_bounds())) {
                        game_over = true;
                    }
                }

                score++;
                speed = calculate_speed(score, 5.0f);

                draw_line(COLOR_DARK_GREEN, 0, GROUND_Y, SCREEN_WIDTH, GROUND_Y);
                player.draw();
                
                for (auto &obs : obstacles) obs.draw();
                draw_text("Score: " + to_string(score), COLOR_BLACK, "arial", 20, 10, 10);

                refresh_screen(60);
            }

            draw_text("GAME OVER", COLOR_RED, "arial", 30, SCREEN_WIDTH / 2 - 80, SCREEN_HEIGHT / 2 - 20);
            draw_text("Press R to Restart or ESC to Quit", COLOR_BLACK, "arial", 20, SCREEN_WIDTH / 2 - 120, SCREEN_HEIGHT / 2 + 20);
            refresh_screen();

            while (true) {
                process_events();
                if (key_typed(R_KEY)) break;
                if (key_typed(ESCAPE_KEY) || window_close_requested("Dino Dash DX")) {
                    close_window("Dino Dash DX");
                    return;
                }
            }
        }
    }

    void restart() {
        score = 0;
        speed = 5.0f;
        player = Player();
        obstacles.clear();
    }
};

int main() {
    Game dino_game;
    dino_game.run();
    return 0;
} 
