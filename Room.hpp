#pragma once
#include <raylib.h>
#include<vector>
#include "Platform.hpp"
#include "Player.hpp"
#include"Star.hpp"

class Room {
private:
    Rectangle nextroom;
    Texture2D backgroundTexture,Exit_texture;
    
    Vector2 playerSpawn;

public:
    std::vector<Platform*> plat;
    std::vector<Star*> skull;
    bool levelcomplete = 0;
    Room* next;


    Room(Texture2D BGTex,Vector2 P_Spawn, Rectangle exit);
    ~Room();

    void AddPlatform(Platform &platform);
    void AddStar(Star &star);
    void Draw(Player &player);
    Vector2 get_playerspawn();
    Texture2D get_bgtex();
    Rectangle get_nextroom();




};