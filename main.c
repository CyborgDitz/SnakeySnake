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
        DrawBoard();
        SnakeEatsFood(&snake, &food);
        DrawSnake(&snake);
        DrawFood(&food);
    EndDrawing();

    MoveSnake(&snake);
}

CloseWindow();

return 0;
}