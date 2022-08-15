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
    if (!getAlive()) return;
    worldPosLastFrame = worldPos;
    
    // creating if else statments to take key inputs to move the map
    if (IsKeyDown(KEY_A)) velocity.x -= 1.0;
    if (IsKeyDown(KEY_D)) velocity.x += 1.0;
    if (IsKeyDown(KEY_W)) velocity.y -= 1.0;
    if (IsKeyDown(KEY_S)) velocity.y += 1.0;

    if (IsKeyDown(KEY_LEFT)) velocity.x -= 1.0;
    if (IsKeyDown(KEY_RIGHT)) velocity.x += 1.0;
    if (IsKeyDown(KEY_UP)) velocity.y -= 1.0;
    if (IsKeyDown(KEY_DOWN)) velocity.y += 1.0;


    BaseCharacter::tick(deltaTime);

    Vector2 origin{};
    Vector2 offset{};
    float rotation{};
    if (rightLeft > 0.f)
    {
        origin = {0.f, weapon.height * scale};
        offset = {35.f, 55.f};
        weaponCollisionRec = {
            getScreenPos().x + offset.x,
            getScreenPos().y + offset.y - weapon.height * scale,
            weapon.width * scale,
            weapon.height * scale 
        };
        IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? rotation = 35.f : rotation = 0.f;
    }
    else
    {
        origin = {weapon.width * scale, weapon.height * scale};
        offset = {25.f, 55.f};
        weaponCollisionRec = {
            getScreenPos().x + offset.x - weapon.width * scale,
            getScreenPos().y + offset.y - weapon.height * scale,
            weapon.width * scale,
            weapon.height * scale 
        };
        IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? rotation = -35.f : rotation = 0.f;
    }

    // Draw the sword
    Rectangle source{0.f, 0.f, static_cast<float>(weapon.width) * rightLeft, static_cast<float>(weapon.height)};
    Rectangle dest{getScreenPos().x + offset.x, getScreenPos().y + offset.y, weapon.width * scale, weapon.height * scale};
    DrawTexturePro(weapon, source, dest, origin, rotation, WHITE);

    DrawRectangleLines(
        weaponCollisionRec.x,
        weaponCollisionRec.y,
        weaponCollisionRec.width,
        weaponCollisionRec.height,
        RED
    );
}
