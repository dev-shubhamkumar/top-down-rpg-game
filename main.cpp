#include "raylib.h"
#include "raymath.h"


int main()
{
    const int windowWidth{384};
    const int windowHeight{384};
    InitWindow(windowWidth, windowHeight, "Classy Class RPG");




    // Imporing Map to the Raylib window
    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    // Demifing vector and speed for assinging position to map
    Vector2 mapPos{0.0, 0.0};
    float speed{4.0};




    // Importing Character Texture to Raylib window
    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 knightPos{
        (float)windowWidth/2.0f - 4.0f * (0.5f * (float)knight.width/6.0f),
        (float)windowHeight/2.0f - 4.0f * (0.5f * (float)knight.height)
    };

    


    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);




        // creating if else statments to take key inputs to move the map
        Vector2 direction{};
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;

        if (IsKeyDown(KEY_LEFT)) direction.x -= 1.0;
        if (IsKeyDown(KEY_RIGHT)) direction.x += 1.0;
        if (IsKeyDown(KEY_UP)) direction.y -= 1.0;
        if (IsKeyDown(KEY_DOWN)) direction.y += 1.0;
        if (Vector2Length(direction) != 0.0)
        {
            // set mapPos = mapPos - direction
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
        }




        /*
            IMPORTANT: ADDING THE DIFFERENT CHARACTERS, MAP AND OTHER ASSETS IN THE FRAME LOOP
        */
        // Drawing Map Texture to Raylib window in each frame
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);


        // Drawing the charcater
        Rectangle source{0.f, 0.f, (float)knight.width/6.f, (float)knight.height};
        Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width/6.0f, 4.0f * (float)knight.height};
        Vector2 origin{};
        DrawTexturePro(knight, source, dest, origin, 0.f, WHITE);


        

        EndDrawing();
    }

    CloseWindow();
}