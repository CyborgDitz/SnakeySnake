#include "draw.h"

#include <stdio.h>

#include "raylib.h"


void drawBoard(void) {
    ClearBackground(RAYWHITE);
    for (int x = 0; x < SCREEN_WIDTH; x += CELL_SIZE) {
        for (int y = 0; y < SCREEN_HEIGHT; y += CELL_SIZE) {
            DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, LIGHTGRAY);
            DrawRectangle(x + 2, y + 2, GRID_CELLS, GRID_CELLS, BLACK);

            char positionText[8];
            snprintf(positionText, sizeof(positionText), "%d.%d", x / CELL_SIZE, y / CELL_SIZE );
            DrawText(positionText, x, y + 30 , 8, RAYWHITE);
        }
    }
}

void drawSnake(Snake *snake) {
    DrawRectangle(snake->position.x, snake->position.y, CELL_SIZE, CELL_SIZE, PINK);
}