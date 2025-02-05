
#ifndef GAME_H
#define GAME_H


#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 720
#define CELL_SIZE 40
#define GRID_CELLS CELL_SIZE - 4

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
Snake InitSnake();
#endif //GAME_H
