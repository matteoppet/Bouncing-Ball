#include "include/ball.h"

void Ball::draw() {
    DrawCircle(position.x, position.y, radius, WHITE);
}

void Ball::update(const int &WINDOW_SIZE_X, const int &WINDOW_SIZE_Y, std::vector<Object>& objects) {
    collision = this->detect_collisions(WINDOW_SIZE_X, WINDOW_SIZE_Y, objects);

    if (collision) {
        Vector2 normal = calculate_normal(); 
        acc_h = 0;
        
        float perpendicular_velocity = (vel_h * normal.x) + (vel_v * normal.y);
        Vector2 perpendicular_velocity_vector = {perpendicular_velocity * normal.x, perpendicular_velocity * normal.y};
        Vector2 parallel_velocity_vector = {vel_h - perpendicular_velocity_vector.x, vel_v - perpendicular_velocity_vector.y};
        perpendicular_velocity_vector = {-coeff_restitution * perpendicular_velocity_vector.x, -coeff_restitution * perpendicular_velocity_vector.y};
        
        vel_h = parallel_velocity_vector.x + perpendicular_velocity_vector.x;
        vel_v = parallel_velocity_vector.y + perpendicular_velocity_vector.y;

    } else {
        acting_force = gravity * mass;
        acc_v = acting_force / mass;
        vel_v += acc_v;
        vel_h += acc_h;
    }

    position.x += vel_h * delta_time;
    position.y += vel_v * delta_time;
}

bool Ball::detect_collisions(const int &window_size_x, const int &window_size_y, std::vector<Object>& objects) {
    // horizontal
    if (position.x+radius >= window_size_x) {
        position.x = window_size_x-radius;
        normal_direction = "wall right";
        return true;
    } else if (position.x-radius <= 0) {
        position.x = 0+radius;
        normal_direction = "wall left";
        return true;
    }
    
    // vertical
    if (position.y+radius >= window_size_y) {
        position.y = window_size_y-radius;
        normal_direction = "wall down";
        return true;
    } else if (position.y-radius <= 0) {
        position.y = 0+radius;
        normal_direction = "wall up";
        return true;
    }

    for (Object& object: objects) {
        auto result = object.collisions(*this);
        if (result.first == 1) {
            normal_direction = result.second;
            return true;
        }
    }

    return false;
}


Vector2 Ball::calculate_normal() {
    Vector2 normal;
    if (normal_direction == "wall right") {
        normal = {-1, 0};
    } else if (normal_direction == "wall left") {
        normal = {1, 0};
    } else if (normal_direction == "wall down") {
        normal = {0, 1};
    } else if (normal_direction == "wall up") {
        normal = {0, -1};
    }

    return normal;
}


void Ball::reset() {
    vel_v = 0;
    vel_h = 0;
    acc_v = 0;
    acc_h = 4;
    acting_force = 0;
    collision = false;
}