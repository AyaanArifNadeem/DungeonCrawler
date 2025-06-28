#include "Entity.hpp"
#include <raylib.h>


Entity::Entity() {}

Entity& Entity::operator=(const Entity& other) {
    if (this == &other) return *this;
    
    position = other.position;
    speed = other.speed;
    attack = other.attack;
    atk_range = other.atk_range;
    facingRight = other.facingRight;
    is_attacking = other.is_attacking;
    isGrounded = other.isGrounded;
    atk_cooldown = other.atk_cooldown;
    atk_delay = other.atk_delay;
    scale = other.scale;
    UnloadTexture(image);
    image = LoadTextureFromImage(LoadImageFromTexture(other.image));

    return *this;
}


Entity::~Entity() {
    UnloadTexture(image);
}



Rectangle Entity::hitbox()
{
    return Rectangle{position.x,position.y,float(image.width*scale),float(image.height*scale)};
}

Rectangle Entity::get_attack_hitbox() {
    atk_range = 1200*0.05;
    float width = atk_range;  
    float height = float(image.height * scale *0.8f);
    if (facingRight) {
        return Rectangle{position.x + float(image.width * scale), position.y+float(image.height * scale *0.1f) , width, height};
    } else {
        return Rectangle{position.x - width, position.y+float(image.height *scale* 0.1f) , width, height};
    }
}

Rectangle Entity::get_wall_coll()
{
    float width = 10.0f;
    float height = float(image.height * scale );
    if (facingRight) {
        return Rectangle{position.x + float(image.width * scale), position.y+float(image.height * scale *0.1f) , width, height};
    } else {
        return Rectangle{position.x - width, position.y+float(image.height *scale* 0.1f) , width, height};
    }
}

void Entity::DrawAtkHitbox(){
        DrawRectangleLinesEx(get_attack_hitbox(),10,RED);
    
}

void Entity::gravity_on()
{
    if (!isGrounded) {
    speed.y += gravity * deltaTime; 
    position.y += speed.y * deltaTime;
    }
    if (position.y>GetScreenHeight()-float(image.height*scale)) {
        position.y = groundY - float(image.height*scale);
        speed.y = 0;
    }
   

}


Rectangle Entity::get_jumphitbox(){
    return Rectangle{position.x,(position.y + float(image.height*scale)),float(image.width*scale),float(image.height*scale)*0.05f};
}