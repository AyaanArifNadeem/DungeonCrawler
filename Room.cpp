#include "Platform.hpp"
#include "Player.hpp"
#include <vector>
#include "Room.hpp"

Room::Room(Texture2D BGTex, Vector2 P_Spawn, Rectangle exit)
{
    backgroundTexture = BGTex;
    playerSpawn = P_Spawn;
    nextroom = exit;
    Exit_texture = LoadTexture("resources/next.png") ;
    next = nullptr;
}

void Room::AddPlatform(Platform &platform)
{
    plat.push_back(&platform);
}

void Room::AddStar(Star &star)
{
    skull.push_back(&star);
}

void Room::Draw(Player &player){

    DrawTexturePro(backgroundTexture,(Rectangle){0, 0, (float)backgroundTexture.width, (float)backgroundTexture.height},(Rectangle){0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},(Vector2){0, 0},0.0f,WHITE);
        
            DrawTexturePro(
            Exit_texture,
            {0, 0, (float)Exit_texture.width, (float)Exit_texture.height},
            nextroom,
            {0, 0},
            0.0f,
            WHITE
        );


    for (Platform* platform : plat) {
        platform->update();
        if (!platform->breakable || (platform->breakable && platform->GetHitbox().x > 0)) {
        platform->Draw();
        }
    }

    for (Star* star : skull) {
        star->Draw();
        if(CheckCollisionRecs(player.hitbox(),star->GetHitbox())){
            star->update();
            player.stars_collected++;
        }
    }

    if(CheckCollisionRecs(player.hitbox(),nextroom)){
            if(skull.size() != player.stars_collected){
            DrawText(TextFormat("Collect all skulls to proceed"), 130, 300, 40, RED);   
            }else {
            DrawText(TextFormat("MOVING TO NEXT ROOM"), 130, 300, 80, RED);
            levelcomplete = 1;
            }
        }


    player.Draw();

    DrawText(TextFormat("Skulls: %d", player.stars_collected), 10, 10, 20, RED);

}


Vector2 Room::get_playerspawn()
{
    return playerSpawn;
}

Texture2D Room::get_bgtex()
{
    return backgroundTexture;
}

Rectangle Room::get_nextroom()
{
    return nextroom;
}

Room::~Room()
{
    UnloadTexture(backgroundTexture);
}