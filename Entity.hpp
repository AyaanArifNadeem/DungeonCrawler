#pragma once
#include <raylib.h>


class Entity {
protected:

    Texture2D image;
    Vector2 position, speed;
    float  attack;
    float atk_range;
    bool facingRight = true;
    bool is_attacking = false;
    bool isGrounded = false;
    int atk_cooldown =0;
    int atk_delay = 30;
    float scale = 1.0f;

    
    const float gravity = 700.0f; 
    const float deltaTime = 1.0f / 60.0f;
    const float jumpVelocity = -400.0f;
    const float groundY = GetScreenHeight();
    float moveSpeed = 600.0f;       
    float acceleration = 2000.0f;   
    const float friction = 1500.0f;       


public:
    Entity();
    Entity& operator=(const Entity& other);
    ~Entity();
    virtual void Draw() const = 0;
    Rectangle hitbox();
    void gravity_on();
    Rectangle get_attack_hitbox();
    Rectangle get_wall_coll();
    void DrawAtkHitbox();
    Rectangle get_jumphitbox();
};

