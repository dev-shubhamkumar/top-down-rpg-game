#include "raylib.h"
#include "raymath.h"


// ###########################################################################################
// Defining Classes and its functions
// ###########################################################################################
class Character
{
    public:
        Vector2 getWorldPos() {return worldPos;}
        void setScreenPos(int winWidth, int winHeight);
        void tick(float deltaTime);
    private:
        Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
        Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
        Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
        Vector2 screenPos{};
        Vector2 worldPos{};
        // 1 : facing right direction : -1 : facing left direction
        float rightLeft{1.f};
        // animation variables
        float runningTime{};
        int frame{};
        const int maxFrames{6};
        const float updateTime{1.f / 12.f};
        const float speed{4.f};
};

void Character::setScreenPos(int winWidth, int winHeight)
{
    screenPos = {
        (float)winWidth/2.0f - 4.0f * (0.5f * (float)texture.width/6.0f),
        (float)winHeight/2.0f - 4.0f * (0.5f * (float)texture.height)
    };
}

void Character::tick(float deltaTime)
{
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
        // set worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;     // using terniary operator
        texture = run;
    }
    else
    {
        texture = idle;
    }


    // upadate animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames) frame = 0;
    }


    // Drawing the charcater
    Rectangle source{frame * (float)texture.width/6.f, 0.f, rightLeft * (float)texture.width/6.f, (float)texture.height};
    Rectangle dest{screenPos.x, screenPos.y, 4.0f * (float)texture.width/6.0f, 4.0f * (float)texture.height};
    Vector2 origin{};
    DrawTexturePro(texture, source, dest, origin, 0.f, WHITE);
}






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