#include <stdio.h>

#include "draw.h"
#include "raylib.h"
#include "game.h"

//todo add food to pickup

int main(void) {
InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game");
    Snake snake = InitSnake();

while (!WindowShouldClose()) {
    BeginDrawing();
    drawBoard();
    drawSnake(&snake);
    EndDrawing();

    movePlayer(&snake);
}

CloseWindow();

return 0;
}