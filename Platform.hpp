#pragma once
#include <raylib.h>

class Platform{
private:
    Rectangle rect;       
    Texture2D texture;    
    Vector2 origin, dimensions;

public:
    bool breakable;
    int health = 30;
    bool isSolid;  
      
    
    Platform(float x, float y, bool iswall);
    Platform(float x, float y, float width,float height, bool iswall);
    Platform(float x, float y, float width,float height, bool iswall, bool isbreakable);
    void Draw();
    void update();
    Rectangle GetHitbox();
    ~Platform();
};