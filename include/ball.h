#ifndef BALL_H
#define BALL_H

#include "raylib.h"
#include <iostream>

class Ball {
    public:
        float acc_h = 0;
        float acc_v = 0;
        float vel_h = 0;
        float vel_v = 0;
        Vector2 position = {400, 400};

        float radius = 15;
        float mass = 0.1; // kg
        float gravity = 9;
        float coeff_restitution = 0;
        float impact_time = 0.016;

        float acting_force = 0;
        bool collision = 0;
        double delta_time = 0.016;

        void draw();
        void update();
        bool detect_collisions(const int &window_size_x, const int &window_size_y);
};

#endif