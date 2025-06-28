#pragma once
#include<raylib.h>

class Star{
private:
    Rectangle rect;       
    Texture2D texture;    
    Vector2 origin;
public:
    

    Star(float x, float y);
    void Draw();
    void update();
    Rectangle GetHitbox();
    ~Star();
};
