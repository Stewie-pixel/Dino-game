#pragma once
#ifndef OBSTACLE_H
#include "splashkit.h"

using namespace std;

struct Obstacle_Data {
    sprite cactus;
    float speed;
    float x, y;
};

void create_Obstacle(const Obstacle_Data &obstacle);
void draw_Obstacle(const Obstacle_Data &obstacle);
void update_Obstacle(Obstacle_Data &obstacle);
#endif
