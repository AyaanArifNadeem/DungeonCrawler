#include"Star.hpp"
#include<raylib.h>


    Star::Star(float x,float y){
        rect={x,y,30,30};
        texture = LoadTexture("resources/skull.png");
    }

    void Star::Draw(){
        DrawTexturePro(
            texture,
            {0, 0, (float)texture.width, (float)texture.height},
            rect,
            {0, 0},
            0.0f,
            WHITE
        );
    }

    void Star::update(){
        rect.x = -100.0f;
        rect.y = -100.0f;
    }
    
    Rectangle Star::GetHitbox() {
    return rect;
    }

    Star::~Star()
    {
        UnloadTexture(texture);
    }

   