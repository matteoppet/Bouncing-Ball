#include "include/raylib.h"
#include "include/ball.h"
#include "include/objects.h"
#include <iostream>
#include <vector>
#include <string>

const int WINDOW_SIZE_X = 800;
const int WINDOW_SIZE_Y = 800;

int main() {
    InitWindow(WINDOW_SIZE_X, WINDOW_SIZE_Y, "Bouncing ball");
    SetTargetFPS(60);

    Ball ball;
    std::vector<Object> objects;

    while (!WindowShouldClose()) {
        
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            ball.reset();
            ball.position = GetMousePosition();
        } else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            float mouse_position_x = GetMousePosition().x;
            float mouse_position_y = GetMousePosition().y;
            objects.emplace_back(Object(mouse_position_x, mouse_position_y));
        }

        ball.update(WINDOW_SIZE_X, WINDOW_SIZE_Y, objects);

        BeginDrawing();
            ClearBackground(BLACK);

            // draw text
            DrawText(TextFormat("Gravity: %02.02f m/s", ball.gravity), 10, 10, 20, WHITE);
            DrawText(TextFormat("Mass: %02.02f grams", ball.mass), 10, 35, 20, WHITE);

            ball.draw();

            // draw objects using pointers
            for (Object& object : objects) {
                object.draw();
            }

            DrawFPS(10, 65);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}