#include "include/objects.h"
#include "include/ball.h"

void Object::draw() {
    DrawRectangle(position.x-(size.x/2), position.y-(size.y/2), size.x, size.y, RED);
}   


std::pair<bool, std::string> Object::collisions(Ball& ball) {
    bool collision = CheckCollisionCircleRec(ball.position, ball.radius, this->rect_object);

    if (collision) {
        if (ball.position.y < this->position.y &&
            ball.position.x >= this->position.x-(this->size.x/2) &&
            ball.position.x <= this->position.x+(this->size.x/2) ) {
            ball.position.y = (this->position.y-(this->size.y/2))-ball.radius;
            return {true, "wall down"};
        } 
        else if (ball.position.y > this->position.y &&
            ball.position.x >= this->position.x-(this->size.x/2) &&
            ball.position.x <= this->position.x+(this->size.x/2)) {
            ball.position.y = (this->position.y+(this->size.y/2))+ball.radius;
            return {true, "wall up"};
        } 
        else if (ball.position.x < this->position.x) {
            ball.position.x = (this->position.x-(this->size.x/2))-ball.radius;
            return {true, "wall right"};
        } 
        else if (ball.position.x > this->position.x) {
            ball.position.x = (this->position.x+(this->size.x/2))+ball.radius;
            return {true, "wall left"};
        }
    }

    return {false, "default"};
}