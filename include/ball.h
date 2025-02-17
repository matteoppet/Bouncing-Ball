#ifndef BALL_H
#define BALL_H

#include "raylib.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "objects.h"

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
        float coeff_restitution = 0.8;
        float impact_time = 0.016;

        float acting_force = 0;
        bool collision = false;
        double delta_time = 0.016;
        std::string normal_direction;

        void draw();
        void update(const int &window_size_x, const int &window_size_y, std::vector<Object>& objects);
        bool detect_collisions(const int &window_size_x, const int &window_size_y, std::vector<Object>& objects);
        void reset();
        Vector2 calculate_normal();
};

#endif