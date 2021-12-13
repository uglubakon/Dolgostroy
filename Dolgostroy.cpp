
#include "raylib.h"
#include <string>

//IDC
std::string PointsText = "Points: ";

//BUTTON PLACEMENT
int PointsButtonPosX = 100;
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
int CostOfProducerTwo = 120;

//PRODUCER EXECS

void ProducerOne()
{
    Points = Points + 1 * AmountOfProducersOne;
}

void ProducerTwo()
{
    Points = Points + 5 * AmountOfProducersOne;
}

void ProducerThree()
{
    Points = Points + 20 * AmountOfProducersOne;
}

void ProducerFour()
{
    Points = Points + 50 * AmountOfProducersOne;
}

void ProducerFive()
{
    Points = Points + 100 * AmountOfProducersOne;
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
        //DRAWING 
        BeginDrawing();
        ClearBackground(WHITE);

        //MOUSE POSITION CALL
        int MouseX = GetMouseX();
        int MouseY = GetMouseY();

        //BUTTONS CALLS
        DrawRectangle(100, 100, 133, 30, BLACK);
        DrawRectangle(100, 166, 133, 30, BLACK);
        DrawRectangle(100, 233, 133, 30, BLACK);
        DrawRectangle(100, 300, 133, 30, BLACK);
        DrawRectangle(100, 366, 133, 30, BLACK);

        //TEXT CALLS
        DrawText("Producer I", 103, 105, 20, WHITE);
        DrawText("Producer II", 103, 171, 20, WHITE);
        DrawText("Producer III", 103, 238, 20, WHITE);
        DrawText("Producer IV", 103, 305, 20, WHITE);
        DrawText("Producer V", 103, 371, 20, WHITE);

        //COUNTER CALLS
        FrameCounterOneSecondPointsFunc();
        FrameCounterOneSecondProducerOneFunc();

        std::string PointsToText = std::to_string(Points);
        std::string FormatedString = PointsText + PointsToText;
        DrawText(FormatedString.c_str(), 110, 50, 20, BLACK);
        if(IsMouseButtonReleased(0) && MouseX > PointsButtonPosX && MouseY > PointsButtonPosY 
                                    && MouseX < PointsButtonPosX + PointsButtonWidth 
                                    && MouseY < PointsButtonPosY + PointsButtonHeight
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

