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
    for (int i = 0; i < snake->length; i++) {
        if (i == 0) {
            DrawRectangle(snake->position[i].x,
                          snake->position[i].y,
                          CELL_SIZE,
                          CELL_SIZE,
                          PINK);
            float eyeRadius = CELL_SIZE / 8.0f;
            float offsetX = CELL_SIZE / 4.0f;
            float offsetY = CELL_SIZE / 4.0f;
            DrawCircle(snake->position[i].x + offsetX,
                       snake->position[i].y + offsetY,
                       eyeRadius,
                       BLACK);

            DrawCircle(snake->position[i].x + CELL_SIZE - offsetX,
                       snake->position[i].y + offsetY,
                       eyeRadius,
                       BLACK);
        } else {
            DrawRectangle(snake->position[i].x,
                          snake->position[i].y,
                          CELL_SIZE,
                          CELL_SIZE,
                          PINK);
        }
        printf("Segment %d at (%d, %d)\n", i,
               (int)snake->position[i].x, (int)snake->position[i].y);
    }
}


void DrawFood(Food *food) {
    DrawRectangle(food->position.x, food->position.y, CELL_SIZE, CELL_SIZE, RED);
}