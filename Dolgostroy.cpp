
#include "raylib.h"
#include <string>
#include <Header.h>

//STRING VAR
std::string PointsText = "Points: ";

//BUTTON POSITIONS
int ProducerOneButtonPosX = 100; int ProducerOneButtonPosY = 100; int ProducerOneButtonWidth = 133; int ProducerOneButtonHeight = 30;
int ProducerTwoButtonPosX = 100; int ProducerTwoButtonPosY = 166; int ProducerTwoButtonWidth = 133; int ProducerTwoButtonHeight = 30;
int ProducerThreeButtonPosX = 100; int ProducerThreeButtonPosY = 233; int ProducerThreeButtonWidth = 133; int ProducerThreeButtonHeight = 30;
int ProducerFourButtonPosX = 100; int ProducerFourButtonPosY = 300; int ProducerFourButtonWidth = 133; int ProducerFourButtonHeight = 30;
int ProducerFiveButtonPosX = 100; int ProducerFiveButtonPosY = 366; int ProducerFiveButtonWidth = 133; int ProducerFiveButtonHeight = 30;

//COUNTERS
int FrameCounterOneSecondPoints = 0;
int FrameCounterOneSecondProducerOne = 0;
int FrameCounterOneSecondProducerTwo = 0;
int FrameCounterOneSecondProducerThree = 0;
int FrameCounterOneSecondProducerFour = 0;
int FrameCounterOneSecondProducerFive = 0;

//ECONOMY
int Points = 0;
int AmountOfProducersOne = 0;
int AmountOfProducersTwo = 0;
int AmountOfProducersThree = 0;
int AmountOfProducersFour = 0;
int AmountOfProducersFive = 0;
int CostOfProducerOne = 10;
int CostOfProducerTwo = 10;
int CostOfProducerThree = 10;
int CostOfProducerFour = 10;
int CostOfProducerFive = 10;

//PRODUCER EXECS

void ProducerOne()
{
    Points = Points + 1 * AmountOfProducersOne;
}

void ProducerTwo()
{
    Points = Points + 5 * AmountOfProducersTwo;
}

void ProducerThree()
{
    Points = Points + 20 * AmountOfProducersThree;
}

void ProducerFour()
{
    Points = Points + 50 * AmountOfProducersFour;
}

void ProducerFive()
{
    Points = Points + 100 * AmountOfProducersFive;
}

//COUNTERS

void FrameCounterOneSecondProducerOneFunc() 
{
    FrameCounterOneSecondProducerOne++;
    if (FrameCounterOneSecondProducerOne == 60)
    {
        ProducerOne();
        FrameCounterOneSecondProducerOne = 0;
    }
}

void FrameCounterOneSecondProducerTwoFunc()
{
    FrameCounterOneSecondProducerTwo++;
    if (FrameCounterOneSecondProducerTwo == 60)
    {
        ProducerTwo();
        FrameCounterOneSecondProducerTwo = 0;
    }
}

void FrameCounterOneSecondProducerThreeFunc()
{
    FrameCounterOneSecondProducerThree++;
    if (FrameCounterOneSecondProducerThree == 60)
    {
        ProducerThree();
        FrameCounterOneSecondProducerThree = 0;
    }
}

void FrameCounterOneSecondProducerFourFunc()
{
    FrameCounterOneSecondProducerFour++;
    if (FrameCounterOneSecondProducerFour == 60)
    {
        ProducerFour();
        FrameCounterOneSecondProducerFour = 0;
    }
}

void FrameCounterOneSecondProducerFiveFunc()
{
    FrameCounterOneSecondProducerFive++;
    if (FrameCounterOneSecondProducerFive == 60)
    {
        ProducerFive();
        FrameCounterOneSecondProducerFive = 0;
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
    InitWindow(333, 450, "Point Producer 0.0.1 Debug");

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
        FrameCounterOneSecondProducerTwoFunc();
        FrameCounterOneSecondProducerThreeFunc();
        FrameCounterOneSecondProducerFourFunc();
        FrameCounterOneSecondProducerFiveFunc();

        //INT TO TEXT TRANSMUTATION
        std::string PointsToText = std::to_string(Points);
        std::string FormatedString = PointsText + PointsToText;
        DrawText(FormatedString.c_str(), 122, 50, 20, BLACK);

        //MOUSE CLICKS
        if(IsMouseButtonReleased(0) && MouseX > ProducerOneButtonPosX && MouseY > ProducerOneButtonPosY 
                                    && MouseX < ProducerOneButtonPosX + ProducerOneButtonWidth
                                    && MouseY < ProducerOneButtonPosY + ProducerOneButtonHeight
                                    && Points >= CostOfProducerOne)
        { 
            AmountOfProducersOne++;
            Points = Points - CostOfProducerOne;
            CostOfProducerOne *= 2;
        }

        if(IsMouseButtonReleased(0) && MouseX > ProducerTwoButtonPosX && MouseY > ProducerTwoButtonPosY 
                                    && MouseX < ProducerTwoButtonPosX + ProducerTwoButtonWidth
                                    && MouseY < ProducerTwoButtonPosY + ProducerTwoButtonHeight
                                    && Points >= CostOfProducerTwo)
        { 
            AmountOfProducersTwo++;
            Points = Points - CostOfProducerTwo;
            CostOfProducerTwo *= 2;
        }

        if(IsMouseButtonReleased(0) && MouseX > ProducerThreeButtonPosX && MouseY > ProducerThreeButtonPosY 
                                    && MouseX < ProducerThreeButtonPosX + ProducerThreeButtonWidth
                                    && MouseY < ProducerThreeButtonPosY + ProducerThreeButtonHeight
                                    && Points >= CostOfProducerThree)
        { 
            AmountOfProducersThree++;
            Points = Points - CostOfProducerThree;
            CostOfProducerThree *= 2;
        }

        if(IsMouseButtonReleased(0) && MouseX > ProducerFourButtonPosX && MouseY > ProducerFourButtonPosY 
                                    && MouseX < ProducerFourButtonPosX + ProducerFourButtonWidth
                                    && MouseY < ProducerFourButtonPosY + ProducerFourButtonHeight
                                    && Points >= CostOfProducerFour)
        { 
            AmountOfProducersFour++;
            Points = Points - CostOfProducerFour;
            CostOfProducerFour *= 2;
        }

        if(IsMouseButtonReleased(0) && MouseX > ProducerFiveButtonPosX && MouseY > ProducerFiveButtonPosY
                                    && MouseX < ProducerFiveButtonPosX + ProducerFiveButtonWidth
                                    && MouseY < ProducerFiveButtonPosY + ProducerFiveButtonHeight
                                    && Points >= CostOfProducerFive)
        { 
            AmountOfProducersFive++;
            Points = Points - CostOfProducerFive;
            CostOfProducerFive *= 2;
        }

        EndDrawing(); 
    }
    
    CloseWindow();

    return 0;
}

