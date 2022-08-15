#include "Enemy.h"
#include "raymath.h"


Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
    worldPos = pos;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;

    width = texture.width / maxFrames;
    height = texture.height;
    speed = 3.5f;
}

void Enemy::tick(float deltaTime)
{
    /*
        ################################################################################
        START:      Writing Code for AI Logic to Chase Knight
        ################################################################################
    */
    
    // STEP 1:  Get toTarget
    Vector2 toTarget = Vector2Subtract(target->getScreenPos(), screenPos);

    // STEP 2:  normalize toTarget
    toTarget = Vector2Normalize(toTarget);

    // STEP 3:  multiply toTarget by speed
    toTarget = Vector2Scale(toTarget, speed);

    // STEP 4:  move to enemy
    worldPos = Vector2Add(worldPos, toTarget);

    /*
        ################################################################################
        END:        Writing Code for AI Logic to Chase Knight
        ################################################################################
    */
    



    screenPos = Vector2Subtract(worldPos, target->getWorldPos());
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
