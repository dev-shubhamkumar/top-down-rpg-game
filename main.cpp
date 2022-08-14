#include "raylib.h"
#include "raymath.h"
#include "Character.h"



// ###########################################################################################
// Defining int main() function 
// ###########################################################################################
int main()
{
    const int windowWidth{384};
    const int windowHeight{384};
    InitWindow(windowWidth, windowHeight, "Classy Class RPG");

    // Imporing Map to the Raylib window
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    // Demifing vector and speed for assinging position to map
    Vector2 mapPos{0.0, 0.0};




    // Defining Character with help of defined class
    Character knight;
    knight.setScreenPos(windowWidth, windowHeight);




    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);


        // Deriving mapPos from worldPos varibale 
        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);


        /*
            IMPORTANT: ADDING THE DIFFERENT CHARACTERS, MAP AND OTHER ASSETS IN THE FRAME LOOP
        */
        // Drawing Map Texture to Raylib window in each frame
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
        // Drawing the character
        knight.tick(GetFrameTime());
        



        EndDrawing();
    }

    CloseWindow();
}