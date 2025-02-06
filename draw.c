#include "draw.h"
#include <stdio.h>
#include "raylib.h"


void DrawBoard(void) {
    ClearBackground(RAYWHITE);
    for (int x = 0; x < SCREEN_WIDTH; x += CELL_SIZE) {
        for (int y = 0; y < SCREEN_HEIGHT; y += CELL_SIZE) {
            DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, LIGHTGRAY);
            DrawRectangle(x + 2, y + 2, GRID_CELLS_SIZE, GRID_CELLS_SIZE, BLACK);

            char positionText[8];
            snprintf(positionText, sizeof(positionText), "%d.%d", x / CELL_SIZE, y / CELL_SIZE );
            DrawText(positionText, x, y + 30 , 8, RAYWHITE);
        }
    }
}

void DrawSnake(Snake *snake) {
    DrawRectangle(snake->position[0].x, snake->position[0].y, CELL_SIZE, CELL_SIZE, PINK);
}
void DrawFood(Food *food) {
    DrawRectangle(food->position.x, food->position.y, CELL_SIZE, CELL_SIZE, RED);
}