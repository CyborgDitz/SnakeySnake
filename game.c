#include "game.h"
#include "raylib.h"

void gridBoundary(Snake *snake) {
    if (snake->position.x < 0) snake->position.x = 0;
    if (snake->position.x >= SCREEN_WIDTH) snake->position.x = SCREEN_WIDTH - CELL_SIZE;
    if (snake->position.y < 0) snake->position.y = 0;
    if (snake->position.y >= SCREEN_HEIGHT) snake->position.y = SCREEN_HEIGHT - CELL_SIZE;
}

void movePlayer(Snake *snake)
{
    if (IsKeyPressed(KEY_A)) snake->position.x -= CELL_SIZE;
    if (IsKeyPressed(KEY_D)) snake->position.x += CELL_SIZE;
    if (IsKeyPressed(KEY_W)) snake->position.y -= CELL_SIZE;
    if (IsKeyPressed(KEY_S)) snake->position.y += CELL_SIZE;
    gridBoundary(snake);
}

//todo improve move boundary later
Snake InitSnake() {
    Snake snake;
    snake.position.x = SCREEN_WIDTH / 2;
    snake.position.y = SCREEN_HEIGHT / 2;
    return snake;
}
Food InitRandomFood() {
    Food food;
    food.position.x = GetRandomValue(0, GRID_WIDTH - 1) * CELL_SIZE;
    food.position.y = GetRandomValue(0, GRID_HEIGHT - 1) * CELL_SIZE;

    return food;
}