#include "game.h"
#include <stdio.h>
#include "raylib.h"
#include "raymath.h"

typedef enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

Direction currentDir = RIGHT;

void MoveSnake(Snake *snake) {

    if (IsKeyDown(KEY_A) && currentDir != RIGHT) {
        currentDir = LEFT;
    } else if (IsKeyDown(KEY_D) && currentDir != LEFT) {
        currentDir = RIGHT;
    } else if (IsKeyDown(KEY_W) && currentDir != DOWN) {
        currentDir = UP;
    } else if (IsKeyDown(KEY_S) && currentDir != UP) {
        currentDir = DOWN;
    }

    Vector2 nextHead = snake->position[0];
    switch (currentDir) {
        case LEFT:
            nextHead.x -= CELL_SIZE;
            break;
        case RIGHT:
            nextHead.x += CELL_SIZE;
            break;
        case UP:
            nextHead.y -= CELL_SIZE;
            break;
        case DOWN:
            nextHead.y += CELL_SIZE;
            break;
    }

    if (nextHead.x < 0 || nextHead.x >= SCREEN_WIDTH ||
        nextHead.y < 0 || nextHead.y >= SCREEN_HEIGHT) {

        return;
    }

    for (int i = snake->length - 1; i > 0; i--) {
        snake->position[i] = snake->position[i - 1];
    }

    snake->position[0] = nextHead;
}

void SnakeEatsFood(Snake *snake, Food *food) {
    if (snake->position[0].x == food->position.x &&
        snake->position[0].y == food->position.y) {

        *food = InitRandomFood();
        GrowSnake(snake);
    }
}

void GrowSnake(Snake *snake) {
    if (snake->length < MAX_SNAKE) {
        snake->position[snake->length] = snake->position[snake->length - 1];
        snake->length++;
        printf("Snake length increased to: %d\n", snake->length);
    }
}

Snake InitSnake(void) {
    Snake snake;
    snake.length = 1;
    snake.position[0].x = 8 * CELL_SIZE;
    snake.position[0].y = 8 * CELL_SIZE;
    return snake;
}

Food InitRandomFood() {
    Food food;
    food.position.x = GetRandomValue(0, GRID_WIDTH - 1) * CELL_SIZE;
    food.position.y = GetRandomValue(0, GRID_HEIGHT - 1) * CELL_SIZE;
    return food;
}
