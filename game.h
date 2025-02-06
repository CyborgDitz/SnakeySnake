#include "raylib.h"
#ifndef GAME_H
#define GAME_H


#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 720
#define CELL_SIZE 40
#define GRID_WIDTH SCREEN_WIDTH / CELL_SIZE
#define GRID_HEIGHT SCREEN_HEIGHT / CELL_SIZE
#define GRID_CELLS_SIZE CELL_SIZE - 4
#define MAX_SNAKE SCREEN_WIDTH / CELL_SIZE

typedef struct Snake {
    Vector2 position[MAX_SNAKE];
    int length;
} Snake;
typedef struct {
    Vector2 position;
} Food;

Snake InitSnake();
void MoveSnake(Snake *snake);
void GrowSnake(Snake *snake);
void SnakeDirection(Snake *snake);
void SnakeEatsFood(Snake *snake, Food *food);

Food InitRandomFood();


#endif //GAME_H
