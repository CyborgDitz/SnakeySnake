#include "raylib.h"
#ifndef GAME_H
#define GAME_H


#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 720
#define CELL_SIZE 40
#define GRID_WIDTH  SCREEN_WIDTH / CELL_SIZE
#define GRID_HEIGHT  SCREEN_HEIGHT / CELL_SIZE
#define GRID_CELLS_SIZE  (CELL_SIZE - 4)

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;

} Snake;
typedef struct {
    Position position;
} Food;

void movePlayer(Snake *snake);
Snake InitSnake(void);
Food InitRandomFood(void);


#endif //GAME_H
