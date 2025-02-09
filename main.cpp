#include "include/raylib.h"
#include "include/ball.h"
#include <iostream>

const int WINDOW_SIZE_X = 800;
const int WINDOW_SIZE_Y = 800;

int main() {
    InitWindow(WINDOW_SIZE_X, WINDOW_SIZE_Y, "Bouncing ball");
    SetTargetFPS(60);

    Ball ball;

    while (!WindowShouldClose()) {
        ball.collision = ball.detect_collisions(WINDOW_SIZE_X, WINDOW_SIZE_Y);
        ball.update();

        std::cout << ball.acting_force << std::endl;

        BeginDrawing();
            ClearBackground(BLACK);

            // draw text
            DrawText(TextFormat("Gravity: %02.02f m/s", ball.gravity), 10, 10, 20, WHITE);
            DrawText(TextFormat("Mass: %02.02f grams", ball.mass), 10, 35, 20, WHITE);

            ball.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}