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
    drawSnake(&snake);
    drawFood(&food);
    EndDrawing();

    movePlayer(&snake);
}

CloseWindow();

return 0;
}