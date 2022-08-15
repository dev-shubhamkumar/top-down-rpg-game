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
    if (!getAlive()) return;
    
    /*
        ################################################################################
        START:      Writing Code for AI Logic to Chase Knight
        ################################################################################
    */
    
    // STEP 1:  Get toTarget
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());

    // // STEP 2:  normalize toTarget
    // toTarget = Vector2Normalize(toTarget);

    // // STEP 3:  multiply toTarget by speed
    // toTarget = Vector2Scale(toTarget, speed);

    // // STEP 4:  move to enemy
    // worldPos = Vector2Add(worldPos, toTarget);

    /*
        ################################################################################
        END:        Writing Code for AI Logic to Chase Knight
        ################################################################################
    */
    


    BaseCharacter::tick(deltaTime);

    if (CheckCollisionRecs(target->getCollisionRec(), getCollisionRec()))
    {
        target->takeDamage(damagePerSec * deltaTime);
    }
    
}

Vector2 Enemy::getScreenPos()
{
    return Vector2Subtract(worldPos, target->getWorldPos());
}
