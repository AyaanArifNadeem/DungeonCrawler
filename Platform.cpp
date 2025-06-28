#include "Platform.hpp"
#include<raylib.h>

Platform::Platform(float x, float y, bool iswall){
    isSolid = iswall;    
    origin={x,y};
    if(!isSolid){
    rect={x,y,300.0f,50.0f};
    dimensions = {300.0f,50.0f};
    texture = LoadTexture("resources/map.png");
    } 
    if(isSolid){
    rect={x,y,50.0f,300.0f};
    dimensions = {50.0f,300.0f};
    texture = LoadTexture("resources/wall.png");
    }
}

Platform::Platform(float x, float y,float width, float height, bool iswall)
{ 
    isSolid = iswall;  
    origin = {x,y};  
    dimensions={width,height};
    if(!isSolid){
    rect={x,y,width,height};
    texture = LoadTexture("resources/map.png");
    } 
    if(isSolid){
    rect={x,y,width,height};
    texture = LoadTexture("resources/wall.png");
    }
}

Platform::Platform(float x, float y,float width, float height, bool iswall, bool isbreakable)
{ 
    breakable = isbreakable;
    isSolid = iswall;  
    origin = {x,y};  
    dimensions={width,height};
    if(!isSolid){
    rect={x,y,width,height};
    texture = LoadTexture("resources/breakablefloor.png");
    } 
    if(isSolid){
    rect={x,y,width,height};
    texture = LoadTexture("resources/breakablewall.png");
    }
}

void Platform::Draw(){
DrawTexturePro(
            texture,
            {0, 0, (float)texture.width, (float)texture.height},
            rect,
            {0, 0},
            0.0f,
            WHITE
        );
}

Rectangle Platform::GetHitbox() {
    return rect;
}

Platform::~Platform()
{
        UnloadTexture(texture);
}




void Platform::update()
{
    if(breakable && health<0){
        rect.x = -100.0f;
        rect.y = -100.0f;
    }
}
