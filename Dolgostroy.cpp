
#include "raylib.h"
#include <string>

int Points = 0;
int AmountOfProducersOne = 0;
int CostOfProducerOne = 30;

void ProducerOne() 
{
    Points + 1 * AmountOfProducersOne;
}

int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");
    
    int FrameCounterOneSecondPoints = 0;
    int FrameCounterOneSecondProducerOne = 0;
    std::string PointsText = "Points: ";
    int PointsButtonPosX = 150;
    int PointsButtonPosY = 200;
    int PointsButtonWidth = 100;
    int PointsButtonHeight = 50;
    

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        int MouseX = GetMouseX();
        int MouseY = GetMouseY();
        FrameCounterOneSecondPoints++;

        if (FrameCounterOneSecondPoints == 60)
        {
            Points++;
            FrameCounterOneSecondPoints = 0;
        }

        FrameCounterOneSecondProducerOne++;
        if (FrameCounterOneSecondProducerOne == 60)
        {
            ProducerOne();
            FrameCounterOneSecondProducerOne = 0;
        }

        DrawRectangle(150, 200, 100, 50, BLACK);
        std::string PointsToText = std::to_string(Points);
        std::string FormatedString = PointsText + PointsToText;
        DrawText(FormatedString.c_str(), 100, 100, 20, BLACK);
        if(IsMouseButtonReleased(0) && MouseX > PointsButtonPosX && MouseY > PointsButtonPosY 
                                    && MouseX < PointsButtonPosX + PointsButtonWidth && MouseY < PointsButtonPosY + PointsButtonHeight
                                    && Points >= CostOfProducerOne)
        { 
            AmountOfProducersOne++;
            CostOfProducerOne *= 2;
        }
        EndDrawing(); 
    }
    
    CloseWindow();

    return 0;
}

