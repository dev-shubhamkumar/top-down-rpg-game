#include "Enemy.h"


Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
    worldPos = pos;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;

    width = texture.width / maxFrames;
    height = texture.height;
}

void Enemy::tick(float deltaTime)
{
    BaseCharacter::tick(deltaTime);
    
    // worldPosLastFrame = worldPos;

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
