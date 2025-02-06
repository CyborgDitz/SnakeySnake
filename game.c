#include "game.h"
#include "raylib.h"
#include "raymath.h"
void gridBoundary(Snake *snake) {
    if (snake->position[0].x < 0) snake->position[0].x = 0;
    if (snake->position[0].x >= SCREEN_WIDTH) snake->position[0].x = SCREEN_WIDTH - CELL_SIZE;
    if (snake->position[0].y < 0) snake->position[0].y = 0;
    if (snake->position[0].y >= SCREEN_HEIGHT) snake->position[0].y = SCREEN_HEIGHT - CELL_SIZE;
}
void MoveSnake(Snake *snake) {
    if (IsKeyPressed(KEY_A)) snake->position[0].x -= CELL_SIZE;
    if (IsKeyPressed(KEY_D)) snake->position[0].x += CELL_SIZE;
    if (IsKeyPressed(KEY_W)) snake->position[0].y -= CELL_SIZE;
    if (IsKeyPressed(KEY_S)) snake->position[0].y += CELL_SIZE;
    gridBoundary(snake);
}

void SnakeEatsFood(Snake *snake, Food *food) {
    if (snake->position[0].x == food->position.x && snake->position[0].y == food->position.y) {
        *food = InitRandomFood();
    }
}
void GrowSnake(Snake *snake) {
    if (snake->length < MAX_SNAKE) {
        snake->position[snake->length] = snake->position[snake->length - 1];
        snake->length++;
    }
}
//todo improve move boundary later
Snake InitSnake() {
    Snake snake;
    snake.length = 1;
    snake.position[0].x = SCREEN_WIDTH / 2;
    snake.position[0].y = SCREEN_HEIGHT / 2;
    return snake;
}

Food InitRandomFood() {
    Food food;
    food.position.x = GetRandomValue(0, GRID_WIDTH - 1) * CELL_SIZE;
    food.position.y = GetRandomValue(0, GRID_HEIGHT - 1) * CELL_SIZE;

    return food;
}