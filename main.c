#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    
    float screenWidth = 960;
    float screenHeight = 540;

    InitWindow(screenWidth, screenHeight, "aa");

    SetTargetFPS(60);               

    SetWindowState(FLAG_WINDOW_RESIZABLE);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();

        Rectangle rec = { (screenWidth / 2.0f) - 50, (screenHeight / 9.818f), 100, 50};      // 430. width pixel 55.  heigth
        Rectangle rec2 = { (screenWidth / 2.0f) - 175, (screenHeight / 2.0f) + 90, 110, 50}; // 320. width pixel 360. heigth
        Rectangle rec3 = { (screenWidth / 2.0f) + 75, (screenHeight / 2.0f) + 90, 100 , 50}; // 555. width pixel 360. heigth

        BeginDrawing();

        ClearBackground(RAYWHITE);
        
        DrawRectangleLinesEx(rec, 5.0f, BLACK);
        DrawRectangleLinesEx(rec2, 5.0f, BLACK);
        DrawRectangleLinesEx(rec3, 5.0f, BLACK);

        DrawText("aa", (screenWidth / 2.0f) - 50, screenHeight / 2.5f, 100, BLACK);
        DrawText("MENU", (screenWidth / 2.0f) - 40, (screenHeight / 10.0f) + 10, 30, BLACK);
        DrawText("STATS", (screenWidth / 2.0f) - 165, (screenHeight / 2.0f) + 100, 25, BLACK);
        DrawText("PLAY", (screenWidth / 2.0f) + 85, (screenHeight / 2.0f) + 100, 30, BLACK);
        
        EndDrawing();
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int coordinatex = GetMouseX();
            int coordinatey = GetMouseY();
            if ((coordinatex < 300 && coordinatex>250) && (coordinatey < 180 && coordinatey>150)) {
                while (!IsKeyPressed(KEY_ESCAPE)) {
                    BeginDrawing();
                    ClearBackground(WHITE);

                    EndDrawing();
                }
                coordinatex = 0;
                coordinatey = 0;
                while (!((coordinatex < 300 && coordinatex>250) && (coordinatey < 180 && coordinatey>150))) {
                    BeginDrawing();
                    ClearBackground(WHITE);

                    EndDrawing();
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        coordinatex = GetMouseX();
                        coordinatey = GetMouseY();
                    }
                }

            }
        }

    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}