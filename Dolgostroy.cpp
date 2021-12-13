
#include "raylib.h"
#include <string>

//IDC
std::string PointsText = "Points: ";

//BUTTON PLACEMENT
int PointsButtonPosX = 150;
int PointsButtonPosY = 200;
int PointsButtonWidth = 100;
int PointsButtonHeight = 50;

//COUNTERS
int FrameCounterOneSecondPoints = 0;
int FrameCounterOneSecondProducerOne = 0;

//ECONOMY
int Points = 0;
int AmountOfProducersOne = 0;
int CostOfProducerOne = 30;

void ProducerOne()
{
    Points = Points + 1 * AmountOfProducersOne;
}

void FrameCounterOneSecondProducerOneFunc() 
{
    FrameCounterOneSecondProducerOne++;
    if (FrameCounterOneSecondProducerOne == 60)
    {
        ProducerOne();
        FrameCounterOneSecondProducerOne = 0;
    }
}

void FrameCounterOneSecondPointsFunc() 
{
    FrameCounterOneSecondPoints++;
    if (FrameCounterOneSecondPoints == 60)
    {
        Points = Points++;
        FrameCounterOneSecondPoints = 0;
    }
}


int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        int MouseX = GetMouseX();
        int MouseY = GetMouseY();
        FrameCounterOneSecondPointsFunc();
        FrameCounterOneSecondProducerOneFunc();

        DrawRectangle(150, 200, 100, 50, BLACK);
        std::string PointsToText = std::to_string(Points);
        std::string FormatedString = PointsText + PointsToText;
        DrawText(FormatedString.c_str(), 100, 100, 20, BLACK);
        DrawText("Producer I", 200, 200, 20, BLACK);
        if(IsMouseButtonReleased(0) && MouseX > PointsButtonPosX && MouseY > PointsButtonPosY 
                                    && MouseX < PointsButtonPosX + PointsButtonWidth && MouseY < PointsButtonPosY + PointsButtonHeight
                                    && Points >= CostOfProducerOne)
        { 
            AmountOfProducersOne++;
            Points = Points - CostOfProducerOne;
            CostOfProducerOne *= 2;
        }
        EndDrawing(); 
    }
    
    CloseWindow();

    return 0;
}

