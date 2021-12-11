
#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    void SetTargetFPS(int fps);
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        int MouseX = GetMouseX();
        int MouseY = GetMouseY();
        ClearBackground(WHITE);
        DrawText("CUM", 190, 200, 20, BLACK);
        EndDrawing(); 
    }

    CloseWindow();

    return 0;
}