#include "include/ball.h"

void Ball::draw() {
    DrawCircle(position.x, position.y, radius, WHITE);
}

void Ball::update() {
    if (collision) {
        float impact_force = (mass * -vel_v) / 2*impact_time;

        acting_force = impact_force - (gravity*mass);
        acc_v = acting_force / mass;
        vel_v -= acc_v;

    } else {
        acting_force = gravity * mass;
        acc_v = acting_force / mass;
        vel_v += acc_v;
    }

    position.y += vel_v * delta_time;
}

bool Ball::detect_collisions(const int &window_size_x, const int &window_size_y) {
    // horizontal
    if (position.x+radius >= window_size_x) {
        return true;
    } else if (position.x + radius <= 0) {
        return true;
    }

    if (position.y+radius >= window_size_y) {
        position.y = window_size_y-radius;
        vel_v = -vel_v * coeff_restitution;
        return true;
    } else if (position.y+radius <= 0) {
        return true;
    }
    return false;
}