#include "Player.hpp"
#include "Platform.hpp"
#include "Star.hpp"
#include<raylib.h>
#include <vector>

std::vector<Star*>* Player::allStars;
std::vector<Platform*>* Player::allPlatforms;

Player::Player(){
    image = LoadTexture("resources/76.png");
    position = {100, 100};
    attack = 40;
    speed = {10,0};
    moveSpeed = 300.0f;
}    

void Player::Draw() const{
    Rectangle sourceRect = {
        0.0f, 0.0f,
        float(image.width), float(image.height)
    };

    if (!facingRight) {
        sourceRect.width *= -1; 
    }

    Rectangle destRect = {
        position.x, position.y,
        float(image.width) * scale,
        float(image.height) * scale
    };

    Vector2 origin = {0, 0}; 
    DrawTexturePro(image, sourceRect, destRect, origin, 0.0f, RAYWHITE);
    DrawText(name, position.x+ 10.0f, position.y - 20.0f, 15, LIGHTGRAY);
}

void Player::light_attack(Platform& target)
{
    if (CheckCollisionRecs(target.GetHitbox(), get_attack_hitbox()) && atk_cooldown>atk_delay &&target.breakable) {

        DrawAtkHitbox();
        target.health -= attack;
        atk_cooldown=0;
        is_attacking = true;
        
    } else{
        is_attacking = false;
    
}

}

void Player::setpositon(Vector2& pos)
{
    position = pos;
}

void Player::update()
{
    isGrounded = false;
    gravity_on();
    atk_cooldown++;

//Control Clipping
    if(speed.y > 400.0f){
        speed.y = 400.0f;
    }

    
// PLATFORM COLLISION
bool groundCollisionFound = false;
bool wallCollisionFound = false;

for (Platform* platform : (*allPlatforms)) {

    if(IsKeyDown(KEY_Z)){light_attack((*platform));}
    if (!groundCollisionFound && 
        (CheckCollisionRecs(hitbox(), platform->GetHitbox()) || 
         CheckCollisionRecs(get_jumphitbox(), platform->GetHitbox()))) 
    {
        if (speed.y >= 0 && 
            position.y + (image.height * scale) <= platform->GetHitbox().y + 10) 
        {
            position.y = platform->GetHitbox().y - (image.height * scale);
            speed.y = 0;
            isGrounded = true;
            groundCollisionFound = true;
        }
    }
    
    if (!wallCollisionFound && platform->isSolid &&
        (CheckCollisionRecs(hitbox(), platform->GetHitbox()) || 
         CheckCollisionRecs(get_wall_coll(), platform->GetHitbox()))) 
    {
        if (position.x + (image.width * scale) >= platform->GetHitbox().x && 
            position.x < platform->GetHitbox().x) 
        {
            position.x = platform->GetHitbox().x - (image.width * scale);
            speed.x = 0;
            wallCollisionFound = true;
        }
        else if (position.x <= platform->GetHitbox().x + platform->GetHitbox().width && 
                 position.x > platform->GetHitbox().x + platform->GetHitbox().width - (image.width * scale)) 
        {
            position.x = platform->GetHitbox().x + platform->GetHitbox().width + 1.0f;
            speed.x = 0;
            wallCollisionFound = true;
        }
    }
    
    if (groundCollisionFound && wallCollisionFound) {
        break;
    }
}


if (position.y >= GetScreenHeight() - (image.height * scale)) {
    isGrounded = true;
}

    
//Movement
    if((IsKeyDown(KEY_UP) && isGrounded)){
        speed.y = jumpVelocity; 
    }
    if(IsKeyDown(KEY_DOWN) && (position.y!=GetScreenHeight()-float(image.height*scale))) {
        speed.y += gravity * 2 * deltaTime; 
        position.y += speed.y * deltaTime;
    }
    
    float sprint = IsKeyDown(KEY_LEFT_SHIFT) ? 2.0f : 1.0f;

    if (IsKeyDown(KEY_LEFT) && (position.x>0)) {
        speed.x -= acceleration * sprint * deltaTime;
        facingRight = false;
    } else if (IsKeyDown(KEY_RIGHT) && (position.x<GetScreenWidth()-float(image.width*scale))) {
        speed.x += acceleration * sprint * deltaTime;
        facingRight = true;
    } else {
        if (speed.x > 0) {
            speed.x -= friction * deltaTime;
            if (speed.x < 0) speed.x = 0;
        } else if (speed.x < 0) {
            speed.x += friction * deltaTime;
            if (speed.x > 0) speed.x = 0;
        }
    }
    
    float maxSpeed = moveSpeed * sprint;

    if (speed.x > maxSpeed) speed.x = maxSpeed;
    if (speed.x < -maxSpeed) speed.x = -maxSpeed;
    
    position.x += speed.x * deltaTime;
    position.y += speed.y * deltaTime;
    
//Clamping Positions
    float entityWidth = float(image.width) * scale;
    float entityHeight = float(image.height) * scale;
    if (position.x < 0) position.x = 0;
    if (position.x > GetScreenWidth() - entityWidth) position.x = GetScreenWidth() - entityWidth;
   
    


}

