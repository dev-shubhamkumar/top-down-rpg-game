#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"



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
    const float mapScale{4.0f};




    // Defining Character with help of defined class
    Character knight(windowWidth, windowHeight);




    // Defining Prop with help of defined class
    Prop props[2]{
        Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")},
    };




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

        for (auto prop : props)
        {
            prop.Render(knight.getWorldPos());
        }

        // Drawing the character
        knight.tick(GetFrameTime());
        /*
            IMPORTANT: Adding condition to check if
            our character has not crossed
            the Map of the game
        */
        if (knight.getWorldPos().x < 0.f ||
           knight.getWorldPos().y < 0.f ||
           knight.getWorldPos().x + windowWidth > map.width * mapScale ||
           knight.getWorldPos().y + windowHeight > map.height * mapScale)
        {
            knight.undoMovement();
        }

        // check if our charcater is coliding with prop
        for (auto prop: props)
        {
            if (CheckCollisionRecs(prop.getCollisionRec(knight.getWorldPos()), knight.getCollisionRec()))
            {
                knight.undoMovement();
            }
        }
        



        EndDrawing();
    }

    CloseWindow();
}
