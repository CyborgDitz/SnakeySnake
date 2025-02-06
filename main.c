#include <stdio.h>
#include "draw.h"
#include "raylib.h"
#include "game.h"

//todo add food to pickup

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game");
    Snake snake = InitSnake();
    Food food = InitRandomFood();

    float moveTimer = 0.0f;
    const float moveDelay = 0.5f;

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        moveTimer += deltaTime;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawBoard();
        SnakeEatsFood(&snake, &food);
        DrawSnake(&snake);
        DrawFood(&food);
        EndDrawing();

        if (moveTimer >= moveDelay) {
            MoveSnake(&snake);
            moveTimer = 0.0f;
        }
    }
    return 0;
}
