#include <stdio.h>
#include "draw.h"
#include "raylib.h"
#include "game.h"

//todo add food to pickup

int main(void) {
InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game");
    Snake snake = InitSnake();
    Food food = InitRandomFood();

while (!WindowShouldClose()) {
    BeginDrawing();
        drawBoard();
        SnakeEatsFood(&snake, &food);
        drawSnake(&snake);
        drawFood(&food);
    EndDrawing();

    MoveSnake(&snake);
}

CloseWindow();

return 0;
}