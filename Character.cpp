#include "Character.h"
#include "raymath.h"


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
