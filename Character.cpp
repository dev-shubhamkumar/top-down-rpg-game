#include "Character.h"
#include "raymath.h"


Character::Character(int winWidth, int winHeight) :
    windowWidth(winWidth),
    windowHeight(winHeight)
{
    width = texture.width / maxFrames;
    height = texture.height;
}

Vector2 Character::getScreenPos(){
    return {
        static_cast<float>(windowWidth)/2.0f - scale * (0.5f * static_cast<float>(width)/6.0f),
        static_cast<float>(windowHeight)/2.0f - scale * (0.5f * static_cast<float>(height))
    };
}

void Character::tick(float deltaTime)
{
    // worldPosLastFrame = worldPos;

    // creating if else statments to take key inputs to move the map
    // Vector2 velocity{};
    if (IsKeyDown(KEY_A)) velocity.x -= 1.0;
    if (IsKeyDown(KEY_D)) velocity.x += 1.0;
    if (IsKeyDown(KEY_W)) velocity.y -= 1.0;
    if (IsKeyDown(KEY_S)) velocity.y += 1.0;

    if (IsKeyDown(KEY_LEFT)) velocity.x -= 1.0;
    if (IsKeyDown(KEY_RIGHT)) velocity.x += 1.0;
    if (IsKeyDown(KEY_UP)) velocity.y -= 1.0;
    if (IsKeyDown(KEY_DOWN)) velocity.y += 1.0;


    BaseCharacter::tick(deltaTime);
    

    // // upadate animation frame
    // runningTime += deltaTime;
    // if (runningTime >= updateTime)
    // {
    //     frame++;
    //     runningTime = 0.f;
    //     if (frame > maxFrames) frame = 0;
    // }


    // // Drawing the charcater
    // Rectangle source{frame * width, 0.f, rightLeft * width, height};
    // Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};
    // Vector2 origin{};
    // DrawTexturePro(texture, source, dest, origin, 0.f, WHITE);
}
