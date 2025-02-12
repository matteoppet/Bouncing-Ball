#ifndef OBJECTS_H
#define OBJECTS_H

#include "raylib.h"
#include <iostream>
#include <string>

class Ball;

class Object {
    public:
        Vector2 size = {100,50};
        Vector2 position;
        Rectangle rect_object;

        Object(float &center_position_x, float &center_position_y) {
            position = {center_position_x, center_position_y};
            rect_object = {position.x-(size.x/2), position.y-(size.y/2), size.x, size.y};
        }   

        void draw();
        std::pair<bool, std::string> collisions(Ball& ball);
};

#endif