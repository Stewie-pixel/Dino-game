#pragma once
#include "splashkit.h"

using namespace std;

struct Obstacle_Data {
    sprite cactus;
    bool scored;
    float speed;
};

Obstacle_Data create_Obstacle();
void draw_Obstacle(const Obstacle_Data &obstacle);
void update_Obstacle(Obstacle_Data &obstacle);
