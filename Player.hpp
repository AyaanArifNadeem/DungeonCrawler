#pragma once
#include <iostream>
#include "Platform.hpp"
#include "Entity.hpp"
#include "Star.hpp"
#include <vector>

class Player : public Entity{

public:
char name[8]={'P','l','a','y','e','r'};
int stars_collected = 0;
static std::vector<Star*>* allStars;
static std::vector<Platform*>* allPlatforms;
void update();
Player();
void Draw() const override;
void light_attack(Platform& target);
void setpositon(Vector2& pos);

};